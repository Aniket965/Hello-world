program olympic_rings;

var i:integer;

begin
	uCircle(0,0,1);
	uRGBColor(1,1,1);
	uCircle(0,0,1);

	uRGBColor(0,0,0);
	for i:=1 to 50 do
		begin
			uCircle(-9,0,3-(i*0.01));
		end;

	uRGBColor(0.14,0.6,0.81);
	for i:=1 to 50 do
		begin
			uCircle(-16,0,3-(i*0.01));
		end;

	uRGBColor(0.85,0,0.1);
	for i:=1 to 50 do
		begin
			uCircle(-2,0,3-(i*0.01));
		end;

	uRGBColor(1,0.7,0.2);
	for i:=1 to 50 do
		begin
			uCircle(-12.5,-3,3-(i*0.01));
		end;

	uRGBColor(0.05,0.65,0.25);
	for i:=1 to 50 do
		begin
			uCircle(-5.5,-3,3-(i*0.01));
		end;

end.