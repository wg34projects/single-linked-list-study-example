#include "main.h"

int main()
{
    int dllCount = 0;  // variable to give every dataset an ID
    char cont = 'a';
    int del = 0;
    MP3TAG *pHead = NULL;  // main structure which we will pass to the function
    MP3TAG *pTail = NULL;  // main structure which we will pass to the function
    int years = 0;

    printf("Double Linked List Example - by Helmut\n\n");
    printf("please don't use SPACE, I don't check for it\n");

    printf("(a)dd / e(x)it > ");
    cont = fgetc(stdin);
    getchar();

    if(cont != 'a')  // if not a we leave
    {
        exit(EXIT_SUCCESS);
    }

    addDLLhead(&pHead, &pTail, dllCount);  // ad first data

    while(1)
    {

        printf("\n(a)add@head (b)add@tail (e)add@band-before match\n");
        printf("(p)print@head-tail (q)print@tail-head / (d)delete node by ID\n");
        printf("(m)count years of all albums per band\n");
        printf("(n)print only albums of a band\n");
        printf("(w)change 2 nodes by ID\n");
        printf("(x)exit > ");
        cont = fgetc(stdin);
        getchar();

        if(cont == 'x') // exit if wished
        {
            break;
        }

        if(cont == 'd') // delete dataset by ID
        {
            printf("enter dataset ID you want to delete > ");
            scanf("%d", &del);
            getchar();
            delDLLitem(&pHead, &pTail, del);
        }

        if(cont == 'p')
        {
            showDLLall1(pHead, pTail);  // show on screen all datasets
        }

        if(cont == 'q')
        {
            showDLLall2(pHead, pTail);  // show on screen all datasets
        }

        if(cont == 'a')  // add dataset to the head
        {
            dllCount++;
            addDLLhead(&pHead, &pTail, dllCount);
        }

        if(cont == 'b')  // add dataset to the bottom, this is tricky with single linked list
        {
            dllCount++;
            addDLLend(&pHead, &pTail, dllCount);
        }

        if(cont == 'e')  // add dataset before first appearance of same bandname, no sorting, tricky with single linked list
        {
            dllCount++;
            addDLLsort(&pHead, &pTail, dllCount);
        }

        if(cont == 'm')
        {
            years = getYears(pHead);
            printf("\nTOTAL %d YEARS\n", years);
        }

        if(cont == 'n')
        {
            showDLLall3(pHead);
        }

        if(cont == 'w')
        {
            changeNodes(&pHead, &pTail);
        }
    }

    freeDLL(&pHead, &pTail); // clean up before exit

    return 0;
}
