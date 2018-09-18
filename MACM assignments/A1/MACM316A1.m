%MACM 316 computing assignment 1
a = acos(1-2^-53);
b =(2^-26);
E = [-2^-10,-2^-20,-(2^-24),-(2^-25),-b,-(2^-26.5),(2^-26.5),b,2^-25,2^-24,2^-23,2^-22,2^-21,2^-20,2^-10];
COMPUTEDVECTOR = (1-cos(E))./(E);
F = [-b,b];
NOROUNDING = (1-cos(F))./(F);


syms x
f=(1-cos(x))/x;
figure(1)
fplot(f,[-0.00001,0.00001])
grid
legend('(1-cos(x))/x')
xlabel('x')
ylabel('f(x)')

%discovered c through brute force after using logspace
%c=1.0536712127723507839831109316819715560065162662795046344399452209472656251e-8;




