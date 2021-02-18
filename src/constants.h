#pragma once

#include <string>
#include <iostream>

#define LOGV(VAR) (std::cout << #VAR << "= " << VAR << std::endl)
#define LOG(VAR)  (std::cout << VAR << std::endl)

const unsigned int SCREEN_WIDTH = 768/2;
const unsigned int SCREEN_HEIGHT = 1136/2;

const float SPLASH_STATE_SHOW_TIME = 3.0f;

const std::string X_PIECE_FILEPATH = "res/cross.png";
const std::string LOGO_FILEPATH = X_PIECE_FILEPATH;
const std::string SPLASH_SCREEN_BACKGROUND_FILEPATH = "res/splash_backgound.png";
const std::string MAIN_MENU_TITLE_FILEPATH = "res/main_menu_title.png";
const std::string PLAY_BUTTON_FILEPATH = "res/play.png";
