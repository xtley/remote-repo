<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2023-12-30
  Time: 19:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>注册</title></head>
<body>
<form action="${pageContext.request.contextPath}/registerUser"
      method="post">
    用户名：<input type="text" name="username"/><br/>
    密&nbsp;&nbsp;&nbsp;码：<input type="password" name="password"/><br/>
    <input type="submit" value="注册"/>
</form>
</body>
</html>
