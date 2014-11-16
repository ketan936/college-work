<script  runat="server">
Sub submit(Sender As Object,e As EventArgs)
mess.Text="You selected " & drop1.SelectedItem.Text
End Sub
</script>

<!DOCTYPE html>
<html>
<body>

<form runat="server">
<asp:ListBox id="drop1" rows="3" runat="server">
<asp:ListItem selected="true">Item 1</asp:ListItem>
<asp:ListItem>Item 2</asp:ListItem>
<asp:ListItem>Item 3</asp:ListItem>
<asp:ListItem>Item 4</asp:ListItem>
<asp:ListItem>Item 5</asp:ListItem>
<asp:ListItem>Item 6</asp:ListItem>
</asp:ListBox>
<asp:Button Text="Submit" OnClick="submit" runat="server" />
<p><asp:label id="mess" runat="server" /></p>
</form>

</body>
</html>