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
//    User user;
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}


bool UserManager::isThereALogin(string login)
{
    for (int i=0; i<users.size(); i++){
        if (users[i].getLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loadDataIntoAVector(){
    cout << "WSZEDLEM DO TEGO IFA" << endl;
    system("pause");
    User user;
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
//    if (!fileExists){
//        lastUserId = 1;
//    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem()){
        xml.IntoElem();
        xml.FindElem();
        user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
//        cout << "USERID: " << user.getUserId() << endl;
//        system("pause");
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
    for (int i=0; i<users.size(); i++){
        cout << "userId: " << users[i].getUserId() << endl;
        cout << "getLogin: " << users[i].getLogin() << endl;
        cout << "getPassword: " << users[i].getPassword() << endl;
        cout << "getName: " << users[i].getName() << endl;
        cout << "getSurname: " << users[i].getSurname() << endl;
    }
    system("pause");
}

/*
void UzytkownikMenedzer::wypiszWszystkichUzytkownikow(){
    for (int i=0; i<uzytkownicy.size(); i++){
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

int UzytkownikMenedzer::logowanieUzytkownika(){
    Uzytkownik uzytkownik;
    MetodyPomocnicze metodyPomocnicze;
    string login = "", haslo = "";
    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    ustawIdZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                    return idZalogowanegoUzytkownika;
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

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany(){
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int id){
    idZalogowanegoUzytkownika = id;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::wylogowanieUzytkownika(){
    idZalogowanegoUzytkownika = 0;
} */
