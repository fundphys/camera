#include "test_camera.hpp"
#include <iostream>

int main() {
  auto camera = std::make_shared<TestCamera>(TestCamera(0.0, Roi(640, 480, 0, 0), 0.0, 0.0));
  auto frame = camera->getFrame();

  double av = 0.0;
  for (int i = 0; i < frame.height(); ++i) {
    for (int j = 0; j < frame.width(); ++j) {
      av += frame.frame().at(i).at(j);
    }
  }

  std::cout << av/(frame.width()*frame.height()) << std::endl;

  return 0;
}
