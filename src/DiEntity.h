#ifndef DIENTITY_H__
#define DIENTITY_H__

#include "../include/raylib.h"
typedef struct Di {
    Color color;
    Vector2 pos;
    float radius;

} Di;



typedef struct Box
{
    Color color;
    Vector2 pos;
    int width;
    int hight;
    
}Box;

void Di_Draw(Di *dishu) {
    DrawCircle(dishu->pos.x, dishu->pos.y, dishu->radius, dishu->color);
}
#endif