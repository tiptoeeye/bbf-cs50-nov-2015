#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, char **argv)
{
    //printf("Input=%s\n", argv[1]);
    string s = "";
    //do
    //{
        printf("Give me something:\n");
        s = GetString();
        string word = "";
        int flag = 0;
        for(int i=0, n=strlen(s); i<n; i++)
        {
            if((char)s[i] != ' ')
            {
                if(flag == 0)
                {
                    printf("%c", toupper(s[i]));
                    flag = 1;
                }
                else
                    printf("%c", s[i]);
            }
            else
            {
                printf("\n");
                //word = "";
                flag = 0;
            }        
        }
    //}while(s[0] != '\n');
    return 0;
}
