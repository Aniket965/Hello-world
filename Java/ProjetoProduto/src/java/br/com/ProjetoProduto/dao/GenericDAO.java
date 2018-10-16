/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.ProjetoProduto.dao;

import java.util.List;

/**
 *
 * @author PC 05
 */
public interface GenericDAO {
     //Object é uma classe generica, sendo implementada em varias classes diferentes, assumindo qualquer formato.
    public abstract Boolean cadastrar(Object objeto);
    public abstract Boolean inserir(Object objeto);
    public abstract Boolean alterar(Object objeto);
    public abstract Boolean excluir(int numero);
    public abstract Object carregar(int numero);
    public abstract List<Object> Listar();
    
}
