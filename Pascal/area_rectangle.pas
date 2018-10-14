program area_rectangle;

var side1,side2,area:real;

begin
	writeln('This program returns the area of a rectangle');
	writeln('after given the two side lengths as input');
	writeln;
	writeln;
	write('Side length: ');
	readln(side1);
	write('Side length: ');
	readln(side2);
	writeln;
	area := side1*side2;
	write('Area:       ',area:0:2); 
end.