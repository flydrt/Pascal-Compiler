program helloworld;
var a:integer;
function test(b:integer):integer;
begin
	b := b + 1;
	test := b;
end;
begin
	a := 10;
	writeln(test(a));
end.
