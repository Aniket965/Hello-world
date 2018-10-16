import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class PA05 extends JPanel implements MouseMotionListener{
	public PA05() {
		setBackground(Color.BLACK);
		addMouseMotionListener(this);
	}
	static ArrayList<Point> points = new ArrayList<Point>();
		int lastx=0;
		int lasty=0;
		
	static class Point{
		int x;
		int y;
		Point(int x,int y){
			this.x=x; this.y=y;
		}
		public String toString() {
			return ""+x+" "+y;
		}
	}	
	
	static class PA05a extends JPanel implements MouseListener{
		public PA05a(){
			setBackground(Color.BLACK);
			addMouseListener(this);
		}	
		public void mousePressed(MouseEvent evt) { 
			Color newColor = new Color((int)(Math.random()*255),(int)(Math.random()*255),(int)(Math.random()*255));
			setBackground(newColor);
		} 
		public void mouseEntered(MouseEvent evt) { 
			Color newColor = new Color((int)(Math.random()*200 + 55),0,0);
			setBackground(newColor);
		}
		public void mouseExited(MouseEvent evt) { 
			Color newColor = new Color(0,(int)(Math.random()*200 + 55),0);
			setBackground(newColor);
		}
		public void mouseClicked(MouseEvent evt) { }
		public void mouseReleased(MouseEvent evt) { }	
	}
	
	static boolean drawRect = false;
	static JButton create = new JButton("Create");
	static JTextField decision = new JTextField("True If You Want A Square");
	static JSlider degree = new JSlider(0,255,255);
	static int degreeI;
	
	static class Actions extends JComponent{
		public Actions() {
			setBackground(Color.WHITE);
			create.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent event){
					String resultS = decision.getText();
					boolean resultB = Boolean.parseBoolean(resultS);
					drawRect = resultB;
					
					degreeI = degree.getValue();
					repaint();
				}
			});
			
			
		}
		
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			g.setColor(Color.WHITE);
			g.fillRect(0,0,getSize().width,getSize().height);
			
			if (drawRect == true) {
				g.setColor(Color.RED);
				g.drawRect(50, 100, 100, 100);
				
				Color newColor = new Color(degreeI, degreeI, degreeI);
				g.setColor(newColor);
				g.fillRect(50, 100, 100, 100);
			}
		}
	}
	
	public static void main(String[] args) {
		JFrame window = new JFrame("PA05");
		JPanel content = new JPanel();
		JPanel actContent = new JPanel();
		JPanel drawArea = new PA05();
		JPanel clickArea = new PA05a();
		Actions actionArea = new Actions();
		
		content.setLayout(new GridLayout(1,4));
		content.add(actContent);
		content.add(actionArea);
		content.add(drawArea);
		content.add(clickArea);
		
	
		actContent.setLayout(new GridLayout(4,1));
		
		actContent.add(create);
		
		actContent.add(decision);
		JCheckBox filled = new JCheckBox("Click This Again to Erase");
		actContent.add(filled);
		
		degree.setFont(new Font("Calibri", Font.BOLD,8));
		degree.setMajorTickSpacing(30);	
		degree.setPaintTicks(true);
		degree.setPaintLabels(true);
		actContent.add(degree);
		
		
		filled.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	points.clear();
	        return;
            }
        });
		
		window.setContentPane(content);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setLocation(120,70);
        window.setSize(800,300);
        window.setVisible(true);
	}
	
	public void paintComponent(Graphics g){
		 g.setColor(Color.yellow);
		 g.fillRect(0,0,getWidth(),getHeight());

		 g.setColor(Color.black);
		 if (points.size()==0)
		   return;

		 Point lastPoint = points.get(0);
		 for(Point p: points){
			 g.drawLine(lastPoint.x,lastPoint.y, p.x, p.y);
			 lastPoint = p;
		 }
	 }
	
	
	public void mouseMoved(MouseEvent evt){ 
		int x = evt.getX();  
		int y = evt.getY();  
		points.add(new Point(x,y));
		repaint();
	}
	public void mouseDragged(MouseEvent evt){}
}

