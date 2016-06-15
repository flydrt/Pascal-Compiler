program wrong_example;

var
    x : integer;
    a : (red, blue, white);

function f1(a : integer) : integer;
begin

end;

begin
    case a of
        red: writeln('a');
        blue: writeln('b');
        white: writeln('c');
    end;
end.