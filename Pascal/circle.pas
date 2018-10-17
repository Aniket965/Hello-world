program circle;

var r,d,c,a:real;

begin
	writeln('This program calculates dimensions of a circle from a given circumference');
	writeln;
	writeln;
	write('Enter the circumference:  ');
	readln(c);
	writeln;
	writeln;
	r:=c/2/Pi;
	d:=2*r;
	a:=round(Pi*r^2);
	writeln('For a circle with circumference ',c:0:2,':');
	writeln('Radius: ',r:0:2);
	writeln('Diameter: ',d:0:2);
	writeln('Area: ',a:0:2);
end.
