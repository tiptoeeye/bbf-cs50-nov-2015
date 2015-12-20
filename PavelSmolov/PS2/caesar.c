#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>


//'a'-'z' 97 - 122; 'A'-'Z' 65 - 90 -for information only.

string algROT (string ofSomething, int _ROT)
{
    string str = ofSomething;
    int ROT = _ROT;
    for (int i = 0, n = strlen(str);i < n; i++)
    {
        int tokenID = str[i];
        if (tokenID >= 'a' && tokenID <= 'z' ){
            tokenID = str[i] + ROT;
            if (tokenID > 'z') {
                tokenID += 'a' - 'z' -1;
            }
        }else if( tokenID >= 'A' && tokenID <= 'Z') {
            tokenID = str[i] + ROT;
            if (tokenID > 'Z') {
                tokenID += 'A' - 'Z' -1;
            }
        }
        str[i] = tokenID;
    }
    
    return str;
}


int main(int argc, string argv[])
{
    int ROT;
    string toCrypto;
    
    //to check wether user input is correct
    if(argv[1] == NULL || atoi(argv[1]) <= 0)
    {
        printf("Invalid input! Please enter a number, try again.\n");
        return 1;
    }
    
    /*loop in order to get positive number
    */ 
    do
    {
        ROT = atoi(argv[1]);
    } while(ROT < 0 );
    
    if (ROT > 26) {
        do {
            ROT -= 26;
        }while(ROT >= 26);
    }
    
    printf("Please provide your text on the next line: \n");
    toCrypto = GetString();
    
    string outcome = algROT(toCrypto,ROT);
    printf("%s\n",outcome);
    
    return 0;
}






