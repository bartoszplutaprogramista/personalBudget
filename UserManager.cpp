#include "UserManager.h"

void UserManager::userRegistration(){
    User user = writeNewUserData();

    users.push_back(user);
    fileXMLUsers.addTheRecipientToTheFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::writeNewUserData(){
    User user;
    string login;
    string password;
    string name;
    string surname;

    user.setUserId(getNewUserId());

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isThereALogin(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}


int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}


bool UserManager::isThereALogin(string login)
{
    int usersSize = users.size();
    for (int i=0; i<usersSize; i++){
        if (users[i].getLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loadDataIntoAVector(){
    User user;
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
    if (fileExists){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem()){
            xml.IntoElem();
            xml.FindElem();
            user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            user.setLogin(xml.GetData());
            xml.FindElem();
            user.setPassword(xml.GetData());
            xml.FindElem();
            user.setName(xml.GetData());
            xml.FindElem();
            user.setSurname(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
/*
        for (int i=0; i<users.size(); i++){
            cout << "userId: " << users[i].getUserId() << endl;
            cout << "getLogin: " << users[i].getLogin() << endl;
            cout << "getPassword: " << users[i].getPassword() << endl;
            cout << "getName: " << users[i].getName() << endl;
            cout << "getSurname: " << users[i].getSurname() << endl;
        }
        system("pause"); */
    }
}

int UserManager::userLoggIn(){
    string login = "", password = "";
    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserID = itr -> getUserId();
                    return loggedInUserID;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changeOfTheLoggedInUserPassword(int loggedInUserID){
    FileXMLUsers fileXMLUsers;
    fileXMLUsers.changeUserPassword(loggedInUserID, users);
}

int UserManager::getTheLoggedInUserID(){
    return loggedInUserID;
}

bool UserManager::isTheUserLoggedIn(){
    if(loggedInUserID > 0)
        return true;
    else
        return false;
}

void UserManager::loggOutOfTheUser(){
    loggedInUserID = 0;
}
