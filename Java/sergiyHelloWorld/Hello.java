import java.util.stream.Stream;

public class Hello {
  public static void main(String[] args)
  {
          Stream.of(new String("Hello world!").split("")).forEach(System.out::println);
  }
}
