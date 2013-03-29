function math_test2( comString)

close all

% variable containing the position
x = 0;
y = 0;
angle = 0;
global deltaArray;
deltaArray = [0 0];

% create the serial link object
serialLink = serial(comString, 'BaudRate',9600,'Terminator','CR/LF');
set(serialLink,'BytesAvailableFcn',@MouseCallback)
% connect
fopen( serialLink);
% low resolution
fprintf( serialLink, 'l');
data = fscanf(serialLink);
% get 3 seconds of data
data=[];
tic
while( toc < 2)
    temp = fscanf(serialLink)
    data = [data; -str2num(temp)]; %- to compensate for the reversed mouse
end

% disconnect
fclose( serialLink);

% process the data
bufX = 0;
bufY = 0;
for i=1:size(data,1);
    bufX = bufX + data(i,1);
    bufY = bufY + data(i,2);
    if( abs(bufX) > 5)
        alpha = atan( bufX / bufY );
        distance = sqrt( bufX^2 + bufY^2 );
        angle = angle + alpha;
        Dx = distance * sin( angle );
        Dy = distance * cos( angle );
        x(end + 1) = x(end) + Dx;
        y(end + 1) = y(end) + Dy;
        bufX = 0;
        bufY = 0;
    elseif( i == size(data(i,1) ) )
        alpha = atan( bufX / bufY );
        distance = sqrt( bufX^2 + bufY^2 );
        angle = angle + alpha;
        Dx = distance * sin( angle );
        Dy = distance * cos( angle );
        x(end + 1) = x(end) + Dx;
        y(end + 1) = y(end) + Dy;
        bufX = 0;
        bufY = 0;
    end
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