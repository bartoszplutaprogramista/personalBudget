#include "FileXMLUsers.h"
#include "FileXMLUsers.h"

void FileXMLUsers::addTheRecipientToTheFile(User user){

    string userIdXML = "User";
    string iString = "";
    iString = AuxiliaryMethods::convertIntToString(user.getUserId());
    userIdXML += iString;

    bool fileExists = xml.Load( "users.xml" );
    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.IntoElem();
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem(userIdXML);
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("UserId ", user.getUserId());
    xml.AddElem("login ", user.getLogin());
    xml.AddElem("password ", user.getPassword());
    xml.AddElem("name ", user.getName());
    xml.AddElem("surname ", user.getSurname());
    xml.OutOfElem();
    xml.OutOfElem();
    xml.Save("users.xml");
}
