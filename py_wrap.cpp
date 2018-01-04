#include "camera.hpp"
#include "frame.hpp"
#include "test_camera.hpp"
#include <boost/python.hpp>
#include "roi.hpp"


using namespace boost::python;

BOOST_PYTHON_MODULE(pycamera) {

	class_<Roi>("Roi", init <uint32_t, uint32_t, uint32_t, uint32_t>() )
		.def(init<uint32_t, uint32_t, uint32_t, uint32_t>())
	;

	class_<Frame>("Frame", no_init)
	;


	class_<Camera, boost::noncopyable>("Camera", no_init)
    	.def("setGamma", &Camera::setGamma)
    	.def("setExposure", &Camera::setExposure)
  		.def("getFrame", &Camera::getFrame)  
	;

	class_<TestCamera>("TestCamera", init <uint64_t, Roi, double, double>() )  
		.def("getFrame", &TestCamera::getFrame)
	;
}