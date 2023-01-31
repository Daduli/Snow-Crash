## LEVEL01

Firstly, we're looking for files that we can use,  
-> `ls -la` or `la`  
As we can see, there's nothing here. As same as the last level, we're going to check at the root of the virtual machine.  
-> `cd /`

> On Linux, the passwords of users are stored in the **/etc/passwd** file. It contains all the informations required during login.

Next, we look up the content of */etc/passwd*,  
-> `cat /etc/passwd`

> The information in the */etc/passwd* file are listed as follow:  
**username:password** [...]  
The password is replaced with an *'x'* to indicate that it is encrypted. 

Secondly, we will search for the password for *flag01* and we can notice that it is *42hDRfypTqqnw*. Then, we log on *flag01*.  
-> `su flag01`  
However, the password doesn't work and it seems that the password is once again encrypted.

> The **/etc/shadow** file contains all the encrypted user passwords but is only accessible by the root.  
**/etc/login.defs** is a configuration file that set up the rule for the */etc/shadow* password suite.

We print the content of */etc/login.defs* to see how the password is encrypted.  
-> `cat /etc/login.defs`  
We can notice *ENCRYPT_METHOD SHA512* on line 279. Accordingly, the password is encrypted using SHA512.

> **SHA512** is an encryption function of *SHA-2*, that uses 512 bits. The *SHA-2* encrypt passwords by using different shift amounts and additive constants differing on the number of rounds between *SHA-224*, *SHA-256*, *SHA-384* and *SHA-512*.

To decrypt the password, we will need to use a decrypter for SHA512, named *John the Ripper*. So, we are going to install *Kali Linux* to have access to the decrypter.

> **Kali Linux** is a virtual machine that is specialized in *penetration testing* and *security auditing*. It has all the applications and features needed for security testing.

Thirdly, we install [Kali Linux](https://www.kali.org/get-kali/#kali-virtual-machines) in our *goinfre* directory. Once, it is installed, we have to unzip it using *7zz*,  
-> `7zz e {ISO_file}`  
Then, we add a virtual machine and select the *.vbox* file. After launching *Kali Linux*, we decrypt the password with *John the Ripper*,  
-> `echo 42hDRfypTqqnw > token`  
-> `john token`

And we should get *abcdefg* after the decryption, we just to have to log on flag01 with it.  
-> `su flag01`  
-> `getflag`  
-> `su level02`