<!DOCTYPE>
<html>
<head>
    <title>ListBox Example</title>
<script language="VB" runat="server">

    Sub SubmitBtn_Click(sender As Object, e As EventArgs)
        If ListBox1.SelectedIndex > - 1 Then
            Label1.Text = "You chose: " & ListBox1.SelectedItem.Text +" and the cost of it is " &ListBox1.SelectedItem.Value
        End If
    End Sub
	
  </script>
  <script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
  <script type="text/javascript">
        $(document).ready(function () 
		{
            $("#ListBox1").change(function () {
                var dpt = document.getElementById("ListBox1");     
                if (dpt.selectedIndex == 0)
                { 
					document.getElementById("image1").style.visibility="visible";
					document.getElementById("image2").style.visibility="hidden";
					document.getElementById("image3").style.visibility="hidden";
                }
				if (dpt.selectedIndex == 1)
                { 
					document.getElementById("image1").style.visibility="hidden";
					document.getElementById("image2").style.visibility="visible";
					document.getElementById("image3").style.visibility="hidden";
                }
				if (dpt.selectedIndex == 2)
                { 
					document.getElementById("image1").style.visibility="hidden";
					document.getElementById("image2").style.visibility="hidden";
					document.getElementById("image3").style.visibility="visible";
                }
            })
        })
    </script>
</head>
<body>

   <h3>ListBox Example</h3>

   <form id="form1" runat="server">

      <asp:ListBox id="ListBox1" Rows="3" Width="100px" SelectionMode="Single" runat="server">
         <asp:ListItem Value="Rs.50.0"  runat="server" >Item 1</asp:ListItem>
         <asp:ListItem Value="Rs.100.0"  runat="server" >Item 2</asp:ListItem>
         <asp:ListItem Value="Rs.80.0"  runat="server" >Item 3</asp:ListItem>
      </asp:ListBox>
	 
	  <br><br>
      <asp:button id="Button1" Text="Submit" OnClick="SubmitBtn_Click" runat="server" />
       <br><br>
      <asp:Label id="Label1" Font-Names="Verdana" Font-Size="10pt" runat="server" Style="position:absolute;left:10px;top:200px;"/>
	  
      <asp:Image id="image1"  runat="server" AlternateText="img1" ImageUrl="p1.jpg" Style ="visibility:hidden;position:absolute;left:150px;top:20px;"/>
	  <asp:Image id="image2" runat="server" AlternateText="img2" ImageUrl="p2.jpg" Style ="visibility:hidden;position:absolute;left:150px;top:20px;"/>
	  <asp:Image id="image3" runat="server" AlternateText="img3" ImageUrl="p3.jpg" Style ="visibility:hidden;position:absolute;left:150px;top:20px;"/>
   </form>

</body>
</html>