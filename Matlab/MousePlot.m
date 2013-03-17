clear
close all
global deltaArray;
instrreset

s = serial('COM15','BaudRate',9600,'Terminator','CR/LF');

set(s,'BytesAvailableFcn',@MouseCallback)
deltaArray = [0 0];
fopen(s)
plot(deltaArray(1),deltaArray(2));
hold on
pause
disp('closing')
fclose(s)
disp('Reset')
instrreset

% plot(1:length(deltaArray),deltaArray(:,1),1:length(deltaArray),deltaArray(:,2));
% Movement=cumsum(deltaArray,1);
% figure
% plot(1:length(Movement),Movement(:,1),1:length(Movement),Movement(:,2));
% figure
% plot(Movement(:,1),Movement(:,2));

