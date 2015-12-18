#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{

    float a;
    int n;
    printf("How much change, sir?\n");
    //scanf("%d", &n);
    
    //GetInt();
    
    
    for(scanf("%f", &a); a<=0; scanf("%f", &a))
    {
        printf("Common! I need a positive number\n");}
        //a=roundf(a * 100) / 100;
       //a=  roundf (a); // how to round the numbers?
       // printf ("%f", a);
        
        
        n=a*100;
        
        //round (n);
        
        int quaters;
        quaters = 0;
        int dimes;
        dimes = 0;
        int nickel;
        nickel = 0;
        int cent;
        cent = 0;
        int total;
        int change;
        int change1;
        int change2;

        //int change1;6
        //change=n;
        
    if (n>=25) {
        quaters = n/25;
        change=n%25;
        if (quaters>1)
            printf ("%d quaters \n", quaters);
        else 
            printf ("%d quater \n", quaters);
    }
    
    else change=n; 
        
        if (change>=10) {
        dimes = change/10;
        change1=change%10;
    if (dimes>1){
    printf ("%d dimes \n", dimes);}
    else printf ("%d dime \n", dimes);}
    
    else change1=change; 
        if (change1>=5) {
        nickel = change1/5;
        change2=change1%5;
    if (nickel>1){
    printf ("%d nikels \n", nickel);}
    else printf ("%d nikel \n", nickel);}
    
    else change2=change1;
        cent = change2/1;
    if (cent>1){
    printf ("%d cents \n", cent);
    }
    else printf ("%d cent \n", cent);
    
    total = quaters+dimes+nickel+cent;
    printf("Total: %d coins \n", total);
    
    //}
    
      
    
    return 0;
}
