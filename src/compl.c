#include <stdio.h>
#include <stdint.h>

#include <raylib.h>

typedef struct point {
  float real_pos;      // Position on the real axis
  float imaginary_pos; // Position on the imaginary axis
  bool rendered;
} point_t;

#define MAX_PTS 2
#define PTRADII 005   // Point radius


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

  // force to be uninitialized
  for(int i = 0; i != MAX_PTS; i++){
    points[i].imaginary_pos = 0;
    points[i].real_pos      = 0;
    points[i].rendered      = false;
  }

  while(!WindowShouldClose()){
    // Draw
    BeginDrawing();
      ClearBackground(WHITE);

      // Plot all visible points
      for(int i = 0; i != MAX_PTS; i++){
        if(points[i].rendered == true){
          DrawCircle(points[i].real_pos, points[i].imaginary_pos,
                      PTRADII, BLACK);
        }
      }

      // Draw graph lines
      DrawLine(640/2, 0, 640/2, 480, BLACK);
      DrawLine(0, 480/2, 640, 480/2, BLACK);

      DrawText(TextFormat("Re: %d\nIm: %d",
                          GetMouseX(), GetMouseY()), 0, 0, 10, BLACK);

      // If left click, and no point is visible at the mouse X, plot a point
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        for(int i = 0; i != MAX_PTS; i++){
          if(points[i].real_pos != GetMouseX() &&
             points[i].real_pos != GetMouseY()){
            points[cur_pt_iter].imaginary_pos = GetMouseY();
            points[cur_pt_iter].real_pos      = GetMouseX();
            points[cur_pt_iter].rendered      = true;
            cur_pt_iter++;
          } else continue;
        }
      }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}