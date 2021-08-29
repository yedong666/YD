package ChatRoom;

import java.util.HashMap;

//用户类，包含一个用户的基本信息
public class User {
    private int account;
    private String password;
    private String age;
    private String sex;
    private String name;
    public HashMap<String, User> friends;

    User(int account, String password){
        friends = new HashMap<>();
        this.account = account;
        this.password = password;
    }

    User(){};

    public void setAccount(int account){
        this.account = account;
    }

    public void setAge(String age) {
        this.age = age;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setPassword(String password){
        this.password = password;
    }

    public void setSex(String sex){
        this.sex = sex;
    }

    public String getName(){
        return this.name;
    }

    public String getPassword(){
        return this.password;
    }

    public int getAccount(){
        return this.account;
    }

    public String getAge(){
        return this.age;
    }

    public String getSex(){
        return this.sex;
    }
}
