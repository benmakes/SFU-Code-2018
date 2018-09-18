%MACM316A3app
[x1,a1,b1,c1] = MACM316A3fun(1);
[x2,a2,b2,c2] = MACM316A3fun(2);
[x3,a3,b3,c3] = MACM316A3fun(3);
[x4,a4,b4,c4] = MACM316A3fun(4);
[x5,a5,b5,c5] = MACM316A3fun(5);
iterations = 0:100;
plot(iterations,log10(abs(x1)))
hold on
plot(iterations,log10(abs(x2)))
plot(iterations,log10(abs(x3)))
plot(iterations,log10(abs(x4)))
plot(iterations,log10(abs(x5)))
hold off
legend('k=1','k=2','k=3','k=4','k=5')
xlim([0,50])
xlabel('Number of iterations')
ylabel('Error in log10')
title('Computing the minimum x* of -cos(x^k) [-1,1]')
grid