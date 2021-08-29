<%--
  Created by IntelliJ IDEA.
  User: yang
  Date: 2021/8/21
  Time: 21:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!--使用EL表达式-->
<%@page isELIgnored="false"%>
<html>
<head>
    <title>登录成功</title>
</head>
<body>
    ${user.username}欢迎你!
    <br> ${user.userdata}
</body>
</html>
