program advanced_calculator;

var prev_num,new_num,result:real;operator,finished:char;exit:boolean;

begin
	writeln('Advanced Calculator');
	writeln;
	writeln;

	write('Enter a number:           ');
	readln(prev_num);

	repeat
  		
		write('Enter an operator:        ');
		read(operator);
		writeln;
		write('Enter another number:     ');
		readln(new_num);
	
		case operator of
			'+':prev_num:=prev_num+new_num;
			'-':prev_num:=prev_num-new_num;
			'*':prev_num:=prev_num*new_num;
			'/':prev_num:=prev_num/new_num;
			end;
		write('Finished? (Y/n)  ');
		read(finished);
		if (finished='Y') or (finished='y') then
			begin
				exit:=true;
			end
		else
			exit:=false;
		writeln;

	until exit=true;
	
	writeln;
	writeln;
	write('The result of the calculation is ',prev_num:0:2);

end.
