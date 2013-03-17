function MouseCallback(serial, event)
%MOUSECALLBACK Summary of this function goes here
%   Detailed explanation goes here

global deltaArray
global array
%try
    
    if( not (exist('array','var')))
        array = deltaArray
    end

    [A,count,msg]=fscanf(serial,'%d %d');
    
     deltaArray = deltaArray + A(1:2)';
     array = [array ; deltaArray];
    
    
    if (serial.BytesAvailable<=6)
    plot(array(:,1),array(:,2));
    drawnow;
    clearvars -global array
    array = deltaArray
    end
%catch
    disp('Error')
    fclose(serial)
%end
return

