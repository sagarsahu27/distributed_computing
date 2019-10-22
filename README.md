# distributed_computing
repository for writing basic distributed computing programs from Distributed computing class

## Calculator App using RPC

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

###########################################

## Sample app based on Lamport logical code

Steps to compile task
  gcc src.c -o lamport

Sample usage:
./lamport

 enter the no of events (Max 9)

4

 enter the no of send-receive message between p1, p2 and p3

2

Enter details for Message 1 

```<sender pid> <sender event> <receiver pid> <receiver event>```

1 2 2 2

Enter details for Message 2 

```<sender pid> <sender event> <receiver pid> <receiver event>```

3 1 2 3

Timestamps of processes are:

**---<`E1`>---<`E2`>---<`E3`>---<`E4`>

P1---< 4>---< 7>---<10>---<13>

P2---< 4>---<10>---<13>---<16>

P3---< 4>---< 7>---<10>---<13>