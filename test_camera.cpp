#include "test_camera.hpp"

  

  TestCamera::TestCamera(uint64_t exposure, const Roi &roi, double gain, double gamma)
      : Camera(exposure, roi, gain, gamma) {}

  Frame TestCamera::getFrame(){
    std::srand(time(0));
    std::vector<uint8_t> testFrame(roi_.width*roi_.height*4);
    uint8_t max = std::numeric_limits<uint8_t>::max();

    for (int i = 0; i < roi_.height * roi_.width * 4; ++i) {
      testFrame[i] = std::rand() % max;
    }

    Frame::FrameType frameData;
    for (int i = 0; i < roi_.height; ++i) {
      std::vector<uint32_t> row;
      for (int j = 0; j < roi_.width * 4; j += 4) {
        uint32_t pixel = (uint32_t)testFrame[j] +
                         ((uint32_t)testFrame[j + 1] << 8) +
                         ((uint32_t)testFrame[j + 2] << 16) +
                         ((uint32_t)testFrame[j + 3] << 24);
        row.push_back(uint32_t(pixel * exposure_ * exposure_const) );
      }
      frameData.push_back(row);
    }
    return Frame(frameData);
  }

