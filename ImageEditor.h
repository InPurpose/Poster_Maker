//
// Created by xiwen on 6/2/2021.
//

#ifndef SFML_PROJECT_IMAGEEDITOR_H
#define SFML_PROJECT_IMAGEEDITOR_H
#include "GUIComponents.h"
#include "SliderHandler.h"
#include "Slider.h"
#include "TextInput.h"
#include "DropdownMenu.h"
#include "MenuBar.h"
#include "ColorMenu.h"
#include <fstream>
class ImageEditor : public GUIComponents{
private:
    TextInput textInput;
    MenuBar menuBar;
    DropdownMenu dropdownMenu;
    SliderHandler sliderHandler;

    sf::RenderTexture renderTexture;
    sf::Text Logoname;

    ColorMenu background;
    ColorMenu TextColor;
    sf::Text Shadow;
    sf::Sprite icon;
    sf::Texture lo;
    Window_Dialog w;

    void addSlider(std::string name, sf::Vector2f pos, int start,int end);
    int CreatRT();

    void FileIn(std::string name);
    void LogoSetUp();
    void ShadowSetUp();
public:
    ImageEditor();
    void saveImage();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
//    virtual sf::FloatRect getGlobalBound() = 0;
};


#endif //SFML_PROJECT_IMAGEEDITOR_H
