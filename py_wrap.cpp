#include "camera.hpp"
#include "frame.hpp"
#include "test_camera.hpp"
#include <boost/python.hpp>
#include "roi.hpp"


using namespace boost::python;

BOOST_PYTHON_MODULE(pycamera) {

	class_<Camera, boost::noncopyable>("Camera", no_init)
    	.def("setGamma", &Camera::setGamma)
    	.def("setExposure", &Camera::setExposure)
  		.def("getFrame", &Camera::getFrame)  
	;

	class_<TestCamera>("TestCamera", init <uint64_t, Roi, double, double>())
	;
}