#include "cal.h"
void calc_prg_1(char *host)
{
 CLIENT *clnt;
 struct response *result_1;
 char num1[24], num2[24];
 int n1, n2;
 variable calc_1_arg;
 clnt = clnt_create (host, calc_prg, calc_version, "udp");
 if (clnt == NULL) {
 clnt_pcreateerror (host); exit (1);
 }
printf("\n1 addition \n2.multiplication \n3.subtraction \n4.division\n5.remainder \n6.is first number prime\n7. Are both evan or both Odd\nenter choice : ");
scanf("%d",&calc_1_arg.choice);
printf("enter values");
scanf("%s %s",num1,num2);
n1 = atoi(num1);
n2 = atoi(num2);
    if (n1 == 0 && num1[0] != '0') {
      printf("First input argument is not valid integer\n");
      exit(1);
    }
    if (n2 == 0 && num2[0] != '0') {
      printf("Second input argument is not valid integer\n");
      exit(1);
    }
    calc_1_arg.x = n1;
    calc_1_arg.y = n2;
    
 result_1 = calc_1(&calc_1_arg, clnt);
 if (result_1 == (struct response *) NULL) {
 clnt_perror (clnt, "call failed");
 }

 if (*(result_1->error)) {
     if (*(result_1->error) == 1)
     {
        printf("\ndivide by zero error, second input not valid\n");
     } else if (*(result_1->error) == 2)
     {
        printf("\ninteger overflow, given arguments cause integer overflow\n");
     }
     exit(1);
 }

if(calc_1_arg.choice < 6)
 printf("Your result is %d\n",*(result_1->res));
else if(calc_1_arg.choice>=6 && *(result_1->res)==1)
 printf("\nYES\n");
 else
 printf("\nNO\n");
clnt_destroy (clnt);
}

int main (int argc, char *argv[])
{
 char *host;
 if (argc < 2) {
 printf ("usage: %s server_host\n", argv[0]);
 exit (1);
 }
 host = argv[1];
 calc_prg_1 (host);
exit (0);
} 