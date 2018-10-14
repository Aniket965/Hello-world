import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

import javax.swing.*;
/**
  *
  * Beschreibung
  *
  * @version 1.0 vom 14.09.2018
  * @author 
  */

@SuppressWarnings("serial")
public class GuiSwing extends JFrame {
	private JButton [] NumButtons = new JButton[10];
	private JLabel output = new JLabel();
	private JLabel lastCalc = new JLabel();
	
	private JButton Solve = new JButton();
	private JButton Clear = new JButton();
	private JButton badWritter = new JButton();
	
	private JButton Plus = new JButton();
	private JButton Minus = new JButton();
	private JButton Divided = new JButton();
	private JButton Times = new JButton();
	private JButton Modulo = new JButton();
	
	// Variables to position the buttons
	short px = 5;
	short py = 150;
	short deltapx = 77;
	short deltapy = 52;
	
	// Numbers to calculate
	ArrayList<Integer> Numbers = new ArrayList<>();
	// Operators
	ArrayList<String> Operators = new ArrayList<>();
  
	public GuiSwing() { // Construction
		super();
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		int frameWidth = 330; 
		int frameHeight = 400;
		setSize(frameWidth, frameHeight);
		Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
		int x = (d.width - getSize().width) / 2;
		int y = (d.height - getSize().height) / 2;
		setLocation(x, y);
		setTitle("Calculator");
		setResizable(false);
		setFocusable(true);
		Container cp = getContentPane();
		cp.setLayout(null);
		addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent evt) {
				if (isInteger(Character.toString(evt.getKeyChar())) == true) {
					jNumberButtonClick(Character.toString(evt.getKeyChar()));
				} else if  (Character.toString(evt.getKeyChar()).equals("+") || 
							Character.toString(evt.getKeyChar()).equals("-") ||
							Character.toString(evt.getKeyChar()).equals("*") ||
							Character.toString(evt.getKeyChar()).equals("/")) {
					
					operatorButtonClick(Character.toString(evt.getKeyChar()));
				}
				
				
			}
			
		});
		getRootPane().setDefaultButton(Solve);
    
		output.setBounds(0, 25, 330, 70);
		output.setText(" ");
		output.setOpaque(true);
		output.setBackground(Color.WHITE);
		output.setFont(new Font("Arial Rounded MT Bold", Font.PLAIN, 20));
		cp.add(output);
		
		lastCalc.setBounds(0, 0, 330, 20);
		lastCalc.setText(" ");
		lastCalc.setFont(new Font("Arial Rounded MT Bold", Font.PLAIN, 10));
		cp.add(lastCalc);
		
		
		for (int i = 0;i < NumButtons.length;i++ ) {
			int invertedI = NumButtons.length - i-1;
			JButton temp = new JButton();
			temp.setBounds(px, py, 75, 50);
			temp.setText(Integer.toString(invertedI));
			temp.setBorderPainted(false);
			temp.setFocusPainted(false);
			temp.setFont(new Font("Arial Rounded MT Bold", Font.PLAIN, 20));
			temp.setBackground(Color.WHITE);
			temp.addMouseListener(new MouseAdapter() { 
				public void mousePressed(MouseEvent evt) { 
					jNumberButtonClick(temp.getText());
				}
			});
			NumButtons[i] = temp;
			cp.add(temp);
			px += deltapx;
			if (invertedI == 7 || invertedI == 4 || invertedI == 1) {
				py += deltapy;
				px = 5;
				if (invertedI == 1) {
					px += deltapx;
				}
			}
		}
		
		
		Solve.setBounds(px, py, 75, 50);
		Solve.setText("=");
		Solve.setFocusPainted(false);
		Solve.setBorderPainted(false);
		Solve.setBackground(Color.LIGHT_GRAY);
		Solve.setFont(new Font("Arial Rounded MT Bold", Font.PLAIN, 20));
		Solve.addMouseListener(new MouseAdapter() { 
		  public void mousePressed(MouseEvent evt) { 
		    Solve();
		  }
		});
		Solve.addActionListener(new ActionListener() { 
			  public void actionPerformed(ActionEvent evt) { 
			    Solve();
			  }
			});
		cp.add(Solve);
		
		px += deltapx;
      
		Plus.setBounds(px, py, 75, 50);
		Plus.setText("+");
		Plus.setFocusPainted(false);
		Plus.setBorderPainted(false);
		Plus.setBackground(Color.LIGHT_GRAY);
		Plus.setFont(new Font("Arial", Font.PLAIN, 24));
		Plus.addMouseListener(new MouseAdapter() { 
			public void mousePressed(MouseEvent evt) { 
				operatorButtonClick("+");
			}
		});
		cp.add(Plus);
    
		py -= deltapy;
		
		Minus.setBounds(px, py, 75, 50);
		Minus.setText("-");
		Minus.setFocusPainted(false);
		Minus.setBorderPainted(false);
		Minus.setBackground(Color.LIGHT_GRAY);
		Minus.setFont(new Font("Arial", Font.PLAIN, 24));
		Minus.addMouseListener(new MouseAdapter() { 
			public void mousePressed(MouseEvent evt) { 
				operatorButtonClick("-");
			}
		});
		cp.add(Minus);
		
		py -= deltapy;
		
		Times.setBounds(px, py, 75, 50);
		Times.setText("x");
		Times.setFocusPainted(false);
		Times.setBorderPainted(false);
		Times.setBackground(Color.LIGHT_GRAY);
		Times.setFont(new Font("Arial", Font.PLAIN, 24));
		Times.addMouseListener(new MouseAdapter() { 
			public void mousePressed(MouseEvent evt) {
				operatorButtonClick("x");
			}
		});
		cp.add(Times);
		
		py -= deltapy;
		
		Divided.setBounds(px, py, 75, 50);
		Divided.setText("�");
		Divided.setFocusPainted(false);
		Divided.setBorderPainted(false);
		Divided.setBackground(Color.LIGHT_GRAY);
		Divided.setFont(new Font("Arial", Font.PLAIN, 24));
		Divided.addMouseListener(new MouseAdapter() { 
			public void mousePressed(MouseEvent evt) {
				operatorButtonClick("�");
			}
		});
		cp.add(Divided);
		
		py -= deltapy;
		
		Clear.setBounds(px, py, 75, 50);
		Clear.setText("C");
		Clear.setFocusPainted(false);
		Clear.setBorderPainted(false);
		Clear.setBackground(Color.LIGHT_GRAY);
		Clear.setFont(new Font("Arial", Font.PLAIN, 20));
		Clear.addMouseListener(new MouseAdapter() { 
			public void mousePressed(MouseEvent evt) {
				openNumber = "";
				Numbers.clear();
				Operators.clear();
				lastCalc.setText(lastCalc.getText() + " = " +output.getText());
				output.setText(" ");
			}
		});
		cp.add(Clear);
		
		px -= deltapx;
		
		Modulo.setBounds(px, py, 75, 50);
		Modulo.setText("%");
		Modulo.setFocusPainted(false);
		Modulo.setBorderPainted(false);
		Modulo.setBackground(Color.LIGHT_GRAY);
		Modulo.setFont(new Font("Arial", Font.PLAIN, 16));
		Modulo.addActionListener(new ActionListener() { 
			public void actionPerformed(ActionEvent evt) {
				operatorButtonClick("%");
			}
		});
		cp.add(Modulo);
		
		px -= deltapx;
		
		badWritter.setBounds(px, py, 75, 50);
		badWritter.setText("<");
		badWritter.setFocusPainted(false);
		badWritter.setBorderPainted(false);
		badWritter.setBackground(Color.LIGHT_GRAY);
		badWritter.setFont(new Font("Arial", Font.PLAIN, 16));
		badWritter.addMouseListener(new MouseAdapter() { 
			public void mousePressed(MouseEvent evt) {
				// Delete last char/num 
				if (!openNumber.equals("")) {
					openNumber.substring(openNumber.length()-1);
					String text = output.getText(); // get the Output text
					text = text.substring(0, text.length() - 1);
					output.setText(text);
					
				} else if(Operators.size() > 0) {
					Operators.remove(Operators.size() - 1);
					String text = output.getText();
					text = text.substring(0,text.length() - 3); // space operator space " + "
					output.setText(text);
				}
			}
		});
		cp.add(badWritter);
		
		
		setVisible(true);
	}
	
	private String openNumber = "";
	int result = 0;   
	private void Solve() {
		if (Numbers.size() > 0) {
			Numbers.add(Integer.parseInt(openNumber));
			
			System.out.println(Numbers);
			System.out.println(Operators);
			
			if (Numbers.size() == Operators.size()) {
				System.out.println("gea");
				Operators.remove(Operators.size() - 1);
			}
			
			lastCalc.setText(output.getText());
			
			
			openNumber = ""; // Reset OpenNum
			result = Numbers.get(0);
			for (int i = 1; i < Numbers.size(); i++) {
				int num = Numbers.get(i);		
				if (i-1 < Operators.size()) {
					result = applyOperator(result,num,i-1);
				}
			}
			output.setText(" "+Integer.toString(result));
			Numbers.clear();
			Operators.clear();
			openNumber += Integer.toString(result);
			result = 0;
		}
	}
		     
	private int applyOperator(int numBefore,int num,int i) {
		int newNum = numBefore;
		switch (Operators.get(i)) {
			case "+":
				newNum += num;
				break;
			case "-":
				newNum -= num;
				break;
			case "x":
				newNum *= num;
				break;
			case "�":
				newNum /= num;
				break;
			case "%":
				newNum %= num;
				break;
		}
		return newNum;
	}
	
	public static boolean isInteger(String s) {
	      boolean isValidInteger = false;
	      try
	      {
	         Integer.parseInt(s);
	 	 
	         isValidInteger = true;
	      }
	      catch (NumberFormatException ex)
	      {
	      }
	 
	      return isValidInteger;
	   }
	
	public void jNumberButtonClick(String PNewNum) {
		if (!(openNumber.equals("") && PNewNum.equals("0"))) {
			openNumber += PNewNum;
			updateOutput(PNewNum);
		}
	}
	
	public void operatorButtonClick(String value) {
		if (!openNumber.equals("")) {
			Numbers.add(Integer.parseInt(openNumber));
			if (Numbers.size() > 0) { // If a number exist
				String valueToAdd = " " + value + " ";
				openNumber = ""; // Reset OpenNum
				
				Operators.add(value);
				updateOutput(valueToAdd);
			}
		}
	}
	
	private void updateOutput(String valueToAdd) {
		String oldText = output.getText();
		String newText = oldText + valueToAdd;
		output.setText(newText);
	}
	
	
}
