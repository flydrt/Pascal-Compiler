program wrong_example;

var
    x : integer;
    a : (red, blue, white);

begin
    case a of
        red: writeln('a');
        blue: writeln('b');
        white: writeln('c');
    end;
end.