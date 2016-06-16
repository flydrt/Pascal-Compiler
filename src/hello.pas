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
	write('The a of Outer is:');

end;
begin
	a := 1;
	c := 2;
	outer(a,c);
end.
