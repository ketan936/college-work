<!DOCTYPE html>
<html>
<%
dim year
year=Request.Form("year")
%>
<body>
<form action="form.asp" method="post">
<p>Please select your year:</p>

<input type="radio" name="year"
<%if year="1" then Response.Write("checked")%>
value="1">Year 1</input>
<br>
<input type="radio" name="year"
<%if year="2" then Response.Write("checked")%>
value="2">Year 2</input>
<br>
<input type="radio" name="year"
<%if year="3" then Response.Write("checked")%>
value="3">Year 3</input>
<br><br>
<input type="submit" value="Submit" />
</form>
<%
if year<>"" then
   Response.Write("<p>please download year: " & year & " pdf</p>")
end if
%>
</body>
</html>