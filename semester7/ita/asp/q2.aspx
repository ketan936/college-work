<!DOCTYPE html>
<html>
<head>
</head>
<body>
<%
Dim href1,href2,href3
Dim title1,title2,title3

href1 = "1.pdf" 'The url of the site
title1 = "1st Year" ' The title you want to use

href2 = "2.pdf" 'The url of the site
title2 = "2nd Year" ' The title you want to use

href3 = "3.pdf" 'The url of the site
title3 = "3rd Year" ' The title you want to use

Response.Write("<a href='"& href1 &"' target='_blank'>" & title1 & "</a><br>")
Response.Write("<a href='"& href2 &"' target='_blank'>" & title2 & "</a><br>")
Response.Write("<a href='"& href3 &"' target='_blank'>" & title3 & "</a>")
%>

</body>
</html>