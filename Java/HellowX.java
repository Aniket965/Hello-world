public class HellowX {
  public static void main(String[] args) {
    String subject = args.length > 0 ? args[0] : "World";
    
    System.out.println(String.format("Hellow %s!", subject));
  }
}
