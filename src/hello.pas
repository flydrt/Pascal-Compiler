program helloworld;
type myarray = array[1..10] of integer;
var a:myarray;b:integer;
procedure test(b:myarray);
var a:integer;
begin
	writeln(b[2]);
end;

begin
	a[1]:=1;
	a[2]:=2;
	test(a);
end.
