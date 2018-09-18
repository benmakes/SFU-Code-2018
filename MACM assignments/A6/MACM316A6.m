clear;clc;
n = 100;
%function handle
fx = @(x) (sin(x)).^2;

%derivates calculated by hand f'(x) = sin(2x)
a = 0;%f'(0)
b = 0;%f'(2*pi)

%interp points
z = linspace(0,pi,1000);

for i = 2:n
    x = linspace(0,pi,i);
    y = fx(x);
    for j = 1:100
        tic
        S = spline(x,[a, y, b],z);
        timeRep(j) = toc;
    end
    time(i-1) = mean(timeRep);
    errorS(i-1) = max(abs(S - fx(z)));
    error(i-1) = norm(S - fx(z),inf);

end



figure(1)
plot(2:100,time)
title('Avg Time to Compute Spline vs. n')
ylabel('Time(s)')
xlabel('Number of Interpolating Points n')
legend('Time')
grid
figure(2)
plot(2:100,log10(error),'k')
ylabel('Error of inf norm in log10')
xlabel('Number of interpolating points n')
title('Error of Clamped Cubic Spline for Sin^2(x) vs. n')
legend('Error in inf norm')
grid

errorbound = ones(1,99);
for s = 2:99
errorbound(s) = (40/384)*(pi/s)^4;
end
confirmation = error./errorbound;