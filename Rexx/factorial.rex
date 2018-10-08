/* Main program */
do n=1 to 5
    say 'The factorial of' n 'is:' factorial( n )
    end
return

/* Function to get factorial */
factorial : procedure
    n = arg(1)
    if n = 1 then
      return 1
    return n * factorial( n - 1 )