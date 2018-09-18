function u = baryinterp(x,y,grid)

n = length(x);
m = length(grid);

w = zeros(n,1);
for i = 1:n 
    X = x-x(i)*ones(n,1);
    X = X([1:i-1 i+1:n],1);
    w(i) = 1/prod(X);
end

u = zeros(m,1);

for i = 1:m
    
    diff = grid(i).*ones(n,1)-x;
    l = sum(diff == 0);
   
    if l == 0
       z = w./diff;
       u(i) = (z'*y)/sum(z);
    else
        u(i) = y(diff == 0);
    end
end
  
end