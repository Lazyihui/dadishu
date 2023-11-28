#ifndef COMMON_H__
#define COMMON_H__
#include "stdio.h"

// /////////////////////////////////////////////////给数组排序
void sort(int *arr, int length) {

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
            }
        }
    }
}

///////////////////////////////////////////////二分 有序从小到大

int Find_Binary(int *arr, int target, int arrlength) {
    int min = 0;
    int max = arrlength - 1;
    int index = -1;

    if (arr[min] == target) {
        index = min;
    } else if (arr[max] == target) {
        index = max;
    }
    if (index == -1) {
        for (int i = 0; i < arrlength; i++) {
            if (min == max) {
                break;
            }
            int mid = (max + min) / 2;
            if (arr[mid] == target) {
                index = mid;
                break;
            } else if (arr[mid] > target) {
                max = mid;
            } else if (arr[mid] < target) {
                min = mid;
            }
        }
    }
    return index;
}

/////////////////////////////////////////////////////暴力查找数组
int Find_violent(int *arr, int arrlength, int target) {
    int index = -1;
    for (int i = 0; i < arrlength; i++) {
        if (arr[i] == target) {
            index = i;
        }
    }
    return index;
}
///////////////////////////////////////////////////////////////////////////////鼠标和圆的交叉检测
bool IsCirlceInsideMouse(Vector2 dipos,float diradius,Vector2 mouse) {
    int a = diradius*diradius;
    int b = (mouse.x - dipos.x)*(mouse.x-dipos.x)+(mouse.y-dipos.y)*(mouse.y-dipos.y);
    if (b>=a) {
        return false;
    } else {
        return true;
    }
}
#endif