program sales_prices;

var reduced_price,reduction_percent,original_price:real;

begin
	writeln('This program calculates the original price of an item from its discount information');
	writeln;
	writeln;
	write('Enter the reduced price:  ');
	readln(reduced_price);
	write('Enter the discount precentage:  ');
	readln(reduction_percent);
	writeln;
	writeln;
	original_price:=reduced_price/(1-(reduction_percent/100));
	writeln('Original price: ',original_price:0:2);
end.