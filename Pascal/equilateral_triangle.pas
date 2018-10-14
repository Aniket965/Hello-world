program equilateral_triangle;

var side,height,per,area:real;

begin
	writeln('This program calculates dimensions of an equilateral triangle from its side length');
	writeln;
	writeln;
	write('Enter the side length:  ');
	readln(side);
	writeln;
	writeln;
	height:=sqrt(3)/2*side;
	area:=sqrt(3)/4*side^2;
	per:=side*3;
	writeln('For an equilateral triangle with side length of ',side:0:2,':');	
	writeln('Height: ',height:0:2);
	writeln('Area: ',area:0:2);
	writeln('Perimeter: ',per:0:2);
end.