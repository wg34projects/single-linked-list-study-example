#ifndef _main_
#define _main_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAGLENGTH 255  // max stringlength
#define DEBUG 0

/* Double Linked List */

typedef struct mp3tag MP3TAG;

struct mp3tag
{
    char title[MAXTAGLENGTH];
    char band[MAXTAGLENGTH];
    char genre[MAXTAGLENGTH];
    char album[MAXTAGLENGTH];
    int year;
    int dataSet;
    MP3TAG *pNext;
    MP3TAG *pPrev;
};

int addDLLhead(MP3TAG **pH, MP3TAG **pT, int cnt); // add at head
int addDLLend(MP3TAG **pH, MP3TAG **pT, int cnt); // ad at tail
int addDLLsort(MP3TAG **pH, MP3TAG **pT, int cnt); // add before match band
int delDLLitem(MP3TAG **pH, MP3TAG **pT, int id); // del nodes
void showDLLall1(MP3TAG *pH, MP3TAG *pT);  // show head to tail
void showDLLall2(MP3TAG *pH, MP3TAG *pT); // show tail to head
void freeDLL(MP3TAG **pH,  MP3TAG **pT);  // cleanup
int getYears(MP3TAG *pH); // sums all years of a given band
void showDLLall3(MP3TAG *pH);  // list by given band
void changeNodes(MP3TAG **pH, MP3TAG **pT);

#endif // _main_

