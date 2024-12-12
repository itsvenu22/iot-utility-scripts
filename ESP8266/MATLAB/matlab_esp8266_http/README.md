# ESP8266 Data Visualization with MATLAB via HTTP

This contains quick scripts for sending data from one ESP8266 to another and visualizing it in MATLAB.

---

## Files Included

1. **`esp8266_server_http_serial.ino`**
   - Runs on the server ESP8266.
   - Receives data from the client ESP8266 via HTTP and sends it to MATLAB via USB (serially).

2. **`esp8266_client_http.ino`**
   - Runs on the client ESP8266.
   - Sends random numbers (0-20) to the server ESP8266 over HTTP.

3. **`matlab_esp8266_server_plot.m`**
   - A MATLAB script that:
     - Reads data from the server ESP8266 via USB.
     - Plots the data on a graph in real time.

---

## How to Use

### Step 0: Update SSID and Password in `credentials.h`
- Upload `esp8266_server_http_serial.ino` to the server ESP8266.
- Once uploaded, the server ESP8266 will provide its IP address in the serial monitor.

### Step 1: Upload Server Code
- Upload `esp8266_server_http_serial.ino` to the server ESP8266.
- Once uploaded, the server ESP8266 will provide its IP address in the serial monitor.

### Step 2: Update Client Credentials
- In the `credentials.h` file, update the `SERVER_IP` with the IP address obtained from the server ESP8266.
- Enter your Wi-Fi **SSID** and **Password** in the `credentials.h` file.

### Step 3: Upload Client Code
- Upload `esp8266_client_http.ino` to the client ESP8266.
- The client will start sending random numbers (0-20) to the server via HTTP.

### Step 4: Run MATLAB
- Open `matlab_esp8266_server_plot.m` in MATLAB.
- Update the serial port in the script (e.g., `COM3` or the port where the server ESP8266 is connected).
- Click **Run** in MATLAB to see the graph update in real time.

---

## Troubleshooting

- **If there is a COM port error**: 
  - Remove the ESP8266 device from the USB port and then reinsert it.

---

## What You’ll See

- A graph showing random numbers sent by the client ESP8266.
  - **X-axis**: Time (seconds).
  - **Y-axis**: Random values (0-20).

---
