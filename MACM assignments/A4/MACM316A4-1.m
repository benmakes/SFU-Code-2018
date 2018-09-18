%A program to calculate the exp(A) = I + A + A^2/2! ...
load('CA4.mat');
expA = expm(A);
errvec = zeros(1,15);
timevec = zeros(1,15);
iterexpA = A;
normexpA = norm(expA);
for count = 1:15
    tic;
    iterexpA = expAk(count*10,A);
    timevec(count) = toc;
    errvec(count) = (norm(expA - iterexpA))/normexpA;
end
%plot errorvec
figure(1);
plot(10:10:150,log10(errvec))
title('Relative Error in the 2-norm')
xlabel('Number of terms computed')
ylabel('Error in log10')
grid
%plot timevec
figure(2);
plot(10:10:150,timevec)
title('Time to compute exp(A) using taylor expansion')
xlabel('Number of terms computed')
ylabel('Time (seconds)')
grid
%flops per second CHANGE BACK TO 150
secondsperiter = (mean(timevec./[10:10:150]));
flopspersec = 2001000000/(mean(timevec./[10:10:150]));
%finding the slope of the errorbound for y in log10
errorslope = (log10(errvec(8))-log10(errvec(6)))/20;
%finding the x intercept
xintercept10 = 70 - log10(errvec(7))/errorslope;
%finding the y intercept
yintercept10 = -xintercept10*errorslope; 