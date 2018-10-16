,                # Read first number    
>                # Move the data pointer to next cell
,                # Read the second number
>                # Move the data pointer to third cell 

# Logic to convert ASCII numbers to their decimal format
++++++++         # Init third cell to 8 
[
 -
 <
 ------
 <
 ------
 >>
]

# Sum the numbers
<                  # Move the pointer from 3rd cell to 2nd cell
[
  -
  <
  +
  >
]

# Move to 1st cell and print the sum
< .
