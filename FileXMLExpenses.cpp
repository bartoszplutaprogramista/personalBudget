#include "FileXMLExpenses.h"

void FileXMLExpenses::addExpenseToTheFile(Expenses expenses){
//    string expenseIdXML = "Expense";
//    string iString = "";
    string amountString = "", dateString = "", dateStringWithDashes = "";
    stringstream sstream;
    dateString = AuxiliaryMethods::convertIntToString(expenses.getDate());
    dateStringWithDashes = Date::insertDashes(dateString);

    sstream << expenses.getAmount();
    amountString = sstream.str();

//    iString = AuxiliaryMethods::convertIntToString(expenses.getExpensesId());
//    expenseIdXML += iString;

    bool fileExists = xml.Load( "expenses.xml" );
    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        xml.IntoElem();
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("expenseId", expenses.getExpensesId());
    xml.AddElem("UserId", expenses.getUserId());
    xml.AddElem("Date", dateStringWithDashes);
    xml.AddElem("Item", expenses.getItem());
    xml.AddElem("Amount", amountString);
    xml.OutOfElem();
    xml.OutOfElem();
    xml.Save("expenses.xml");
}

vector <Expenses> FileXMLExpenses::loadDataOfExpensesIntoAnAuxiliaryVector(const int LOGGED_IN_USER_ID){
    Expenses expenses;
    CMarkup xml;
    vector <Expenses> expensesAuxiliary;
    bool fileExists = xml.Load( "expenses.xml" );
    if (fileExists){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem()){
            xml.IntoElem();
            xml.FindElem();
            expenses.setExpensesId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            expenses.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            expenses.setDate(AuxiliaryMethods::convertStringToInt(Date::getYearMonthDay(MCD_2PCSZ(xml.GetData()))));
            xml.FindElem();
            expenses.setItem(xml.GetData());
            xml.FindElem();
            expenses.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.OutOfElem();
            if(expenses.getUserId() == LOGGED_IN_USER_ID){
                expensesAuxiliary.push_back(expenses);
            }
        }
    }
    return expensesAuxiliary;
}

int FileXMLExpenses::getLastNumberOfExpenseID(){
    Expenses expenses;
    CMarkup xml;
    bool fileExists = xml.Load( "expenses.xml" );
    if (fileExists){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem()){
            xml.IntoElem();
            xml.FindElem();
            expenses.setExpensesId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            expenses.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            expenses.setDate(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            expenses.setItem(xml.GetData());
            xml.FindElem();
            expenses.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.OutOfElem();
        }
    }
    else {
        expenses.setExpensesId(0);
    }
    return expenses.getExpensesId();
}
