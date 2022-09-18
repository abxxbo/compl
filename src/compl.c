#include <stdio.h>
#include <stdint.h>

#include <raylib.h>

typedef struct point {
  float real_pos;      // Position on the real axis
  float imaginary_pos; // Position on the imaginary axis
  bool rendered;
} point_t;

#define MAX_PTS 256


// Ignore this, this makes raylib not log anything
void _(){}

int main(void){
  SetTraceLogCallback(_);
  InitWindow(640, 480, "COMPL");

  // Array of points
  point_t points[MAX_PTS];
  int cur_pt_iter = 0;    // the current element for the array
                          // this value would be 3 if you are looking
                          // for the 4th element in the array.

  while(!WindowShouldClose()){
    // Draw
    BeginDrawing();
      ClearBackground(WHITE);

      // Draw graph lines
      DrawLine(640/2, 0, 640/2, 480, BLACK);
      DrawLine(0, 480/2, 640, 480/2, BLACK);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}