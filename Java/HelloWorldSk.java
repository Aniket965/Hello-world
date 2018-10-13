import javax.swing.JOptionPane;
class HelloWorldSk{
    public static void main(String args[]){
        int hello = Integer.parseInt(JOptionPane.showInputDialog("splace one if you want to be greeted, place two if not"));
            if(hello == 1){
                JOptionPane.showMessageDialog(null , "hello world");
            }
            else{
            // will no be greeted
                System.out.println("will no be greeted");
            }
    }
}
