import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;
import javax.script.ScriptException;
import java.io.File;
import java.util.Scanner;
import java.lang.Math;

public class calculator {

    static String problem;

    public static String cal(String st) throws ScriptException {
        ScriptEngineManager mgr = new ScriptEngineManager();
        ScriptEngine engine = mgr.getEngineByName("JavaScript");
        return engine.eval(st).toString();
    }

    public static void cal_sin() throws ScriptException {
        for (int i = 0; i < problem.length(); i++) {
            if (problem.charAt(i) == 's') {
                for (int j = i; i < problem.length(); j++) {
                    if (problem.charAt(j) == ')') {
                        String str = problem.substring(i + 4, j);
                        str = cal(str);
                        double a=Double.parseDouble(str);
                        a=a*Math.PI/180;
                        a=Math.sin(a);
                        str=String.valueOf(a);
                        problem = problem.substring(0, i) +"("+ str +")"+ problem.substring(j+1);
                        break;
                    }
                }
            }
        }
    }


    public static void main(String[] args) throws ScriptException {
        while (true) {
            System.out.println("please enter:");
            Scanner input = new Scanner(System.in);
            problem = input.nextLine();
            cal_sin();
            System.out.println(cal(problem));

        }

    }


}
