package analysisString;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/*
    解析字符串:
         在机器人足球比赛中，server 和球员 client 之间通过发送字符串来进行信息交互，其
         中server 要把某球员的听觉和视觉信息发送给该球员，信息的格式如下所示：
        （hear Time Sender Message）（see Time ObjInfo ObjInfo）
        其中ObjectInfo又有以下规则，且其数量不定
        （ObjName Distance Direction DistChng DirChng BodyDir HeadDir）

        示例:(hear 1022 -30 passto(23,24))(see 1022 ((ball) 20 -20 1 -2) ((player hfut1 2) 23 45 0.5 1 22 40) ((goal r) 12 20)) ((Line r) -30))
        输出：
            在 1022 周期 hear 从 -30 方向 听到了 passto(23,24)； 在 1022 周期 see Ball 距离我的 Distance 是 20，Direction 是 -20，
            DistChng 是 1，DirChng是-2；player hfut 2 距离我的 Distance 是 23， Direction 是 45，DistChng 是 0.5，DirChng 是 1，
            它的 BodyDir 是 22 和 HeadDir 是 44；goal r 距离我的 Distance 是 12，Direction 是 20。Line r 和我的角度是-30 度

    需求分析:
        输入是一整个字符串，其可分为两部分--hear与see,首先需要将这两部分分开，以字符串”))(“分割（注意其与")) ("是是不同的），分别进行解析
        对于hear的解析较为简单，将其按空格分割加以修饰即可，唯一需要注意的是Sender为其它球员时的表示
        对于see的解析则可分为两个模块，我们不能以空格将语句分割解析，因为ObjectInfo中也含有许多空格，仔细观察便会发现see语句的每个组成部分都恰好被
        "(("这个字符串分割，分割后对于see time无需多加处理可直接进行解析，而其余的每个ObjInfo需先进行一定处理，再进行解析，因为不同Obj的信息种类是不同的
         Distance，Direction 表示目标的相对距离和相对方向
         DistChng 和 DirChng 分别表示目标距离和方向的相对变化，如果是固
            定物体（球和球员以外的所有对象）则没有改项值
         BodyDir 和 HeadDir，分别是被观察球员相对观察者的身体和头部的
            相对角度，只有是球队对象才有这一项值。
        Line有唯一属性即与球员client的角度
 */
public class Analysis {
    final static int HEAR = 0;
    final static int SEE = 1;
    public static void main(String[] args) {
        /**
         * 输入原始语句
         * 这里采用从控制台直接输入
         */
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入需解析的语句:");
        String initialStatement = scanner.nextLine();

        /**
         * 开始进行解析
         * 借助工具类
         */
        String[] s = initialStatement.split("\\)\\(" );
        if (s.length != 2){
            System.out.println("输入语句错误,请修改后再进行解析");
        }else{
            System.out.println("解析完毕，已保存至clientData中，显示如下: ");
            //解析hear指令
            Util.analysisHearStr(s[HEAR]);
            //解析see指令
            Util.analysisSeeStr(s[SEE]);
        }
    }
}

class Util{
    final static int CMDKIND = 0;
    final static int TIME = 1;
    final static int SENDER = 2;
    final static int MESSAGE = 3;
    final static int DISTANCE = 0;
    final static int DIRECTION = 1;
    final static int DISTHNG = 2;
    final static int DISTCHNG = 3;
    final static int BODYDIR = 4;
    final static int HEADDIR = 5;
    final static int LINE = 0;
    /**
     * 解析hear语句
     * @param hearStr 初始hear语句
     * @return 解析后下henr语句
     */
    public static String analysisHearStr(String hearStr){
        String returnHearStr;
        String[] s = (hearStr.substring(1)).split(" ");

        if(!s[CMDKIND].equals("hear")){
            System.out.println("error: 找不到hear指令,请修改后再进行解析");
            return "";
        }else{
            String sender;
            switch (s[SENDER]){
                case "self": sender = "我自己那里"; break;
                case "referee": sender = "裁判那里"; break;
                case "online_coach_left": sender = "在线教练那里"; break;
                default:sender = s[SENDER] + "方向"; break;
            }
            returnHearStr = "在" + s[TIME] + "周期hear从" + sender + "听到了" + s[MESSAGE] + ";";
            //保存听到的信息
            Obj obj = new Obj(("hear " + s[SENDER]), s);
            ClientData.groupByData(obj);
            System.out.println(returnHearStr);
        }
        return returnHearStr;
    }

    /**
     * 解析see语句
     * @param seeStr 初始see语句
     * @return 解析后的see语句
     */
    public static String analysisSeeStr(String seeStr){
        StringBuilder returnSeeStr = new StringBuilder();
        String[] s = seeStr.split(" \\(\\(");
        String[] basicCmd = s[0].split(" ");
        String cmdKind = basicCmd[0];
        String time = basicCmd[1];
        if (!cmdKind.equals("see")){
            System.out.println("error: 找不到see指令,请修改后再进行解析");
            return "";
        }else{
           returnSeeStr.append("在").append(time).append("周期 see ");
            for(int i = 1; i < s.length; i++){
                //逐个解析objectInfo
                String[] obj = s[i].split("\\) ");
                String objName = obj[0];
                String[] objData = obj[1].split(" ");
                objData[objData.length-1] = objData[objData.length-1].replaceAll("\\)", "");

                //保存信息
                Obj obj1 = new Obj(objName, objData);
                ClientData.groupByData(obj1);

                //根据属性个数判断obj的类型，对应进行解析
                if (objData.length == 6){
                    returnSeeStr.append(objName).append("距离我的 Distance 是").append(objData[0]).append(", Direction 是").
                                    append(objData[1]).append(", DistChng 是").append(objData[2]).append(", DirChng是 ").
                                        append(objData[3]).append(", BodyDir是 ").append(objData[4]).append(", HeadDir是 ").
                                            append(objData[5]).append(";\n");
                } else if(objData.length == 4){
                    returnSeeStr.append(objName).append("距离我的 Distance 是").append(objData[0]).
                                    append(", Direction 是").append(objData[1]).append(", DistChng 是").
                                        append(objData[2]).append(", DirChng 是").append(objData[3]).append(";\n");
                }else if (objData.length == 2){
                    returnSeeStr.append(objName).append("距离我的 Distance 是").append(objData[0]).append(", Direction 是").
                                    append(objData[1]).append(";\n");
                }else if(objData.length == 1){
                    returnSeeStr.append(objName).append("和我的角度是").append(objData[0]).append(";\n");
                }else{
                    System.out.println("error: 观察对象格式书写错误，请检查后再进行解析!");
                }
            }

            System.out.println(returnSeeStr);
        }
        return returnSeeStr.toString();
    }
}

/**
 * 封装通过see得到的信息
 */
class ClientData{
    final static String TEAMA = "hfut1";
    final static String TEAMB = "hfut2";
    final static String BALL = "ball";
    final static String PLAYER = "player";
    final static String GOAL = "goal";
    final static String LINE = "Line";
    final static String FLAG = "flag";
    static Map<String, Obj> teammateMap;
    static Map<String, Obj> opponent;
    static Map<String, Obj> other;
    static Map<String, Obj> hear;

    static {
        teammateMap = new HashMap<>();
        opponent = new HashMap<>();
        other = new HashMap<>();
        hear = new HashMap<>();
    }

    //对保存信息进行分类
    public static boolean groupByData(Obj obj){
        String objName = obj.name;
        if (objName.contains(PLAYER + " " + TEAMA)){
            addTeammateData(obj);
        } else if(objName.contains(PLAYER + " " + TEAMB)){
            addOpponentData(obj);
        } else if(objName.contains(BALL) || objName.contains(GOAL) ||
                    objName.contains(LINE) || objName.contains(FLAG)){
            addOtherData(obj);
        } else if(objName.contains("hear")){
            addHearData(obj);
        } else{
            System.out.println(objName);
            System.out.println("出现未知物品，信息保存出错");
            return false;
        }
        return true;
    }

    //保存队友信息
    private static void addTeammateData(Obj obj){
        teammateMap.put(obj.name, obj);
    }

    //保存对手信息
    private static void addOpponentData(Obj obj){
        opponent.put(obj.name, obj);
    }

    //保存球场上除球员外的其它所有信息
    private static void addOtherData(Obj obj){
        other.put(obj.name, obj);
    }

    //保存球场上除球员外的其它所有信息
    private static void addHearData(Obj obj){
        other.put(obj.name, obj);
    }
}

class Obj{
    public String name;
    public String[] data;
    public Obj(String name, String[] data){
        this.name = name;
        this.data = data;
    }
}
