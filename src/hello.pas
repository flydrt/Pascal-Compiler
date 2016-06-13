program helloworld;
var b,c:integer;
begin
	read(b);	
	case b of
		1:c := 1;
		2:c := 2;
		3:c := 3;
	end;
	writeln(c);
end.

