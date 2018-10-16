
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
        <title>Cadastro de Produtos</title>
    </head>
    <body>

        <h1 class="font-weight-light text-primary" align="center">Fatec Jales</h1>
        <hr>
        <div class="container">

            <strong>${mensagem}</strong> 

            <!--</div>-->
            <form name="cadastrarproduto" id="cadastrarproduto" action="CadastrarProduto"  method="POST">
                <div class="form-row">
                    <div class="form-group col-md-6">
                        <label for="descProduto">Descrição</label>
                        <textarea class="form-control" id="descProduto" name="descProduto" ></textarea>
                    </div>
                    <div class="form-group col-md-6">
                        <label for="valor">Valor</label>
                        <input type="number" class="form-control" id="valor" name="valor">
                    </div>


                    <div class="col-md-6 form-group">
                        <label for="marca">Marca</label>
                        <input  type="text" name="marca" id="marca" class="form-control"/>
                    </div>

                    <div class="form-group col-md-6">
                        <label for="categoria">Categoria</label>
                        <select name="categoria" class="form-control" >
                            <c:forEach var="categoria" items="${categorias}">
                                <option value="${categoria.idCategoria}">${categoria.descCategoria}</option>
                            </c:forEach>
                        </select>
                    </div>



                </div>
                
                <button type="submit" name="cadastrar" id="cadastrar" value="Cadastrar" class="btn btn-primary">Cadastrar</button>
                <a href="./index.jsp" id="voltar" value="Voltar" class="btn btn-primary">Voltar</a>
            </form>
        </div>       
    </body>
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
</html>
