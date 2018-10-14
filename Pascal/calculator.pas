program calculator;

var num1,num2,result:real;operator:char;

begin
	writeln('This Program calculates with two numbers');
	writeln;
	writeln;
	write('Enter the first number:  ');
	readln(num1);
	write('Enter the second number:  ');
	readln(num2);
	write('Enter the operator:  ');
	read(operator);
		case operator of
		'+':result:=num1+num2;
		'-':result:=num1-num2;
		'*':result:=num1*num2;
		'/':result:=num1/num2;
		end;
	writeln;
	writeln;
	writeln('The result is: ',result:0:2);

end.