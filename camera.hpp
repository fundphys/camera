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

#ifndef CAMERA_CAMERA_HPP
#define CAMERA_CAMERA_HPP

#include "frame.hpp"
#include "roi.hpp"

class Camera {
public:
  Camera(uint64_t exposure, const Roi &roi, double gain, double gamma)
      : exposure_(exposure), roi_(roi), gain_(gain), gamma_(gamma) {}
  void setExposure(uint64_t exposure) { exposure_ = exposure; }
  void setRoi(const Roi &roi) { roi_ = roi; }
  void setGain(double gain) { gain_ = gain; }
  void setGamma(double gamma) { gamma_ = gamma; }

  virtual Frame getFrame() = 0;

protected:
  uint64_t exposure_;
  Roi roi_;
  double gain_;
  double gamma_;
};

#endif // CAMERA_CAMERA_HPP
