#include "Image.h"
#include "Renderer.h"
#include "Surface.h"
#include <iostream>

int main(int argc, char **argv) {
  Surface surface(200, 200);
  Renderer renderer;

  renderer.drawLine(surface, 13, 20, 80, 40, RGBA{1.0f, 0.0f, 0.0f, 1.0f});
  SaveSurfaceTGA("image.tga", surface);

  return 0;
}
