program right_triangle;

var s1,s2,hyp,area,per,h:real;

begin
	writeln('This Program calculates various lengths in a right triangle');
	writeln;
	writeln;
	write('Enter the first side length:  ');
	readln(s1);
	write('Enter the second side length:  ');
	readln(s2);
	writeln;
	writeln;
	hyp:=sqrt(s1^2+s2^2);
	area:=s1*s2/2;
	per:=s1+s2+hyp;
	h:=2*area/hyp;
	writeln('Hypotenuse: ',hyp:5:2);
	writeln('Area: ',area:5:2);
	writeln('Perimeter: ',per:5:2);
	writeln('Height: ',h:5:2);
end.