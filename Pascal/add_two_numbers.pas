program add_two_numbers;

var summand1,summand2,sum:real;

begin
	writeln('This program adds two numbers');
	writeln;
	writeln;
	write('Enter the first number:  ');
	readln(summand1);
	write('Enter the second number:  ');
	readln(summand2);
	writeln;
	writeln;
	sum:=summand1+summand2;
	write('The sum of the numbers ',summand1:0:2,' and ',summand2:0:2,' is ',sum:0:2);
end.