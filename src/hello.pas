program hello;

type
	atype=array[1..256] of integer;
	
var 
	te: integer;
	n: integer;
	
	v1 : boolean;
	v3 : char;
	v4 : string;
	v5 : atype;

function f2(x:integer;y:string):integer;
	var
		i,s:integer;

	begin
		v5[1]:=2*4 ;
		n:=5;
		if v5[1] > n 
		then te:= n
		else te:=v5[1];
		
		for i:=1 to n do
			begin
					v5[1]:=v5[1]+1;		
			end;
		while  i > 2 do
			begin
   				v5[1]:=v5[1]+1;
				i := i -1;
			end;	
		repeat
			begin
   			v5[1] := v5[1]+1;
			i := i + 1;
			end;
		until i = x;
		f2 := v5[1];
	end;
	
	
begin
  
   te := f2(10,'12');
   writeln(te);
end.
