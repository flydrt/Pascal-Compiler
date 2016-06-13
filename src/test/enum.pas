program helloworld;
type color=(red,green,yellow);
var a:color;b:integer;
begin
	read(b);	
	case b of
		1:a := red;
		2:a := green;
		3:a := yellow;
	end;
	case a of
		red: writeln('red');
		green:writeln('green');
		yellow:writeln('yellow');
	end;
end.

