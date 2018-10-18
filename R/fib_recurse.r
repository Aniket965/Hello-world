fib_recurse <- function(n)
{
  if (n <= 1)
  {
    return(n)
  }
  else
  {
    return(fib_recurse(n-1) + fib_recurse(n-2))
  }
}

# taking input from user
nterms = as.integer(readline(prompt='Enter a positive integer: '))
while(nterms < 0)
{
  print('Cannot accept negative numbers ...')
  nterms = as.integer(readline(prompt='Enter a positive integer: '))
}

print('The Fibonacci sequence:')
for (i in 0:(nterms - 1))
{
  print(fib_recurse(i))
}