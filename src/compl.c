#include <stdio.h>
#include <stdint.h>

#include <raylib.h>
#include "compl.h"

// Ignore this, this makes raylib not log anything
void _(){}

int main(void){
  SetTraceLogCallback(_);
  InitWindow(640, 480, "COMPL");
  SetTargetFPS(60);

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
                .re.start_y  = 480/2, .re.end_y = 480/2,

                 .im.start_y = (640/2), .im.end_y = 480,
                 .im.start_x = 0, .im.end_x = (640/2) };


  Font f = LoadFont("src/res/font.ttf");

  while(!WindowShouldClose()){
    // Draw
    BeginDrawing();
      
      ClearBackground(WHITE);

      // Draw info, top left
      DrawTextEx(f, "Welcome to COMPL.\nRunning at 60 FPS",
                 (Vector2){0.0f, 0.0f}, 20, 0, BLACK);



      // Plot all visible points
      for(int i = 0; i != MAX_PTS; i++){
        if(points[i].rendered == true){
          DrawCircle(points[i].real_pos, points[i].imaginary_pos,
                      PTRADII, COLOR);
        }
      }

      // Draw graph lines
      // DrawLine(640/2, 0, 640/2, 480, BLACK); // Y
      // DrawLine(0, 480/2, 640, 480/2, BLACK); // X
      DrawLine(gr.re.start_x, gr.re.start_y, gr.re.end_x, gr.re.end_y, CO_LINE);   // X
      DrawLine(gr.im.start_y, gr.im.start_x, gr.im.start_y, gr.im.end_y, CO_LINE); // Y


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
      } else if(IsKeyPressed(KEY_UP)){
        gr.re.start_y += 5;
        gr.re.end_y = gr.re.start_y;
        for(int k = 0; k != MAX_PTS; k++){
          if(points[k].rendered == true){
            points[k].imaginary_pos += 5;
          }
        }
      } else if(IsKeyPressed(KEY_DOWN)){
        gr.re.start_y -= 5;
        gr.re.end_y = gr.re.start_y;
        for(int k = 0; k != MAX_PTS; k++){
          if(points[k].rendered == true){
            points[k].imaginary_pos -= 5;
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
          } else {
            // if the rendered state is true, and we
            // are on the point, just unrender it.
            // TODO: remove from list of points
            // also broken, but ehhh
            for(int i = 0; i != MAX_PTS; i++){
              if(points[i].rendered == true)
                points[i].rendered = false;
            }
          };
        }
      }

      // Clear every single point visible
      if(IsKeyPressed(KEY_C))
        for(int i = 0; i != MAX_PTS; i++)
          points[i].rendered = false;

    EndDrawing();
  }
  CloseWindow();
  return 0;
}