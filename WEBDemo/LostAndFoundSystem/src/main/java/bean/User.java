package bean;

public class User {
    private int id;
    private String username;
    private String password;
    private String account;
    private String userdata;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getAccount() {
        return account;
    }

    public void setAccount(String account) {
        this.account = account;
    }

    public String getUserdata() {
        return userdata;
    }

    public void setUserdata(String userdata) {
        this.userdata = userdata;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", account='" + account + '\'' +
                ", userdata='" + userdata + '\'' +
                '}';
    }
}
