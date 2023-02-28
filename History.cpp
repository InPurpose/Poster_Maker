//
// Created by xiwen on 4/9/2021.
//

#include "History.h"

std::stack<Snapshot> History::stack;
std::map<std::string, GUIComponents*> History::components;

void History::pushHistory(const Snapshot &snapshot)
{
    stack.push(snapshot);
}

Snapshot &History::topHistory()
{
    return stack.top();
}

void History::popHistory()
{
    if(!stack.empty())
        stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

History::Response &History::getComponent(std::string componentID)
{

}

void History::addComponent(std::string componentID, GUIComponents *component)
{
//    components[componentID] = component;
}

bool History::empty()
{
    return stack.empty();
}
