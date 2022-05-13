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
