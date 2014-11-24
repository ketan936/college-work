<%@ language="vbscript"%>
<html>
<body>
<%
dim v1
v1=request.cookies("v2")
if v1="" then
response.cookies("v2")=1
response.write("HELLO WORLD")
else
response.cookies("v2")=v1+1
response.write(v1)
end if
%>
</body></html>