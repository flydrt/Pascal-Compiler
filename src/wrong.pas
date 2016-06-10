program wrong_example;
var
    c : char;
    o : boolean;
    p, q : integer;
    t, u : (AA, BB, CC, DD, EE);
    v : real;
    a : record
        a : real;
        b : integer;
    end;

begin
    case a.b of
    1: o := true;
    2: o := false;
    end;
end.