#include "stdio.h"
#include "..\include\raylib.h"
#include "DiEntity.h"
#include "time.h"
#include "Context.h"
#include "Common.h"
#include "Controller.h"
Vector2 Get_Rand(Vector2 dipos, int x, int y, int width, int hight, int gap, int a) {
}

void DrawAll(Box *box) {
    DrawRectangle(box->pos.x, box->pos.y, box->width, box->hight, box->color);
}


void ContextInit(Context *ctx) {
    ctx->arrboxlength = 9;
    ctx->boxheight =100;
    ctx->boxwidth = 100;
    ctx->boxgap = 40;
    ctx->start.x=50;
    ctx->start.y=50;
    ctx->boxindex = 0;

    ctx->arrlength = 10;

}
int main() {
    InitWindow(500, 500, "cyh");
    Context ctx = {0};
    ContextInit(&ctx);


    const int LINE_COUNT = 3;
    const int COLUMN_COUNT = 3;
    for (int x = 0; x < COLUMN_COUNT; x += 1) {
        for (int y = 0; y < LINE_COUNT; y += 1) {
            int cur_x = ctx.start.x + x * (ctx.boxwidth + ctx.boxgap);
            int cur_y = ctx.start.y + y * (ctx.boxheight + ctx.boxgap);
            ctx.box.color = BROWN;
            ctx.box.hight = ctx.boxheight;
            ctx.box.width = ctx.boxheight;
            ctx.box.pos.x = cur_x;
            ctx.box.pos.y = cur_y;
            ctx.boxarr[ctx.boxindex] = ctx.box;
            ctx.boxindex++;
        }
    }
    ////////////////////////////////////////////////////////给Context里的值全部赋值为0
    /////////////////////////////////////////////////////////值的初始化

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);



        // for (int k = 0; k < ctx.arrlength; k++) {

        //     int a = ctx.arr[k];
        //     const char *b = TextFormat("%d", a);

        //     DrawText(b, 50 + (k * 50), 50, 20, RED);
        // }

        for (int i = 0; i < 9; i++) {
            Box a = ctx.boxarr[i];
            DrawAll(&a);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}