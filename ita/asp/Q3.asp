<%@ language="vbscript"%>
<html>
<body>
<%
l=request.form("l")
q=request.form("q")
a=80
b=100
c=50
d=40
e=10
%>
<form method="post" action="Q3.asp">
<table>
<select name="l" id="s" size="5">
<option <%if l="1" then response.write("checked")%> value="1">BOAT A</option>
<option <%if l="2" then response.write("checked")%> value="2">BOAT B</option>
<option <%if l="3" then response.write("checked")%> value="3">BOAT C</option>
<option <%if l="4" then response.write("checked")%> value="4">BOAT D</option>
<option <%if l="5" then response.write("checked")%> value="5">BOAT E</option>
</select><br>

<input type="submit" value="Enter the Quantity">
<input type="text" name="q"><br>
<input type="submit" value="submit">
</table>
</form>
<% if l="" then %>
<img src="" height="300" width="300"><br>
<input type="text" value="COST (10k) (10k) : ">

<% elseIf q="" and l="1" then %>
<img src="m.jpg" height="300" width="300">
<h4>COST (10k) : $<%response.write(a)%></h4>

<% elseIf q<>"" and l="1" then %>
<img src="m.jpg" height="300" width="300">
<h4>COST (10k)  : $<%response.write(q*a)%></h4>

<% elseIf q="" and l="2" then %>
<img src="c.jpg" height="300" width="300">
<h4>COST (10k)  : $<%response.write(b)%></h4>

<% elseIf q<>"" and l="2" then %>
<img src="c.jpg" height="300" width="300">
<h4>COST (10k) : $<%response.write(q*b)%></h4>

<% elseIf q="" and l="3" then %>
<img src="w.jpg" height="300" width="300">
<h4>COST (10k)  : $<%response.write(c)%></h4>

<% elseIf q<>"" and l="3" then %>
<img src="w.jpg" height="300" width="300">
<h4>COST (10k)  : $<%response.write(q*c)%></h4>

<% elseIf q="" and l="4" then %>
<img src="s.jpg" height="300" width="300">
<h4>COST (10k)  : $<%response.write(d)%></h4>

<% elseIf q<>"" and l="4" then %>
<img src="s.jpg" height="300" width="300">
<h4>COST (10k)  : $<%response.write(q*d)%></h4>

<% elseIf q="" and l="5" then %>
<img src="g.jpg" height="300" width="300">
<h4>COST (10k)  : $<%response.write(e)%></h4>

<% elseIf q<>"" and l="5" then %>
<img src="g.jpg" height="300" width="300">
<h4>COST (10k)  : $<%response.write(q*e)%></h4>

<% end if %>
</body>
</html>