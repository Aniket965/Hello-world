program average_grade;

var ma,fr,de,en,average,mangelpunkte:real;calculate:boolean;

begin
	calculate := True;
	mangelpunkte := 0;

	writeln('This program calculates your grade average from 4 subjects');
	writeln;
	writeln;
	write('Math grade: ');
	readln(ma);
	write('French grade: ');
	readln(fr);
	write('German grade: ');
	readln(de);
	write('English grade: ');
	readln(en);
	writeln;
	writeln;

	ma := round(ma*2)/2;
	if ma<4 then
		mangelpunkte := mangelpunkte + 4 - ma;

	fr := round(fr*2)/2;
	if fr<4 then
		mangelpunkte := mangelpunkte + 4 - fr;

	de := round(de*2)/2;
	if de<4 then
		mangelpunkte := mangelpunkte + 4 - de;

	en := round(en*2)/2;
	if en<4 then
		mangelpunkte := mangelpunkte + 4 - en;

	average := (ma+fr+de+en)/4;
	writeln('Your average is: ',average:0:2);
	writeln('You have ',mangelpunkte:0:1,' Mangelpunkte');
	writeln;
	if (average<4) OR (mangelpunkte>1.5) then
		writeln('WARNING! Better start learning before its too late!');
end.