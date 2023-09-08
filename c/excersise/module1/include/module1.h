#ifndef MODULE1_H
#define MODULE1_H
#include<time.h>
struct teacher{
    int name;
    int group;
    int size;
    time_t tval;
};

void setname(struct teacher *t );
void setgroup(struct teacher *t);
int getsize(struct teacher *t);
void timemod(struct teacher *t);

#endif