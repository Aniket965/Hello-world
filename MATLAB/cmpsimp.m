 function In = cmpsimp(f,a,b,n)
 % n must be a positive even integer
 h=(b-a)/n; %step size
 x=linspace(a,b,n+1); %(n+1) equally spaced points
 fx=feval(f,x); %function evaluations
 %Composite Simpson
 In=(h/3)*(fx(1)+4*sum(fx(2:2:n))+2*sum(fx(3:2:n-1))+fx(n+1));
