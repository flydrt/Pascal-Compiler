program helloworld;
var a:integer;b:char;
begin
	read(a);
	b := 'a';
	write('abs:');
	writeln(abs(a));
	write('succ:');
	writeln(succ(a));
	write('ord:');
	writeln(ord(-a));
	write('chr:');
	writeln(chr(b));
	write('odd:');
	writeln(odd(a));
	write('pred:');
	writeln(pred(a));
	write('sqr:');
	writeln(sqr(a));
	
end.
