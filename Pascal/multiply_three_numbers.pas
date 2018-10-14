program multiply_three_numbers;

var n1,n2,n3,product:real;

begin
	writeln('This program multiplies three numbers');
	writeln;
	writeln;
	write('Enter first number:  ');	
	readln(n1);
	write('Enter second number:  ');
	readln(n2);
	write('Enter third number:  ');
	readln(n3);
	product:=n1*n2*n3;
	writeln('The product of ',n1:0:2,', ',n2:0:2,', ',n3:0:2,' is ',product:0:2);
end.