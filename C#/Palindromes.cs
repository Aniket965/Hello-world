using System;
using System.Diagnostics;


class MainClass
{
  
  public static bool VerificaPalindromo(string _string)
  {
    if(_string.Length <=1 )
    {
      return true;
    }
    else
    {
      if(_string[0]==_string[_string.Length-1])
      {
        if(_string.Length==2)
        {
          return true;
        }
        return VerificaPalindromo(_string.Substring(1, _string.Length-2));
      }
      else
      {
        return false;
      }
    }
  }
  
  public static void ImprimePalindromos(int _inicio, int _fim)
  {
    Console.WriteLine("Numeros palindromos de {0} ate {1}:", _inicio, _fim);
    for (var i=_inicio; i <= _fim; i++)
    {
      if(VerificaPalindromo(i.ToString()))
      {
        Console.Write("{0} | ",i);
      }
      
    }
  }
  
  
  static void Main()
  {
    var stopwatch = new Stopwatch();
    stopwatch.Start();
    
    ImprimePalindromos(1,1000000);
    
    stopwatch.Stop();
    Console.WriteLine("\n\nTempo passado: {0}",stopwatch.Elapsed);
    
  }
  
}