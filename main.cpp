#include "test_camera.hpp"
#include <iostream>
#include <memory>



double average_frame( const Frame & frame) {
  double av = 0.0;
  for (int i = 0; i < frame.height(); ++i) {
    for (int j = 0; j < frame.width(); ++j) {
      av += frame.frame().at(i).at(j);
    }
  }

  return av/(frame.width()*frame.height());
} 


int main() {
  std::shared_ptr<Camera> camera = std::make_shared<TestCamera>(TestCamera(10, Roi(640, 480, 0, 0), 0.0, 0.0));
  auto frame = camera->getFrame();
  std::cout <<  average_frame(frame) << std::endl;
  camera->setExposure(20);
  frame = camera->getFrame();
  std::cout <<  average_frame(frame) << std::endl;
  return 0;
}
