clear;clc;
f1 = @(x) 1./(2+x);
f2 = @(x) cos(10*pi*x);

for n=1:100;
x_equi = 0:n; 
x_equi = -1 + 2*x_equi'/n;

x_cheb = 0:n; 
x_cheb = cos(pi*x_cheb'/n);

grid1 = linspace(-1,1,n*10);
grid1 = grid1';

ue = baryinterp(x_equi,f1(x_equi),grid1);
uc = baryinterp(x_cheb,f1(x_cheb),grid1);

%error calc in 2 norm
errore(n) = norm(f1(grid1)-ue,2);
errorc(n) = norm(f1(grid1)-uc,2);
end

figure(1)
hold on
plot(1:100,log10(errore),'r');
plot(1:100,log10(errorc),'k');
grid on
legend('equispaced','Chebyshev');
title('Error of Barycentric Lagrange Interpolation for f1');
xlabel('Number of Interpolation Points');
ylabel('Error of the 2-norm in log10')
hold off

%f2
for n=1:100;
x_equi = 0:n; 
x_equi = -1 + 2*x_equi'/n;

x_cheb = 0:n; 
x_cheb = cos(pi*x_cheb'/n);

grid1 = linspace(-1,1,n*10);
grid1 = grid1';

ue2 = baryinterp(x_equi,f2(x_equi),grid1);
uc2 = baryinterp(x_cheb,f2(x_cheb),grid1);

%error calc in 2 norm
errore2(n) = norm(f2(grid1)-ue2,2);
errorc2(n) = norm(f2(grid1)-uc2,2);
end

figure(2)
hold on
plot(1:100,log10(errore2),'r');
plot(1:100,log10(errorc2),'k');
grid on
legend('equispaced','Chebyshev');
title('Error of Barycentric Lagrange Interpolation for f2');
xlabel('Number of Interpolation Points');
ylabel('Error of the 2-norm in log10')
hold off