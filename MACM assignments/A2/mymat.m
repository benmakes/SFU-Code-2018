function A = mymat(n)

A = tril(-ones(n));
A = A + 2*eye(n);
A(:,end) = 1;

end