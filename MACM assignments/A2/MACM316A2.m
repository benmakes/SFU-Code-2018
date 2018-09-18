%MACM316 Computing Assignment 2 Benjamin Martin

clear
nvec = [1010:-50:10];
for j = 1:21
n = nvec(j);
trials = j*2;
    for i = 1:trials
    A=mymat(n);
    x=rand(n,1);
    b=A*x;
    tic;
    GaussPP = GaussElim(A,b);
    tpp(i)=toc;
    Errorgpp(i) = max(abs(GaussPP-x));
    tic;
    GaussCP = gecp(A,b);
    tcp(i)=toc;
    Errorgcp(i) = max(abs(GaussCP-x));
    end
AEgpp(j) = mean(Errorgpp);
AEgcp(j) = mean(Errorgcp);
ATgpp(j) = mean(tpp);
ATgcp(j) = mean(tcp);
end
%calculating slopes
slopeATgpp = (ATgpp(15)-ATgpp(18))/(nvec(15)-nvec(18));
slopeATgcp = (ATgcp(15)-ATgcp(18))/(nvec(15)-nvec(18));
sloperatio = slopeATgcp/slopeATgpp

subplot(2,1,1)
plot(nvec,log10(ATgpp),nvec,log10(ATgcp))
legend('GE with Partial Pivoting','GE with Complete Partial Pivoting')
title('Average Time of Computation vs Matrix Size(nxn)')
xlabel('n')
xlim([0,1010])
ylabel('Time in (log base 10) sec')
grid
subplot(2,1,2)
plot(nvec,log10(AEgpp),nvec,log10(AEgcp))
grid
title('Average Error vs Matrix Size(nxn)')
xlabel('n')
xlim([0,1010])
ylabel('Error (log base 10)')
legend('GE with Partial Pivoting','GE with Complete Partial Pivoting')