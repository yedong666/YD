package dao;

public class Page {
    private int id;
    private String author;
    private String title;
    private String mainData;
    private int status;
    private String getDtae;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getMainData() {
        return mainData;
    }

    public void setMainData(String mainData) {
        this.mainData = mainData;
    }

    public int getStatus() {
        return status;
    }

    public void setStatus(int status) {
        this.status = status;
    }

    public String getGetDtae() {
        return getDtae;
    }

    public void setGetDtae(String getDtae) {
        this.getDtae = getDtae;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
}
