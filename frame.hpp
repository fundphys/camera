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

#ifndef CAMERA_FRAME_HPP
#define CAMERA_FRAME_HPP

#include <vector>

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
