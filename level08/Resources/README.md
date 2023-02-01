## LEVEL 08

To start, we search for some files we can use.  
-> `ls -la` or `la`  
Here, we have an executable and a file respectively named *level08* and *token*. And it seems that *level08* is an executable, we try to launch it.  
-> `./level08`  
It prints "*./level08 \[file to read\]*". We can conclude that it takes an argument that needs to be a file, so we input *token*.  
-> `./level08 token`  
Now, the program output *You may not access 'token'*. In this case, we list up all the printable strings in the binary, as same as before.  
-> `strings level08`  
We can notice the string *'token'* and some strings that define an error. So, the program filter if the file is named *'token'* and prints an error if it does.  
To exploit this, we just need to change the permission of our directory and rename *token*.  
-> `chmod 777 .`  
-> `mv token flag`  
Then, we execute the program again but with the newly renamed file.  
-> `./level08 flag`  
And we get our token for flag08, we can now go to the next level.  
-> `su flag08`

> Copy and paste the token.

-> `getflag`  
-> `su level09`