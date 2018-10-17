program currency_conversion;

var chf,converted:real;currency:string;

begin
	writeln('This program converts CHF to EUR, USD or GBP');
	writeln;
	writeln;
	write('Enter amount of Swiss Francs: ');
	readln(chf);
	write('Currency abbreviation: ');
	readln(currency);
		case currency of 
		'EUR':converted:=chf/1.17;
		'USD':converted:=chf/0.81;
		'GBP':converted:=chf/1.32;
		end;

	writeln;
	writeln;

	if converted > 0 then
		begin

		write(round(chf),' CHF is equal to ',converted:0:2,' ',currency);
		end
	else
		if chf <> 0 then
			write('Please type in a valid currency abbreviation - three uppercase letters');
		if chf = 0 then
			write('Cannot convert 0 CHF');
end.
