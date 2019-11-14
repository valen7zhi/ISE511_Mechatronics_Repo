function Testbed()
%Main function driver class
global outfile;
global infile;


infile = fopen('data.txt','r'); 
outfile = fopen('ISE511L.txt','w');


if(infile<0)
    printf('data file does not exist!\n');
    return;
else 
    shapeNum = fscanf(infile,'%d',[1,1]);
end

for i = 1:shapeNum
    shapeType = fscanf(infile,'%d,',[1,1]);
    
    switch(shapeType)
        case 0 
            A = fscanf(infile,'%f,%f,%f,%f',[1,4]);
            x1 = A(1,1);
            y1= A(1,2);
            x2 = A(1,3);
            y2 = A(1,4);
            DrawLine(x1,y1,x2,y2);
        case 1
            A = fscanf(infile,'%f,%f,%f',[1,3]);
            xc = A(1,1);
            yc = A(1,2);
            radius = A(1,3);
            DrawCircle(xc,yc,radius);
        otherwise
            fprintf('invalid file! \n');
    end 
end 

fprintf(outfile,'%f %f %d \n', [0, 0, 0]);

fclose(infile);
fclose(outfile);
end 
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            