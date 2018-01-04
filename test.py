#!/usr/bin/env python3

from pycamera import TestCamera
from pycamera import Roi
from pycamera import Frame

roi = Roi(640, 480, 0, 0)

test_camera = TestCamera(10, roi, 0, 0)

frame = test_camera.getFrame()
print(type(frame))
print(len(frame))



#LD_LIBRARY_PATH=. ./test.py