/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CAMERA_TEST_CAMERA_HPP
#define CAMERA_TEST_CAMERA_HPP

#include "camera.hpp"
#include <cstdlib>
#include <ctime>
#include <limits>

class TestCamera : public Camera {
public:
  TestCamera(uint64_t exposure, const Roi &roi, double gain, double gamma)
      : Camera(exposure, roi, gain, gamma) {}

  Frame getFrame() override {
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
        row.push_back(pixel);
      }
      frameData.push_back(row);
    }
    return Frame(frameData);
  }

private:
};

#endif // CAMERA_TEST_CAMERA_HPP
