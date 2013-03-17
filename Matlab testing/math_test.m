function math_test( comString)

close all
% variable containing the position
x = 0;
y = 0;
totalX = 0;
totalY = 0;
% create the serial link object
serialLink = serial(comString, 'BaudRate', 9600);
% connect
fopen( serialLink);
% low resolution
fprintf( serialLink, 'l');
data = fscanf(serialLink)
% get 3 seconds of data
data=[];
tic
while( toc < 4)
    data = fscanf(serialLink)
    if( numel(data >0 ) )
        data = str2num(data);
        x = [x (x(size(x,2)) - data(1)) ];
        y = [y (y(size(y,2)) - data(2)) ];
        totalX = totalX - data(1);
        totalY = totalY - data(2);
    end   
end

% disconnect
fclose( serialLink);

% plot the data
t = 1:size(x, 2);
plot(t,x);
title('X versus time');
figure;
plot(t,y);
title('Y versus time');
figure
plot(y,x);
title('Y versus X');
totalX
totalY



end