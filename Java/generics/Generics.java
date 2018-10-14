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
public class Generics {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        DynamicStack s1 = new DynamicStack();
        s1.push(new Customer("C002"));
        s1.push(new Customer("C003"));
        s1.push(new Customer("C004"));
        s1.display();
        
    }
    
}
