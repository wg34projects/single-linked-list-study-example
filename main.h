#ifndef _main_
#define _main_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAGLENGTH 255  // max stringlength
#define DEBUG 0

/* Single Linked List */

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
};

int addSLLhead(MP3TAG **pH, int cnt);  // add always as first
int addSLLend(MP3TAG **pH, int cnt);  // add always as last
int addSLLsort1(MP3TAG **pH, int cnt); // add sorted band after first match
int addSLLsort2(MP3TAG **pH, int cnt); // add sorted band before first match
int delSLLitem(MP3TAG **pH, int id);  // delete nodes
int getYears(MP3TAG *pH); // sums all years of a given band
void showSLLall1(MP3TAG *pH);  // list tail to head
void showSLLall2(MP3TAG *pH);  // list head to tail
void showSLLall3(MP3TAG *pH);  // list by given band
void freeSLL(MP3TAG **pH);  // cleaning up

#endif // _main_
