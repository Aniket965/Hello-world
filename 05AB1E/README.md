# [05AB1E](https://github.com/Adriandmen/05AB1E) is a concise, stack-based golfing language.

You can use [Try It Online!](https://tio.run/##yy9OTMpM/f9fySM1JydfRyE8vygnRfH/f8v/AA) to run these programs.

## [Hello, World!](helloworld.abe)

```
"Hello, World!
```

The expected `Hello, World!` program is `"Hello, World!"` (pushes the string `Hello, World!` to the stack and then implicitly outputs it). However, the trailing quote is optional, allowing for a more concise program `"Hello, World!`.

It seems that [somebody has found a more concise program than me](https://codegolf.stackexchange.com/questions/55422/hello-world/67457#67457), but it is not in any way readable.

## [Factorial](factorial.abe)

```
GN*
```

This is a pretty simple program that outputs the factorial of the input.

```
		- The input is pushed to the stack
G		- Loop the code until } until N is the first element in the stack (starting at 1), for(N = 1, N <= input, N++)
	N	- N is the counter variable for the loop, this pushes it to the stack
	*	- Sum the top 2 elements of the stack and push it to the stack
		- } is implied (the end of the loop)
```
