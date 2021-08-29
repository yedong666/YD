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
    <script src="<%=request.getContextPath() %>static/js/checkData.js"></script>
    <script>
        if (${not empty account}){
            alert("恭喜你注册成功! 你的账号为'${account}'")
        }
    </script>
</head>
<body>
<div class="mainWindow">
    <div class="head">
        <h1>赶快注册一个属于你自己的账号吧</h1>
    </div>
    <div class="register">
        <form class="form" action="register.do" onsubmit="return check(this)">
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
            <input style="border-radius: 10px; font-family: 'Arial Black'" type="submit" value="注册">
        </form>
        <script>
            alert(${account})
        </script>
    </div>
</div>
</body>
</html>
