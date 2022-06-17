#include "FileXMLUsers.h"

void FileXMLUsers::addTheRecipientToTheFile(User user){

//    string userIdXML = "User";
//    string iString = "";

//    iString = AuxiliaryMethods::convertIntToString(user.getUserId());
//    userIdXML += iString;

    bool fileExists = xml.Load( "users.xml" );
    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.IntoElem();
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.OutOfElem();
    xml.OutOfElem();
    xml.Save("users.xml");
}

void FileXMLUsers::changeUserPassword(int loggedInUserID, vector <User> users){
    string password = "";
//    User user;
    int userIDFromXML = 0;
    cout << "Wprowadz nowe haslo: " << endl;
    cin >> password;
    users[loggedInUserID-1].setPassword(password);
                for (int i=0; i<users.size(); i++){
                    cout << "userId: " << users[i].getUserId() << endl;
                    cout << "getLogin: " << users[i].getLogin() << endl;
                    cout << "getPassword: " << users[i].getPassword() << endl;
                    cout << "getName: " << users[i].getName() << endl;
                    cout << "getSurname: " << users[i].getSurname() << endl;
                }
                system("pause");
//    users[loggedInUserID-1].setPassword(password);
    bool fileExists = xml.Load( "users.xml" );
    if (fileExists){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem()){
            xml.IntoElem();
            xml.FindElem();
            userIDFromXML = atoi(MCD_2PCSZ(xml.GetData()));
//            expenses.setExpensesId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
//            expenses.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            if (userIDFromXML == loggedInUserID){
                xml.RemoveElem();
                xml.AddElem("password", password);
                xml.Save("users.xml");
            }
            xml.FindElem();
//            expenses.setItem(xml.GetData());
            xml.FindElem();
//            expenses.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.OutOfElem();
        }
    }
    cout << "Haslo zmieniono pomyslnie!" << endl;
    getch();
}
