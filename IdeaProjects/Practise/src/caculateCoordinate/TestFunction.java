package caculateCoordinate;

/*
       设图中 C(0,0),P1(‐52.5,‐32) P2(‐52.5, 32), P3(52.5,32), P4(52.5,‐32), P5(0,‐32),
        P6(0,32),P7(‐30,‐7),P8(‐30,P7),P9(30,7),P10(30,‐7),G1(‐52.5,0),G2(52.5,0)
        随机得到附近 2 点距离自己的信息(r,theta), r 表示目标点距离自己的距离，theta
        表示以自己中心的极角.（顺时针（0,180），逆时针（0，‐180）。计算自己的位置。
        输入示例：
            (p8 22 0) (p7 27.7 30)
        输出：px = 8.2, py = 10.14

        分析:将此问题转化为数学问题。即已知两点坐标，以及此两点
            与第三点连线的长度与它们之间的夹角，求第三点的坐标。
            根据条件：利用向量的点积与叉积分别列出方程，即可求解

 */

import java.util.HashMap;

/**
 * 输入信息
 */

class InputData{
    String name;
    double r;
    double theta;

    public InputData(String name, double r, double theta) {
        this.name = name;
        this.r = r;
        this.theta = theta;
    }
}

/**
 * 坐标
 */
class CorordinateData{
    //标识
    String name;
    double x;
    double y;

    public CorordinateData(String name, double x, double y) {
        this.name = name;
        this.x = x;
        this.y = y;
    }
}

class Util{
    static HashMap<String, CorordinateData> corordinateDataMap;
    public static void initData(){
        corordinateDataMap = new HashMap<>();
        corordinateDataMap.put("C", new CorordinateData("C", 0.0, 0.0));
        corordinateDataMap.put("P1", new CorordinateData("P1", -52.5, -32.0));
        corordinateDataMap.put("P2", new CorordinateData("P2", -52.5, 32.0));
        corordinateDataMap.put("P3", new CorordinateData("P3", 52.5, 32.0));
        corordinateDataMap.put("P4", new CorordinateData("P4", -52.5, -32.0));
        corordinateDataMap.put("P5", new CorordinateData("P5", 0.0, -32.0));
        corordinateDataMap.put("P6", new CorordinateData("P6", 0.0, 32.0));
        corordinateDataMap.put("P7", new CorordinateData("P7", -30.0, -7.0));
        corordinateDataMap.put("P8", new CorordinateData("P8", -30.0, 7.0));
        corordinateDataMap.put("P9", new CorordinateData("P9", 30.0, 7.0));
        corordinateDataMap.put("P10", new CorordinateData("P10", 30.0, -7.0));
        corordinateDataMap.put("G1", new CorordinateData("G1", -52.5, 0.0));
        corordinateDataMap.put("G2", new CorordinateData("G2", 52.5, 0.0));
    }

    /**
     * 计算位置
     * @param M1 附近坐标1
     * @param M2 附近坐标2
     * @return 自己所处位置坐标P
     */
    public static void caculateCoordinate(InputData M1, InputData M2){
        double Ax = corordinateDataMap.get(M1.name).x;
        double Ay = corordinateDataMap.get(M1.name).y;
        double Bx = corordinateDataMap.get(M2.name).x;
        double By = corordinateDataMap.get(M2.name).y;
        double La = M1.r;
        double Lb = M2.r;
        double angle = Math.abs(M1.theta - M2.theta)/180*Math.PI;
        double cosAngle = Math.cos(angle);
        double sinAngle = Math.sin(angle);
        /**
         * 设P点坐标为Px, Py
         * 点积列方程：
         * (Ax - Px) * (Bx - Px) + (Ay - Py) * (By - Py) = La * Lb * cos(angle);
         * 合并同类项得：
         * (Px)^2 + (Py)^2 - (Ax + Bx)*Px - (Ay + By)*Py + Ax*Bx + Ay*By - La * Lb * cos(angle) = 0;
         * 叉积列方程：
         * （Ax - Px) * (By - Py) - (Ay - Py) * (Bx - Px) = La * Lb * sin(angle);
         * 合并同类项得：
         * (Ay - By)*Px + (Bx - Ax)*Py + Ax*By - Ay*Bx = La * Lb * sin(angle);
         */
        double temp1, temp2;
        double a, b, c, t;
        if (Math.abs(Ay - By) > 0.0000001){
            //用Py 标识 Px, 带入点积
            temp1 = (La*Lb*sinAngle + Ay*Bx - Ax*By)/(Ay - By);
            temp2 = (Ax - Bx)/(Ay - By);
            /**
             * 一元二次方程的各项系数
             */
            a = 1.0 + temp2*temp2;
            b = -(Ay + By + (Ax + Bx)*temp2 - 2.0* temp1 *temp2);
            c = Ax*Bx + Ay*By - La*Lb*cosAngle + temp1 * temp1 - (Ax + Bx)*temp1;
            t = b * b - 4.0 * a * c;
            if (t < 0.0){
                //方程无解
                System.out.println("输入数据出错！");
            }
            double y1 = (-b + Math.sqrt(t))/(2.0 * a);
            double y2 = (-b - Math.sqrt(t))/(2.0 * a);
            double x1 = temp1 + temp2 * y1;
            double x2 = temp1 + temp2 * y2;
            //两向量的叉积
            double coss = (Ax - x1) * (By - y1) - (Ay - y1)*(Bx - x1);
            /**
             * 当有两个解时，需利用叉积根据theta判断出唯一解
             */
            if ((M1.theta > M2.theta && coss < 0.0) || (M1.theta <= M2.theta && coss > 0.0)){
                //说明p1应在p2的顺时针方向
                System.out.println("px = " + x1 +"  py = " + y1);
            }else {
                System.out.println("px = " + x2 +"  py = " + y2);
            }
        }else{
            //用Px 标识 Py, 带入点积方程
            temp1 = (La*Lb*sinAngle + Ay*Bx - Ax*By)/(Bx - Ax);
            temp2 = (By - Ay)/(Bx - Ax);
            a = 1.0 + temp2 * temp2;
            b = -(Ax + Bx + (Ay + By) * temp2 - 2.0 * temp1 *temp2);
            c = Ax*Bx + Ay*By - La*Lb*cosAngle + temp1 * temp1 - (Ay + By)*temp1;
            t = b * b - 4.0 * a * c;
            double x1 = (-b + Math.sqrt(t))/(2.0 * a);
            double x2 = (-b - Math.sqrt(t))/(2.0 * a);
            double y1 = temp1 + temp2 * x1;
            double y2 = temp1 + temp2 * x2;
            double coss = (Ax - x1) * (By - y1) - (Ay - y1)*(Bx - x1);
            if ((M1.theta > M2.theta && coss < 0.0) || (M1.theta <= M2.theta && coss > 0.0)){
                //说明p1应在p2的顺时针方向
                System.out.println("px = " + x1 +"  py = " + y1);
            }else {
                System.out.println("px = " + x2 +"  py = " + y2);
            }
        }
    }

    /**
     * 这部分真™写得又臭又烂。2021-10-1
     * 解方程组真的烦
     */
}
public class TestFunction {
    public static void main(String[] args) {
        /**
         * 初始化图中已知点信息
         */
        Util.initData();
        /**
         * 设置测试数据
         */
        InputData inputData1 = new InputData("C", 10.0, 45.0);
        InputData inputData2 = new InputData("P5", 43.17, 76.65);
        /**
         * 计算
         */
        Util.caculateCoordinate(inputData1, inputData2);
    }
}

