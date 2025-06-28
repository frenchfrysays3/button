#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer, MyMenuLayer) {
	bool init() {
		// start up the class

		// This is used when we are appending to the init function (which we are)
		if (!MenuLayer::init()) {
			return false;
		}

		log::info("Starting up...");

		// make the button

	}
}