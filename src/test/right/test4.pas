program helloworld;
type 
tests = record
		year:integer;
		judge:boolean;
		comment:string;
end;
var a:tests;b:integer;
begin
		a.year:=2016;
		write('2016 mode 5: ');
		writeln(a.year mod 5);
		a.judge := false;
		writeln(not a.judge);
		a.comment := 'this is a comment';
		write('the comment is: ');
		writeln(a.comment);
end.
