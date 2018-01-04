

#ifndef CAMERA_FRAME_HPP
#define CAMERA_FRAME_HPP

#include <vector>
#include <cstdint>

class Frame {
public:
  using FrameType = std::vector<std::vector<uint32_t>>;

  Frame(const FrameType &frame)
      : frame_(frame), width_(frame_.at(0).size()), height_(frame_.size()) {}

  uint32_t width() const { return width_; }

  uint32_t height() const { return height_; }

  const FrameType &frame() const { return frame_; }

private:
  FrameType frame_;
  uint32_t width_;
  uint32_t height_;
};

#endif // CAMERA_FRAME_HPP
