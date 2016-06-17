program wrong_example;

var
    a : array [1..3] of real;
    b : record
        a : real;
        b : integer;
    end;
    c : integer;

function f1(i:integer): real;
var a : integer;
begin
    a = 3;
end;

begin
    for c = 1 to 3 do
        b.b := 2 * 4;
    for c := 1 to 3 do
        b.b := 2 * 4.1;
end.