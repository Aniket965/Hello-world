/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.ProjetoProduto.model;

/**
 *
 * @author VINICIUSEDUARDODASIL
 */
public class Categoria {
    private int idCategoria;
    private String descCategoria;

    public Categoria() {
    }

    public Categoria(int idCategoria, String descCategoria) {
        this.idCategoria = idCategoria;
        this.descCategoria = descCategoria;
    }
    
    public int getIdCategoria() {
        return idCategoria;
    }

    public void setIdCategoria(int idCategoria) {
        this.idCategoria = idCategoria;
    }

    public String getDescCategoria() {
        return descCategoria;
    }

    public void setDescCategoria(String descCategoria) {
        this.descCategoria = descCategoria;
    }
    
    
}
