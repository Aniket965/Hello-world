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
public class Node {
    public Customer value;
    public Node nextNode;
    public Node(Customer val){
        this.value = val;
        this.nextNode = null;
    }
}
