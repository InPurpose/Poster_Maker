//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_SNAPSHOT_H
#define SFML_PROJECT_SNAPSHOT_H
#include <iostream>

class Snapshot {
private:
    std::string string1;
    char ID;
public:
    char getID() const;
    void setID(char id);

    std::string getString() const;
    void setString(std::string s1);
};


#endif //SFML_PROJECT_SNAPSHOT_H
