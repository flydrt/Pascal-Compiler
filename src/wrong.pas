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

begin
    read(c.x);
    x := abs(c.x);
end.