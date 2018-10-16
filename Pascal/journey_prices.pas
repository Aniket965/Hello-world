program journey_prices;

var train_km,bus_km,boat_km,price:real;

begin
	writeln('This program calculates the price of your journey with travelling information');
	writeln;
	writeln;
	write('How long have you travelled per train (km):  ');
	readln(train_km);
	write('How long have you travelled per bus (km):  ');
	readln(bus_km);
	write('How long have you travelled per boat (km):  ');
	readln(boat_km);
	writeln;
	writeln;
	price:=(train_km*0.36)+(bus_km*0.27)+(boat_km*0.51);
	writeln('Price exact: ',price:0:2);
	writeln('Price rounded: ',round(price*10)/10:0:2);
end.