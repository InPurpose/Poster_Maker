//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_HISTORY_H
#define SFML_PROJECT_HISTORY_H
#include "GUIComponents.h"
#include <stack>
#include "Keyboard_Shortcuts.h"

class History {
private:
    static std::stack<Snapshot> stack;
    static std::map<std::string, GUIComponents*> components;
public:
    struct Response{
        bool found = false;
        GUIComponents* component;
    };
    static Response& getComponent(std::string componentID);
    static void addComponent(std::string componentID, GUIComponents* component);

    static void pushHistory(const Snapshot& snapshot);
    static Snapshot& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static bool empty();
};


#endif //SFML_PROJECT_HISTORY_H
