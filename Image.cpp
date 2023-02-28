//
// Created by xiwen on 5/15/2021.
//

#include "Image.h"
std::map<Image::image,sf::Texture> Image::images;
std::map<Image::image,bool> Image::loaded;

sf::Texture &Image::getImage(Image::image image1)
{
    if(!loaded[image1])
        loadImage(image1);
    return images[image1];
}

void Image::loadImage(Image::image image1)
{
    if(!loaded[image1])
    {
        if(!images[image1].loadFromFile("images/"+getImagePath(image1)))
            exit(28);
        loaded[image1] = true;
    }
}

std::string Image::getImagePath(Image::image image1)
{
    switch (image1)
    {
        case FOLDER: return "folder.png";
        case TXT: return "file.png";
        case PHOTO: return "photo.png";
    }
}
