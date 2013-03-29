function math_test_file2()
% math test from files
close all

% variable containing the position
x = 0;
y = 0;
angle = 0;



% open file
%file = fopen( 'rear left 90.txt');
%file = fopen( 'straight about 10cm.txt');
%file = fopen( 'turn right about 90.txt');
file = fopen( 'droit puis 90 gauche.txt'); % straight then 90 left
%file = fopen( 'droit puis 90 droite.txt'); % straight then 90 right

% get the data
data = fscanf(file, '%i', [2,inf]);

% disconnect
fclose( file);

% get the actual movement (- as the mouse is mounted backward
Dx = -data(1,:);
Dy = -data(2,:);


% process the data

 for i=1:size(Dx,2);
        alpha = atand( Dx(i) / (6*250/2.54) );  % 6 = dist in cm from sensor to turning center of car -> to be measured/ determined more precisely
        angle(end+1) = angle(end) - alpha;
        delta_x = Dy(i) * sind(angle(end-1)) ;
        delta_y = Dy(i) * cosd(angle(end-1));
        x(end + 1) = x(end) + delta_x;
        y(end + 1) = y(end) + delta_y;
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
plot(x,y);
axis equal
title('Y versus X');
figure
plot( t, angle)
title('Angle versus time');



end