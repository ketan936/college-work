<%@ language="vbscript"%>
<html>
<body>
<%
uname=request.form("uname")
pwd=request.form("pwd")
response.cookies("users")("u1")="A"
response.cookies("users")("p1")="1"
response.cookies("users")("u2")="B"
response.cookies("users")("p2")="2"
%>
<form method="post" action="Q5.asp">
USERNAME:<input type="text" name="uname"><br>
PASSWORD:<input type="password" name="pwd"><br>
<input type="submit" value="submit">
</form>
<% if uname=request.cookies("users")("u1") and pwd=request.cookies("users")("p1")  then
Response.Write("Valid User <br>")
Response.Write("Your Session ID is: "& Session.SessionID)
session("username")=uname
session("password")=pwd %>
<br><a href="http://www.google.com" target="_blank">LINK TO THE HOME PAGE</a>
<% elseIf uname=request.cookies("users")("u2") and pwd=request.cookies("users")("p2")  then
Response.Write("Valid User <br>")
Response.Write("Your Session ID is: "& Session.SessionID)
session("username")=uname
session("password")=pwd %>
<br><a href="http://www.google.com" target="_blank">LINK TO THE HOME PAGE</a>
<%
else
response.write("NOT A VALID USER")
%>
<% end if %>
</body>
</html>