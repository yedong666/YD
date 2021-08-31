<%--
  Created by IntelliJ IDEA.
  User: yang
  Date: 2021/8/20
  Time: 14:51
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page isELIgnored="false"%>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="<%=request.getContextPath() %>/static/css/logWindowStyle.css">
    <meta charset="UTF-8">
    <title>失物招领网</title>
</head>
<script>
    if ('${sessionScope.registerMessage}' !== ""){
        alert('${sessionScope.registerMessage}')
    }
</script>
<body>
<div class="mainWindow">
    <div class="head">
        <h1>欢迎访问失物招领网站</h1>
    </div>
    <div class="loginWindow">
        <div class="loginForm">
            <form action="${pageContext.request.contextPath}/allLoginReq/doLogin.do">
                <br><br><br>
                账号: <input style="border-radius: 10px; font-family: 'Arial Black'" type="text" name="account"> <br><br>
                密码: <input style="border-radius: 10px; font-family: 'Arial Black'" type="password" name="password"> <br><br>
                <input style="border-radius: 25px; font-family: 'Arial Black'; color: burlywood" type="submit" value="登录"><br><br>
            </form>
            <button style="border-radius: 25px; color: burlywood; font-family: 'Arial Black'">游客登录</button> <br><br>
        </div>
        <div class="tip">
            如果您还没有注册可以选择游客登录,也可以
            <a href="${pageContext.request.contextPath}/allLoginReq/jumpToRegister">
                点我进行注册
            </a>
        </div>
    </div>
</div>
</body>
</html>
