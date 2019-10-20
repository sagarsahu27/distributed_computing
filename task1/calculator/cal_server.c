#include "cal.h"
int isprime(int a)
{
int i;
for(i=2;i<=a/2;i++)
 {if(a%i==0)
 {break;}}
if(i==a/2+1)
{
printf("\nYES\n");
return 1;
}
else
{
printf("\nNO\n");
return 0;
}
}
struct response *calc_1_svc(variable *argp, struct svc_req *rqstp)
{
 static int result;

/*
  err_code:
  0 -> no error
  1 -> divide by zero
  2 -> integer overflow
*/
 static int err_code=0;
 static struct response resp;
 switch(argp->choice)
{
 case 1:
{
  result=(argp->x)+(argp->y);
  // Check for integer overflow
  err_code = ((result < argp->x) || (result < argp->y))*2;
  break;
}
 case 2:
{
  result=(argp->x)*(argp->y);
  // Check for integer overflow
  if (( argp->x != 0) && (argp->y !=0)) {
    err_code = ((result < argp->x) || (result < argp->y))*2;
  }
  break;
}
 case 3:
{
    result=(argp->x)-(argp->y);
    // Check for integer overflow
    err_code = ((result < argp->x) || (result < argp->y))*2;
     break;
}
 case 4:
 {
    // Check for divide by zero
    err_code = ( argp->y == 0);
    if (!err_code) {
        result=(argp->x)/(argp->y);
    }
    break;
 }
 case 5:
 {
    // Check for divide by zero
    err_code = ( argp->y == 0);
    if (!err_code) {
        result=(argp->x)%(argp->y);
    }
    break;
 }
 case 6:
 {
    result=isprime(argp->x);
    break;
 }
 case 7:
 {
     result= !(((argp->x)%2) ^ ((argp->y)%2));
 }
}
  resp.res = &result;
  resp.error = &err_code;
 return &resp;
}