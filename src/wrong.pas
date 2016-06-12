program wrong_example;
type
    ww = record
        x : integer;
        y : real;
        z : char;
    end;
var
    x : integer;
    c : ww;

function p1(x:integer; y:real): integer;
var
    z : char;

begin
    x := 1;
    p1 := p1(1, 1.2);
end;

begin

end.