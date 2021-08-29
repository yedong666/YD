<%--
  Created by IntelliJ IDEA.
  User: yang
  Date: 2021/8/27
  Time: 13:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page isELIgnored="false"%>
<html>
<head>
    <title>${sessionScope.user}的主页</title>
    <style>
        body{
            border: 0;
            padding: 0;
            margin: 0;
        }
        .mainWindow{
            position: absolute;
            width: 100%;
            height: 100%;
            top: 0;
            left: 0;
            border: 0;
            padding: 0;
            margin: 0;
            background: url("<%=request.getContextPath() %>/static/images/bg3.jpg");
            background-size: cover;
        }
        .personData{
            position: absolute;
            width: 60%;
            height: 60%;
            top: 20%;
            left: 20%;
            border: brown solid 1px;
            font-size: medium;
            font-family: "Bookman Old Style", serif;
            background-color: rgba(160, 150, 217, 1);
            text-align: center;
        }
    </style>
</head>
<body>
    <div class="mainWindow">
        <div class="personData">
            <h1 style="text-align: center">个人信息</h1><br>
            <p>账号: ${sessionScope.user.account} </p> <br>
            <p>昵称: ${sessionScope.user.username} </p> <br>
            相关介绍: ${sessionScope.user.userdata} <br> <br><br>
            <a href="jumpToChangeData" style="text-decoration: none">修改个人信息</a>
        </div>
    </div>
</body>
</html>
