using System;
using System.Collections.Generic;

public class Program{
  public static void Main(Stirng[] args){
    bool whetherIWon = false;
    
    var myName = Console.ReadLine();
    
    if (myName.StartsWith("P")){
      bool whetherIWon = true;
    }
    
    if (whetherIWon){
      Console.WriteLine("I won");
    }else{
      Console.WriteLine("I loose");
    }
  }
}
