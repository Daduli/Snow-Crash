## LEVEL 11

As usual, we look for files to use.  
-> `ls -la` or `la`  
We have a file named *level11.lua* that is a *Lua* script. Let's see what's inside the file.  
-> `cat level11.lua`  
So, the script is hosting a server at *localhost:5151* and ask for a password upon a connection. The password given is hashed with *sha1sum* by calling *popen()*.

> **sha1sum** is a command that hash a string using SHA-1.  
**popen()** is a function that executes system's commands.

If we try to launch the script,  
-> `./level11.lua`  
We get an error saying that the address *127.0.0.1 (localhost)* is already in use. Thus, we try to connect to the server.  
-> `nc localhost 5151`  
We connect to the server and it asks for a password. But we know that the script is using a function that can execute system commands to hash the password given. Therefore, we can exploit this and enter the following command as password to get our flag.  
-> `$(getflag > /tmp/flag)`  
And we should get our flag in */tmp/flag*.  
-> `cat /tmp/flag`  
To finish, we can go to the next level.  
-> `su level12`