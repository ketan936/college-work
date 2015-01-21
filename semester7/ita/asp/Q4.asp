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
<form method="post" action="Q4.asp">
USERNAME:<input type="text" name="uname"><br>
PASSWORD:<input type="password" name="pwd"><br>
<input type="submit" value="submit">
</form>
<% if uname=request.cookies("users")("u1") and pwd=request.cookies("users")("p1")  then %>
<a href="http://www.google.com" target="_blank">HOME PAGE</a><br><br>
<% elseIf uname=request.cookies("users")("u2") and pwd=request.cookies("users")("p2")  then %>
<a href="http://www.google.com" target="_blank">HOME PAGE</a><br><br>
<% else %>
<a href="Q9.htm" target="_blank">LOGIN PAGE</a><br><br>
<% end if %>
<%
dim fs,f
set fs=Server.CreateObject("Scripting.FileSystemObject")
set f=fs.GetFile("c:\inetpub\wwwroot\Q\Q4.asp")
Response.Write("Site last accessed on: ")
Response.Write(f.DateLastAccessed)
set f=nothing
set fs=nothing
%>
</body>
</html>