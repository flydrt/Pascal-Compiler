program helloworld;
		var a:record
				year:integer;
				month:integer;
				day:integer;
		end;
begin
		a.day := 2015;
		writeln(a.day);
end.

