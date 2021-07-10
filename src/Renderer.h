#ifndef RENDERER_H
#define RENDERER_H
#include "Color.h"

class Surface;

class Renderer {
public:
  void drawLine(Surface &surface, int x0, int y0, int x1, int y1,
                const RGBA &color);
};

#endif
