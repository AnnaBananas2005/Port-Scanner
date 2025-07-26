# Port-Scanner

## Basic Overview
Before describing port scanners- we first have to describe what even are ports.
<br><br>There are 0-65535 ports, so that means different protocols for each one. 
<br>The one most commonly used on a device is port 80, which is used for HTTP browsing or port 443 which is HTTPS. Your computer first sends a request to the web server, and then the server uses that same port, port 80 (or port 443 if you are on a HTTPS website) to send back the webpage data.

Port scanners check which of these ports are open or closed. When you send a request to the port, and it doesn't listen to the connection, that means it's closed. Now there are 3 types of port-ranges. 
The first would be Well-known ports, which are 0-1023 which includes HTTP (80), HTTPS (443), File Transfer Protocol (FTP) (21), etc. 
<br><br>The 2nd type is Registered ports 1024-49151 are used by many different applications and typically registered with IANA (Internet Assigned Numbers Authority, which usually involves documentation and all the… fun stuff).
<br><br>The 3rd is the Dynamic/Private ports 49152-65535, dynamic being that an application is not assigned to a specific service, just chosen randomly for a connection.

## Setting up your Properties
1) Project->Project Name Properties
	C/C++ -> General -> Additional Include Directories <br><br>
	C:\SFML\SFML-2.6.1\include
	<br><br>(SFML-2.6.1 could be changed, if you got a different version when downloading)
----

2) Linker -> General -> Additional Library Directories
	<br><br>C:\SFML\SFML-2.6.1\lib
----

3) Linker -> Input -> Additional Dependencies
	<br><br>Paste this before the existing text:
	<br><br>sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-network-d.lib;sfml-audio-d.lib;
----

PUT .dll files from your local disk -> C:\SFML\bin to -> (filename) -> x64 -> Debug folder.

----


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

