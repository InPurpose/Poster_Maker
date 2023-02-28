//
// Created by xiwen on 5/15/2021.
//

#ifndef SFML_PROJECT_IMAGE_H
#define SFML_PROJECT_IMAGE_H
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

class Image {
public:
    enum image{FOLDER,TXT,PHOTO};
    static std::map<image,sf::Texture> images;
    static std::map<image,bool> loaded;
    static sf::Texture &getImage(image image1);
    static void loadImage(image image1);
    static std::string getImagePath(image image1);
};


#endif //SFML_PROJECT_IMAGE_H
