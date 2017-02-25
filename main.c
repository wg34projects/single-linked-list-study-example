#include "main.h"

int main()
{
    int sllCount = 0;  // variable to give every dataset an ID
    char cont = 'a';
    int del = 0;
    MP3TAG *pHead = NULL;  // main structure which we will pass to the function
    int years = 0;

    printf("Single Linked List Example - by Helmut\n\n");
    printf("please don't use SPACE, I don't check for it\n");

    printf("(a)dd / e(x)it > ");
    cont = fgetc(stdin);
    getchar();

    if(cont != 'a')  // if not a we leave
    {
        exit(EXIT_SUCCESS);
    }

    addSLLhead(&pHead, sllCount);  // ad first data

    while(1)
    {

        printf("\n(a)add@head (b)add@tail (c)add@band-after match (e)add@band-before match\n");
        printf("(p)print@head-tail (q)print@tail-head / (d)delete node by ID\n");
        printf("(m)count years of all albums per band\n");
        printf("(n)print only albums of a band\n");
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
            delSLLitem(&pHead, del);
        }

        if(cont == 'p')
        {
            showSLLall1(pHead);  // show on screen all datasets
        }

        if(cont == 'q')
        {
            showSLLall2(pHead);  // show on screen all datasets
        }

        if(cont == 'a')  // add dataset to the head
        {
            sllCount++;
            addSLLhead(&pHead, sllCount);
        }

        if(cont == 'b')  // add dataset to the bottom, this is tricky with single linked list
        {
            sllCount++;
            addSLLend(&pHead, sllCount);
        }

        if(cont == 'c')  // add dataset after first appearance of same bandname, no sorting, tricky with single linked list
        {
            sllCount++;
            addSLLsort1(&pHead, sllCount);
        }

        if(cont == 'e')  // add dataset before first appearance of same bandname, no sorting, tricky with single linked list
        {
            sllCount++;
            addSLLsort2(&pHead, sllCount);
        }

        if(cont == 'm')
        {
            years = getYears(pHead);
            printf("\nTOTAL %d YEARS\n", years);
        }
        if(cont == 'n')
        {
            showSLLall3(pHead);
        }
    }

    freeSLL(&pHead); // clean up before exit

    return 0;
}
