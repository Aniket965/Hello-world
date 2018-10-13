import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class PhoneBook {
	public static void main(String[] args) {
		TreeMap<String,String> phoneBook = new TreeMap<String,String>();
		TreeMap<String,String> reversePhoneBook = new TreeMap<String,String>();
		
		
		JFrame window = new JFrame("PhoneBook");
		JPanel content = new JPanel();
		
		content.setLayout(new BorderLayout());
		JPanel title = new JPanel();
		title.add(new JLabel("Digital Phone Book!"));
		content.add(title, BorderLayout.PAGE_START);
		
		JPanel buttons = new JPanel();
		buttons.setLayout(new GridLayout(1,4));
		JPanel space = new JPanel();
		buttons.add(space);
		JPanel space1 = new JPanel();
		buttons.add(space1);
		JButton save = new JButton("save");
		buttons.add(save);
		JButton lookup = new JButton("lookup");
		buttons.add(lookup);
		content.add(buttons);
		
		JPanel entries = new JPanel();
		entries.setLayout(new GridLayout(2,2));
		JLabel name = new JLabel("Name:");
		entries.add(name);
		JTextField nameT = new JTextField("Tim");
		entries.add(nameT);
		JLabel phone = new JLabel("Phone:");
		entries.add(phone);
		JTextField phoneT = new JTextField("781-736-2706");
		entries.add(phoneT);
		content.add(entries, BorderLayout.PAGE_END);
		
		save.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent event){
				String nameS = nameT.getText();
				String phoneS = phoneT.getText();
				
				if (nameS != null && phoneS != null) {
					phoneBook.put(nameS, phoneS);
					reversePhoneBook.put(phoneS, nameS);
					
				}
			}
		});
		
		lookup.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent event){
				String nameS = nameT.getText();
				String phoneS = phoneT.getText();
				
				if (nameS.equals("")) {
					String newName = reversePhoneBook.get(phoneS);
					nameT.setText(newName);
					if (newName==null) {
						nameT.setText("unknown");
					}
				}
				if (phoneS.equals("")) {
					String newPhone = phoneBook.get(nameS);
					phoneT.setText(newPhone);
					if (newPhone==null) {
						phoneT.setText("unknown");
					}
				}
			}
		});
		
		
		window.setContentPane(content);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setLocation(100, 100);
		window.setSize(300,125);
		window.setVisible(true);
	}
}