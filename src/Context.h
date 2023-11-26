#ifndef CONTEXT_H__
#define CONTEXT_H__
#include "time.h"

typedef struct Context {
    int arr[10];

    time_t last_time;
    /////////////////////////////////////////box
    Box boxarr[9]; // 中数量  数组下标 数组长度
    Box box;
    int arrboxlength;
    Vector2 boxstart;
    int boxwidth;
    int boxheight;
    int boxgap;
    int boxindex;
    /// //// //////////////////////Di
    Di dishu;
    Di diarr[9];
    Di diarrpos[9];
    Vector2 distart;
    int arrlength;
    int diindex;
    int cur_rd;
    int last_rd;
    int dicount;

} Context;

#endif