#ifndef CONTROLLER_H__
#define CONTROLLER_H__
#include "stdio.h"
#include "..\include\raylib.h"
#include "DiEntity.h"
#include "time.h"
#include "Context.h"

// ///////////////////////////////////////////////
void ArrShift_Time(Context *ctx, int arrlength) {
    if (arrlength > 10) {
        return;
    }

    time_t current_time = time(NULL);

    if (current_time - ctx->last_time >= 2) {
        arrlength++;

        for (int i = 0; i < arrlength; i++) {
            ctx->arr[i] = i + 1;

            printf("%d\r\n", ctx->arr[i]);
        }

        ctx->last_time = current_time;
    }
}
////////////////////////////////////////////////////////左移
void ArrShift_Left(int *arr, Context *ctx) {
    if (IsKeyPressed(KEY_SPACE)) {
        ctx->arrlength = ctx->arrlength - 1;
        printf("%d", ctx->arrlength);
        for (int i = 0; i < ctx->arrlength; i++) {
            arr[i] = arr[i + 1];
        }
    }
}
///////////////////////////////////////////////////////交换//没试
void Arr_Swap(int *arr, Context *ctx) {
    if (IsKeyPressed(KEY_SPACE)) {
        int b = arr[0];
        arr[0] = arr[ctx->arrlength - 1];
        arr[ctx->arrlength - 1] = b;
        ctx->arrlength = ctx->arrlength - 1;
        ////////////////////每个变量要初始化 就是赋值
    }
}

void Arr_Add(int *arr, Context *ctx) {

    if (IsKeyPressed(KEY_SPACE)) {
        ctx->arrlength += 1;
        for (int i = 0; i < ctx->arrlength; i++) {
            arr[i] = i + 1;
            printf("%d\r\n", arr[i]);
        }
    }
}

void Arr_SwapCount(int *arr, int arrlength, int i) {
    int tmp = arr[i];
    arr[i] = arr[arrlength - 1];
    arr[arrlength - 1] = tmp;
    arrlength = arrlength - 1;
}

#endif