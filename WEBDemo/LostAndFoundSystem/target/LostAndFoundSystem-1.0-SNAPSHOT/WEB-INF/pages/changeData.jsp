<%--
  Created by IntelliJ IDEA.
  <%--
  Created by IntelliJ IDEA.
  User: yang
  Date: 2021/8/23
  Time: 11:32
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page isELIgnored="false"%>
<html>
<head>
    <title>注册界面</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="<%=request.getContextPath() %>/static/css/registerStyle.css">
    <script src="<%=request.getContextPath() %>/static/js/checkData.js"></script>
</head>
<body>
<div class="mainWindow">
    <div class="head">
        <h1>编辑结束后点击保存按钮即可修改个人信息</h1>
    </div>
    <div class="register">
        <form class="form" action="${pageContext.request.contextPath}/allLoginReq/doUpdateUser.do" onsubmit="return check(this)">
            <br><br>
            昵&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp称:
            <input style="border-radius: 10px; font-family: 'Arial Black'"
                   id="name" type="text" name="username" > <br><br>
            性&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp别: &nbsp&nbsp&nbsp&nbsp
            <input style="border-radius: 10px; font-family: 'Arial Black'"
                   type="checkbox" name="sex" value="男">男
            &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
            <input style="border-radius: 10px; font-family: 'Arial Black'"
                   type="checkbox" name="sex" value="女">女&nbsp&nbsp&nbsp<br><br>
            年&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp龄:
            <input style="border-radius: 10px; font-family: 'Arial Black'"
                   id="age" type="text" name="age"> <br><br>
            生&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp日:
            <input style="border-radius: 10px; font-family: 'Arial Black'"
                   type="text" name="birthday"><br><br>
            密&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp码:
            <input style="border-radius: 10px; font-family: 'Arial Black'"
                   id="p1" type="password" name="password"><br><br>
            确认密码:
            <input style="border-radius: 10px; font-family: 'Arial Black'"
                   id="p2" type="password" name="confirmPassword"><br><br>
            &nbsp&nbsp&nbsp&nbsp&nbsp
            <input style="border-radius: 10px; font-family: 'Arial Black'" type="submit" value="保存">
        </form>
        <script>
            if ('${sessionScope.updateMessage}' !== ""){
                alert('${sessionScope.updateMessage}');
                window.location = "jumpToPerson";
            }
        </script>
    </div>
</div>
</body>
</html>
