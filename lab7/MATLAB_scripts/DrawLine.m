function DrawLine ( x1,y1,x2,y2 )
% output line matrix
global outfile;

x = 0;
y = 0;

LASERSTATUS = 1;

n = fix(sqrt((x2-x1)^2 + (y2-y1)^2)/0.005);

x = linspace(x1,x2,n);
y = linspace(y1,y2,n);

for i = 1:n
    [alpha,beta] = ConverCoordinatesToAngles(x(i),y(i));
    fprintf(outfile,'%f %f %d \n',[alpha,beta,LASERSTATUS]);
end

LASERSTATUS = 0;

%turn off the laser
alpha = 0;
beta = 0;
fprintf(outfile,'%f %f %d \n',[0,0, LASERSTATUS]);
   
end

