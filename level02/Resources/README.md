## LEVEL 02

First, we search for files that we can use.  
-> `ls -la` or `la`  
We notice that we have one file named *level02.pcap*.

> **.pcap** *(packet capture)* file extension is used to store the packet data of a network and contains all the exchange done in the network. It is used for analyzing the network characteristics of a certain data.  
**Wireshark** is a program used to analyze network.

Next, we transfer *level02.pcap* onto our local directory.  
-> `scp -P 4242 level02@{VM_ip}:level02.pcap .`  
And we need to set the permission to read the file before using *Wireshark* to analyze.  
-> `chmod +r level02.pcap`

> Wireshark **packet analyzing** have 3 panes:  
The top pane is the *Packet List*, it lists all the packets in the capture.  
The middle pane is the *Packet Details*, it shows as much readable information about the packet as possible, depending on the packet type.  
The bottom pane is the *Packet Bytes*, it displays the packet exactly as it was captured in hexadecimal.

On the Packet List pane, we can notice:
* In the *Source* and *Destination* tab, that we only have 2 ip.
* In the *Info* tab, *PSH* and *ACK*.

> **ACK** means that the machine is sending a packet to say that it has acknowledged all the data it has receive from the other machine.  
**PSH** means that the machine is sending data that the receiver doesn't have.

If we use the *ip.src=={ip}* filter, we can see that one ip is sending the password to the other. And if we concatenate the message that *59.233.235.218* is sending, we have: *ft_waNDReL0L*.  
Finally, we connect to *flag02* using this password.  
-> `su flag02`  
-> `getflag`  
-> `su level03`