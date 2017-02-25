# single-linked-list-study-example
Single linked list code as training before 2nd examn C-coding WS2016 - lot of functions

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
