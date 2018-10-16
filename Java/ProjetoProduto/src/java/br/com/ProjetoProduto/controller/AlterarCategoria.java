/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.ProjetoProduto.controller;

import br.com.ProjetoProduto.dao.CategoriaDAOImpl;
import br.com.ProjetoProduto.dao.GenericDAO;
import br.com.ProjetoProduto.model.Categoria;
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
@WebServlet(name = "AlterarCategoria", urlPatterns = {"/AlterarCategoria"})
public class AlterarCategoria extends HttpServlet {

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
            Integer idCategoria = Integer.parseInt(request.getParameter("idCategoria"));
            String descCategoria = request.getParameter("descCategoria");
            String mensagem = null;

            Categoria categoria = new Categoria();
            categoria.setIdCategoria(idCategoria);
            categoria.setDescCategoria(descCategoria);

            try {
                GenericDAO dao = new CategoriaDAOImpl();
                if (dao.alterar(categoria)) {
                    mensagem = "Foi realizado com sucesso!";
                } else {
                    mensagem = " Problemas ao cadastrar Tipo de Usuário";
                }
                request.setAttribute("mensagem", mensagem);
                request.getRequestDispatcher("ListarCategoria").forward(request, response);
            } catch (Exception ex) {
                System.out.println("Problemas no Servlet ao cadastrar Categoria! Erro " + ex.getMessage());
            }
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
