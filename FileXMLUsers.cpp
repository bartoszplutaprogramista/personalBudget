#include "FileXMLUsers.h"

void FileXMLUsers::addTheRecipientToTheFile(User user){
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

void FileXMLUsers::changeUserPassword(int loggedInUserID, string password){
    int userIDFromXML = 0;
    bool fileExists = xml.Load( "users.xml" );
    if (fileExists){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem()){
            xml.IntoElem();
            xml.FindElem();
            userIDFromXML = atoi(MCD_2PCSZ(xml.GetData()));
            xml.FindElem();
            xml.FindElem();
            if (userIDFromXML == loggedInUserID){
                xml.RemoveElem();
                xml.AddElem("password", password);
                xml.Save("users.xml");
            }
            xml.FindElem();
            xml.FindElem();
            xml.OutOfElem();
        }
    }
}
