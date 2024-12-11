% Define the COM port and baud rate
comPort = "COM4";  
% Replace with your ESP8266's COM port
baudRate = 115200;

% Create a serialport object
esp8266 = serialport(comPort, baudRate);

% Set up a loop to read and display data
disp("Reading data from ESP32...");
while true
    if esp8266.NumBytesAvailable > 0
        % Read a line of data
        data = readline(esp8266);
        % Convert to numeric (optional)
        numericData = str2double(data); 
        % Display the data
        disp(numericData);            
    end
    % Small delay to avoid overwhelming the system
    pause(0.1);
    
end
