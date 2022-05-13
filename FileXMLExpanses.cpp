/*
#include "FileXMLExpanses.h"

void FileXMLExpanses::addExpansesToTheFile(User user){

    string expanseIdXML = "Expanse";
    string iString = "";
    iString = AuxiliaryMethods::convertIntToString(user.getUserId());
    expanseIdXML += iString;

    bool fileExists = xml.Load( "expanses.xml" );
    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expanses");
        xml.IntoElem();
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem(expanseIdXML);
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

*/
