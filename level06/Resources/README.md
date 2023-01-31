## LEVEL 06

First of all, let's take a look on the files we have.  
-> `ls -la` or `la`  
As we can see, we have 2 files:
* *level06.php*
* *level06*

So, we have a PHP script and its executable. If we open up the PHP file,  
-> `cat level06.php`  
We can notice few things:  
1. It contains 2 functions
2. Both functions uses *Regex*
3. The program takes 2 arguments

> **Regex** is a sequence of characters that forms a search pattern. It can be used to search or replace some text. *Regex* syntax starts with delimiter that are character that are not letters, the most commonly used is '/'.

Then, if we launch the executable with arguments,  
-> `./level06 test flag`  
We get an error on the output that says it failed to open 'test'. Therefore, the program takes 2 arguments, open the first one and store its content then change it with *Regex*.  
With the help of this [cheat sheet](https://quickref.me/regex), we can see that the function is looking for an 'x' followed by any characters in square bracket, to replace it with a call to the function *y* and take as parameters all the content after the 'x'.

> The **exec** function in PHP executes an external program that can be a binary file.

Then, we set the permission to create a file and use the syntax of *Regex* to exploit this file.  
-> `chmod 777 .`  
-> `echo '[x {${exec(getflag)}}]' > flag`  
-> `./level06 flag`

We can now move to the next level with the flag.  
-> `su level07`