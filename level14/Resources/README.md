## LEVEL 14

For the last level, as same as the previous ones, we search for files that we can use.  
-> `ls -la` or `la`  
It seems that we don't have any files here. Let's take a look at the root of the virtual machine.  
-> `find -name level14 2> /dev/null | grep -v proc`  
-> `find -user level14 2> /dev/null | grep -v proc`  
-> `find -group level14 2> /dev/null | grep -v proc`  
-> `find -name flag14 2> /dev/null | grep -v proc`  
-> `find -user flag14 2> /dev/null | grep -v proc`  
-> `find -group flag14 2> /dev/null | grep -v proc`  
We don't have any files that we can exploit, so, the last solution is to reverse the binary of `getflag`. To do so, We disassemble `getflag` with gdb.  
-> `gdb -q getflag`  
Then, we look up the functions that are used and disassemble the main.  
-> `info functions`  
-> `disassemble main`  
We can notice that *ptrace()* and *getuid()* are used here.

> **ptrace()** is a function that provides a means by which one process (the "tracer") may observe and control the execution of another process (the "tracee"), and examine and change the tracee's memory and registers. It is primarily used to implement breakpoint debugging and system call tracing.

So, we can set breakpoints after the execution of *ptrace()* to change the value that it checks to get through the protection to the program reverse and when *getuid()* is called.

> In Assembly, **EAX** is a 32-bits data register that stores input/output and arithmetic instructions.

-> `break *0x0804898e`  
-> `break getuid`

After that, we run the program and change *eax* with the values we want, to trick the program to give us the flag.  
-> `run`  
-> `print $eax=0`  
-> `continue`  
We can see that the UID for flag14 in */etc/passwd* is 3014.  
-> `step`   
-> `print $eax=3014`  
-> `continue`  
Finally, we get the last flag and finished all the levels !