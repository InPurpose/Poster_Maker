//
// Created by xiwen on 6/2/2021.
//

#ifndef SFML_PROJECT_SLIDERHANDLER_H
#define SFML_PROJECT_SLIDERHANDLER_H
#include "Slider.h"
#include <map>

class SliderHandler : public GUIComponents{
private:
    std::map<std::string,Slider> sliders;
public:
    SliderHandler();
    void ChangeName(std::string sliderName,std::string newName);//???
    void setPosition(std::string sliderName,sf::Vector2f vector2F);
    void setInit(std::string sliderName,const int left, const int right);
    int getSliderValue(std::string sliderName);

    void addSlider(std::string sliderName);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
//    virtual sf::FloatRect getGlobalBound() = 0;
};


#endif //SFML_PROJECT_SLIDERHANDLER_H
