program helloworld;
var a,b:integer;
procedure test(a,b:integer);
begin
	a := a + b;
	writeln(a);
end;
begin
	a := 10;
	b := 10;
	test(a,b);
	writeln(a);
end.
