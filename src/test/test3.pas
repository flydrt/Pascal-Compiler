program helloworld;
var a:integer;
function test(b:integer):integer;
var d:integer;
procedure inner(a:integer);
begin
	writeln(d);
	writeln(a);
end;
begin
	d := 117;
	b := b + 1;
	inner(b);
	b := b * 2;
	inner(b);
	b := b div 2;
	inner(b);
	b := b - 2;
	test := b;
end;
begin
	a := 10;
	writeln(test(a));
end.
