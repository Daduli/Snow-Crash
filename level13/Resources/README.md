## LEVEL 13

First, let's see what files do we have in this level.  
-> `ls -la` or `la`  
We can see that we have an executable named *level13*, and we try to launch it.  
-> `./level13`  
And it prints *"UID 2013 started us but we we expect 4242"*. Then, we analyze it to see what we can do with it.  
-> `strings level13`  
-> `nm -u level13`  
So we can notice that the program checks the UID of the user that launches it and compares it with the UID *4242*.

> **gdb**, the *GNU Project Debugger*, allows to see what is going on during runtime, set breakpoints and analyze the behavior inside another program while it executes. It can also disassemble the program to get the assembly code.

Next, we disassemble the program and exploit it to get our flag. To do so, we first need to launch gdb on *level13*.  
-> `gdb -q level13`  
Then, we list all the functions that the program contains and disassemble it.  
-> `info functions`  
-> `disassemble main`  
Now, we have the assembly of the main. Furthermore, we can notice that there's a comparaison after the call of *getuid()*. So, we can set a breakpoint at the address where the comparaison is done and change the value of the variable during runtime.  
-> `break *0x0804859a`  
-> `run`  
-> `print $eax=0x1092`  
-> `continue`  
Finally, we collect the flag and we can move on to the last level.  
-> `su level14`
