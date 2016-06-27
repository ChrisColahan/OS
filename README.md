# OS
An operating system by me, Christopher Colahan

#### Requirements
Currently, I am only using Linux to build the OS, so if you build with Windows you are on your own.
You will need the following programs/packages installed
- git
- make
- nasm (netwide assembler)
- gcc
- qemu (for emulating the OS)

#### Building
Currently, building has only been tested on Linux.

1. Clone the repository: `git clone https://github.com/ChrisColahan/OS.git`
2. Ensure you have the nessessary requirements (see Requirements section)
3. cd into the directory and run make: `cd OS && make`
4. Hopefully, if everything worked correctly, then a qemu window should pop up with the OS running: 
![alt text](https://github.com/ChrisColahan/OS/blob/master/screenshots/qemu-26-june-2016.png "qemu screenshot")
5. The generated OS image is in raw binary form as `bin/os_image.bin`. There is currently no pre-defined way in the makefile of writing this image to a CD, flashdrive, or converting it to any other format such as an ISO.

#### Credits
I was helped/inspired by the resources found in these links:
- https://www.youtube.com/watch?v=YvZhgRO7hL4&index=11&list=WL
- http://wiki.osdev.org/Main_Page
