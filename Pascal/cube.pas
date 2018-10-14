program cube;

var surface_area,side,diagonal,volume:real;

begin
	writeln('Whis program calculates dimensions of a cube from a given surface area');
	writeln;
	writeln;
	write('Enter the surface area:  ');
	readln(surface_area);
	writeln;
	writeln;
	side:=sqrt(surface_area/6);
	diagonal:=sqrt(3)*side;
	volume:=side^3;
	writeln('For a cube with surface area ',surface_area:0:2,':');
	writeln('Side: ',side:0:2);
	writeln('Space diagonal: ',diagonal:0:2);
	writeln('Volume: ',volume:0:2);
end.