#ifndef FILEXMLUSERS_H
#define FILEXMLUSERS_H
#include <iostream>
#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileXMLUsers{
    CMarkup xml;
    const string NAME_OF_THE_FILE_WITH_USERS;
//    fstream XMLFile;
    bool isTheFileEmpty();
public:
//    FileXMLUsers(string NAMEOFTHEFILEWITHUSERS) : NAME_OF_THE_FILE_WITH_USERS(NAMEOFTHEFILEWITHUSERS){};
    void addTheRecipientToTheFile(User user);
};

#endif
