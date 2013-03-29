function math_test2( comString)
% math test from files
close all

% variable containing the position
x = 0;
y = 0;
angle = 0;



% open file
%file = fopen( 'C:\Users\Xavier\Dropbox\ecosse\EE579\rear left 90.txt');
file = fopen( 'C:\Users\Xavier\Dropbox\ecosse\EE579\straight about 10cm.txt');
%file = fopen( 'C:\Users\Xavier\Dropbox\ecosse\EE579\turn right about 90.txt');

% get the data
data = fscanf(file, '%i', [2,inf]);

% disconnect
fclose( file);

% get the actual movement (- as the mouse is mounted backward
Dx = -data(1,:);
Dy = -data(2,:);


% process the data
 bufX = 0;
 bufY = 0;
 for i=1:size(Dx,2);
    bufX = bufX + Dx(i);
    bufY = bufY + Dy(i);
   % if( abs(bufX) > 5)
    if( mod(i,5) == 0)
        alpha = atand( bufX / bufY );
        distance = sqrt( bufX^2 + bufY^2 );
        angle(end+1) = angle(end) + alpha
        delta_x = distance * sind(angle(end)) ;
        delta_y = distance * cosd(angle(end)) ;
        x(end + 1) = x(end) + delta_x;
        y(end + 1) = y(end) + delta_y;
        bufX = 0;
        bufY = 0;
    elseif( i == size(Dx,2) )
        alpha = atand( bufX / bufY );
        distance = sqrt( bufX^2 + bufY^2 );
        angle(end+1) = angle(end) + alpha
        delta_x = distance * sind( angle(end)) ;
        delta_y = distance * cosd( angle(end)) ;
        x(end + 1) = x(end) + delta_x;
        y(end + 1) = y(end) + delta_y;
        bufX = 0;
        bufY = 0;
    end
 end

% convert from dpi to inch
x = x/250;
y= y/250;
% convert from inch to cm
x = 2.54 * x;
y = 2.54 * y;

t = 1:size(x, 2);
plot(t,x);
title('X versus time');
figure;
plot(t,y);
title('Y versus time');
figure
plot(y,x);
title('Y versus X');
figure
plot( t, angle)
title('Angle versus time');

angle


end