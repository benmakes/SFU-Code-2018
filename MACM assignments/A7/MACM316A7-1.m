clear;clc;
tic
stepSize = 1;
mSmall = 100;
mBig = 1000;
iterator = 1;
for m = mSmall:stepSize:mBig;
    
for i = 0:m
    xEq(i+1)=-1+2*i/m;
    yEq(i+1)=-1+2*i/m;
end

%xMc = -1+2*rand(1,m+1);
%yMc = -1+2*rand(1,m+1);
intEq = 0;
intMc = 0;
intNewMc = 0;

for j = 1:m+1
    for k = 1:m+1
        if ( (xEq(j)^2 + yEq(k)^2) <= 1 )
            intEq = intEq+1;
        end
 %       if ( (xMc(j)^2 + yMc(j)^2) <= 1 )
 %           intMc = intMc+1;
 %       end
        if((-1+2*rand)^2 + (-1+2*rand)^2 <= 1)
            intNewMc = intNewMc+1;
        end
    end
end

intEq = intEq*4/(m+1)^2;
%intMc = intMc*4/(m+1)^2;
intNewMc = intNewMc*4/(m+1)^2;

intEqErr(iterator) = abs(pi-intEq)/pi;
%intMcErr(iterator) = abs(pi-intMc)/pi;
newMcErr(iterator) = abs(pi-intNewMc)/pi;

iterator = iterator + 1;
end
iterator = 1;
for c = mSmall:stepSize:mBig
    N(iterator) = (c+1)^2;
    iterator = iterator +1;
end
timeSpent = toc

fit = polyfit(N,log10(newMcErr),1);

figure(1)
hold on
scatter(N,log10(intEqErr),3,'k','filled')
plot(N,log10(1./(N.^(2/5))),'r')
title('Numerical Integration of a Circle with N Equal Spaced points')
ylabel('Relative Error in log10')
xlabel('N')
legend('Equal Spaced','1/(N\^(2/5))')
xlim([0,10^6])
grid on
hold off

%figure(2)
%scatter(N,log10(intMcErr),4,'r','filled')
%title('Mc')
%ylabel('relative error in log10')
%xlabel('N')
%grid

figure(2)
hold on
scatter(N,log10(newMcErr),3,'b','filled')
title('Numerical Integration of a Circle with N Monte Carlo points')
ylabel('Relative Error in log10')
xlabel('N')
plot(N,log10(1./(N.^.5)),'r')
xlim([0,10^6])
legend('MC','1/(N\^0.5)')
grid on
hold off
