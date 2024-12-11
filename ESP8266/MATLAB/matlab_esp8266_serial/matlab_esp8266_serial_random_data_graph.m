% Define the COM port and baud rate
comPort = "COM4";  
baudRate = 115200;

% Create a serialport object
esp8266 = serialport(comPort, baudRate);

% Set up the figure for real-time plotting
figure('Name', 'Real-Time Data Plot', 'NumberTitle', 'off');
% Create an animated line
hLine = animatedline('LineWidth', 2, 'Color', 'b'); 
xlabel('Time (s)');
ylabel('Data');
title('Real-Time Data from esp8266');
grid on;

% Initialize variables for tracking time
startTime = datetime('now');
timeElapsed = 0;

disp("Reading data from esp8266 and plotting...");

% Real-time data plotting loop
while true
    if esp8266.NumBytesAvailable > 0
        % Read a line of data
        data = readline(esp8266);
        numericData = str2double(data); 
        
        % Check if the data is valid
        if ~isnan(numericData) 
            % Calculate elapsed time
            currentTime = datetime('now');
            timeElapsed = seconds(currentTime - startTime);
            
            % Add data to the animated line
            addpoints(hLine, timeElapsed, numericData);
            % Update the plot
            drawnow limitrate; 
        else
            disp("Invalid data received, skipping...");
        end
    end
    
    % Small delay to avoid overwhelming the system
    pause(0.05);
end
