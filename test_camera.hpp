

#ifndef CAMERA_TEST_CAMERA_HPP
#define CAMERA_TEST_CAMERA_HPP

#include "camera.hpp"
#include <cstdlib>
#include <ctime>
#include <limits>



class TestCamera : public Camera {
public:
  TestCamera();
  TestCamera(uint64_t exposure, const Roi &roi, double gain, double gamma);
  Frame getFrame() override ;
private:
  const double exposure_const  = 1e-6;
};

#endif // CAMERA_TEST_CAMERA_HPP
