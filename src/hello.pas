program helloworld;
var a:integer;
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

procedure outer(x:integer);
var a:integer;
begin
	read(a);
	a := a + x;
	a := test(a);
end;
begin
	a := 1;
	outer(a);
end.
