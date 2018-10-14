using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace MathExpressionsCalculator
{
    public class Program
    {
        private const string Operators = "+-*/%^";
        private const string LeftParenthesis = "(";
        private const string RightParenthesis = ")";

        /// <summary>
        /// Stores the values of each mathematical variable (letter)
        /// </summary>
        private static Dictionary<char, double> Variables;

        /// <summary>
        /// Replaces all positive and negative floating numbers from an infix expression with letters.
        /// </summary>
        /// <param name="expression">The mathematical expression</param>
        /// <returns>Returns the new infix expression</returns>
        static string NormalizeInfixExpression(string expression)
        {
            /*
             * Regex details:
             *      (?:(?<![)0-9])-)? = an optional non-capturing group matching 1 or 0 occurences of:
             *          (?<![)0-9]) = a place in string that is not immediately proceded with a ) or digit
             *          '-' = a minus
             *      [0-9]+ = one or more digits
             *      (?:\.[0-9]+)? = an optional non-capturing group matching 1 or 0 occurences of a dot followed with one or more digits
             */
            Regex rx = new Regex(@"(?:(?<![)0-9])-)?[0-9]+(?:\.[0-9]+)?");
            char letter = (char) 96; // char before 'a' in ASCII table
            string result = rx.Replace(expression, m =>
                {
                    letter++; // char is incremented
                    double value;
                    if (!Double.TryParse(m.Value, out value))
                    {
                        throw new Exception("Invalid input!");
                    }
                    Variables[letter] = value; // the value of each letter is saved in a Dictionary
                    return letter.ToString();
                }
            );

            // This foreach replaces all occurences of (nr) with nr
            foreach (char c in result)
            {
                if (char.IsLetter(c))
                {
                    result = result.Replace(string.Format("({0})", c), c.ToString());
                }
            }

            return result;
        }

        /// <summary>
        /// Checks if op1 has a lower or equal precedence with op2
        /// </summary>
        /// <param name="op1">First operator</param>
        /// <param name="op2">Second operator</param>
        static bool CheckPrecedence(string op1, string op2)
        {
            return Operators.IndexOf(op1, StringComparison.Ordinal) <= Operators.IndexOf(op2, StringComparison.Ordinal);
        }

        /// <summary>
        /// Converts an infix expression into a postfix expression
        /// </summary>
        /// <param name="infix">The infix expression</param>
        /// <returns>Returns the postfix expression</returns>
        static string ConvertInfixToPostfix(string infix)
        {
            Stack<string> stack = new Stack<string>();

            string postfix = string.Empty;

            foreach (char character in infix)
            {
                if (char.IsLetter(character))
                {
                    postfix += character;
                    continue;
                }

                if (character.ToString() == LeftParenthesis)
                {
                    stack.Push(character.ToString());
                    continue;
                }

                if (character.ToString() == RightParenthesis)
                {
                    while (stack.Count != 0 && stack.Peek() != LeftParenthesis)
                    {
                        postfix += stack.Pop();
                    }

                    stack.Pop();
                    continue;
                }

                if (Operators.Contains(character))
                {
                    if (stack.Count == 0 || stack.Peek() == LeftParenthesis)
                    {
                        stack.Push(character.ToString());
                    }
                    else
                    {
                        while (stack.Count != 0 && stack.Peek() != LeftParenthesis &&
                               CheckPrecedence(character.ToString(), stack.Peek()))
                        {
                            postfix += stack.Pop();
                        }

                        stack.Push(character.ToString());
                    }
                }
            }

            while (stack.Count != 0)
            {
                postfix += stack.Pop();
            }

            return postfix;
        }

        /// <summary>
        /// Evaluates a mathematical postfix expression
        /// </summary>
        /// <param name="expression">The postfix expression</param>
        /// <returns>Returns the result of the evaluation</returns>
        static double EvaluatePostfixExpression(string expression)
        {
            Stack<double> stack = new Stack<double>();
            foreach (var character in expression)
            {
                if (char.IsLetter(character))
                {
                    stack.Push(Variables[character]);
                    continue;
                }

                if (Operators.Contains(character))
                {
                    double A = stack.Pop();
                    double B = stack.Pop();
                    switch (character)
                    {
                        case '^':
                            stack.Push(Math.Pow(B, A));
                            break;
                        case '*':
                            stack.Push(B * A);
                            break;
                        case '/':
                            stack.Push(B / A);
                            break;
                        case '+':
                            stack.Push(B + A);
                            break;
                        case '-':
                            stack.Push(B - A);
                            break;
                        case '%':
                            stack.Push(B % A);
                            break;
                    }
                }
                else
                {
                    throw new Exception("Invalid input!");
                }
            }

            return stack.Pop();
        }

        public static void Main(string[] args)
        {
			      Variables = new Dictionary<char, double>();
			
            // The commented results are from http://www.wolframalpha.com/
            List<string> expressions = new List<string>()
            {
                "1+2+3+4+(-1)-2", // 7
                "((-2*(-4))^2)%2", // 0
                "(-1)*3+(-2)/1+3.5", // -1.5
                "10^3-(-100*(-5)+5.12345)", // 494.87655
                "(1+5)*(-3)", // -18
                "(2*3)^2-5+(-2)", // 29
                "(((-30)+5.2)*(2+7))-((-3.1*2.5)-9.12-3)" // -203.33
            };

            foreach (string expression in expressions)
            {
                Console.WriteLine("Expression: " + expression);
                string infix = NormalizeInfixExpression(expression);
                Console.WriteLine("Infix: " + infix);
                string postfix = ConvertInfixToPostfix(infix);
                Console.WriteLine("Postfix: " + postfix);
                double result = EvaluatePostfixExpression(postfix);
                Console.WriteLine("Result: " + result + Environment.NewLine);
                Variables.Clear();
            }

        }
    }
}
