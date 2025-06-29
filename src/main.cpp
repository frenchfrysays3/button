#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		// start up the class

		// This is used when we are appending to the init function (which we are)
		if (!MenuLayer::init()) {
			return false;
		}

		log::info("Starting up...");

		// make the button
		auto spr = ButtonSprite::create("Click me for SE.");
		auto btn = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyMenuLayer::onBtn));

		// declare the menu and add achild to it
		auto menu = CCMenu::create();
		menu->addChild(btn);

		// update menu
		menu->updateLayout();

		// finish up
		return true;
	}

	// Function(onBtn) for button(btn)
	void onBtn(CCObject*) {
		// Show a popup
		FLAlertLayer::create(
			"Button", // name
			"I have played a sound effect!", // body
			"Ok cool" // button
		)->show();

		// Function for sound effects
		soundEffect();
	}

	// function for sound effect (soundEffect)
	void soundEffect() {
		
	}
};