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
		test := b;
	end;
end;
begin
	a := 10;
	writeln(test(a));
end.
