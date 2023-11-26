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
    Vector2 start;
    int boxwidth;
    int boxheight;
    int boxgap;
    int boxindex; ////////

    Di diarr[8];

    int arrlength;

} Context;

#endif