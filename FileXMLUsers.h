#ifndef FILEXMLUSERS_H
#define FILEXMLUSERS_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileXMLUsers{
    CMarkup xml;
    const string NAME_OF_THE_FILE_WITH_USERS;
    bool isTheFileEmpty();
public:
    void addTheRecipientToTheFile(User user);
    void changeUserPassword(int loggedInUserID, vector <User> users);
};

#endif
