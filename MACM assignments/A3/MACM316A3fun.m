function [xv,av,bv,cv] = MACM316A3fun(k)
%The algorithm described in MACM316A3 for finding a minimum of a fun
a0 = -1;b0 = -1/2;c0 = 1; av = zeros(1,101); bv = zeros(1,101); cv = zeros(1,101); xv = zeros(1,101);
av(1) = a0; bv(1) = b0; cv(1) = c0;
for i = 1:100

%start the function

lam = (3-5^.5)/2;
fa0 = -cos(a0^k); fb0 = -cos(b0^k); fc0 = -cos(c0^k);
%check for error
if(fa0<=fb0 || fc0<=fb0)
    disp('OOPS!! ERROR fa<=fb or fc<=fb')
end
%calc new x
if(c0-b0>b0-a0)
    x=b0+lam*(c0-b0);
else
    x=b0+lam*(a0-b0);
end
%create new triplet
fx = -cos(x^k);
%if (fx == fb0)
 %   fprintf('fx == bx at %d\n',i)
%end
if (fx<fb0)
    if (x<b0)
        a1 = a0;
        b1 = x;
        c1 = b0;
    elseif (x>b0)
        a1 = b0;
        b1 = x;
        c1 = c0;
    end
elseif (fx>fb0)
    if (x<b0)
        a1 = x;
        b1 = b0;
        c1 = c0;
    elseif (x>b0)
        a1 = a0;
        b1 = b0;
        c1 = x;
    end
end
a0 = a1;
b0 = b1;
c0 = c1;
av(i+1) = a1;
bv(i+1) = b1;
cv(i+1) = c1;
xv(i+1) = x;
end
end

