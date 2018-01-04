

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
  uint64_t exposure_;       // Exposure [usec]
  Roi roi_;
  double gain_;
  double gamma_;
};

#endif // CAMERA_CAMERA_HPP
