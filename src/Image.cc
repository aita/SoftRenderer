#include "Image.h"
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image.h>
#include <stb_image_write.h>

namespace {

void SurfaceToImage(const Surface &surface, std::vector<uint8_t> &image) {
  size_t i = 0;
  const int w = surface.width();
  const int h = surface.height();
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      auto color = surface.pixel(x, y);
      image[i++] = 255 * color.R;
      image[i++] = 255 * color.G;
      image[i++] = 255 * color.B;
      image[i++] = 255 * color.A;
    }
  }
}

} // namespace

void SaveSurfaceTGA(const std::string &filename, const Surface &surface) {
  std::vector<uint8_t> image(surface.width() * surface.height() * 4);
  SurfaceToImage(surface, image);

  stbi_write_tga(filename.c_str(), surface.width(), surface.width(), 4,
                 &image[0]);
}
