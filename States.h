//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H
#include <map>

enum ObjectStates{
    Typable,Cursor_Swtich,Undo,ShowMenu,
    ShowBar,ShowGrind,ShowList,LoadFile,

    ///This should always be the last state
    LASTSTATE
};

class States {
public:

    States();
    bool isStateEnable(ObjectStates state) const;
    void enableState(ObjectStates state);
    void disableState(ObjectStates state);
private:
    std::map<ObjectStates,bool> states;
};


#endif //SFML_PROJECT_STATES_H
