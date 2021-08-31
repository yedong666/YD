package service;

import bean.Page;
import dao.PageDao;

import javax.servlet.http.HttpSession;
import java.nio.charset.StandardCharsets;
import java.util.Date;
import java.util.List;

public class PageService {
    private static PageDao pageDao;

    static {
        pageDao = new PageDao();
    }

    public static void showAllPages(HttpSession session){
        List<Page> pages = pageDao.select();
        session.setAttribute("pages", pages);
    }

    public static void placePage(String author, String title, String mainData, int status, HttpSession session){
        String newData = new String(mainData.getBytes(StandardCharsets.ISO_8859_1), StandardCharsets.UTF_8);
        String newTitle = new String(title.getBytes(StandardCharsets.ISO_8859_1), StandardCharsets.UTF_8);
        if (pageDao.insert(author, newTitle, newData, status, new Date().toString())){
            session.setAttribute("placePageMessage", "文章已发布");
        }else{
            session.setAttribute("placePageMessage", "文章发布失败, 请稍后再试");
        }
    }
}
