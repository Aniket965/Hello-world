program speed_control;

var speed:real;
begin
	writeln('Speed Control Program');
	writeln;
	writeln;
	write('Enter speed: ');
	readln(speed);
	writeln;
	writeln;
	if speed=50 then
		begin
			write('You are driving exactly at the speed limit. Be careful not to drive faster.');
		end
	else
		begin
			if speed>50 then
				begin
					write('You are driving ',speed-50:0:2,' km/h too fast. Slow down!');
				end
			else
				write('You are within the speed limit of 50 km/h');
		end
end.