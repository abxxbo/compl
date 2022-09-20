#pragma once
#include <stdint.h>

typedef struct point {
  float real_pos;      // Position on the real axis
  float imaginary_pos; // Position on the imaginary axis
  bool rendered;
} point_t;


typedef struct {
  uint32_t start_y;
  uint32_t end_y;
  uint32_t start_x;
  uint32_t end_x;
} graph_im_line_t;

typedef struct {
  uint32_t start_x;
  uint32_t end_x;
  uint32_t start_y;
  uint32_t end_y;
} graph_re_line_t;


typedef struct {
  graph_re_line_t re;
  graph_im_line_t im;
} graph_t;

#define MAX_PTS 256
#define PTRADII 005   // Point radius

// point color
#define COLOR    RED
#define CO_LINE  BLACK