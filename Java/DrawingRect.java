import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class DrawingRect extends PA05{

    public static void main(String[] args) {
        RectShape component =  new RectShape();
        JFrame frame = new JFrame();
        frame.add(component);
        frame.setSize(600, 650);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

class RectShpe extends JComponent{

    public void paint (Graphics g) {

        Graphics2D g2 = (Graphics2D) g;
      
        g2.drawRect(100,100,300,300);
          
    }
}