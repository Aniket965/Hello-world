/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.ProjetoProduto.controller;

import br.com.ProjetoProduto.dao.CategoriaDAOImpl;
import br.com.ProjetoProduto.dao.GenericDAO;
import br.com.ProjetoProduto.dao.ProdutoDAOImpl;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author VINICIUSEDUARDODASIL
 */
@WebServlet(name = "CarregarProduto", urlPatterns = {"/CarregarProduto"})
public class CarregarProduto extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            Boolean inteiro = false;
            Integer idProduto = null;
            try {
                idProduto = Integer.parseInt(request.getParameter("idProduto"));
                inteiro = true;
                System.out.println("Converteu o valor");
            } catch (Exception e) {
                inteiro = false;
                System.out.println("Não converteu o valor ");
            }

            if (inteiro) {

                GenericDAO categoriaDAO = new CategoriaDAOImpl();
                request.setAttribute("categorias", categoriaDAO.Listar());
                GenericDAO dao = new ProdutoDAOImpl();
                request.setAttribute("produto", dao.carregar(Integer.parseInt(request.getParameter("idProduto"))));
                request.getRequestDispatcher("alterarProduto.jsp").forward(request, response);
            } else {
                GenericDAO categoriaDAO = new CategoriaDAOImpl();
                request.setAttribute("categorias", categoriaDAO.Listar());
                request.getRequestDispatcher("cadastrarProduto.jsp").forward(request, response);

            }

        } catch (Exception e) {
            System.out.println("Problemas no Servlet ao listar Categoria! Erro: " + e.getMessage());
        }
    }

// <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
