//
// Created by xiwen on 4/9/2021.
//

#include "Snapshot.h"

std::string Snapshot::getString() const
{
    return string1;
}

void Snapshot::setString(std::string s1)
{
    string1 = s1;
}

char Snapshot::getID() const
{
    return ID;
}

void Snapshot::setID(char id)
{
    ID = id;
}
