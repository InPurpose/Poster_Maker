//
// Created by xiwen on 4/10/2021.
//

#include "ChangeColor.h"

int ChangeColor::counter = 0;
int ChangeColor::dynamic_counter = 0;

void ChangeColor::colorChange(LinkedList<sf::Text>::iterator &iter)
{
    if(digit(iter))
        (*iter).setFillColor(sf::Color::Red);
    if(operators(iter))
        (*iter).setFillColor(sf::Color::Green);

    if(counter == 0)
        counter = SpecialWords(iter);
    if(counter != 0)
    {
        (*iter).setFillColor(sf::Color::Blue);
        counter--;
    }
}

bool ChangeColor::digit(LinkedList<sf::Text>::iterator &iter)
{
    char temp = (char)(*iter).getString()[0];
    return (isdigit(temp));
}

bool ChangeColor::operators(LinkedList<sf::Text>::iterator &iter)
{
    char temp = (char)(*iter).getString()[0];

    return (temp == '+' || temp == '-' || temp == '*' || temp == '='
            || temp == '/'|| temp == '<' || temp == '>' );
}

int ChangeColor::SpecialWords(LinkedList<sf::Text>::iterator &iter)
{
    //check int,double,float,char,for,string,bool

    char tempMinusOne = (char)(*(iter-1)).getString()[0];
    char temp1 = (char)(*iter).getString()[0];
    char temp2 = (char)(*(iter+1)).getString()[0];
    char temp3 = (char)(*(iter+2)).getString()[0];
    char temp4 = (char)(*(iter+3)).getString()[0];
    char temp5 = (char)(*(iter+4)).getString()[0];
    char temp6 = (char)(*(iter+5)).getString()[0];

//    if(temp1 == 'i' && temp2 == 'n' && temp3 == 't' && tempMinusOne == ' ' && temp4 == ' ')
    if(temp1 == 'i' && temp2 == 'n' && temp3 == 't')
        return 3;

    if(temp1 == 'f' && temp2 == 'o' && temp3 == 'r')
        return 3;

    if(temp1 == 'c' && temp2 == 'h' &&
       temp3 == 'a' && temp4 == 'r')
        return 4;

    if(temp1 == 'b' && temp2 == 'o' &&
       temp3 == 'o' && temp4 == 'l')
        return 4;

    if(temp1 == 'f' && temp2 == 'l' && temp3 == 'o' &&
       temp4 == 'a' && temp5 == 't')
        return 5;

    if(temp1 == 's' && temp2 == 't' && temp3 == 'r' &&
       temp4 == 'i' && temp5 == 'n' && temp6 == 'g')
        return 6;

    if(temp1 == 'd' && temp2 == 'o' && temp3 == 'u' &&
       temp4 == 'b' && temp5 == 'l' && temp6 == 'e')
        return 6;

    return 0;
}

void ChangeColor::colorChange(LinkedList<sf::Text>::iterator &begin, LinkedList<sf::Text>::iterator &end)
{
    LinkedList<sf::Text>::iterator walker = begin;
    for(;walker != end;++walker)
    {
        std::string temp = "";
        for (int i = 0; i < SpecialWords(walker); ++i)
        {
            temp += (*(walker+i)).getString();
        }
//        if(temp == "int")
    }
}

void ChangeColor::ifDigit(LinkedList<sf::Text>::iterator &iter)
{
    char temp = (char)(*iter).getString()[0];
    if(isdigit(temp))
        dynamic_counter =1;
}

void ChangeColor::ifOperators(LinkedList<sf::Text>::iterator &iter) {
    char temp = (char)(*iter).getString()[0];

    if(temp == '+' || temp == '-' || temp == '*' || temp == '='
            || temp == '/'|| temp == '<' || temp == '>' )
        dynamic_counter = 1;
}
