Program HelloWorldWithName;
var
    name,surname: String;
begin
    write('Enter your name:');
	readln(name);
	write('Enter your surname:');
	readln(surname);
	writeln;
	writeln;
	writeln('Hello there, ',name,' ',surname);
	readln;
end.
