function DrawCircle(xc, yc, radius)
%output circle matrix
global outfile;

x = 0;
y = 0;

LASERSTATUS = 1;

n = fix(2*pi*radius/0.01);

theta = linspace(0, 2*pi, n);

x = radius* cos(theta) + xc;
y = radius * sin(theta) + yc;

for i = 1:n 
    [alpha,beta] = ConverCoordinatesToAngles(x(i),y(i));
    fprintf(outfile,'%f %f %d \n', [alpha, beta, LASERSTATUS]);
end

end

