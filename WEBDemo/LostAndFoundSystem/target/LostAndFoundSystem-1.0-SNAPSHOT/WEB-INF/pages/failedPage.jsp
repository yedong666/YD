<%--
  Created by IntelliJ IDEA.
  User: yang
  Date: 2021/8/22
  Time: 20:08
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="<%=request.getContextPath() %>/static/css/failedStyle.css">
    <title>登录失败</title>
</head>
<body>
    <div class="mainWindow">
        <div class="head">
            <h1>登录失败！</h1>
        </div>
        <div class="failed">
            <br><br>
            你的账号或密码错误，请
            <a href="returnLogin">重新登录</a> <br><br><br>
            忘记密码？<a href="">点击找回密码</a>
        </div>

    </div>
</body>
</html>
