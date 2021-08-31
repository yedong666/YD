<%--
  Created by IntelliJ IDEA.
  User: yang
  Date: 2021/8/30
  Time: 18:23
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page isELIgnored="false"%>
<html>
<head>
    <meta charset="UTF-8">
    <title>文字处理</title>
</head>
<script>
    if ('${sessionScope.returnMessage}' !== ""){
        alert("返回信息:" + '${sessionScope.returnMessage}');
    }
</script>
<body>
<div class="head">
    <h2>你可以在此编写你的寻物启示或寻找失主内容，提交后本站主页</h2>
</div>
<div id="writeCharater" class="write">
    <div id="menu" class="setmenu">
        <table style="width: 100%; height:100%">
            <tr>
                <td>
                    <select style="margin: 0px;">
                        <option>微软雅黑</option>
                        <option>宋体</option>
                        <option>黑体</option>
                    </select>
                </td>
                <td>
                    <label>段落</label>
                </td>
                <td>
                    插入
                </td>
                <td>
                    样式
                </td>
            </tr>
        </table>
    </div>
    <form action="${pageContext.request.contextPath}/allLoginReq/doUpdateUser.do" method="post">
        <div class="title">
            <input id="inputTitle"type="text" value="请在此输入标题" name="title">
        </div>
        <div class="inputText">
            <textarea id="textArea"class="textArea" rows="50" cols="85" name="page">请在此输入内容</textarea>
        </div>
        <div id="submit">
            <input type="submit" value="提交">
        </div>
    </form>
</div>
<div id="showBoard" class="show">
    <h1 id="showTitle" style="text-align: center;">标题</h1>
    <p id="str"></p>
</div>
</body>
<style>

    *{
        box-sizing: border-box;
    }

    div{
        position: absolute;
    }

    .head{
        width: 100%;
        height: 5%;
        background-color:wheat;
        top:0px;
        left: 0px;
        margin: 0px;
    }

    .head h2{
        text-align: center;
        height: 100%;
        margin: 0px;
    }

    .write{
        width: 48%;
        height: 95%;
        left:1%;
        top:5%;
        margin-top: 5px;
        background-color: aquamarine;
        overflow: hidden;
    }

    .setmenu{
        width: 100%;
        height: 10%;
        top:0px;
        background-color: red;
    }

    .title{
        width: 100%;
        height: 5%;
        top:10%;
        background-color: aliceblue;
    }

    .title input{
        position:absolute;
        width: 50%;
        height: 80%;
        left: 25%;
        top:10%;
        box-sizing: border-box;
    }

    .inputText{
        width: 100%;
        height: 80%;
        top:15%;
        background-color: aliceblue;
        overflow: scroll;
    }

    textarea{
        font-size: medium;
        font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
        resize: none;
    }

    #submit{
        width: 100%;
        height: 5%;
        bottom: 0px;
        background-color: bisque;
    }

    #submit input{
        width: 100%;
        height: 100%;
    }

    .show{
        width: 48%;
        height: 95%;
        right: 1%;
        top:5%;
        margin-top: 5px;
        background-color:white;
        overflow: scroll;
    }
</style>
<script>
    /*
        定时获取文本输入框内容并显示在d2上
    */
    setInterval(function(){
        let title = document.getElementById("inputTitle");
        let showTitle = document.getElementById("showTitle");
        let textArea = document.getElementById("textArea");
        let showStr = document.getElementById("str");
        let text = textArea.value;
        let head = title.value;
        text = text.replaceAll('\n', '<br>');
        text = text.replaceAll(' ', '&nbsp');
        showStr.innerHTML = text;
        showStr.style = textArea.style;
        showTitle.innerHTML = head;
    }, 100);

</script>
</html>
