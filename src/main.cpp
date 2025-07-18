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
		// Declare a variable that will be used for playing the sound effects
		static int sound = 0;

		// if tree to play the sound effects depending on sound variable
		if (sound == 0) {
			FMODAudioEngine::sharedEngine()->playEffect("geometry-dash.mp3"_spr);
		} else if (sound == 1) {
			FMODAudioEngine::sharedEngine()->playEffect("fire-in-the-hole-geometry-dash.mp3"_spr);
		} else if (sound == 2) {
			FMODAudioEngine::sharedEngine()->playEffect("easy-geometry-dash.mp3"_spr);
		} else if (sound == 3) {
			FMODAudioEngine::sharedEngine()->playEffect("death-sound-geometry-dash.mp3"_spr);
		}

		// bump up sound to the next number
		sound = sound + 1;

		// check if sound is 4 and if so, set it to 0
		if (sound == 4) {
			sound = 0;
		}
	}
};