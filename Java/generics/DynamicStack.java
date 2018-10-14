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
public class DynamicStack {
    private Node Top;
    public void push(Customer value){
        Node node = new Node(value);
        //node.value = value;
        //node.nextNode = null;
        if(this.Top == null){
            Top = node;
        }
        else{
            node.nextNode = Top;
            Top = node;
        }
    }
    public void pop(){
        Node node = Top.nextNode;
        Top = node;
    }
    public void display(){
        Node temp = Top;
        System.out.print("[");
        while(temp != null){
            System.out.print(temp.value);
            temp = temp.nextNode;
            
        }
        System.out.println("\b]");
    }
}
