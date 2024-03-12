<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" 
    Inherits="例3_1.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        </div>
        <table align="left" border="1" style="background-color:Gray">
            <tr><td class="style1">  <!-- 表格标题和文字 -->
                <strong> 商品图片 </strong> </td>
            </tr>
            <tr><td class="style4">
                <asp:ImageButton ID="ImageButton1" runat="server" 
                 ImageUrl="~/iPAD2.jpg" OnClick="ImageButton1_Click" Height="79px"/> </td>
            </tr>
        </table>



    </form>
</body>
</html>
