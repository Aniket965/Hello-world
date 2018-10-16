


<%@page import="br.com.ProjetoProduto.model.Produto"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%--<%@page import="br.com.aplicacoesmatutino.model.Usuario"%>--%>
<%@page import="br.com.ProjetoProduto.model.Categoria"%>
<%@page import="java.util.List"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Listagem de Produtos</title>
    </head>
    <body>
        <h1 align="center">Fatec Jales</h1>
        <hr>
        <table align="center" border="1">
            ${mensagem}
            <tr>
                <td colspan="8" align="center"> Listagem de Produtos</td>
            </tr>
            <tr>
                <th align="center">ID</th>
                <th align="center">Descrição</th>
                <th align="center">Valor</th>
                <th align="center">Marca</th>
                <th align="center">Categoria</th>


            </tr>
            <%
                List<Produto> produtos = (List<Produto>) request.getAttribute("produtos");
                for (Produto produto : produtos) {

            %>
            <tr>
                <td align="center"><%=produto.getIdProd()%></td>
                <td align="center"><%=produto.getDescProd()%></td>
                <td align="center"><%=produto.getValor()%></td>
                <td align="center"><%=produto.getMarca()%></td>
                <td align="center"><%=produto.getCategoria().getDescCategoria()%></td>
                <td align="center"><a href="ExcluirProduto?idProduto=<%=produto.getIdProd()%>">Excluir</a></td>
                <td align="center"><a href="CarregarProduto?idProduto=<%=produto.getIdProd()%>">Alterar</a></td>
            </tr>

            <% }%>

            <tr>
                <td align="center" colspan="8"><h5><a href="index.jsp">Voltar</a></h5></td>
            </tr>
        </table>
    </body>
</html>
