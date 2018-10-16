/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.ProjetoProduto.dao;

import br.com.ProjetoProduto.model.Categoria;
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
public class CategoriaDAOImpl implements GenericDAO {

    private Connection conexao;

    public CategoriaDAOImpl() throws Exception {
        try {
            this.conexao = ConnectionFactory.getConnection();
            System.out.println("Conectado com sucesso!");
        } catch (Exception ex) {
            throw new Exception(ex.getMessage());
        }
    }

    @Override
    public Boolean cadastrar(Object objeto) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Boolean inserir(Object objeto) {
        Categoria categoria = (Categoria) objeto;
        PreparedStatement stmt = null;
        String sql = "Insert into categoria(desccategoria) values (?)";

        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, categoria.getDescCategoria());
            stmt.execute();

            return true;
        } catch (SQLException ex) {
            System.out.println("Problemas ao cadastrar Cadastro! Erro" + ex.getMessage());
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
    public Boolean alterar(Object objeto) {
        Categoria categoria = (Categoria) objeto;
        PreparedStatement stmt = null;
        String sql = "UPDATE categoria SET desccategoria = (?) WHERE idcategoria = (?)";

        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setString(1, categoria.getDescCategoria());
            stmt.setInt(2, categoria.getIdCategoria());
            stmt.execute();

            return true;
        } catch (SQLException ex) {
            System.out.println("Problemas ao cadastrar Cadastro! Erro" + ex.getMessage());
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

        String sql = "DELETE FROM categoria WHERE idcategoria = (?)";

        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, id);
            stmt.execute();

            return true;
        } catch (SQLException ex) {
            System.out.println("Problemas ao deletar Categoria! Erro" + ex.getMessage());
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
        Categoria categoria = new Categoria();
        PreparedStatement stmt = null;
        ResultSet rs = null;

        String sql = "SELECT * FROM categoria WHERE idcategoria = (?) ;";
        System.out.println(sql);
        try {
            stmt = conexao.prepareStatement(sql);
            stmt.setInt(1, numero);
            rs = stmt.executeQuery();
            if (rs.next()) {
                categoria.setIdCategoria(rs.getInt("idcategoria"));
                categoria.setDescCategoria(rs.getString("desccategoria"));
            }

        } catch (Exception erro) {
            System.out.println("Erro ao carregar categoria " + erro.getMessage());
        } finally {
            try {
                ConnectionFactory.closeConnection(conexao, stmt);
            } catch (Exception ex) {
                System.out.println("Problemas ao fechar os parâmetros de conexao! " + ex.getMessage());
            }
        }
        return categoria;
    }

    public List<Object> Listar() {
        List<Object> categorias = new ArrayList<Object>();
        PreparedStatement stmt = null;
        ResultSet rs = null;

        String sql = "SELECT * FROM  categoria order by idcategoria;";

        try {
            stmt = conexao.prepareStatement(sql);
            rs = stmt.executeQuery();
            while (rs.next()) {
                Categoria categoria = new Categoria();
                categoria.setIdCategoria(rs.getInt("idcategoria"));
                categoria.setDescCategoria(rs.getString("desccategoria"));
                categorias.add(categoria);

            }

            System.out.println("Deu certo no BD... " + categorias.toString());
        } catch (SQLException ex) {
            System.out.println("Problemas ao Listar Categorias! Erro " + ex.getMessage());
        } finally {
            try {
                ConnectionFactory.closeConnection(conexao, stmt);
            } catch (Exception ex) {
                System.out.println("Problemas ao fechar os parâmetrs de conexão! "
                        + "Erro " + ex.getMessage());
            }
        }

        return categorias;

    }

}
