# Port-Scanner

## Basic Overview
This project is a basic port-scanner written in C++ using the Winsock2 API on Windows. It allows the user to enter a port number, or a port-range.

 This tool was solely used for educational purposes only with both the port-scanner and the Winsock2 API.

## Features
For a single-Port Scan, enter a specific port number, and the scanner will attempt a connection, and it reports back whether the port is 
<br>OPEN -> TCP Connection succeeds, yay!
<br>CLOSED -> Connection fails

For range-scan, enter a starting and ending port, the scanner will loop through the range and displays the status of each port.

<br>ADDITIONAL FEATURES: <br>
<br>This project uses Winsock2 for socket operations
<br>Has a class-based design Scanner keeps it clean
<br>Neat and helpful console output
<br>Cleanup of Winsock resources

# How it works
1. We initialize Winsock with WSAStartup
2. Creates a TCP socket (which is AF_INET, SOCK_STREAM)
3. For each port (single or range):
   	<br>-Attempts to connection
    <br>-If Succeeds (port is open), if fails (port is closed)
4. Cleans up Winsock resources when finished

## Setting up your Properties

PUT .dll files from your local disk -> C:\SFML\bin to -> (filename) -> x64 -> Debug folder.




## Configurations in Microsoft Visual Studios (When using WinSock2)
<img width="948" height="185" alt="image" src="https://github.com/user-attachments/assets/498427f8-0a58-4509-9b17-630218c23b44" />
<br><br>
In Solution Property pages, switch over to 'Debug'
<br><br>Go to the Property pages and go to Linker -> Input -> Additional Dependencies and add in
'Ws2_32.lib;' in front. 
<br><br>This is because you need to link the Winsock2 library so you can use the functions
<br><br>

<img width="967" height="297" alt="image" src="https://github.com/user-attachments/assets/70bd8e3e-a2bb-460d-9215-61b720c36a93" />
<br><br>
Switch over to 'Release' and do the same thing ^
<br><br>
<img width="936" height="191" alt="image" src="https://github.com/user-attachments/assets/49080520-8152-47b8-b88b-c178a726a281" />

