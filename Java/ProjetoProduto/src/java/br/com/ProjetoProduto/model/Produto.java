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
public class Produto {

    private int idProd;
    private String descProd;
    private Double valor;
    private String marca;
    private Categoria categoria;

    public Produto(int idProd, String descProd, Double valor, String marca, Categoria categoria) {
        this.idProd = idProd;
        this.descProd = descProd;
        this.valor = valor;
        this.marca = marca;
        this.categoria = categoria;
    }

    public Produto() {
    }

    public int getIdProd() {
        return idProd;
    }

    public void setIdProd(int idProd) {
        this.idProd = idProd;
    }

    public String getDescProd() {
        return descProd;
    }

    public void setDescProd(String descProd) {
        this.descProd = descProd;
    }

    public Double getValor() {
        return valor;
    }

    public void setValor(Double valor) {
        this.valor = valor;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public Categoria getCategoria() {
        return categoria;
    }

    public void setCategoria(Categoria categoria) {
        this.categoria = categoria;
    }

}
