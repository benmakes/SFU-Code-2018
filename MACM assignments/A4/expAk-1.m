function [expAkOut] = expAk(count,A)
%MACM316 A4 algorithm for exp(A)
i1000 = eye(1000);
increment = i1000;
B = i1000;
for j = 1:count
    increment = (A/j)*increment;
    B = B + increment;
end
expAkOut = B;

end

