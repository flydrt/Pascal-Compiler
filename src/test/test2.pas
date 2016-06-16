program helloworld;
type myarray = array[1..10] of integer;
var a:myarray;b:integer;
procedure test(b:myarray);
var a:integer;
begin
	a := 1;
	while a <= 10 do
	begin
		writeln(b[a]);
		a := a + 1;
	end;
end;

begin
	for b := 1 to 10 do
	begin
		a[b] := b;
	end;
	test(a);
	b := 10;
	repeat
		writeln(a[b]);
		b := b - 1;
	until b = 0;
end.
