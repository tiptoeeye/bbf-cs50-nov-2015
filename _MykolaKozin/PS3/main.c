#include <stdio.h>


void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int count, int values[])
{
    for(int i=1; i<count; i++)
    {
           int j = i;
           //int element = values[j];
           while(values[j]<values[j-1] && j>0)
           {
               swap(&values[j], &values[j-1]);
               j--;
           }
    }
}

int main(int argc, char **argv)
{
    int values[] = {9,8,7,4,1};
    sort(5, values);
    for(int i=0; i<5; i++)
        printf("%d", values[i]);
    return 0;
}
