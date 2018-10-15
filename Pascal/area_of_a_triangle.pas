program area_of_a_triangle;

var base,height,area:real;

begin
	writeln('This program calculates the area of a triangle');
	writeln;
	writeln;
	write('Enter base length:  ');
	readln(base);
	write('Enter height:  ');
	readln(height);
	area:=base*height/2;
	writeln('The area of a triangle with base ',base:0:2,' and height ',height:0:2,' is ',area:0:2);
end.