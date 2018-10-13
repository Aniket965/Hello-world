
# !/bin/bash 
  
# Take user Input 
echo "Enter Two numbers : "
read a 
read b 
  
# Input type of operation 
echo "Enter Choice :"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read ch 
  
# Switch Case to perform 
# calulator operations 
case $ch in
  1)res=`echo $a + $b | bc` 
  ;; 
  2)res=`echo $a - $b | bc` 
  ;; 
  3)res=`echo $a \* $b | bc` 
  ;; 
  4)res=`echo "scale=2; $a / $b" | bc` 
  ;; 
esac
echo "Result : $res"
