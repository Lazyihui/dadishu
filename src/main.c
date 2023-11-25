#include "stdio.h"
#include "..\include\raylib.h"
#include "DiEntity.h"
#include "time.h"
Vector2 Get_Rand(Vector2 dipos, int x, int y, int width, int hight, int gap, int a) {
}

void DrawAll(Box *box) {

    // for(int i =0; i<length ;i++){

    //    boxes->pos = boxes[i];
    // }

    DrawRectangle(box->pos.x, box->pos.y, box->width, box->hight, box->color);
}

int main() {
    InitWindow(600, 500, "cyh");

    // Di diarr[8];
    // Box boxarr[9] = {0}; // 中数量  数组下标 数组长度
    // int array[10] = {0};
    // // boxarr[0]
    // Vector2 start;
    // start.x = 50;
    // start.y = 50;
    // int width = 100;
    // int height = 100;
    // int gap = 40;
    // int i = 0; ////////
    // int a = 0;
    // // int n = 10;
    // int c = 10 ;

    // const int LINE_COUNT = 3;
    // const int COLUMN_COUNT = 3;
    // for (int x = 0; x < COLUMN_COUNT; x += 1) {
    //     for (int y = 0; y < LINE_COUNT; y += 1) {
    //         int cur_x = start.x + x * (width + gap);
    //         int cur_y = start.y + y * (height + gap);
    //         Box box;
    //         box.color = BROWN;
    //         box.hight = height;
    //         box.width = width;
    //         box.pos.x = cur_x;
    //         box.pos.y = cur_y;
    //         boxarr[i] = box;
    //         i++;
    //     }
    // }

    // //////////////赋值
    // for (int j = 0; j < 10; j++) {
    //     array[j] = j + 1;
    //     a = array[j];
    // }
    // printf("%d", a);

    int arr[10] = {0};
    int n = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        // printf("%d", arr[i]);
    }

    time_t start_time = time(NULL);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        time_t current_time = time(NULL);

        if (current_time - start_time >= 2) {
            n++;
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
                printf("%d\r\n", arr[i]);}
                start_time = current_time;

                printf("n=%d\r\n", n);
            }

            // if (IsKeyPressed(KEY_SPACE)) {
            //     n += 1;
            //     for (int i = 0; i < n; i++) {
            //         arr[i] = i + 1;
            //         printf("%d\r\n", arr[i]);
            //     }
            // }

            // if (IsKeyPressed(KEY_SPACE)) {
            //     /////////左移
            //     // n = n - 1;
            //     // for (int j = 0; j < n; j++) {
            //     //     array[j] = array[j + 1];
            //     // }
            //     //////////////////////////
            //     ////////交换
            //     int b = array[0];
            //     array[0] = array[c-1];
            //     array[c-1] = b;
            //     c = c - 1;
            //     //////////////////////每个变量要初始化 就是赋值
            // }
            // for (int k = 0; k < c; k++) {

            //     int a = array[k];
            //     const char *b = TextFormat("%d", a);

            //     DrawText(b, 50 + (k * 50), 50, 20, RED);
            // }

            // for (int i = 0; i < 9; i++) {
            //     Box a= boxarr[i];
            //     DrawAll(&a);
            // }

            EndDrawing();
        }
        CloseWindow();
        return 0;
    }