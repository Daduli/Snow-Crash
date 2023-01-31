## LEVEL 04

First, we look for usuable files.  
-> `ls -la` or `la`  
We can see that we have a *level04.pl* file in our directory.

> **.pl** extension is used for *Perl* script.

Let's take a look on the content of *level04.pl*.  
-> `cat level04.pl`  
In the Perl script, we can notice few things:  
1. There is a webserver hosted at localhost:4747
2. It uses a *CGI (Common Gateway Interface)*
3. There is a function that prints the argument given in parameters

> A **CGI** is a set of rules for running scripts and programs on a webserver. To give parameters via *CGI*, take the webserver URL and add a question mark followed by the parameter name, an equal sign, and the value desired.

Using a web browser, we connect to the webserver and give it `getflag` as followed:  
-> `http://{VM_ip}:4747/?x=$(getflag)`

To finish, we log on the next level with the flag we got.  
-> `su level05`