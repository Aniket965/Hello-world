/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package inheritance;

import java.awt.Font;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author badhr
 */
public class Calculator extends JFrame{
    private JTextField textField;
    private JButton bt0;
    private JButton bt1;
    private JButton bt2;
    private JButton bt3;
    private JButton bt4;
    private JButton bt5;
    private JButton bt6;
    private JButton bt7;
    private JButton bt8;
    private JButton bt9;
    private JButton btAdd;
    private JButton btSub;
    private JButton btMul;
    private JButton btDiv;
    private JButton btDot;
    private JButton btEquals;
    
    Calculator(){
        setSize(300, 300);
        setTitle("Calculator");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        textField = new JTextField();
        textField.setFont(new Font("", Font.BOLD, 20));
        add("North", textField);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4));
        bt7 = new JButton("7");
        bt7.setFont(new Font("", 1, 20));
        buttonPanel.add(bt7);

        bt8 = new JButton("8");
        bt8.setFont(new Font("", 1, 20));
        buttonPanel.add(bt8);

        bt9 = new JButton("9");
        bt9.setFont(new Font("", 1, 20));
        buttonPanel.add(bt9);

        btMul = new JButton("x");
        btMul.setFont(new Font("", 1, 20));
        buttonPanel.add(btMul);
        
        bt4 = new JButton("4");
        bt4.setFont(new Font("", 1, 20));
        buttonPanel.add(bt4);
        
        bt5 = new JButton("5");
        bt5.setFont(new Font("", 1, 20));
        buttonPanel.add(bt5);
        
        bt6 = new JButton("6");
        bt6.setFont(new Font("", 1, 20));
        buttonPanel.add(bt6);
        
        btDiv = new JButton("/");
        btDiv.setFont(new Font("", 1, 20));
        buttonPanel.add(btDiv);
        
        bt1 = new JButton("1");
        bt1.setFont(new Font("", 1, 20));
        buttonPanel.add(bt1);
        
        bt2 = new JButton("2");
        bt2.setFont(new Font("", 1, 20));
        buttonPanel.add(bt2);
        
        bt3 = new JButton("3");
        bt3.setFont(new Font("", 1, 20));
        buttonPanel.add(bt3);
        
        btAdd = new JButton("+");
        btAdd.setFont(new Font("", 1, 20));
        buttonPanel.add(btAdd);
        
        bt0 = new JButton("0");
        bt0.setFont(new Font("", 1, 20));
        buttonPanel.add(bt0);
        
        btDot = new JButton(".");
        btDot.setFont(new Font("", 1, 20));
        buttonPanel.add(btDot);
        
        btSub = new JButton("-");
        btSub.setFont(new Font("", 1, 20));
        buttonPanel.add(btSub);
        
        btEquals = new JButton("=");
        btEquals.setFont(new Font("", 1, 20));
        buttonPanel.add(btEquals);
        
        this.add("Center",buttonPanel);
    }
}
