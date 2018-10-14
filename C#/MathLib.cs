//added comment only for Hacktoberfest: this is from my "BetterMath" repository and WILL probably need a bit of tweaking, since it relies on some exceptions that are in other files.

using System;
using System.Collections;
using System.Linq;

namespace someUtils.BetterMath
{
	/// <summary>
	/// Maybe kinda somewhat better than usual math
	/// </summary>
	public static class bmath
	{
		/// <summary>
		/// The One and Only, The "Circle Number" (π)
		/// </summary>
		public const double PI = 3.141592653589793d;
		/// <summary>
		/// The Square Root of 3
		/// </summary>
		public const double sqrt3 = 1.732050807568877d;
		/// <summary>
		/// The Square Root of 3 divided by 2
		/// 
		/// for triangle-height-stuff, for example
		/// </summary>
		public const double sqrt3over2 = 0.629960524947436d;
		/// <summary>
		/// The Square Root of 2
		/// </summary>
		public const double sqrt2 = 1.414213562373095d;
		/// <summary>
		/// 2PI, since in many equations, you double it anyways. (τ)
		/// </summary>
		public const double TAU = 2d * PI;

		/// <summary>
		/// get the Square Root of a positive Number through the Heron-algorithm with 10000 iterations
		/// </summary>
		/// <param name="n">the number to get the Square Root of</param>
		/// <returns>Square Root of n</returns>
		public static double sqrt(double n)
		{
			return sqrt(n, 10000);
		}

		/// <summary>
		/// get the Square Root of a positive Number through the Heron-algorithm
		/// </summary>
		/// <param name="n">the number to get the Square Root of //HAS TO BE POSITIVE</param>
		/// <param name="i">the number of Iterations (more = more accurate)</param>
		/// <returns>Square Root of n</returns>
		public static double sqrt(double n, uint i)
		{
			double iterate(double lastresult, double m)
			{
				return 0.5 * (lastresult + (m / lastresult));
			}

			if (n == 0)
			{
				return 0;
			}

			if (n < 0)
			{
				throw new RootofNegativeException("guess you wanted i * " + n);
			}

			if (n == 2)
			{
				return sqrt2;
			}

			if (n == 3)
			{
				return sqrt3;
			}

			double num = (n + 1) / 2;

			for (int j = 0; j < i; j++)
			{
				num = iterate(num, n);
			}

			return num;
		}
						     
		/// <summary>
		/// Converts from any Number System to any Number System
		/// </summary>
		/// <param name="input">the string to be converted.</param>
		/// <param name="inalphabet">the alphabet the input uses (for example "01" or "0123456789abcdef")</param>
		/// <param name="outalphabet">the alphabet that should be returned (for example "01" or "0123456789abcdef")</param>
		/// <returns></returns>
		/// <remarks>This may behave weird if the inputalphabet contains double characters.</remarks>
		public static string ConvertNumberSystems(string input, string inalphabet, string outalphabet)
		{
			string output = "";

			int inbase = inalphabet.Length;
			int outbase = outalphabet.Length;

			int dec = 0;

			for (int i = 0; i < input.Length; i++)
			{			
				dec += (int)(inalphabet.IndexOf(input[i]) * Math.Pow(inbase, input.Length - 1 - i));
			}	

			if (outalphabet == "01234567890")
			{
				return dec.ToString();
			}

			int tmp2 = dec;

			while (!(tmp2 == 0))
			{
				output = outalphabet[tmp2 % outbase] + output;
				tmp2 = tmp2 / outbase;
			}

			return output;
		}

		/// <summary>
		/// Squares a Number
		/// </summary>
		/// <param name="n">the number to be squared</param>
		/// <returns></returns>
		//I don't know a single use case where n*n would not be better...
		public static double square(double n)
		{
			return n * n;
		}

		/// <summary>
		/// gives back B^E.
		/// </summary>
		/// <param name="b">the base (i.e. in 3^4 it's 3)</param>
		/// <param name="e">the exponent (i.e. in 3^4 it's 4)</param>
		/// <returns></returns>
		public static double exponential(double b, int e)
		{
			//say newb out loud, yes it's an easter egg
			double newb = b;

			if (e >= 1)
			{
				for (int i = 0; i < e - 1; i++)
				{
					newb *= b;
				}
			}
			else
			{
				for (int i = 0; i < -e + 1; i++)
				{
					newb = newb / b;
				}
			}

			return newb;
		}

		/// <summary>
		/// Restricts a value to be within a specified range.
		/// </summary>
		/// <param name="value">The value to clamp.</param>
		/// <param name="min">The minimum value. If <c>value</c> is less than <c>min</c>, <c>min</c> will be returned.</param>
		/// <param name="max">The maximum value. If <c>value</c> is greater than <c>max</c>, <c>max</c> will be returned.</param>
		/// <returns>The clamped value.</returns>
		public static float Clamp(float value, float min, float max)
		{
			if (min > max)
			{
				throw new MinBiggerThanMaxException("The Minimum Value You put In Clamp is bigger than The Max Value!");
			}

			value = ((value > max) ? max : value);
			value = ((value < min) ? min : value);
			return value;
		}

		/// <summary>
		/// Linearly interpolates between two values.
		/// </summary>
		/// <param name="value1">Source value.</param>
		/// <param name="value2">Source value.</param>
		/// <param name="amount">Value between 0 and 1 indicating the weight of value2.</param>
		/// <returns>Interpolated value.</returns> 
		/// <remarks>This method performs the linear interpolation based on the following formula.
		/// <c>value1 + (value2 - value1) * amount</c>
		/// Passing amount a value of 0 will cause value1 to be returned, a value of 1 will cause value2 to be returned.
		/// </remarks>
		public static double Lerp(double value1, double value2, double amount)
		{
			return value1 + (value2 - value1) * amount;
		}

		/// <summary>
		/// Converts radians to degrees.
		/// </summary>
		/// <param name="radians">The angle in radians.</param>
		/// <returns>The angle in degrees.</returns>
		/// <remarks>
		/// This method uses double precission internally,
		/// though it returns single float
		/// Factor = 180 / pi
		/// </remarks>
		public static float ToDegrees(float radians)
		{
			return (float)((double)radians * 57.295779513082323);
		}

		/// <summary>
		/// Converts degrees to radians.
		/// </summary>
		/// <param name="degrees">The angle in degrees.</param>
		/// <returns>The angle in radians.</returns>
		/// <remarks>
		/// This method uses double precission internally,
		/// though it returns single float
		/// Factor = pi / 180
		/// </remarks>
		public static float ToRadians(float degrees)
		{
			return (float)(degrees * 0.017453292519943295);
		}

		/// <summary>
		/// Gets the Sum of The numbers in the array up to a limit (see Euler's first problem)
		/// </summary>
		/// <param name="nums">the numbers to add the multiples off</param>
		/// <param name="limit">only multiples below this limit will be added</param>
		/// <returns></returns>
		public static long SumofMultiples(int[] nums, int limit)
		{
			ArrayList al = new ArrayList();

			long sum = 0;

			for (int i = 0; i < limit; i++)
			{
				for (int j = 0; j < nums.Length; j++)
				{
					if (i % nums[j] == 0)
					{
						if (!al.Contains(i))
						{
							al.Add(i);
							sum += i;
						}
					}
				}
			}

			return sum;
		}

		public static double roundtomultipleof(double multiple, double numbertoround)
		{
			double tmp1 = ((int)(numbertoround / multiple) * multiple);
			double tmp2 = tmp1 + multiple;

			if (Math.Abs(tmp1 - numbertoround) < Math.Abs(tmp2 - numbertoround))
			{
				return tmp1;
			}
			else
			{
				return tmp2;
			}
		}
	}

	#pragma warning disable CS0659
	#pragma warning disable CS0661

	/// <summary>
	/// A 2D Vector
	/// </summary>
	public class Vec2 : IComparable, IEquatable<Vec2>, IEquatable<Vec3>, IEquatable<Vec>, IComparable<Vec>, IComparable<Vec2>, IComparable<Vec3>

	#pragma warning restore CS0661
	#pragma warning restore CS0659

	{
		///<summary>
		/// A "Zero Vector", it has a x and y value of 0
		///</summary>
		public static readonly Vec2 ZERO = new Vec2(0, 0);

		#region Fields
		/// <summary>
		/// The X Direction / Amount of The Vector
		/// </summary>
		public double x = 0;
		/// <summary>
		/// The Y Direction / Amount of The Vector
		/// </summary>
		public double y = 0;
		#endregion

		#region Constructors
		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="_x">The X Direction / Amount of The Vector</param>
		/// <param name="_y">The Y Direction / Amount of The Vector</param>
		public Vec2(double _x, double _y)
		{
			x = _x;
			y = _y;
		}

		/// <summary>
		/// Constructor as well, X and Y are zero with this.
		/// </summary>
		public Vec2()
		{
			x = 0;
			y = 0;
		}

		/// <summary>
		/// Constructor, X and Y are the same
		/// </summary>
		/// <param name="coord">the number that both coordinates will be</param>
		public Vec2(double coord)
		{
			x = coord;
			y = coord;
		}
		#endregion

		#region Operators
		public static Vec2 operator +(Vec2 s, Vec2 s2)
		{
			return new Vec2(s.x + s2.x, s.y + s2.y);
		}

		public static Vec2 operator -(Vec2 s, Vec2 s2)
		{
			return new Vec2(s.x - s2.x, s.y - s2.y);
		}

		public static bool operator ==(Vec2 vector1, Vec2 vector2)
		{
			return vector1.length() == vector2.length();
			
		}

		public static bool operator !=(Vec2 vector1, Vec2 vector2)
		{
			return !(vector1.length() == vector2.length());
		}

		public static bool operator ==(Vec2 vector1, Vec3 vector2)
		{
			return vector1.length() == vector2.length();
		}

		public static bool operator !=(Vec2 vector1, Vec3 vector2)
		{
			return !(vector1.length() == vector2.length());
		}

		public static bool operator ==(Vec2 vector1, Vec vector2)
		{
			return vector1.length() == vector2.length();
		}

		public static bool operator !=(Vec2 vector1, Vec vector2)
		{
			return !(vector1.length() == vector2.length());
		}

		public static bool Equals(Vec2 v, Vec2 v2)
		{
			return v == v2;
		}

		public bool Equals(Vec2 v) { return this == v; }

		public bool Equals(Vec3 v) { return this == v; }

		public bool Equals(Vec v) { return this == v; }

		public override bool Equals(object o)
		{
			if (o == null || !(o is Vec2))
			{
				return false;
			}
			Vec2 vector = (Vec2)o;
			return Equals(this, vector);
		}

		public static Vec2 operator /(Vec2 s, double s2)
		{
			return new Vec2(s.x / s2, s.y / s2);
		}

		public static Vec2 operator *(Vec2 s, double s2)
		{
			return new Vec2(s.x * s2, s.y * s2);
		}

		public static Vec2 operator -(Vec2 s)
		{
			return new Vec2(-s.x, -s.y);
		}
		#endregion

		public double length()
		{
			return Math.Sqrt(x*x + y*y);
		}

		/// <summary>
		/// Normalizes A vector, meaning it's length becomes 1 but the direction stays
		/// </summary>
		public void normalize()
		{
			Vec2 v = this;
					  
			v /= v.length();

			x = v.x;
			y = v.y;
		}

		public int CompareTo(object obj)
		{
			return ((obj as Vec2).length() < length() ? -1 : (obj as Vec2).length() == length() ? 0 : 1);
		}
	}

	#pragma warning disable CS0659
	#pragma warning disable CS0661

	/// <summary>
	/// A 3D Vector
	/// </summary>
	public class Vec3 : IComparable, IEquatable<Vec2>, IEquatable<Vec3>, IEquatable<Vec>
	{
		/// <summary>
		/// A "Zero Vector", it has a x, y and z value of 0
		/// </summary>
		public static readonly Vec3 ZERO = new Vec3(0, 0, 0);

		#region Fields
		/// <summary>
		/// The X Direction / Amount of The Vector
		/// </summary>
		public double x = 0;
		/// <summary>
		/// The Y Direction / Amount of The Vector
		/// </summary>
		public double y = 0;
		/// <summary>
		/// The Z Direction / Amount of The Vector
		/// </summary>
		public double z = 0;
		#endregion

		#region Constructors
		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="_x">The X Direction / Amount of The Vector</param>
		/// <param name="_y">The Y Direction / Amount of The Vector</param>
		/// <param name="_z">The Z Direction / Amount of The Vector</param>
		public Vec3(double _x, double _y, double _z)
		{
			x = _x;
			y = _y;
		}

		/// <summary>
		/// Constructor, X, Y and Z are zero
		/// </summary>
		public Vec3()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		/// <summary>
		/// Constructor, X, Y and Z are the same
		/// </summary>
		/// <param name="coord">the number that all coordinates will be</param>
		public Vec3(double coord)
		{
			x = coord;
			y = coord;
			z = coord;
		}
		#endregion

		#region Operators
		public static Vec3 operator +(Vec3 s, Vec3 s2)
		{
			return new Vec3(s.x + s2.x, s.y + s2.y, s.z+ s2.z);
		}

		public static Vec3 operator +(Vec3 s, Vec2 s2)
		{
			return new Vec3(s.x + s2.x, s.y + s2.y, s.z);
		}

		public static Vec3 operator -(Vec3 s, Vec3 s2)
		{
			return new Vec3(s.x - s2.x, s.y - s2.y, s.z - s2.z);
		}

		public static Vec3 operator -(Vec3 s, Vec2 s2)
		{
			return new Vec3(s.x - s2.x, s.y - s2.y, s.z);
		}

		public static Vec3 operator /(Vec3 s, double s2)
		{
			return new Vec3(s.x / s2, s.y / s2, s.z / s2);
		}

		public static Vec3 operator *(Vec3 s, double s2)
		{
			return new Vec3(s.x * s2, s.y * s2, s.z * s2);
		}

		public static bool operator ==(Vec3 vector1, Vec3 vector2)
		{
			return vector1.length() == vector2.length();
		}

		public static bool operator !=(Vec3 vector1, Vec3 vector2)
		{
			return !(vector1.length() == vector2.length());
		}

		public static bool operator ==(Vec3 vector1, Vec2 vector2)
		{
			return vector1.length() == vector2.length();
		}

		public static bool operator !=(Vec3 vector1, Vec2 vector2)
		{
			return !(vector1.length() == vector2.length());
		}

		public static bool operator ==(Vec3 vector1, Vec vector2)
		{
			return vector1.length() == vector2.length();
		}

		public static bool operator !=(Vec3 vector1, Vec vector2)
		{
			return !(vector1.length() == vector2.length());
		}

		public bool Equals(Vec2 v)
		{
			return this == v;
		}

		public bool Equals(Vec3 v)
		{
			return this == v;
		}

		public bool Equals(Vec v)
		{
			return this == v;
		}

		public static bool Equals(Vec3 v, Vec3 v2)
		{
			return v == v2;
		}

		public override bool Equals(object o)
		{
			if (o == null || !(o is Vec3))
			{
				return false;
			}
			Vec3 vector = (Vec3)o;
			return Equals(this, vector);
		}

		public static Vec3 operator -(Vec3 vector)
		{
			return new Vec3(-vector.x, -vector.y, -vector.z);
		}
		#endregion

		/// <summary>
		/// The Vector's length
		/// </summary>
		/// <param name="a">The Vector to get the Length of</param>
		/// <returns></returns>
		public double length()
		{
			return Math.Sqrt(x * x + y * y + z * z);
		}

		/// <summary>
		/// Normalizes A vector, meaning it's length becomes 1 but the direction stays
		/// </summary>
		public void normalize()
		{
			Vec3 v = this;
			v /= v.length();

			x = v.x;
			y = v.y;
			z = v.z;
		}

		public int CompareTo(object obj)
		{
			//I know this is awful.

			return ((obj as Vec3).length() < length() ? -1 : (obj as Vec3).length() == length() ? 0 : 1);
		}
	}

	#pragma warning disable CS0660
	#pragma warning disable CS0661

	/// <summary>
	/// A Vector which takes an array of coordinates, so more than 3 dimensions are possible without a seperate class for each
	/// </summary>
	public class Vec : IComparable, IEquatable<Vec2>, IEquatable<Vec3>, IEquatable<Vec>
	{

		public double[] coords
		{
			get {
				return coords;
			}
			set
			{
				coords = value;

				dimNum = value.Length;
			}
		}

		/// <summary>
		/// The Number of Dimensions this Vec has
		/// </summary>
		public int dimNum;

		public Vec(double[] _coords)
		{
			if (_coords.Length == 0 || _coords == null)
			{
				throw new Exception("A Vector can't have 0 Dimensions");
			}

			coords = _coords;

			dimNum = _coords.Length;
		}

		public Vec(int numDimensions)
		{
			if (numDimensions == 0)
			{
				throw new Exception("A Vector can't have 0 Dimensions");
			}

			coords = new double[numDimensions];

			for (int i = 0; i < numDimensions; i++)
			{
				coords[i] = 0;
			}

			dimNum = numDimensions;
		}



		#region Operators
		public static Vec operator +(Vec a, Vec b)
		{
			if (a.coords.Length > b.coords.Length)
			{
				double[] stuffz = a.coords;

				for (int i = 0; i < b.coords.Length; i++)
				{
					stuffz[i] = a.coords[i] + b.coords[i];
				}

				return new Vec(stuffz);

			} else if (b.coords.Length > a.coords.Length)
			{
				double[] stuffz = b.coords;

				for (int i = 0; i < a.coords.Length; i++)
				{
					stuffz[i] = b.coords[i] + a.coords[i];
				}

				return new Vec(stuffz);

			}
			else
			{

				double[] stuffz = new double[a.coords.Length];

				for (int i = 0; i < stuffz.Length; i++)
				{
					stuffz[i] = a.coords[i] + b.coords[i];
				}

				return new Vec(stuffz);
			}
		}
		
		public static Vec operator -(Vec a, Vec b)
		{
			double[] stuffz = a.coords;

			for (int i = 0; i < stuffz.Length; i++)
			{
				stuffz[i] = a.coords[i] - b.coords[i];
			}

			return new Vec(stuffz);
		}

		public static Vec operator /(Vec a, double b)
		{
			double[] d = a.coords;

			for (int i = 0; i < d.Length; i++)
			{
				d[i] = a.coords[i] / b;
			}

			return new Vec(d);
		}

		public static Vec operator *(Vec a, double b)
		{
			double[] d = a.coords;

			for (int i = 0; i < d.Length; i++)
			{
				d[i] = a.coords[i] * b;
			}

			return new Vec(d);
		}

		public static bool operator ==(Vec a, Vec b)
		{
			bool issamesofar = true;

			if (a.coords.Length != b.coords.Length)
			{
				issamesofar = false;
			}else
			{
				for (int i = 0; i < a.coords.Length; i++)
				{
					if (a.coords[i] != b.coords[i])
					{
						issamesofar = false;
						break;
					}
				}
			}

			return issamesofar;
		}

		public static bool operator !=(Vec a, Vec b)
		{
			return !(a == b);
		}

		public static bool operator ==(Vec vector1, Vec2 vector2)
		{
			return vector1.length() == vector2.length();
		}

		public static bool operator !=(Vec vector1, Vec2 vector2)
		{
			return !(vector1.length() == vector2.length());
		}

		public static bool operator ==(Vec vector1, Vec3 vector2)
		{
			return vector1.length() == vector2.length();
			
		}

		public static bool operator !=(Vec vector1, Vec3 vector2)
		{
			return !(vector1.length() == vector2.length());
		}

		public bool Equals(Vec2 v)
		{
			return this == v;
		}

		public bool Equals(Vec3 v)
		{
			return this == v;
		}

		public bool Equals(Vec v)
		{
			return this == v;
		}

		public int CompareTo(object o)
		{
			return ((o as Vec).length() < length() ? -1 : (o as Vec).length() == length() ? 0 : 1);
		}

		public static Vec operator -(Vec a)
		{
			double[] b = a.coords;

			for(int i = 0; i < b.Length; i++)
			{
				b[i] = -b[i];
			}

			return new Vec(b);
		}
		#endregion

		#region Methods
		public static bool Equals(Vec a, Vec b)
		{
			return a == b;
		}

		public override bool Equals(object o)
		{
			if (o == null || !(o is Vec))
			{
				return false;
			}
			Vec vector = (Vec)o;
			return Equals(this, vector);
		}

		public void normalize()
		{
			Vec v = this;

			v /= v.coords.Max();
			v /= v.length();

			coords = v.coords;
		}

		public double length()
		{
			double sumofsquares = 0;

			for (int i = 0; i < coords.Length; i++)
			{
				sumofsquares += coords[i] * coords[i];
			}

			return bmath.sqrt(sumofsquares);
		}
		#endregion
	}
}
