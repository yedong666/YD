<%--
  Created by IntelliJ IDEA.
  User: yang
  Date: 2021/8/23
  Time: 19:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page isELIgnored="false"%>
<html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>主页面</title>
    <link rel="stylesheet" type="text/css" href="<%=request.getContextPath() %>/static/css/mainPage.css">
    <script>
        const imgs = ["<%=request.getContextPath() %>/static/images/bg1.jpg",
                                "<%=request.getContextPath() %>/static/images/bg2.jpg",
                                "<%=request.getContextPath() %>/static/images/bgMainWindow.jpg"];
    </script>
    <script src="<%=request.getContextPath() %>/static/js/playImages.js"></script>
</head>
<body>
<div class="mainWindow" id="mainDiv">
    <div class="menu" id="menuDiv">
        <h2 class="head">失物招领网</h2>
        <button class="status" id="loginModel">登录模式</button>
        <div class="search">
            <input type="search" value="  搜索" name="search" class="searchBar">
            <input type="submit" value="Search" class="searchButton">
        </div>
        <a class="loginHref" href="returnLogin" id="dataOrLogin">登录/注册</a>
    </div>
    <div class="inventory">
        <a>随身物品</a> <br><br>
        <a>现金钞票</a> <br><br>
        <a>证件卡片</a> <br><br>
        <a>书籍资料</a> <br><br>
        <a>贵重物品</a> <br><br>
        <a>其他物品</a> <br><br>
    </div>
    <div class="mainPanel" id="panelDIv">
        <div class="mainData" id="mainDataDiv">
            <div class="images" id="imageDiv">
                <img src="<%=request.getContextPath() %>/static/images/bg1.jpg" width="100%" height="90%" id="image">
                <p id="imgMessage" style="text-align: center;">这是图片一</p>
            </div>
            <div class="foundPage" id="foundPageDiv">
                <h1>寻找失主</h1>
                <br><br>
                <c:forEach var="page" items="${sessionScope.pages}">
                       <div class="page">
                           <a href="pageShow" >
                               <b>${page.title} <br>
                                   <p style="text-align: left"> ${page.author}:${page.mainData}</p>
                           </a>
                       </div>
                    <br> <br>
                </c:forEach>
            </div>
            <div class="lostPages" id="lostPageDiv">
                <h1>丢失物品</h1>
                <br><br>
                <c:forEach var="page" items="${sessionScope.pages}">
                        <div class="page">
                            <a href="pageShow" >
                            <b>${page.title} <br>
                                <p style="text-align: left"> ${page.author}:${page.mainData}</p>
                            </a>
                        </div>
                    <br> <br>
                </c:forEach>
            </div>
        </div>
        <div class="searchData" id="searchDiv">
            <div class="d1" id="d1">

            </div>
            <div class="d1" id="d2">

            </div>
            <div class="d1" id="d3">

            </div>
        </div>
    </div>
</div>
<script>
    if ('${sessionScope.user.userdata}' !== ""){
        alert("欢迎你" + '${sessionScope.user.username}');
        let loginModel = document.getElementById("loginModel");
        let dataOrLogin = document.getElementById("dataOrLogin");
        loginModel.innerHTML = "账号登录";
        dataOrLogin.innerHTML = '${sessionScope.user.username}';
        dataOrLogin.href = "jumpToPerson";
    }
</script>
</body>
</html>
