import java.awt.Color;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JButton;
import javax.swing.JTextPane;
import javax.swing.JEditorPane;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFormattedTextField;
import javax.swing.JTextArea;

public class Login extends JFrame {

	private JPanel contentPane;
	private JTextField userNameField;
	private JPasswordField PassField;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Login frame = new Login();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Login() {
		setTitle("\tJlogin");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 270, 329);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel userName = new JLabel("UserName");
		userName.setHorizontalAlignment(SwingConstants.CENTER);
		userName.setBounds(88, 28, 64, 14);
		contentPane.add(userName);
		
		userNameField = new JTextField();
		userNameField.setBounds(39, 53, 184, 20);
		contentPane.add(userNameField);
		userNameField.setColumns(10);
		
		JLabel Password = new JLabel("Password");
		Password.setHorizontalAlignment(SwingConstants.CENTER);
		Password.setBounds(88, 98, 64, 14);
		contentPane.add(Password);
		
		PassField = new JPasswordField();
		PassField.setBounds(39, 123, 184, 20);
		contentPane.add(PassField);
		
		JLabel demo = new JLabel("Welcome user !");
		demo.setHorizontalAlignment(SwingConstants.CENTER);
		demo.setBounds(39, 218, 184, 14);
		contentPane.add(demo);
		
		JButton btnLogin = new JButton("Login");
		btnLogin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {  
				String pwd = String.valueOf(PassField.getText());
			
            if(userNameField.getText().matches("admin")&& pwd.matches("2018")){
            	demo.setText("Welcome " + userNameField.getText() + " !");
    			demo.setForeground(new Color(255,0,0));
               
            }else{
                demo.setText("Wrong user name or password !");
			}
			}
		});
		btnLogin.setBounds(39, 173, 89, 23);
		contentPane.add(btnLogin);
		
		JLabel help = new JLabel("");
		help.setHorizontalAlignment(SwingConstants.CENTER);
		help.setBounds(39, 243, 184, 14);
		contentPane.add(help);
		
		JButton Help = new JButton("Help");
		Help.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				help.setText("Your Password is 2018");
			}
		});
		Help.setBounds(134, 173, 89, 23);
		contentPane.add(Help);
		
		
		}
		}

