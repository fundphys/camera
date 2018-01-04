

#ifndef CAMERA_ROI_HPP
#define CAMERA_ROI_HPP

struct Roi {
  Roi(uint32_t width, uint32_t height, uint32_t x, uint32_t y)
      : width(width), height(height), x(x), y(y) {}

  uint32_t width;
  uint32_t height;
  uint32_t x;
  uint32_t y;
};

#endif // CAMERA_ROI_HPP
