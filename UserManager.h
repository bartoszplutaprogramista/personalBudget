#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <conio.h>
#include "User.h"
#include "Markup.h"
#include "FileXMLUsers.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UserManager{
    CMarkup xml;
    FileXMLUsers fileXMLUsers;
    int loggedInUserID;
    vector <User> users;
public:
    UserManager(){
        loggedInUserID = 0;
    };
    void loadDataIntoAVector();
    void userRegistration();
    User writeNewUserData();
    int getNewUserId();
    bool isThereALogin(string login);
    int userLoggIn();
    void changeOfTheLoggedInUserPassword(int loggedInUserID);
    int getTheLoggedInUserID();
    int getTheLoggedInUserIDFromUserManager();
    bool isTheUserLoggedIn();
    void loggOutOfTheUser();

};

#endif
