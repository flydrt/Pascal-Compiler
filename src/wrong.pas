program wrong_example;

var
    a : array [1..3] of real;
    b : record
        a : real;
        b : integer;
    end;

begin
    b.a := 2 * 4;
end.