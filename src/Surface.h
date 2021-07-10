#ifndef SURFACE_H
#define SURFACE_H
#include "Color.h"
#include <vector>

class Surface {
public:
  Surface(int width, int height)
      : width_(width), height_(height), pixels_(width * height) {}

  RGBA &pixel(int x, int y) { return pixels_[x + width_ * y]; }

  const RGBA &pixel(int x, int y) const { return pixels_[x + width_ * y]; }

  int width() const { return width_; }
  int height() const { return height_; }
  const RGBA *pixels() const { return &pixels_[0]; }

private:
  int width_, height_;
  std::vector<RGBA> pixels_;
};

#endif
