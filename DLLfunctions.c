#include "main.h"

int addDLLhead(MP3TAG **pH, MP3TAG **pT, int cnt)
{
    char title[MAXTAGLENGTH];
    char band[MAXTAGLENGTH];
    char genre[MAXTAGLENGTH];
    char album[MAXTAGLENGTH];
    int year = 0;
    int tempLength = 0;
    MP3TAG *pAct;

    pAct = (MP3TAG *) malloc (1 * sizeof(MP3TAG));
    if(pAct == NULL)
    {
        perror("couldn't allocate memory, exit\n");
        exit(EXIT_FAILURE);
    }

    pAct->dataSet = cnt;

    printf("\nDATASET ID %d\n", cnt);
    printf("-----------------------------\n");

    printf(" TITLE: ");
    scanf(" %s", title);
    tempLength = strlen(title);
    title[tempLength] = '\0' ;
    strncpy(pAct->title, title, tempLength);
    pAct->title[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->title);
#endif // DEBUG
    tempLength = 0;

    printf("  BAND: ");
    scanf(" %s", band);
    tempLength = strlen(band);
    band[tempLength] = '\0' ;
    strncpy(pAct->band, band, tempLength);
    pAct->band[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->band);
#endif // DEBUG
    tempLength = 0;

    printf(" GENRE: ");
    scanf(" %s", genre);
    tempLength = strlen(genre);
    genre[tempLength] = '\0' ;
    strncpy(pAct->genre, genre, tempLength);
    pAct->genre[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->genre);
#endif // DEBUG
    tempLength = 0;

    printf(" ALBUM: ");
    scanf(" %s", album);
    tempLength = strlen(album);
    album[tempLength] = '\0' ;
    strncpy(pAct->album, album, tempLength);
    pAct->album[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->album);
#endif // DEBUG
    tempLength = 0;

    printf("  YEAR: ");
    scanf("%d", &year);
    pAct->year = year;

    tempLength = 0;
    getchar();

    if(*pH == NULL) // if this is first dataset
    {
        pAct->pNext = NULL;
        pAct->pPrev = NULL;
        *pH = pAct;
        *pT = pAct;
    }
    else // every other dataset will be shifted to the beginning
    {
        pAct->pNext = *pH;
        pAct->pPrev = NULL;
        (*pH)->pPrev = pAct; // this is the tricky thing in double linked list, catch the previous adress in actual head pointer
        *pH = pAct;
    }

    return 0;
}

void freeDLL(MP3TAG **pH, MP3TAG **pT)
{
    MP3TAG *pAct;

    if (*pH == NULL && *pT == NULL)
    {
        printf("no data added up to now, so nothing to free :-)\n");
        return;
    }

    while(1)
    {
        pAct = *pH;

        if(pAct->pNext == NULL)
        {
            free(pAct);
            *pH = NULL;
            *pT = NULL;
            break;
        }
        else
        {
            *pH = pAct->pNext;
            free(pAct);
        }
    }
}

void showDLLall1(MP3TAG *pH, MP3TAG *pT)
{
    MP3TAG *pAct;

    if (pH == NULL)
    {
        printf("no data added up to now, so nothing to show :-(\n");
        return;
    }

    pAct = pH;

    while(1) // break of the loop if pNext = NULL
    {
        printf("\nDATASET ID %d\n", pAct->dataSet);
        printf("-----------------------------\n");
        printf("  BAND: %s\n", pAct->band);
        printf(" ALBUM: %s\n", pAct->album);
        printf(" TITLE: %s\n", pAct->title);
        printf(" GENRE: %s\n", pAct->genre);
        printf("  YEAR: %d\n\n", pAct->year);
        if (pAct == pT)
        {
            break;
        }
        else
        {
            pAct = pAct->pNext; // next iteration
        }
    }
}

void showDLLall2(MP3TAG *pH, MP3TAG *pT)
{
    MP3TAG *pAct;

    if (pT == NULL)
    {
        printf("no data added up to now, so nothing to show :-(\n");
        return;
    }

    pAct = pT;

    while(1) // break of the loop if pNext = NULL
    {
        printf("\nDATASET ID %d\n", pAct->dataSet);
        printf("-----------------------------\n");
        printf("  BAND: %s\n", pAct->band);
        printf(" ALBUM: %s\n", pAct->album);
        printf(" TITLE: %s\n", pAct->title);
        printf(" GENRE: %s\n", pAct->genre);
        printf("  YEAR: %d\n\n", pAct->year);
        if (pAct == pH)
        {
            break;
        }
        else
        {
            pAct = pAct->pPrev; // next iteration
        }
    }
}

int addDLLend(MP3TAG **pH, MP3TAG **pT, int cnt)
{
    char title[MAXTAGLENGTH];
    char band[MAXTAGLENGTH];
    char genre[MAXTAGLENGTH];
    char album[MAXTAGLENGTH];
    int year = 0;
    int tempLength = 0;
    MP3TAG *pAct;

    pAct = (MP3TAG *) malloc (1 * sizeof(MP3TAG));
    if(pAct == NULL)
    {
        perror("couldn't allocate memory, exit\n");
        exit(EXIT_FAILURE);
    }

    pAct->dataSet = cnt;

    printf("\nDATASET ID %d\n", cnt);
    printf("-----------------------------\n");

    printf(" TITLE: ");
    scanf(" %s", title);
    tempLength = strlen(title);
    title[tempLength] = '\0' ;
    strncpy(pAct->title, title, tempLength);
    pAct->title[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->title);
#endif // DEBUG
    tempLength = 0;

    printf("  BAND: ");
    scanf(" %s", band);
    tempLength = strlen(band);
    band[tempLength] = '\0' ;
    strncpy(pAct->band, band, tempLength);
    pAct->band[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->band);
#endif // DEBUG
    tempLength = 0;

    printf(" GENRE: ");
    scanf(" %s", genre);
    tempLength = strlen(genre);
    genre[tempLength] = '\0' ;
    strncpy(pAct->genre, genre, tempLength);
    pAct->genre[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->genre);
#endif // DEBUG
    tempLength = 0;

    printf(" ALBUM: ");
    scanf(" %s", album);
    tempLength = strlen(album);
    album[tempLength] = '\0' ;
    strncpy(pAct->album, album, tempLength);
    pAct->album[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->album);
#endif // DEBUG
    tempLength = 0;

    printf("  YEAR: ");
    scanf("%d", &year);
    pAct->year = year;

    tempLength = 0;
    getchar();

    if(*pH == NULL && *pT == NULL) // if this is first dataset
    {
        pAct->pNext = NULL;
        pAct->pPrev = NULL;
        *pH = pAct;
        *pT = pAct;
    }
    else // every other dataset will be shifted to the end
    {
        pAct->pPrev = *pT;
        pAct->pNext = NULL;
        (*pT)->pNext = pAct; // tricky
        *pT = pAct;
    }

    return 0;
}

int addDLLsort(MP3TAG **pH, MP3TAG **pT, int cnt)
{
    char title[MAXTAGLENGTH];
    char band[MAXTAGLENGTH];
    char genre[MAXTAGLENGTH];
    char album[MAXTAGLENGTH];
    int year = 0;
    int tempLength = 0;
    MP3TAG *pAct;
    MP3TAG *pBefore;
    MP3TAG *pHistory;

    pHistory = *pH;
    pBefore = *pH;  // just to initalize

    pAct = (MP3TAG *) malloc (1 * sizeof(MP3TAG));
    if(pAct == NULL)
    {
        perror("couldn't allocate memory, exit\n");
        exit(EXIT_FAILURE);
    }
    printf("%zu", sizeof(MP3TAG));

    pAct->dataSet = cnt;

    printf("\nDATASET ID %d\n", cnt);
    printf("-----------------------------\n");

    printf(" TITLE: ");
    scanf(" %s", title);
    tempLength = strlen(title);
    title[tempLength] = '\0' ;
    strncpy(pAct->title, title, tempLength);
    pAct->title[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->title);
#endif // DEBUG
    tempLength = 0;

    printf("  BAND: ");
    scanf(" %s", band);
    tempLength = strlen(band);
    band[tempLength] = '\0' ;
    strncpy(pAct->band, band, tempLength);
    pAct->band[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->band);
#endif // DEBUG
    tempLength = 0;

    printf(" GENRE: ");
    scanf(" %s", genre);
    tempLength = strlen(genre);
    genre[tempLength] = '\0' ;
    strncpy(pAct->genre, genre, tempLength);
    pAct->genre[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->genre);
#endif // DEBUG
    tempLength = 0;

    printf(" ALBUM: ");
    scanf(" %s", album);
    tempLength = strlen(album);
    album[tempLength] = '\0' ;
    strncpy(pAct->album, album, tempLength);
    pAct->album[tempLength] = '\0' ;
#if DEBUG
    printf("%s\n", pAct->album);
#endif // DEBUG
    tempLength = 0;

    printf("  YEAR: ");
    scanf("%d", &year);
    pAct->year = year;

    tempLength = 0;
    getchar();

    if(*pH == NULL && *pT == NULL) // if this is first dataset
    {
        pAct->pNext = NULL;
        pAct->pPrev = NULL;
        *pH = pAct;
        *pT = pAct;
    }
    else  // for every other dataset
    {
        while(1)
        {
            if(strcmp(pAct->band, pHistory->band) == 0) // process when match was found
            {
                if(pBefore == pHistory)  // if match on first position data to be added after head pointer
                {
                    pAct->pNext = *pH;
                    pAct->pPrev = NULL;
                    (*pH)->pPrev = pAct; // this is the tricky thing in double linked list, catch the previous adress in actual head pointer
                    *pH = pAct;
                    break;
                }

                if(pBefore != pHistory)  // if match in the middle, the pointer before gets new adress and data before first match
                {
                    pBefore->pNext = pAct;
                    pHistory->pPrev = pAct;
                    pAct->pNext = pHistory;
                    pAct->pPrev = pBefore;
                    break;
                }
            }

            else // process when no match was found
            {

                if(pHistory->pNext != NULL) // if not on the end of the list next iteration, that's why continue
                {
                    pBefore = pHistory; // safe pointer before
                    pHistory = pHistory->pNext;
                }
                else // if at the end and finally no match data will be added at the header
                {
                    pAct->pNext = *pH;
                    pAct->pPrev = NULL;
                    (*pH)->pPrev = pAct; // this is the tricky thing in double linked list, catch the previous adress in actual head pointer
                    *pH = pAct;
                    break;
                }
            }
        }
    }

    return 0;
}

int delDLLitem(MP3TAG **pH, MP3TAG **pT, int id)
{
    MP3TAG *pAct;

    pAct = *pH;

    while(1)
    {
        if(pAct->dataSet == id) // if correct ID was found delete
        {
            if(pAct->pPrev == NULL && pAct->pNext != NULL)  // procedure for first item in the list
            {
                *pH = pAct->pNext;
                pAct->pNext->pPrev = NULL;
                free(pAct);
                break;
            }
            if(pAct->pPrev != NULL && pAct->pNext != NULL) // procedure for item in the middle of the list
            {
                pAct->pPrev->pNext = pAct->pNext;
                pAct->pNext->pPrev = pAct->pPrev;
                free(pAct);
                break;
            }
            if(pAct->pPrev != NULL && pAct->pNext == NULL) // procedure for item at the end of the list
            {
                pAct->pPrev->pNext = NULL;
                *pT = pAct->pPrev;
                free(pAct);
                break;
            }
            if(pAct->pNext == NULL && pAct->pPrev == NULL) // procedure for list without any item
            {
                *pH = NULL;
                *pT = NULL;
                free(pAct);
                break;
            }
        }
        else
        {
            if(pAct->pPrev == NULL && pAct->pNext != NULL)  // procedure for first item in the list
            {
                pAct = pAct->pNext;
                continue;
            }
            if(pAct->pPrev != NULL && pAct->pNext != NULL) // procedure for item in the middle of the list
            {
                pAct = pAct->pNext;
                continue;
            }
            if(pAct->pPrev != NULL && pAct->pNext == NULL) // procedure for item at the end of the list
            {
                break;
            }
            if(pAct->pNext == NULL && pAct->pPrev == NULL) // procedure for list without any item
            {

                break;
            }
        }
    }

    return 0;
}

int getYears(MP3TAG *pH)
{
    MP3TAG *pAct;
    int yearSum = 0;
    char getBand[MAXTAGLENGTH];

    pAct = pH;

    printf("\n  BAND to sum the years: ");
    scanf("%s", getBand);

    getchar();

    while(1)
    {
        if(strcmp(pAct->band, getBand) == 0)
        {
            yearSum = yearSum + pAct->year;
        }

        pAct = pAct->pNext;

        if(pAct->pNext == NULL)
        {
            if(strcmp(pAct->band, getBand) == 0)
            {
                yearSum = yearSum + pAct->year;
            }
            break;
        }
    }

    return yearSum;
}

void showDLLall3(MP3TAG *pH)
{
    MP3TAG *pAct;
    char getBand[MAXTAGLENGTH];

    pAct = pH;

    printf("\n  BAND to print on screen: ");
    scanf("%s", getBand);

    getchar();

    while(1)
    {
        if(strcmp(pAct->band, getBand) == 0)
        {
            printf("\nDATASET ID %d\n", pAct->dataSet);
            printf("-----------------------------\n");
            printf("  BAND: %s\n", pAct->band);
            printf(" ALBUM: %s\n", pAct->album);
            printf(" TITLE: %s\n", pAct->title);
            printf(" GENRE: %s\n", pAct->genre);
            printf("  YEAR: %d\n\n", pAct->year);
        }

        pAct = pAct->pNext; // next iteration

        if (pAct->pNext == NULL)
        {
            if(strcmp(pAct->band, getBand) == 0)
            {
                printf("\nDATASET ID %d\n", pAct->dataSet);
                printf("-----------------------------\n");
                printf("  BAND: %s\n", pAct->band);
                printf(" ALBUM: %s\n", pAct->album);
                printf(" TITLE: %s\n", pAct->title);
                printf(" GENRE: %s\n", pAct->genre);
                printf("  YEAR: %d\n\n", pAct->year);
                break;
            }
            else
            {
                break;
            }
        }
    }
}

void changeNodes(MP3TAG **pH, MP3TAG **pT)
{
    MP3TAG *pAct;
    MP3TAG *temp1 = NULL;
    MP3TAG *temp2 = NULL;
    int node = 0;

    pAct = *pH;

    if(pAct->pNext == NULL)
    {
        return;
    }

    printf("\n  node to switch with its next when minimum 4 nodes: ");
    printf("\n  and node cant be on the beginning or the end > ");
    scanf("%d", &node);

    getchar();

    while(1)
    {
        if(pAct->dataSet == node)
        {
            if(pAct == *pH || pAct->pNext->pNext == NULL) // Abbruch wenn am Anfang oder Ende
            {
                printf("  not in the middle or less then 4 nodes\n");
                break;
            }

            pAct->pPrev->pNext = pAct->pNext;
            pAct->pNext->pNext->pPrev = pAct;

            temp1 = pAct->pNext->pNext;
            temp2 = pAct->pNext;

            pAct->pNext->pNext = pAct;
            pAct->pNext->pPrev = pAct->pPrev;

            pAct->pNext = temp1;
            pAct->pPrev = temp2;

            break;
        }
        pAct = pAct->pNext;
        if(pAct->pNext == NULL)
        {
            break;
        }
    }
}
