program helloworld;
type color=(red,yellow,green);
var a,c:integer;b:color;
function test(b:integer):integer;
var a:integer;
begin
	if b > 0 
	then begin
		writeln(b);
		b := b - 1;
		a := test(b);
	end
	else begin
		test:=a;
	end;
end;

procedure outer(x,y:integer);
var a:integer;
begin
	a := x * y;
	writeln(a);
	a := test(a);
end;
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
	writeln('The calculate end:');
end.
