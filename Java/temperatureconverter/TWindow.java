/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package temperatureconverter;

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.HeadlessException;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.event.MouseInputAdapter;

/**
 *
 * @author badhr
 */
public class TWindow extends JFrame {

    private JTextField txtfaren = new JTextField();
    private JLabel lblcelsius = new JLabel("Celsius");
    private JLabel lblfaren = new JLabel("Farenheit");
    private JLabel lblcelView = new JLabel();
    private JButton btnfind = new JButton("Find");

    public TWindow() {
        setSize(500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("Temperature Window");
        txtfaren.setSize(300, 100);
        JPanel jPanel = new JPanel(new GridLayout(2, 1, 4, 4));
        JPanel jPanel1 = new JPanel(new GridLayout(1, 3));
        jPanel1.setSize(500, 50);
        jPanel1.add(lblfaren);
        jPanel1.add(txtfaren);
        jPanel1.add(btnfind);
        JPanel jPanel2 = new JPanel(new FlowLayout(3, 4, 4));
        jPanel2.setSize(500, 250);
        jPanel2.add(lblcelsius);
        jPanel2.add(lblcelView);
        jPanel.setSize(500, 200);
        jPanel.add(jPanel1);
        jPanel.add(jPanel2);
        add(jPanel);
        setVisible(true);
        setButtonEvt();
        pack();

    }

    public void setButtonEvt() {
        btnfind.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e){
                System.out.println("Pressed");
                TempConvert tmp = new TempConvert();
                tmp.setfarenheit(Float.valueOf(txtfaren.getText()));
                tmp.ConvertToCel();
                lblcelView.setText(tmp.getCelsius()+"");
                
            }
        });
    }

}
