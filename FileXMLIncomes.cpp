#include "FileXMLIncomes.h"

void FileXMLIncomes::addIncomeToTheFile(Incomes incomes){
    string incomeIdXML = "Income";
    string iString = "";
    string amountString = "";
    stringstream sstream;

    sstream << incomes.getAmount();
    amountString = sstream.str();

    iString = AuxiliaryMethods::convertIntToString(incomes.getIncomeId());
    incomeIdXML += iString;

    bool fileExists = xml.Load( "incomes.xml" );
    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        xml.IntoElem();
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem(incomeIdXML);
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("IncomeId ", incomes.getIncomeId());
    xml.AddElem("UserId ", incomes.getUserId());
    xml.AddElem("Date ", incomes.getDate());
    xml.AddElem("Item ", incomes.getItem());
    xml.AddElem("Amount ", amountString);
    xml.OutOfElem();
    xml.OutOfElem();
    xml.Save("incomes.xml");
}

vector <Incomes> FileXMLIncomes::loadDataOfIncomesIntoAnAuxiliaryVector(const int LOGGED_IN_USER_ID){
    Incomes incomes;
    CMarkup xml;
    vector <Incomes> incomesAuxiliary;
    bool fileExists = xml.Load( "incomes.xml" );
    if (fileExists){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem()){
            xml.IntoElem();
            xml.FindElem();
            incomes.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            incomes.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            incomes.setDate(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            incomes.setItem(xml.GetData());
            xml.FindElem();
            incomes.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.OutOfElem();
            if(incomes.getUserId() == LOGGED_IN_USER_ID){
                incomesAuxiliary.push_back(incomes);
            }
        }
/*
        for (int i=0; i<users.size(); i++){
            cout << "userId: " << users[i].getUserId() << endl;
            cout << "getLogin: " << users[i].getLogin() << endl;
            cout << "getPassword: " << users[i].getPassword() << endl;
            cout << "getName: " << users[i].getName() << endl;
            cout << "getSurname: " << users[i].getSurname() << endl;
        } */
//        system("pause");
    }
    return incomesAuxiliary;
}

int FileXMLIncomes::getLastNumberOfIncomeID(){
    cout << "WSZEDLEM DO GET LAST NUMBER" << endl;
    getch();
    Incomes incomes;
    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );
    if (fileExists){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem()){
            xml.IntoElem();
            xml.FindElem();
            incomes.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            incomes.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            incomes.setDate(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            incomes.setItem(xml.GetData());
            xml.FindElem();
            incomes.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.OutOfElem();
        }
    }
    else {
        incomes.setIncomeId(0);
    }
    cout << "incomes.getIncomeId() " << incomes.getIncomeId() << endl;
    getch();
    return incomes.getIncomeId();
}
