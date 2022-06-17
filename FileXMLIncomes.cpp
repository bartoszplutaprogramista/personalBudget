#include "FileXMLIncomes.h"

void FileXMLIncomes::addIncomeToTheFile(Incomes incomes){
//    string incomeIdXML = "Income";
//    string iString = "";
    string amountString = "", dateString = "", dateStringWithDashes = "";
    stringstream sstream;
    dateString = AuxiliaryMethods::convertIntToString(incomes.getDate());
    dateStringWithDashes = Date::insertDashes(dateString);

    sstream << incomes.getAmount();
    amountString = sstream.str();

//    iString = AuxiliaryMethods::convertIntToString(incomes.getIncomeId());
//    incomeIdXML += iString;

    bool fileExists = xml.Load( "incomes.xml" );
    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        xml.IntoElem();
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("IncomeId", incomes.getIncomeId());
    xml.AddElem("UserId", incomes.getUserId());
    xml.AddElem("Date", dateStringWithDashes);
    xml.AddElem("Item", incomes.getItem());
    xml.AddElem("Amount", amountString);
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
            incomes.setDate(AuxiliaryMethods::convertStringToInt(Date::getYearMonthDay(MCD_2PCSZ(xml.GetData()))));
            xml.FindElem();
            incomes.setItem(xml.GetData());
            xml.FindElem();
            incomes.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.OutOfElem();
            if(incomes.getUserId() == LOGGED_IN_USER_ID){
                incomesAuxiliary.push_back(incomes);
            }
        }
    }
    return incomesAuxiliary;
}

int FileXMLIncomes::getLastNumberOfIncomeID(){
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
    return incomes.getIncomeId();
}
