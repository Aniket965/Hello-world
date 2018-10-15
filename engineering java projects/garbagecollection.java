import java.util.*;
 
class GarbageCollection
{
  public static void main(String s[]) throws Exception
  {
    Runtime rs = Runtime.getRuntime();
    System.out.println("Free memory in JVM before Garbage Collection = "+rs.freeMemory());
    rs.gc();
    System.out.println("Free memory in JVM after Garbage Collection = "+rs.freeMemory());
  }
}
