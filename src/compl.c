#include <stdio.h>
#include <stdint.h>

#include <raylib.h>

typedef struct point {
  float real_pos;      // Position on the real axis
  float imaginary_pos; // Position on the imaginary axis
  bool rendered;
} point_t;


typedef struct {
  uint32_t start_y;
  uint32_t end_y;
} graph_im_line_t;

typedef struct {
  uint32_t start_x;
  uint32_t end_x;
} graph_re_line_t;


typedef struct {
  graph_re_line_t re;
  graph_im_line_t im;
} graph_t;



#define MAX_PTS 256
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

  graph_t gr = { .re.start_x = 0, .re.end_x = 640,
                 .im.start_y = (640/2),
                 .im.end_y   = 480 };

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
      // DrawLine(640/2, 0, 640/2, 480, BLACK); // Y
      // DrawLine(0, 480/2, 640, 480/2, BLACK); // X
      DrawLine(gr.re.start_x, 480/2, gr.re.end_x, 480/2, BLACK);     // X
      DrawLine(gr.im.start_y, 0, gr.im.start_y, gr.im.end_y, BLACK); // Y

      DrawText(TextFormat("Re: %d\nIm: %d",
                          GetMouseX(), GetMouseY()), 0, 0, 10, BLACK);


      /**  input  **/
      // be able to move everything on arrow keys
      if(IsKeyPressed(KEY_LEFT)){
        // Move grid
        gr.im.start_y -= 5;

        // Move every point that exists
        for(int k = 0; k != MAX_PTS; k++){
          if(points[k].rendered == true){
            points[k].real_pos -= 5;
          }
        }
      } else if(IsKeyPressed(KEY_RIGHT)){
        // Move grid
        gr.im.start_y += 5;

        // Move every point that exists
        for(int k = 0; k != MAX_PTS; k++){
          if(points[k].rendered == true){
            points[k].real_pos += 5;
          }
        }
      }


      // If left click, and no point is visible at the mouse X, plot a point
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        for(int i = 0; i != MAX_PTS; i++){
          if(points[i].real_pos != GetMouseX() &&
             points[i].imaginary_pos != GetMouseY()){
            points[cur_pt_iter].imaginary_pos = GetMouseY();
            points[cur_pt_iter].real_pos      = GetMouseX();
            points[cur_pt_iter].rendered      = true;
            cur_pt_iter++;
            break;
          } else continue;
        }
      }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}