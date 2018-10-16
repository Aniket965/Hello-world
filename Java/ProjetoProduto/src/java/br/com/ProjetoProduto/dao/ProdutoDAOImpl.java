/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.ProjetoProduto.dao;

import br.com.ProjetoProduto.model.Categoria;
import br.com.ProjetoProduto.model.Produto;
import br.com.ProjetoProduto.util.ConnectionFactory;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author VINICIUSEDUARDODASIL
 */
public class ProdutoDAOImpl implements GenericDAO {

    private Connection conexao;

    public ProdutoDAOImpl() throws Exception {
        try {
            this.conexao = ConnectionFactory.getConnection();
            System.out.println("Conectado com sucesso!");
        } catch (Exception ex) {
            throw new Exception(ex.getMessage());
        }
    }

    @Override
    public Boolean cadastrar(Object objeto) {

//        Produto produto = (Produto) objeto;
        Produto produto = (Produto) objeto;
        PreparedStatement stmt = null;
        String sql = "Insert into produto(descprod,valor,"
                + "marca, idcategoria) values (?, ?, ?, ?)";

        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, produto.getDescProd());
            stmt.setDouble(2, produto.getValor());
            stmt.setString(3, produto.getMarca());
            stmt.setInt(4, produto.getCategoria().getIdCategoria());
            stmt.execute();

            return true;
        } catch (SQLException ex) {
            System.out.println("Problemas ao cadastrar categoria! Erro" + ex.getMessage());
            return false;
        } finally {
            try {
                ConnectionFactory.closeConnection(conexao, stmt);
            } catch (Exception ex) {
                System.out.println("Problemas ao fechar os parâmetros de conexao! " + ex.getMessage());
            }
        }
    }

    @Override
    public Boolean inserir(Object objeto) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Boolean alterar(Object objeto) {
        Produto produto = (Produto) objeto;

        PreparedStatement stmt = null;
        String sql = "UPDATE produto SET descprod = (?), valor =  (?), marca =  (?), idcategoria = (?) WHERE idprod =  (?);";
        System.out.println("SQL >> " + sql);
        System.out.println("PRODUTO >> " + produto.getIdProd() + " DESC >> " + produto.getDescProd() + " Valor >> " + produto.getValor().toString() + " MARCA >> " + produto.getMarca()
                + "idCategoria :>> " + produto.getCategoria().getIdCategoria()
        );
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, produto.getDescProd());
            stmt.setDouble(2, produto.getValor());
            stmt.setString(3, produto.getMarca());
            stmt.setInt(4, produto.getCategoria().getIdCategoria());
            stmt.setInt(5, produto.getIdProd());

            stmt.execute();

            return true;
        } catch (SQLException ex) {
            System.out.println("Problemas ao alterar produto! Erro" + ex.getMessage());
            return false;
        } finally {
            try {
                ConnectionFactory.closeConnection(conexao, stmt);
            } catch (Exception ex) {
                System.out.println("Problemas ao fechar os parâmetros de conexao! " + ex.getMessage());
            }
        }
    }

    @Override
    public Boolean excluir(int id) {
        PreparedStatement stmt = null;

        String sql = "DELETE FROM produto WHERE idprod = (?)";

        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            stmt.execute();

            return true;
        } catch (SQLException ex) {
            System.out.println("Problemas ao deletar Projeto! Erro" + ex.getMessage());
            return false;
        } finally {
            try {
                ConnectionFactory.closeConnection(conexao, stmt);
            } catch (Exception ex) {
                System.out.println("Problemas ao fechar os parâmetros de conexao! " + ex.getMessage());
            }
        }
    }

    @Override
    public Object carregar(int numero) {
        Produto produto = new Produto();
        PreparedStatement stmt = null;
        ResultSet rs = null;

        String sql = "SELECT * FROM produto JOIN categoria USING (idcategoria) WHERE idprod = (?);";
//        System.out.println(sql);;
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, numero);
            rs = stmt.executeQuery();
            if (rs.next()) {
                produto.setIdProd(rs.getInt("idprod"));
                produto.setDescProd(rs.getString("descprod"));
                produto.setValor(rs.getDouble("valor"));
                produto.setMarca(rs.getString("marca"));
                produto.setCategoria(new Categoria());
                produto.getCategoria().setIdCategoria(rs.getInt("idcategoria"));
                produto.getCategoria().setDescCategoria(rs.getString("desccategoria"));
            }

        } catch (Exception erro) {
            System.out.println("Erro ao carregar produto " + erro.getMessage());
        } finally {
            try {
                ConnectionFactory.closeConnection(conexao, stmt);
            } catch (Exception ex) {
                System.out.println("Problemas ao fechar os parâmetros de conexao! " + ex.getMessage());
            }
        }
        return produto;
    }

    @Override
    public List<Object> Listar() {
        List<Object> produtos = new ArrayList<Object>();
        PreparedStatement stmt = null;
        ResultSet rs = null;

        String sql = "SELECT * FROM produto JOIN categoria USING (idcategoria) ORDER BY idprod;";

        try {
            stmt = conexao.prepareStatement(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                System.out.println(rs.toString());
                Produto produto = new Produto();
                produto.setIdProd(rs.getInt("idprod"));

                produto.setDescProd(rs.getString("descprod"));

                produto.setValor(rs.getDouble("valor"));

                produto.setMarca(rs.getString("marca"));
                produto.setCategoria(new Categoria());
                produto.getCategoria().setIdCategoria(rs.getInt("idcategoria"));
                produto.getCategoria().setDescCategoria(rs.getString("desccategoria"));
                produtos.add(produto);

            }

//            System.out.println("Deu certo no BD... " + categorias.toString());
        } catch (Exception ex) {
            System.out.println(ex);
            System.out.println("Problemas ao Listar Produtos! Erro " + ex.getMessage());
        } finally {
            try {
                ConnectionFactory.closeConnection(conexao, stmt);
            } catch (Exception ex) {
                System.out.println("Problemas ao fechar os parâmetrs de conexão! "
                        + "Erro " + ex.getMessage());
            }
        }

        return produtos;

    }
}
