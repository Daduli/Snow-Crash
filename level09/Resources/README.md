## LEVEL 09

Like the previous levels, we search for files that we can exploit.  
-> `ls -la` or `la`  
Yet again, we have an executable and a file named *level09* and *token*. Let's see what's inside *token*,  
-> `cat token`  
It looks like we have an encrypted password. Next, if we launch the program,  
-> `./level09`  
We can see that it needs an argument, so we try to give it *token*. And we have *tpmhr* as output. If we try with a string like *"abcdefg"*, we can notice that the letters get shifted from the index of their position. To exploit this, we create our own decrypter using this mechanic.  
-> `chmod 777 .`  
-> `vim decrypt.c`  

> Paste the code in *decrypt.c* in the *Resources*.

Finally, we can launch our program and decrypt the password to finish the level.  
-> `gcc decrypt.c -o exploit`  
-> `./exploit token`  
-> `su flag09`

> Copy and paste the token.

-> `getflag`