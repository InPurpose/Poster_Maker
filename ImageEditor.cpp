//
// Created by xiwen on 6/2/2021.
//

#include "ImageEditor.h"

ImageEditor::ImageEditor()
{
    textInput.setLabel("Your name:");
    textInput.setLabelSize(24);
    textInput.setPosition({10,550});

    dropdownMenu.setPosition({650,580});

    //Text sliders setup
    addSlider("Text Opacity:",{10,720},100,255);
    addSlider("Text Size:",{10, 750},24,72);
    addSlider("Text_X Pos:",{10, 780},20,1200);
    addSlider("Text_Y Pos:",{10, 810},50,450);
    //Shadow sliders setup
    addSlider("Shadow Opacity:",{750,720},100,255);
    addSlider("Shadow Size:",{750, 750},24,72);
    addSlider("Shadow_X Pos:",{750, 780},20,1200);
    addSlider("Shadow_Y Pos:",{750, 810},50,450);

    addSlider("Icon_X Pos:",{10, 690},20,1200);
    addSlider("Icon_Y Pos:",{750, 690},50,450);
    addSlider("Skew:",{10, 840},50,150);


    Shadow.setScale(1,-1);

    CreatRT();
    TextColor.setString("TextColor: ");
    background.setString("BackGround");
    TextColor.setPosition({900,510});
    background.setPosition({1100,510});
}
void ImageEditor::addSlider(std::string name, sf::Vector2f pos, int start, int end)
{
    sliderHandler.addSlider(name);
    sliderHandler.setPosition(name,pos);
    sliderHandler.setInit(name,start,end);
}

void ImageEditor::saveImage()
{
    std::cout << "Image is saved.\n";
    renderTexture.getTexture().copyToImage().saveToFile("Logos/logo_final.jpg");
}

void ImageEditor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(textInput);
    window.draw(sliderHandler);

    window.draw(dropdownMenu);

    sf::Sprite sprite(renderTexture.getTexture());

    window.draw(sprite);
    window.draw(menuBar);

    window.draw(background);
    window.draw(TextColor);
}

void ImageEditor::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    textInput.addEventHandler(window, event);
    menuBar.addEventHandler(window, event);
    dropdownMenu.addEventHandler(window, event);
    sliderHandler.addEventHandler(window, event);


    if (menuBar.checkClick("Save File")) {
        menuBar.disableMenu("Save File");
        saveImage();
    }
    if (menuBar.checkClick("Load Icon")) {
        menuBar.disableMenu("Load Icon");
        w.open();
    }


    if (menuBar.checkClick("Open File")) {
        menuBar.disableMenu("Open File");
        w.open();
    }

    if (menuBar.checkClick("Close File")) {
        menuBar.disableMenu("Close File");
        textInput.setString("");
        renderTexture.clear();

    }

    if (menuBar.checkClick("New File")) {
        std::cout << "New File\n";
        menuBar.disableMenu("New File");
        textInput.setString("");
    }

    if (menuBar.checkClick("Undo")) {
        menuBar.disableMenu("Undo");
        std::cout << "Undo\n";
    }


    renderTexture.clear(background.getColor());
    renderTexture.draw(Logoname);
    renderTexture.draw(Shadow);

    if (w.isStateEnable(LoadFile))
    {
        if(FileNode::OpenImg != "")
        {
            lo.loadFromFile("Icon/" + FileNode::OpenImg);

            icon.setTexture(lo);
            icon.setPosition({150, 150});
            icon.setScale(0.5, 0.5);
        }
        if(FileNode::OpenTxt != "")
        {
            FileIn(FileNode::OpenTxt);
        }

        w.disableState(LoadFile);
    }
    renderTexture.draw(icon);

    renderTexture.display();
    background.addEventHandler(window,event);
    TextColor.addEventHandler(window,event);
}

void ImageEditor::update()
{
    sf::Vector2f pos;

    textInput.update();
    menuBar.update();
    dropdownMenu.update();
    sliderHandler.update();
    background.update();
    TextColor.update();

    LogoSetUp();
    ShadowSetUp();

    pos.x =  sliderHandler.getSliderValue("Icon_X Pos:");
    pos.y = sliderHandler.getSliderValue("Icon_Y Pos:");

    icon.setPosition(pos);

}
void ImageEditor::LogoSetUp()
{
    sf::Vector2f pos;

    Logoname.setFont(Myfont::getFont(dropdownMenu.getItem()));
    Logoname.setCharacterSize(sliderHandler.getSliderValue("Text Size:"));
    Logoname.setString(textInput.getString());
    sf::Color color =TextColor.getColor();
    color.a = sliderHandler.getSliderValue("Text Opacity:");
    Logoname.setFillColor(color);
    pos.x = sliderHandler.getSliderValue("Text_X Pos:");
    pos.y = sliderHandler.getSliderValue("Text_Y Pos:");
    Logoname.setPosition(pos);


}
void ImageEditor::ShadowSetUp() {
    sf::Vector2f pos;

    pos.x = sliderHandler.getSliderValue("Shadow_X Pos:");
    pos.y = sliderHandler.getSliderValue("Shadow_Y Pos:");
    Shadow.setPosition(pos);
    Shadow.setFont((Myfont::getFont(dropdownMenu.getItem())));
    Shadow.setCharacterSize(sliderHandler.getSliderValue("Shadow Size:"));
    Shadow.setString(textInput.getString());

    sf::Color color = Logoname.getFillColor();
    color.a = sliderHandler.getSliderValue("Shadow Opacity:");
    Shadow.setFillColor(color);
    float temp = -0.01*sliderHandler.getSliderValue("Skew:");
    Shadow.setScale(1,temp);

}

int ImageEditor::CreatRT() {
    if (!renderTexture.create(1500, 500))
        return -1;
}

void ImageEditor::FileIn(std::string name) {
    std::string line;
    std::ifstream myfile("Icon/"+name);

    if (myfile.is_open())
    {
        getline (myfile,line);
        std::cout << line << "\n";
        myfile.close();
    }
    textInput.setString(line);
}

Snapshot &ImageEditor::getSnapshot() {}

void ImageEditor::applySnapshot(const Snapshot &snapshot) {}


