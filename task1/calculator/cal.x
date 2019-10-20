struct variable
{
int x; int y; int ans; int choice;
};
struct response
{
    int *res;
    int *error;
};
program calc_prg
{
 version calc_version
 {
 response calc(variable)=1;
 }=1;
}=0x32345676;