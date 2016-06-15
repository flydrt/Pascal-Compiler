program helloworld;
		var a:record
				year:integer;
				month:char;
				day:string;
		end;
begin
		a.day := 'hahah';
		a.month := 'A';
		
		writeln(a.day);
end.

