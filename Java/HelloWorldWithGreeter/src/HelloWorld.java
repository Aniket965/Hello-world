public class HelloWorld {
    public static void main(String[] args) {
        if(args.length == 0) {
            System.out.println("No name to greet");
        } else {
            final String greeting = new Greeter().createGreeting(args[0]);
            System.out.println(greeting);
        }
    }
}
