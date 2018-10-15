program hdi_calculator;

var le,dsd,vsd,bnepk,lei,dsdi,vsdi,bi,ei,hdi:real;

begin
	writeln('This program calculates the Human Development Index');
	writeln('of a particular program from various inputs');
	writeln;
	writeln;
	write('Life expectancy at birth: ');
	readln(le);
	write('Average school attendancy duration: ');
	readln(dsd);
	write('Expected school attendancy duration: ');
	readln(vsd);
	write('Gross national income per person adjusted to purchasinf power in USD: ');
	readln(bnepk);

	lei := (le-20)/65;
	dsdi := dsd/15;
	vsdi := vsd/18;
	bi := (dsdi+vsdi)/2;
	ei := (Ln(bnepk)-2)/(Ln(75000)-2);
	hdi := Exp((1/3)*Ln(lei*bi*ei));

	writeln('HDI: ',hdi:0:3);
end.