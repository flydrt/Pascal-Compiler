program helloworld;
var a:integer;
function test(b:integer):integer;
procedure inner(a:integer);
begin
	writeln(a);
end;
begin
	b := b + 1;
	inner(b);
	b := b + 2;
	test := b;
end;
begin
	a := 10;
	writeln(test(a));
end.
