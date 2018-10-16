


<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%--<%@page import="br.com.aplicacoesmatutino.model.Usuario"%>--%>
<%@page import="br.com.ProjetoProduto.model.Categoria"%>
<%@page import="java.util.List"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Listagem de Categorias</title>
    </head>
    <body>
        <h1 align="center">Fatec Jales</h1>
        <hr>
        <table align="center" border="1">
            ${mensagem}
            <tr>
                <td colspan="6" align="center"> Listagem de Categorias</td>
            </tr>
            <tr>
                <th align="center">ID</th>
                <th align="center">Descrição</th>

            </tr>
            <%
                List<Categoria> categorias = (List<Categoria>) request.getAttribute("categorias");
                for (Categoria categoria : categorias) {

            %>
            <tr>
                <td align="center"><%=categoria.getIdCategoria()%></td>
                <td align="center"><%=categoria.getDescCategoria()%></td>
                <td align="center"><a href="ExcluirCategoria?idCategoria=<%=categoria.getIdCategoria()%>">Excluir</a></td>
                <td align="center"><a href="CarregarCategoria?idCategoria=<%=categoria.getIdCategoria()%>">Alterar</a></td>
            </tr>

            <% }%>

            <tr>
                <td align="center" colspan="6"><h5><a href="index.jsp">Voltar</a></h5></td>
            </tr>
        </table>
    </body>
</html>
