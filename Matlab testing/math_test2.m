function math_test2( comString)

close all

% variable containing the position
x = 0;
y = 0;
angle = 0;

% create the serial link object
serialLink = serial(comString, 'BaudRate', 9600);
% connect
fopen( serialLink);
% low resolution
fprintf( serialLink, 'l');
data = fscanf(serialLink);
% get 3 seconds of data
data=[];
tic
while( toc < 2)
    temp = fscanf(serialLink);
    data = [data; str2num(temp)];
end

% disconnect
fclose( serialLink);

% process the data
for i=1:size(data,1);
    alpha = atan( data(i,1) / data(i,2) );
    distance = sqrt( data(i,1)^2 + data(i,2)^2 );
    angle = angle + alpha
    Dx(i) = distance * sin( angle );
    Dy(i) = distance * cos( angle );
    x(i+1) = x(i) + Dx(i);
    y(i+1) = y(i) + Dy(i);
end

t = 1:size(x, 2);
plot(t,x);
title('X versus time');
figure;
plot(t,y);
title('Y versus time');
figure
plot(y,x);
title('Y versus X');




end