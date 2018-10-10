/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package generics;

/**
 *
 * @author badhr
 */
public class Customer {
    private String id;
    public Customer(String id){
        this.id = id;
    }
    public String getid(){
        return this.id;
    }

    @Override
    public String toString() {
        return "Customer-"+id;//super.toString(); //To change body of generated methods, choose Tools | Templates.
    }
    
}
