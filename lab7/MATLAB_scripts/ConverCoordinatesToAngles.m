function [ alpha, beta] = ConverCoordinatesToAngles(x, y)
% alpha beta converter
height = 9.75;
A = sqrt((height*height+y*y));

alpha = (180.0/pi) * atan(y/height);
beta = (180.0/pi) * atan(x/A);

end

