#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("Key word:\n");
    string key = GetString();
    printf("Encrypt:\n");
    string text = GetString();
    int index = 0;
    for(int i=0, n=strlen(text); i<n; i++)
    {
        if((text[i]>='a' && text[i]<='z') || 
            (text[i]>='A' && text[i]<='Z') )
        {
            char shift='a';
            if(text[i]>='A' && text[i]<='Z')
                shift = 'A';
            int encChar = (text[i]-shift + key[index]-shift)%26 + shift;
            printf("%c", encChar);
            if(index==strlen(key)-1)
                index = 0;
            else
                index++;
        }
    }
    return 0;
}
