#include "stdio.h"
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "DiEntity.h"
#include "time.h"
#include "Context.h"
#include "Common.h"
#include "Controller.h"
#include "stdlib.h"

// [min, max)  随机数在[min,max)的范围里
int get_rand(int min, int max) {
    int a;
    a = min + rand() % max;
    return a;
}

void DrawAll(Context *ctx) {

    Box *boxes = ctx->boxarr;
    for (int i = 0; i < 9; i++) {
        Box a = boxes[i];
        DrawRectangle(a.pos.x, a.pos.y, a.width, a.hight, a.color);
    }
    //////////////////////////////////////////////////////画地鼠
    Di *dishus = ctx->diarrpos;
    for (int i = 0; i < ctx->dicount; i++) {
        Di a = dishus[i];
        DrawCircle(a.pos.x, a.pos.y, a.radius, a.color);
    }
}

void ContextInit(Context *ctx) {
    //////box
    ctx->arrboxlength = 9;
    ctx->boxheight = 100;
    ctx->boxwidth = 100;
    ctx->boxgap = 40;
    ctx->boxstart.x = 50;
    ctx->boxstart.y = 50;
    ctx->boxindex = 0;
    ///////di
    ctx->distart.x = 100;
    ctx->distart.y = 100;
    ctx->arrlength = 10;
    ctx->diarr->color = RED;
    ctx->diarr->radius = 50;
    ctx->diindex = 0;
    ctx->last_rd = -1;
    ctx->dicount = 0;
}

int main() {
    InitWindow(500, 500, "cyh");
    Context ctx = {0};
    ContextInit(&ctx);
    // Context *contx = {0};
    const int LINE_COUNT = 3;
    const int COLUMN_COUNT = 3;
    for (int x = 0; x < COLUMN_COUNT; x += 1) {
        for (int y = 0; y < LINE_COUNT; y += 1) {
            int cur_x = ctx.boxstart.x + x * (ctx.boxwidth + ctx.boxgap);
            int cur_y = ctx.boxstart.y + y * (ctx.boxheight + ctx.boxgap);
            ctx.box.color = BROWN;
            ctx.box.hight = ctx.boxheight;
            ctx.box.width = ctx.boxheight;
            ctx.box.pos.x = cur_x;
            ctx.box.pos.y = cur_y;
            ctx.boxarr[ctx.boxindex] = ctx.box;
            ctx.boxindex++;
        }
    }
    /////////////////////////////Di.pos

    const int LINE_COUNT_DI = 3;
    const int COLUMN_COUNT_DI = 3;
    for (int x = 0; x < COLUMN_COUNT_DI; x += 1) {
        for (int y = 0; y < LINE_COUNT_DI; y += 1) {
            int cur_x = ctx.distart.x + x * (ctx.boxwidth + ctx.boxgap);
            int cur_y = ctx.distart.y + y * (ctx.boxheight + ctx.boxgap);
            ctx.dishu.color = ctx.diarr->color;
            ctx.dishu.radius = ctx.diarr->radius;
            ctx.dishu.pos.x = cur_x;
            ctx.dishu.pos.y = cur_y;
            printf("cur_x=%d\r\n", cur_x);
            // printf("di=%d\r\n", ctx.dishu.pos.x);

            ctx.diarr[ctx.diindex] = ctx.dishu;
            // printf("x=%d\r\n", ctx.diarr[ctx.diindex].pos.x);
            // printf("di=%d\r\n", ctx.dishu.pos.x);

            ctx.diindex++;
        }
    }
    int count = 9;
    // 0 1 2 3 4 5 6 7 8
    //       3          cur_rd
    // 0 1 2 8 4 5 6 7 3
    //       3          cur_rd
    int randomArray[9] = {0};
    for (int i = 0; i < count; i++) {
        randomArray[i] = i;
    }
    ctx.last_time = time(NULL);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        // const char *b = TextFormat("%d", a);
        /////////////////////////////////////////////////每隔两秒生成地鼠
        time_t current_time = time(NULL);

        if (current_time - ctx.last_time >= 2) {
            int index_index = get_rand(0, count); ////////下标
            int index = randomArray[index_index];
            ctx.diarrpos[ctx.dicount] = ctx.diarr[index];

            for (int i = 0; i < count; i++) {
                // if (randomArray[i] == index_index) {
                Arr_SwapCount(randomArray, count, i);
                count = count - 1;
                break;
                // }
            }

            ctx.last_time = current_time;
            ctx.dicount++;
        }
        DrawAll(&ctx);

        Vector2 mousepos = GetMousePosition();
        bool inside = IsCirlceInsideMouse(ctx.diarrpos->pos, ctx.diarr->radius, mousepos);
        if (inside && IsMouseButtonPressed(0)) {

            DrawCircle(ctx.diarrpos->pos.x, ctx.diarrpos->pos.y, 20, YELLOW);
        }
        // for (int i = 0; i < 9; i++) {
        //     Box a = ctx.boxarr[i];
        // }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}