x=1:10;
y=cosh(x);
xx=0:0.01:10;
yy=spline(x,y,xx);
x2=[0.9 1.3 1.9 2.1 2.6 3 3.9 4.4 4.7 5 6 7 8 9.2 10.5 11.3 11.6 12 12.6 13 13.3];
y2=[1.3 1.5 1.85 2.1 2.6 2.7 2.4 2.15 2.05 2.1 2.25 2.3 2.25 1.95 1.4 0.9 0.7 0.6 0.5 0.4 0.25];
xx2=0:0.01:13.3;
yy2=spline(x2,y2,xx2);

figure (1)
plot(x,y,'o',xx,yy,'b');
figure (2)
plot(x2,y2,'o',xx2,yy2,'b');
