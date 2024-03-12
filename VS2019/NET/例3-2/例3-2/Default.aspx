<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="例3_2.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style> .style4 {
               width:70px;
            }
    </style>

</head>
<body>
    <form id="form1" runat="server">
        <div>
        </div>

        <table>
            <tr><td class="style1"><strong>友情链接:<br/><br/></strong></td>
            </tr>
            <tr ><td class="style4"><asp:HyperLink ID="HyperLink1" runat="server" 
                    NavigateUrl="https://www.sina.com.cn/">新浪网
                 </asp:HyperLink></td>
                 <td class="style4"> <asp:HyperLink ID="HyperLink2" runat="server"
                    NavigateUrl="https://sg.yahoo.com/?p=us">雅虎网
                 </asp:HyperLink>
                 </td>
                 <td class="style4"> <asp:HyperLink ID="HyperLink3" runat="server"
                    NavigateUrl="https://www.qq.com/">腾讯网
                 </asp:HyperLink>
                 </td>
                 <td class="style4"> <asp:HyperLink ID="HyperLink4" runat="server"
                    NavigateUrl="https://www.taobao.com/">淘宝网
                 </asp:HyperLink>
                 </td>
                 <td class="style4"> <asp:HyperLink ID="HyperLink5" runat="server"
                    NavigateUrl="https://www.sohu.com/">搜狐网
                 </asp:HyperLink>
                 </td>
                 <td class="style4"> <asp:HyperLink ID="HyperLink6" runat="server"
                    NavigateUrl="https://www.ifeng.com/">凤凰网
                </asp:HyperLink>
                 </td>
            </tr>
        </table>
       
    </form>
</body>
</html>
