program helloworld;
var a,b:integer;
function test(a,b:integer):integer;
var c:integer;
begin
	c := 1;
	a := a + b + c;
	test := a;
end;
begin
	a := 10;
	b := 10;
	writeln(test(a,b));
end.
