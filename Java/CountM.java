import java.util.*;
import java.io.*;

public class Atividade1
{
   static int ContarMaiusculas (String x)
   { 
      int cont=0;
      for(int y=0;y<x.length();y++)
      {
         if(x.charAt(y)>='A' && x.charAt(y)<='Z')
            cont++;
      }
      return cont;
   }
   
   static boolean Palindromo (String x)
   { 
      boolean teste=true;
      int cont1=0;
      int tam=x.length();
      System.out.println(tam);
      for(int y=0;y<x.length();y++)
      {
         if(x.charAt(y)==x.charAt(tam-cont1-1))
         {
            cont1++;
         
         }
         else
            return false;
      }
      return teste;
   }
   
   static String Ciframento (String x)
   { 
      String d; 
      int ct;
      char c;
      int tam=x.length();
      char[] xc= x.toCharArray();
      for(int y=0;y<tam;y++)
      { 
         c=xc[y]; 
         ct=Character.getNumericValue(c);
         ct+=3; 
         c=(char)(ct + '0' + 7 + 32);
         xc[y] = c;
      }
      d= String.valueOf(xc);
       
      return d;
   }
   
   
   
   


   public static void main (String[]args)
   {
      Scanner ler=new Scanner(System.in);
      String z;
      System.out.println("Digite Uma Frase:");
      z=ler.nextLine();
      System.out.println(ContarMaiusculas(z));
      System.out.println(Palindromo(z));
      System.out.println(Ciframento(z));
   }
}
