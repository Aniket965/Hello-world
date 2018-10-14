program area_rectangle;

var temp:real;

begin
	writeln('Heating Display');
	writeln;
	writeln;
	write('Temperature: ');
	readln(temp);
	writeln;
	if temp<21 then
		begin
		writeln('HEATING');
		end
	else
		writeln('HEATING STOPPED');
end.