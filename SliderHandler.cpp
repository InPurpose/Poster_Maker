//
// Created by xiwen on 6/2/2021.
//

#include "SliderHandler.h"

SliderHandler::SliderHandler() {

}

void SliderHandler::ChangeName(std::string sliderName, std::string newName)
{
    //??
}

void SliderHandler::setPosition(std::string sliderName, sf::Vector2f vector2F) {
    sliders[sliderName].setPosition(vector2F);
}

void SliderHandler::setInit(std::string sliderName, const int left, const int right) {
    sliders[sliderName].setInit(left,right);
}

int SliderHandler::getSliderValue(std::string sliderName)
{
    return sliders[sliderName].getValue();
}

void SliderHandler::addSlider(std::string sliderName) {
    Slider temp(sliderName);
//    temp.setString(sliderName);
    sliders[sliderName] = temp;
}

void SliderHandler::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    auto iter = sliders.begin();
    for(;iter != sliders.end();++iter)
    {
        window.draw((*iter).second);
    }
}

void SliderHandler::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    auto iter = sliders.begin();
    for(;iter != sliders.end();++iter)
    {
        (*iter).second.addEventHandler(window,event);
    }
}

void SliderHandler::update() {
//    if(sliders.find("Empty"))
        sliders.erase("Empty");
    auto iter = sliders.begin();
    for(;iter != sliders.end();++iter)
    {
        (*iter).second.update();
    }
}

Snapshot &SliderHandler::getSnapshot() {

}

void SliderHandler::applySnapshot(const Snapshot &snapshot) {

}


