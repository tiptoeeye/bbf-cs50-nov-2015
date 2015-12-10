#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float f;
    do //программа работает до ввода числа 932
    {
        printf("Please enter a sum of change, which must have no more than two digits after comma:\n");
        f = GetFloat();
 
    printf("The sum of change is %.2f\n", f);
    int cents = f * 100;
    int quarters = cents/25;
    int dimes = (cents%25)/10;
    int nickels = (((cents%25)%10)/5);
    int remaining_cents = ((cents%25)%10)%5;
printf("Take out");
//дале следуют варианты вывода результатов в зависимости от комбинаций монет
if (quarters!=0) printf (" %i quarters", quarters);
if (dimes!=0&&(quarters!=0&&(nickels!=0||remaining_cents!=0))) printf (", %i dimes", dimes);
if (dimes!=0&&(quarters!=0&&nickels==0&&remaining_cents==0)) printf (" and %i dimes", dimes);
if (dimes!=0&&(quarters==0&&(nickels!=0||remaining_cents!=0))) printf (" %i dimes", dimes);
if (nickels!=0&&((quarters!=0||dimes!=0)&&remaining_cents!=0)) printf (", %i nickels", nickels);
if (nickels!=0&&(quarters!=0||dimes!=0)&&remaining_cents==0) printf (" and %i nickels", nickels);
if (nickels!=0&&(quarters==0&&dimes==0&&remaining_cents==0)) printf (" %i nickels", nickels);
if (remaining_cents!=0&&(quarters!=0||dimes!=0||nickels!=0)) printf (" and %i cents",remaining_cents);
if (remaining_cents!=0&&(quarters==0&&dimes==0&&nickels==0)) printf (" %i cents",remaining_cents);
printf ("\n\n");
   }
    while (f<=0||f!=932); //932 - контрольное значение для выхода из программы
}

