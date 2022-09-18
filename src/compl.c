#include <stdio.h>
#include <stdint.h>

#include <raylib.h>


// Ignore this, this makes raylib not log anything
void _(){}

int main(void){
  SetTraceLogCallback(_);
  InitWindow(640, 480, "COMPL");

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