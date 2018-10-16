/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.ProjetoProduto.util;


import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 *
 * @author PC 05
 */
public class Conversoes {
    public static Date converterData(String data) throws ParseException{
        SimpleDateFormat fmt = new SimpleDateFormat("dd/MM/yyyy");
        if(data == null || data.trim().equals(" ")){
            return null;           
        }else{
            Date date = fmt.parse(data);
            return date;
        }
    }
    
}
