#include "main.h"

int addSLLhead(MP3TAG **pH, int cnt)
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
        *pH = pAct;
    }
    else // every other dataset will be shifted to the beginning
    {
        pAct->pNext = *pH;
        *pH = pAct;
    }

    return 0;
}

int addSLLend(MP3TAG **pH, int cnt)
{
    char title[MAXTAGLENGTH];
    char band[MAXTAGLENGTH];
    char genre[MAXTAGLENGTH];
    char album[MAXTAGLENGTH];
    int year = 0;
    int tempLength = 0;
    MP3TAG *pAct;
    MP3TAG *pHistory;

    pHistory = *pH;  // history pointer needed, in single linked list no previous pointer available

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
        *pH = pAct;

    }
    else // for every other dataset
    {
        while(1)
        {
            if(pHistory->pNext != NULL) // iterate to the end of the list, that's why continue
            {
                pHistory = pHistory->pNext;
                continue;
            }

            if(pHistory->pNext == NULL) // if on the end used saved history pointer to add data to the end
            {
                pHistory->pNext = pAct;
                pAct->pNext = NULL;
                break;
            }
        }
    }

    return 0;
}

int addSLLsort1(MP3TAG **pH, int cnt)
{
    char title[MAXTAGLENGTH];
    char band[MAXTAGLENGTH];
    char genre[MAXTAGLENGTH];
    char album[MAXTAGLENGTH];
    int year = 0;
    int tempLength = 0;
    MP3TAG *pAct;
    MP3TAG *pHistory;

    pHistory = *pH;  // history pointer needed, in single linked list no previous pointer available

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
        *pH = pAct;

    }
    else  // for every other dataset
    {
        while(1)
        {
            if(strcmp(pAct->band, pHistory->band) == 0) // process when match was found
            {
                if(pHistory->pNext != NULL)  // if not at the end history and actual are changed
                {
                    pAct->pNext = pHistory->pNext;
                    pHistory->pNext = pAct;
                    break;
                }
                else  // if at the end history and acutal are changed, actual must be set to NULL as new end
                {
                    pAct->pNext = NULL;
                    pHistory->pNext = pAct;
                    break;
                }
            }

            else // process when no match was found
            {
                if(pHistory->pNext != NULL) // if not on the end of the list next iteration, that's why continue
                {
                    pHistory = pHistory->pNext;
                    continue;
                }
                if(pHistory->pNext == NULL) // if at the end and finally no match data will be added at the header
                {
                    pAct->pNext = *pH;
                    *pH = pAct;
                    break;
                }
            }
        }
    }

    return 0;
}

int addSLLsort2(MP3TAG **pH, int cnt)
{
    char title[MAXTAGLENGTH];
    char band[MAXTAGLENGTH];
    char genre[MAXTAGLENGTH];
    char album[MAXTAGLENGTH];
    int year = 0;
    int tempLength = 0;
    MP3TAG *pAct;
    MP3TAG *pHistory;
    MP3TAG *pBefore;

    pHistory = *pH;  // history pointer needed, in single linked list no previous pointer available
    pBefore = *pH;  // just to initalize

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
        *pH = pAct;

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
                    *pH = pAct;
                    break;
                }

                if(pBefore != pHistory)  // if match in the middle, the pointer before gets new adress and data before first match
                {
                    pBefore->pNext = pAct;
                    // pAct->pNext = pBefore->pNext; revised 13.01
                    pAct->pNext = pHistory;
                    break;
                }
            }

            else // process when no match was found
            {

                if(pHistory->pNext != NULL) // if not on the end of the list next iteration, that's why continue
                {
                    pBefore = pHistory; // safe pointer before
                    pHistory = pHistory->pNext;
                    // continue; revised 13.01
                }
                //if(pHistory->pNext == NULL) // revised 13.01
                else // if at the end and finally no match data will be added at the header
                {
                    pAct->pNext = *pH;
                    *pH = pAct;
                    break;
                }
            }
        }
    }

    return 0;
}

int delSLLitem(MP3TAG **pH, int id)
{
    MP3TAG *pAct;
    MP3TAG *pHistory;

    pAct = *pH;
    pHistory = *pH; // needed for simple linked list as no previous pointer is available, only way I could find out if it is first item in list

    while(1)
    {
        if(pAct->dataSet == id) // if correct ID was found delete
        {
            if(pAct == pHistory && pAct->pNext != NULL)  // procedure for first item in the list
            {
                *pH = pAct->pNext;
                free(pAct);
                break;
            }
            else if(pAct != pHistory && pAct->pNext != NULL) // procedure for item in the middle of the list
            {
                pHistory->pNext = pAct->pNext;
                free(pAct);
                break;
            }
            else if(pAct != pHistory && pAct->pNext == NULL) // procedure for item at the end of the list
            {
                pHistory->pNext = NULL;
                free(pAct);
                break;
            }
            else // procedure for list without any item
            {
                *pH = NULL;
                free(pAct);
                break;
            }
        }
        else
        {
            if(pAct->pNext != NULL)  // save history and prepare next iteration, we go through the list, iteration with continue
            {
                pHistory = pAct;
                pAct = pAct->pNext;
                continue;
            }
            if(pAct->pNext == NULL) // if we are at the end of the list we break
            {
                break;
            }
        }
    }

    return 0;
}

void showSLLall1(MP3TAG *pH)
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
        if (pAct->pNext == NULL)
        {
            break;
        }
        else
        {
            pAct = pAct->pNext; // next iteration
        }
    }
}

void showSLLall2(MP3TAG *pH)
{
    MP3TAG *pAct;
    MP3TAG *pHistory;
    MP3TAG *pSave;
    pAct = pH;
    pHistory = pH; // just to initialize
    pSave = pH;

    if (pH == NULL)
    {
        printf("no data added up to now, so nothing to show :-(\n");
        return;
    }

    if (pAct->pNext == NULL) // only 1 item in list print and break
    {
        printf("\nDATASET ID %d\n", pAct->dataSet);
        printf("-----------------------------\n");
        printf("  BAND: %s\n", pAct->band);
        printf(" ALBUM: %s\n", pAct->album);
        printf(" TITLE: %s\n", pAct->title);
        printf(" GENRE: %s\n", pAct->genre);
        printf("  YEAR: %d\n\n", pAct->year);
        return;
    }

    while(pHistory->pNext != NULL)
    {
        pHistory = pHistory->pNext;
    }

    printf("history %d\n", pHistory->dataSet);

    while(1)
    {
        pAct = pH;

        while(1)
        {
            if (pAct->pNext == pHistory)
            {
                pSave = pAct;
            }

            if (pAct == pHistory)
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

            pAct = pAct->pNext; // next iteration
        }

        pHistory = pSave;

        if (pHistory == pH)
        {
            printf("\nDATASET ID %d\n", pH->dataSet);
            printf("-----------------------------\n");
            printf("  BAND: %s\n", pH->band);
            printf(" ALBUM: %s\n", pH->album);
            printf(" TITLE: %s\n", pH->title);
            printf(" GENRE: %s\n", pH->genre);
            printf("  YEAR: %d\n\n", pH->year);
            break;
        }
    }
}

void freeSLL(MP3TAG **pH)
{
    MP3TAG *pAct;

    if (*pH == NULL)
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
            break;
        }
        else
        {
            *pH = pAct->pNext;
            free(pAct);
        }
    }
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

void showSLLall3(MP3TAG *pH)
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
