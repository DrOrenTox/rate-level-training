#define FMT_ENFORCE_COMPILE_STRING 0
#include <Geode/Geode.hpp>
#include <Geode/modify/LeveleditorLayer.hpp>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init(GJGameLevel* level) {
        if (!MenuLayer::init()) return false;

        // 1. Get current date (Year-Month-Day)
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d");

        // 2. Create the text label
        auto label = CCLabelBMFont::create(ss.str().c_str(), "goldFont.fnt");
        label->setScale(0.5f);
        label->setID("calendar-label"_spr);

        // 3. Position it (Top Left, safe from notches)
        auto winSize = CCDirector::get()->getWinSize();
        label->setPosition({ 50, winSize.height - 15 });

        this->addChild(label);
        return true;
    }
};
#include <Geode/Geode.hpp>
#include <Geode/modify/leveleditorLayer.hpp>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace geode::prelude;

class $modify(MyLeveleditorLayer, leveleditorLayer) {
    bool init(GJGameLevel* level) {
        if (!leveleditorLayer::init()) return false;

        // 1. Get current date (Day/Month/Year)
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%d/%m/%Y");

        // 2. Create the label using standard GD font
        auto label = CCLabelBMFont::create(ss.str().c_str(), "goldFont.fnt");
        label->setScale(0.5f);
        label->setID("calendar-date-label"_spr);

        // 3. Position it at the top center
        auto winSize = CCDirector::get()->getWinSize();
        label->setPosition({ winSize.width / 2, winSize.height - 15.f });

        this->addChild(label);
        return true;
    }
};
#include <Geode/Geode.hpp>
#include <Geode/modify/LeveleditorLayer.hpp>
#include <chrono>
using namespace geode::prelude;
class $modify(LeveleditorLayer) { bool init(GJGameLevel* level) { 
    if (!MenuLayer::init()) return false;
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        // Use a safer way to get the time for Android/iOS
    struct tm timeinfo;
    localtime_r(&now, &timeinfo);

    std::stringstream ss; 
    ss << std::put_time(&timeinfo, "%d/%m/%Y");

    auto label = CCLabelBMFont::create(ss.str().c_str(), "goldFont.fnt");
    label->setScale(0.5f);
    
    // Move it to 60 so it's not hidden by the bottom bar
    label->setPosition({ CCDirector::get()->getWinSize().width / 2, 60 });

    // Add with a high Z-Order (100) so it stays on top of other mods
    this->addChild(label, 100);

    return true;
}};
