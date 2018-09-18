function x = GaussElim(A,b)

[~,n] = size(A);
A = [A b];
x = zeros(n,1);

for k = 1:n-1
    
    [~,ind] = max(abs(A(k:end,k)));
    if ind > k
        c = A(k,:);
        A(k,:) = A(ind,:);
        A(ind,:) = c;
        clear c
    end
    
    for j = k+1:n
        m = A(j,k)/A(k,k);
        A(j,:) = A(j,:) - m*A(k,:);
    end
    A(k+1:end,k) = 0;
    
end

x(n) = A(n,n+1)/A(n,n);

for k = n-1:-1:1
    
    x(k) = A(k,n+1) - A(k,1:n)*x;
    x(k) = x(k)/A(k,k);
    
end

end