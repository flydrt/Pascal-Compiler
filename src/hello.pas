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
	writeln(ord(b));
	write('chr:');
	writeln(chr(-a));
	write('odd:');
	writeln(odd(a));
	write('pred:');
	writeln(pred(a));
	write('sqr:');
	writeln(sqr(a));
	
end.
