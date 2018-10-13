import javax.swing.JOptionPane;
public class GreetingsPlanet() {
	public static void main(String[] args) {
		
		JOptionPane.showMessageDialog(null , "Greetings, the earth is flat");
		int question = Integer.parseInt(JOptionPane.showInputDialog("splace one if you you agree with the statement"+
							    "\n place two if not"));
		if(question == 1){
			JOptionPane.showMessageDialog(null , "you know the true. lol :)");
		}
		else{
			JOptionPane.showMessageDialog(null , "you life is a lie. xd");
		}
	}
}
