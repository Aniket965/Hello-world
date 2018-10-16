using System;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;

namespace BF_interpreter
{
	class BFExecuter
	{							
		private bool interactive = false;

		static void Main(string[] args)
		{
			if (args.Length == 0)
			{
				Console.WriteLine("Please give a file's path as an argument.");
				return;
			}

			if (!File.Exists(args[0]))
			{
				Console.WriteLine("The File \"" + args[0] + "\" could not be found.");
				return;
			}					    

			new BFExecuter() {debug = args.Contains("d"), interactive = args.Contains("i") }.ExecuteProgram(File.ReadAllText(args[0]));
		}

		private readonly byte[] bytes = new byte[(int)Math.Pow(2, 16)];

		private string input;

		private int inputindex = 0;
		private int pointer = 0;
		private bool debug;

		private void ExecuteProgram(string whole)
		{
			string v = whole;

			if(!interactive)
			{
				string[] wholeasarray = whole.Split('!', 2);
				input = wholeasarray.Length == 2 ? wholeasarray[1] : "";
				v = wholeasarray[0];
			}

			for (int i = 0; i < v.Length; i++)
			{
				if(v[i] == '[')
				{
					i += doLoop(whole, i, !(bytes[pointer] == 0));
					continue;
				}

				evaluateExpression(v[i], i, whole);
			}
		}

		private int doLoop(string whole, int i, bool shouldExecute)
		{
			int counter = 0;

			string loopText = "";

			for (int j = i + 1; j < whole.Length; j++)
			{
				counter++;

				loopText += whole[j];
				
				if (whole[j] == ']')
				{
					if (bytes[pointer] != 0)
					{
						j = i;
						counter = 0;
						continue;
					}
					return counter;
				}

				if (whole[j] == '[')
				{
					if(!shouldExecute || bytes[pointer] == 0)
					{
						int tmp = doLoop(whole, j, false);
						counter += tmp;
						j += tmp;
					} else
					{
						int tmp = doLoop(whole, j, true);
						counter += tmp;
						j += tmp;
					}
					continue;
				}

				if (shouldExecute)
					evaluateExpression(whole[j], j, whole);
			}

			throw new BrainFuckException("Unmatched Bracket encountered at " + i); //Dont have unmatched brackets kids!
		}

		private void evaluateExpression(char c, int index, string whole)
		{
			if(debug)
			{
				for(int i = 0; i < whole.Length; i++)
				{
					if(i < index)
					{
						Console.Write(whole[i]);
						continue;
					}
					if(i == index)
					{
						Console.Write(whole[i] + "V");
						continue;
					}
					Console.Write(whole[i]);
				}
				Console.Write("\n");
			}				

			if (c == '>')
			{
				pointer++;
				pointer %= bytes.Length;
			}else if (c == '<')
			{
				pointer--;
				pointer = (pointer == -1 ? bytes.Length - 1 : pointer);
			}else if (c == '+')
			{
				bytes[pointer]++;
			}else if (c == '-')
			{
				bytes[pointer]--;
			}else if (c == '.')
			{
				Console.Write((char)bytes[pointer]);
			}else if (c == ',')
			{
				if(!interactive)
				{
					try
					{
						bytes[pointer] = (byte)input[inputindex++];
					} catch(IndexOutOfRangeException)
					{
						Console.ForegroundColor = ConsoleColor.Red;
						Console.Write("\nAn attempt was made to access index " + (inputindex - 1) + " while the input length is only " + input.Length);
						Console.ResetColor();
						System.Environment.Exit(1);
					}
				}else
				{
					bytes[pointer] = (byte)Console.ReadKey().KeyChar;
				}
			}
		}
	}

	[Serializable]
	internal class BrainFuckException : Exception
	{
		public BrainFuckException()
		{
		}

		public BrainFuckException(string message) : base(message)
		{
		}

		public BrainFuckException(string message, Exception innerException) : base(message, innerException)
		{
		}

		protected BrainFuckException(SerializationInfo info, StreamingContext context) : base(info, context)
		{
		}
	}
}
