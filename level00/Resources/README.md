## LEVEL 00

To start, we connect to the virtual machine via *SSH*,  
-> `ssh level00@{VM_ip} -p 4242`  
And then, we authentify with the password *level00*.

Let's see what files we have at the root directory of the user  
-> `ls -la` or `la`  
It seems that there is nothing that we can use here. In this case, we search on the root of the virtual machine,  
-> `cd /`   

> The **find** command searches for files with specifics requirements depending on the flags used.  
The *-user {user_name}* flag specifies the files owned by *user_name*.  

Then, we're going to search all the files that are owned by *flag00*,  
-> `find -user flag00 2> /dev/null`  
We can notice that a file named **john** is located in *./usr/sbin/john* and *./rofs/usr/sbin/john.*

> **/rofs** is a mounted directory that contains a copy of all the files and directories in the root of the virtual machine as read-only.

Next, we print the content of the file,  
-> `cat /usr/sbin/john`  
And we get the following string: *cdiiddwpgswtgt*. If we try to input this string to log as *flag00*,  
-> `su flag00`  
It'll print an authentication failure. Therefore, the password might be encrypted.

> The **ROT (Ceasar) Cipher** is the simplest and most known encryption technique in cryptography. It encrypt a password by substituting the letters based on a shift of N letter in the alphabet.

With the help of this [decrypter](https://www.dcode.fr/rot-cipher), we get the following password: *nottoohardhere*.

Finally, we just have to log on flag00 to get the flag and advanced to level01.  
-> `su flag00`  
> Copy and paste **nottoohardhere**.  

-> `getflag`  
-> `su level01`
