#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadLine(){
    cin.clear();
    cin.sync();
    string variableIn = "";
    getline(cin, variableIn);
    return variableIn;
}

void AuxiliaryMethods::deleteXMLFile(){
    char path[] = "users.xml";
    int remove(const char *path);
    if( remove( path ) == -1 ){
      cout << "Could not delete " << path;
      getch();
    }
}

int AuxiliaryMethods::convertStringToInt(string number){
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
