# distributed_computing
repository for writing basic distributed computing programs from Distributed computing class

Steps to compile calculator app:
1. rpcgen -C  cal.x
2. gcc -lnsl -o client cal_client.c cal_clnt.c cal_xdr.c
3. gcc -lrpcsvc -lnsl -o server cal_server.c cal_svc.c cal_xdr.c

Using the calculator app:
1. To start server 
   ./server
2. In another console, start client
   ./client <ip address>

Sample app menu:

1. addition 
2. multiplication 
3. subtraction 
4. division
5. remainder 
6. is first number prime
7. Are both evan or both Odd
enter choice : 2
enter values4 0
Your result is 0
