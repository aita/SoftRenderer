#include "Renderer.h"
#include "Surface.h"
#include <cmath>

void Renderer::drawLine(Surface &surface, int x0, int y0, int x1, int y1,
                        const RGBA &color) {
  bool steep = false;
  if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
    std::swap(x0, y0);
    std::swap(x1, y1);
    steep = true;
  }
  if (x0 > x1) {
    std::swap(x0, x1);
    std::swap(y0, y1);
  }
  int dx = x1 - x0;
  int dy = y1 - y0;
  int derror = dy * 2;
  int error = 0;
  int y = y0;
  if (steep) {
    for (int x = x0; x <= x1; x++) {
      surface.pixel(y, x) = color;
      error += derror;
      if (error > dx) {
        y += (y1 > y0 ? 1 : -1);
        error -= dx * 2;
      }
    }
  } else {
    for (int x = x0; x <= x1; x++) {
      surface.pixel(x, y) = color;
      error += derror;
      if (error > dx) {
        y += (y1 > y0 ? 1 : -1);
        error -= dx * 2;
      }
    }
  }
}
