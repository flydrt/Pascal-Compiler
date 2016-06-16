program helloworld;
type color=(red,yellow,green);
var a,c:integer;b:color;
begin
	read(a);
	b := red;
	case a of
		1: b := red;
		2: b := yellow;
		3: b := green;
	end;
	case b of
		red: writeln('red'); 
		green: writeln('green');
		yellow: writeln('yellow');
	end;
end.
