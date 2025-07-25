# Port-Scanner

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


## Basic Overview
(will explain soon)

## What is a port scanner?
(will explain soon)

## In-Depth Analysis
(will explain the program with detail relating to port scanning)

