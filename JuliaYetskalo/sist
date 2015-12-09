#include <stdio.h>
#include <cs50.h>

int main(int argc, char **argv)
{
    printf("Enter a non-negative integer number: \n");
    int n;
    n=GetInt();
    while (n<=0) {
   printf("You have entered a negativ number or 0 ,please try again: \n");
    n=GetInt();}
    int i;
    int j=1;
    int a=1;
    int k=0;
    for (i=n;i>0;i=i/2) {
       k=j;
        a=a*10;
    if (i%2==0) { 
    j=a+j%(a/10); };
     if (i%2==1) {   j=a+j;};
     
    }
     printf("%i",j%a);
    return 0;
}
