#include <iostream>
#include <map>
#include <cmath>
#include <conio.h>
#include <string>
#include <iomanip> // manipulator library: here i used comand setw(50), to create space in output

using namespace std;

map <string, string> acc_pass;
map <string, int> acc_bal;

int _1000 = 1000;
int _2000 = 1000;
int _5000 = 1000;
int _10000 = 1000;
int _20000 = 1000;
int _50000 = 1000;
int _100000 = 1000;

void main_menu();

void acc_del(string acc);//deletes account

void info(string card);//all the information of the user
void info_bank(string acc);

void bal_check_bank(string acc);
void bal_check(string card);//atm

void bank_menu();
void bank_menu1(string acc);

void withdraw(int sum, string card);
void withdraw_bank(int sum, string card);

string lowercase(string word);//converts all string into a lowercase

void atm_menu();
void atm_menu1(string card);

void bal_top_up(string card);//top ups balance
void bal_top_up_bank(string card);

void new_pin1(string card);//creates new pin for the new account
void new_pin(string card);//changes pin(not for the first time)
void new_pass(string acc);//bank
void new_pass1(string acc);

void payment_services(string card); ///////////////////////////////////////////////////////���������� ����
void payment_services_bank(string card);

void anything_atm(string card);//asks for completion of other operations
void anything_bank(string acc);

void exchange(string card);
void exchange_bank(string acc);

void main_menu()//Main menu
{
    system("color F1");
    cout << setw(54) << "      ________________________________\n";
    cout << setw(55) << "    |                                |\n";
    cout << setw(55) << "    |     BANK MANAGEMENT SYSTEM     |\n";
    cout << setw(55) << "    |________________________________|\n";
    cout << endl;
    cout << setw(45) << "--DEAR USER--\n";
    cout << setw(65) << "--SELECT OPTION 1 OR 2 FOR FURTHER OPERATIONS--" << endl;
    cout << setw(50) << "\n\n1. BANK ACCOUNT\n\n2. ATM\n\n";
    cout << "-Your option: ";
    string ch = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a >= '1' && a <= '2' && i < 1)
        {
            ch += a;
            cout << a;
            i++;
        }
        if (a == '\b' && i > 0)
        {
            ch.pop_back();
            i--;
            cout << "\b \b";
        }
        if (a == '\r' && i == 1)
        {
            break;
        }
    }
    if (ch == "1")
    {
        system("CLS");
        bank_menu();
    }
    else if (ch == "2")
    {
        system("CLS");
        atm_menu();
    }
    else
    {
        system("CLS");
        cout << "WRONG INPUT\n";
        main_menu();
    }
}

void bank_menu()//Banking menu
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |      - BANK -     |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << endl;
    cout << setw(56) << "< < < BACK TO MAIN MANU - '0' > > >" << endl;
    cout << setw(56) << "-----------------------------------" << endl << endl;
    cout << "INSERT PASSPORT SERIES NUMBER : \n";
    cout << "(2 letters and 7 digits )\n";
    string acc = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        a = toupper(a);
        if (a == '0' && i == 0)//NULL character
        {
            system("CLS");
            main_menu();
        }
        if (a >= 'A' && a <= 'Z' && (i == 0 || i == 1))
        {
            acc += a;
            ++i;
            cout << a;
        }
        if (a >= '0' && a <= '9' && (i > 1) && (i < 9))
        {
            acc += a;
            ++i;
            cout << a;
        }
        if (a == '\b' && i >= 1)//Backspace character
        {
            acc.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && acc != "" && i == 9)//Enter character
        {
            break;
        }
    }
    cout << endl;
    if (acc == "0")
    {
        system("CLS");
        main_menu();
    }
    else  if (acc_pass[acc] == "")
    {
        cout << setw(55) << " < AS THAT IS YOUR FIRST SESSION > \n";
        cout << setw(55) << " _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl << endl;
        cout << setw(50) << " << CREATE A PASSWORD >> \n\n";
        new_pass1(acc);
    }
    else
    {
        cout << "YOUR PASSWORD, PLEASE:\n";
        char a;
        string pass = "";
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '\r' && pass == "0")
            {
                system("CLS");
                main_menu();
            }
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
            {
                pass += a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                pass.pop_back();
                cout << "\b \b";
                --i;
            }
            if (a == '\r' && pass != "")
            {
                break;
            }
        }
        cout << endl;
        if (acc_pass[acc] != "")
        {
            while (acc_pass[acc] != pass)
            {
                pass = "";
                cout << setw(60) << "BACK TO MAIN MENU - '0'";
                cout << setw(60) << "<<  WRONG PASSWORD >>   \n";
                char a;
                for (int i = 0;;)
                {
                    a = _getch();
                    if (a == '\r' && pass == "0")
                    {
                        system("CLS");
                        main_menu();
                    }
                    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
                    {
                        pass += a;
                        ++i;
                        cout << "*";
                    }
                    if (a == '\b' && i >= 1)
                    {
                        pass.pop_back();
                        cout << "\b \b";
                        --i;
                    }
                    if (a == '\r' && pass != "")
                    {
                        break;
                    }
                }
                cout << endl;
            }
            if (pass == acc_pass[acc])
            {
                system("CLS");
                bank_menu1(acc);
            }
        }
    }
}



void bank_menu1(string acc)//Banking menu 1
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |     BANK MENU     |\n";
    cout << setw(50) << "    |___________________|\n";

    cout << setw(57) << "____ CHOOSE OPERATION TO COMPLETE ____" << endl << endl;


    cout << " 0 <->       MAIN MENU       <-> 0" << endl << endl;
    cout << " 1 <->        BALANCE        <-> 1" << endl << endl;
    cout << " 2 <->   DELETE AN ACCOUNT   <-> 2" << endl << endl;
    cout << " 3 <->    CASH WITHDRAWAL    <-> 3" << endl << endl;
    cout << " 4 <->     MONEY EXCHANGE    <-> 4" << endl << endl;
    cout << " 5 <->    PAYMENT SERVICES   <-> 5" << endl << endl;
    cout << " 6 <-> BALANCE REPLENISHMENT <-> 6" << endl << endl;
    cout << " 7 <->    CHANGE PASSWORD    <-> 7" << endl << endl;
    cout << " 8 <->      INFORMATION      <-> 8" << endl << endl;

    cout << " YOUR OPERATION :";
    string ch = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a >= '0' && a <= '8' && i < 1)
        {
            ch += a;
            cout << a;
            i++;
        }
        if (a == '\b' && i > 0)
        {
            ch.pop_back();
            i--;
            cout << "\b \b";
        }
        if (a == '\r' && i == 1)
        {
            break;
        }
    }
    if (ch == "1")
    {
        system("CLS");
        bal_check_bank(acc);
    }
    else if (ch == "2")
    {
        system("CLS");
        acc_del(acc);
    }
    else if (ch == "3")
    {
        system("CLS");
        cout << setw(49) << "     ___________________\n";
        cout << setw(50) << "    |                   |\n";
        cout << setw(50) << "    |       CASH        |\n";
        cout << setw(50) << "    |    WITHDRAWAL     |\n";
        cout << setw(50) << "    |___________________|\n";
        cout << endl;
        cout << setw(47) << "<0>-BANK MENU-<0>" << endl;
        cout << setw(50) << "< HOW MUCH TO WITHDRAW? >" << endl;
        cout << "Operation takes 1%\n";
        cout << "1. 50000" << endl;
        cout << "2. 100000" << endl;
        cout << "3. 200000" << endl;
        cout << "4. 300000" << endl;
        cout << "5. 400000" << endl;
        cout << "6. 500000" << endl;
        cout << "7. Other amount" << endl;
        cout << "-> Option: ";

        string ch = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a >= '0' && a <= '7' && i < 1)
            {
                ch += a;
                cout << a;
                i++;
            }
            if (a == '\b' && i > 0)
            {
                ch.pop_back();
                i--;
                cout << "\b \b";
            }
            if (a == '\r' && i == 1)
            {
                break;
            }
        }
        if (ch == "1")
        {
            system("CLS");
            withdraw_bank(50000, acc);
        }
        else if (ch == "2")
        {
            system("CLS");
            withdraw_bank(100000, acc);
        }
        else if (ch == "3")
        {
            system("CLS");
            withdraw_bank(200000, acc);
        }
        else if (ch == "4")
        {
            system("CLS");
            withdraw_bank(300000, acc);
        }
        else if (ch == "5")
        {
            system("CLS");
            withdraw_bank(400000, acc);
        }
        else if (ch == "6")
        {
            system("CLS");
            withdraw_bank(500000, acc);
        }
        else if (ch == "7")
        {
            system("CLS");
            int money;
            cout << setw(49) << "     ___________________\n";
            cout << setw(50) << "    |                   |\n";
            cout << setw(50) << "    |       CASH        |\n";
            cout << setw(50) << "    |    WITHDRAWAL     |\n";
            cout << setw(50) << "    |___________________|\n";
            cout << endl;
            cout << setw(53) << "<0> -> BANK MENU <- <0>" << endl;
            cout << setw(60) << "Please insert multiple 1000 number." << endl;
            cout << "-> MONEY: ";
            cin >> money;
            while (true)
            {
                if (money % 1000 == 0) break;
                system("CLS");
                cout << setw(60) << ">>> WRONG INPUT <<<" << endl;
                cout << setw(60) << "<<< TRY AGAIN >>>" << endl;
                cout << "-> MONEY: ";
                cin >> money;
            }
            if (money == 0)
            {
                system("CLS");
                bank_menu1(acc);
            }
            system("CLS");
            withdraw_bank(money, acc);
        }
        else if (ch == "0")
        {
            system("CLS");
            bank_menu1(acc);
        }
    }
    else if (ch == "4")
    {
        system("CLS");
        exchange_bank(acc);
    }
    else if (ch == "5")
    {
        system("CLS");
        payment_services_bank(acc);
    }
    else if (ch == "6")
    {
        system("CLS");
        bal_top_up_bank(acc);
    }
    else if (ch == "7")
    {
        system("CLS");
        new_pass(acc);
    }
    else if (ch == "8")
    {
        system("CLS");
        info_bank(acc);
    }
    else if (ch == "0")
    {
        system("CLS");
        main_menu();
    }
}

void anything_bank(string acc)//Asks for other operations in bank
{
    cout << setw(60) << "DO YOU HAVE OTHER OPERATIONS TO COMPLETE ?" << endl;
    cout << setw(30) << "1 - YES - 1";
    cout << setw(30) << "2 - NO - 2 " << endl;
    cout << "-YOUR ANSWER :";
    string ch = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a >= '1' && a <= '2')
        {
            ch += a;
            cout << a;
            i++;
        }
        if (a == '\b' && i > 0)
        {
            ch.pop_back();
            i--;
            cout << "\b \b";
        }
        if (a == '\r' && i == 1)
        {
            break;
        }
    }
    if (ch == "1")
    {
        system("CLS");
        bank_menu1(acc);
    }
    else if (ch == "2")
    {
        system("CLS");
        cout << endl;
        cout << setw(65) << "<- <- <- THANK YOU FOR BANKING AND BEING WITH US -> -> -> " << endl;
        main_menu();
    }
}

void bal_check_bank(string acc)//Prints account's balance
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |      BALANCE      |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(45) << " -YOUR BALANCE :" << endl;
    cout << setw(35) << "-> ->" << acc_bal[acc] << " UZS" << "<- <-" << endl << endl;
    anything_bank(acc);
}

void acc_del(string acc)//deletes banking account from the database
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |      ACCOUNT      |\n";
    cout << setw(50) << "    |     DELETING      |\n";
    cout << setw(50) << "    |___________________|\n";
    if (acc_bal[acc] != 0)
    {
        cout << "Note that:\nThe remainder of your balance " << acc_bal[acc] << " UZS " << "will be allocated to charity funds." << endl;
        cout << "Are you sure that you want to delete your account?\n";
        cout << "1. YES .1\n2. NO .2\n";
        string ch = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a >= '1' && a <= '2' && i < 1)
            {
                ch += a;
                cout << a;
                i++;
            }
            if (a == '\b' && i > 0)
            {
                ch.pop_back();
                i--;
                cout << "\b \b";
            }
            if (a == '\r' && i == 1)
            {
                break;
            }
        }
        if (ch == "1")
        {
            system("CLS");
            acc_pass[acc] = "";
            acc_bal[acc] = 0;
            cout << setw(50) << "-_-_-_- YOUR ACCOUNT WAS SUCCESSFULLY DELETED -_-_-_- " << endl;
            cout << setw(50) << "<> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> " << endl;
            main_menu();
        }
        else if (ch == "2")
        {
            system("CLS");
            bank_menu1(acc);
        }
    }
    else
    {
        acc_bal[acc] = 0;
        acc_pass[acc] = "";
        system("CLS");
        cout << setw(64) << "-_-_-_- YOUR ACCOUNT WAS SUCCESSFULLY DELETED -_-_-_- " << endl;
        cout << setw(64) << "<> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> " << endl;
        main_menu();
    }
}

void withdraw_bank(int sum, string acc)//Money withdrawal in bank
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |       CHECK       |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << "Operation cost: " << sum * 0.01 << " UZS" << endl;
    int k1 = 0;
    int k2 = 0;
    int k5 = 0;
    int k10 = 0;
    int k20 = 0;
    int k50 = 0;
    int k100 = 0;
    if (sum > acc_bal[acc])
    {
        system("CLS");
        cout << setw(70) << "<<>><<>>UNFORTUNATELY YOU HAVE NO MONEY TO WITHDRAW<<>><<>>" << endl;
        cout << setw(70) << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        bank_menu1(acc);
    }
    else
    {
        acc_bal[acc] -= sum * 0.01;
        while (sum >= 100000)
        {
            if (_100000 > 0)
            {
                _100000--;
                sum -= 100000;
                acc_bal[acc] -= 100000;
                k100++;
            }
            else break;
        }
        while (sum >= 50000)
        {
            if (_50000 > 0)
            {
                _50000--;
                sum -= 50000;
                acc_bal[acc] -= 50000;
                k50++;
            }
            else break;
        }
        while (sum >= 20000)
        {
            if (_20000 > 0)
            {
                _20000--;
                sum -= 20000;
                acc_bal[acc] -= 20000;
                k20++;
            }
            else break;

        }
        while (sum >= 10000)
        {
            if (_10000 > 0)
            {
                _10000--;
                sum -= 10000;
                acc_bal[acc] -= 10000;
                k10++;
            }
            else break;
        }
        while (sum >= 5000)
        {
            if (_5000 > 0)
            {
                _5000--;
                sum -= 5000;
                acc_bal[acc] -= 5000;
                k5++;
            }
            else break;
        }
        while (sum >= 2000)
        {
            if (_2000 > 0)
            {
                _2000--;
                sum -= 2000;
                acc_bal[acc] -= 2000;
                k2++;
            }
            else break;
        }
        while (sum >= 1000)
        {
            if (_1000 > 0)
            {
                _1000--;
                sum -= 1000;
                acc_bal[acc] -= 1000;
                k1++;
            }
            else break;
        }
        if (sum == 0)
        {
            cout << "You have got:\n";
            if (k100 > 0) cout << k100 << " - 100.000 UZS banknote(s)\n";
            if (k50 > 0) cout << k50 << " - 50.000 UZS banknote(s)\n";
            if (k20 > 0) cout << k20 << " - 20.000 UZS banknote(s)\n";
            if (k10 > 0) cout << k10 << " - 10.000 UZS banknote(s)\n";
            if (k5 > 0) cout << k5 << " - 5.000 UZS banknote(s)\n";
            if (k2 > 0) cout << k2 << " - 2.000 UZS banknote(s)\n";
            if (k1 > 0) cout << k1 << " - 1.000 UZS banknote(s)\n";
            cout << "Your balance:\n" << acc_bal[acc] << " UZS" << endl;
            anything_bank(acc);
        }
        else
        {
            cout << "Unfortunately, there is no enough banknotes in ATM.\nSorry, for inconvenience\n";
            anything_bank(acc);
        }
    }
}

void exchange_bank(string acc)
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |       MONEY       |\n";
    cout << setw(50) << "    |     EXCHANGE      |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(56) << "< < < BACK TO MAIN MANU - '0' > > >" << endl << endl;
    cout << setw(53) << "____ENTER FOREIGN CURRENCY____" << endl;
    cout << "EXCHANGE RATES:\n1. 1 USD = 10750 UZS\n";
    cout << "2. 1 EUR = 12230 UZS\n";
    cout << "3. 1 GBP = 14382 UZS\n";
    cout << "4. 1 RUB = 149 UZS\n";
    cout << "5. 1 KRW = 9 UZS\n";
    cout << "6. 1 INR = 145 UZS\n";
    string money = "";
    string num = "";
    string cur = "";
    cout << "Please insert your amount of foreign money and right after it the currency:\n";
    cout << "Input sample: '20USD'\n";
    cout << "> > >FOREIGN CURRENCY :";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        a = toupper(a);
        if (a == '\r' && num == "0")
        {
            system("CLS");
            bank_menu1(acc);
        }
        if (a >= '0' && a <= '9')
        {
            num += a;
            ++i;
            cout << a;
        }
        if (a >= 'A' && a <= 'Z' && i > 0)
        {
            cur += a;
            ++i;
            cout << a;
        }
        if (a == '\b' && i >= 1)
        {
            cur.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && cur != "")
        {
            break;
        }
    }
    cout << endl;
    int value = 0;
    for (int i = 0; i < num.size(); i++)
    {
        value += (int(num[i]) - 48) * pow(10, num.size() - i - 1);
    }
    if (value < 0)
    {
        system("CLS");
        cout << setw(60) << "!-!-! Wrong Input , TRY AGAIN !-!-!\n";
        exchange_bank(acc);
    }
    if (cur == "USD")
    {
        value = value * 10750;
    }
    else if (cur == "EUR")
    {
        value = value * 12230;
    }
    else if (cur == "GBP")
    {
        value = value * 14382;
    }
    else if (cur == "RUB")
    {
        value = value * 149;
    }
    else if (cur == "KRW")
    {
        value = value * 9;
    }
    else if (cur == "INR")
    {
        value = value * 145;
    }
    else
    {
        system("CLS");
        cout << setw(50) << "><><UNKNOWN CURRENCY INPUT - TRY AGAIN ><><\n";
        exchange_bank(acc);
    }
    int k1 = 0;
    int k2 = 0;
    int k5 = 0;
    int k10 = 0;
    int k20 = 0;
    int k50 = 0;
    int k100 = 0;
    while (value >= 100000)
    {
        _100000--;
        value -= 100000;
        k100++;
    }
    while (value >= 50000)
    {
        _50000--;
        value -= 50000;
        k50++;
    }
    while (value >= 20000)
    {
        _20000--;
        value -= 20000;
        k20++;
    }
    while (value >= 10000)
    {
        _10000--;
        value -= 10000;
        k10++;
    }
    while (value >= 5000)
    {
        _5000--;
        value -= 5000;
        k5++;
    }
    while (value >= 2000)
    {
        _2000--;
        value -= 2000;
        k2++;
    }
    while (value >= 1000)
    {
        _1000--;
        value -= 1000;
        k1++;
    }
    if (value != 0)
    {
        cout << "Unfortunately, there is no enough banknotes, so the rest of your sum (" << value << " UZS) are sent to your account\n";
        acc_bal[acc] += value;
    }
    if (k1 != 0 || k2 != 0 || k5 != 0 || k10 != 0 || k20 != 0 || k50 != 0 || k100 != 0)
    {
        cout << "You have got:\n";
        if (k100 > 0) cout << k100 << " - 100.000 UZS banknote(s)\n";
        if (k50 > 0) cout << k50 << " - 50.000 UZS banknote(s)\n";
        if (k20 > 0) cout << k20 << " - 20.000 UZS banknote(s)\n";
        if (k10 > 0) cout << k10 << " - 10.000 UZS banknote(s)\n";
        if (k5 > 0) cout << k5 << " - 5.000 UZS banknote(s)\n";
        if (k2 > 0) cout << k2 << " - 2.000 UZS banknote(s)\n";
        if (k1 > 0) cout << k1 << " - 1.000 UZS banknote(s)\n\n";
    }
    cout << setw(45) << " -YOUR BALANCE :" << endl;
    cout << setw(35) << "-> ->" << acc_bal[acc] << " UZS" << "<- <-" << endl << endl;
    anything_bank(acc);
}

void new_pass(string acc)//Sets new password for the banking account
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |        NEW        |\n";
    cout << setw(50) << "    |     PASSWORD      |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(56) << "< < < BACK TO MAIN MANU - '0' > > >" << endl << endl;
    cout << "-}-> YOUR CURRENT PASSWORD:\n";
    string pass3 = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && pass3 == "0")
        {
            system("CLS");
            bank_menu1(acc);
        }
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            pass3 += a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            pass3.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && pass3 != "")
        {
            break;
        }
    }
    cout << endl;
    if (pass3 == acc_pass[acc])
    {
        cout << " -> YOUR NEW PASSWORD:\n";
        string pass = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '\r' && pass == "0")
            {
                system("CLS");
                bank_menu1(acc);
            }
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
            {
                pass += a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                pass.pop_back();
                cout << "\b \b";
                --i;
            }
            if (a == '\r' && pass != "")
            {
                break;
            }
        }
        cout << endl;
        cout << "\n REPEAT YOUR NEW PASSWORD: \n";
        string pass1 = "";
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '\r' && pass == "0")
            {
                system("CLS");
                bank_menu1(acc);
            }
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
            {
                pass1 += a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                pass1.pop_back();
                cout << "\b \b";
                --i;
            }
            if (a == '\r' && pass1 != "")
            {
                break;
            }
        }
        cout << endl;
        if (pass1 == pass)
        {
            acc_pass[acc] = pass;
            cout << setw(65) << " - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << setw(65) << "<- <- <-  YOUR PASSWORD WAS SUCCESSFULLY CHANGED  -> -> ->\n";
            cout << setw(65) << " - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            anything_bank(acc);
        }
        else
        {
            system("CLS");
            cout << setw(65) << " #=#=# YOUR TWO PASSWORDS ARE NOT THE SAME #=#=#" << endl;
            cout << setw(65) << "      #=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#     " << endl;
            cout << setw(50) << "|__TRY AGAIN__| \n";
            new_pass1(acc);
        }
    }
    else
    {
        system("CLS");
        cout << setw(50) << "WRONG PASSWORD\n";
        new_pass(acc);
    }
}

void new_pass1(string acc)//Sets new password for the banking account
{

    cout << "\n YOUR NEW PASSWORD, PLEASE:\n";
    string pass = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && pass == "0")
        {
            system("CLS");
            main_menu();
        }
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            pass += a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            pass.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && pass != "")
        {
            break;
        }
    }
    cout << endl;
    cout << "\n REPEAT YOUR PASSWORD: \n";
    string pass1 = "";
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && pass1 == "0")
        {
            system("CLS");
            main_menu();
        }
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            pass1 += a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            pass1.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && pass1 != "")
        {
            break;
        }
    }
    cout << endl;
    if (pass1 == pass)
    {
        acc_pass[acc] = pass;
        cout << setw(65) << " - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << setw(65) << "<- <- <-  YOUR PASSWORD WAS SUCCESSFULLY SET  -> -> ->\n";
        cout << setw(65) << " - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        anything_bank(acc);
    }
    else
    {
        system("CLS");
        cout << setw(65) << " #=#=# YOUR TWO PASSWORDS ARE NOT THE SAME #=#=#" << endl;
        cout << setw(65) << "      #=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#     " << endl;
        cout << setw(50) << "|__TRY AGAIN__| \n";
        new_pass1(acc);
    }
}


void bal_top_up_bank(string acc)//Top ups balance in bank
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |      BALANCE      |\n";
    cout << setw(50) << "    |   REPLENISHMENT   |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(56) << "< < < BACK TO MAIN MANU - '0' > > >" << endl << endl;
    cout << " -> -> ->  Please insert banknotes starting from 1000 UZS up to 100000 UZS\n\n";
    cout << ">> AMOUNT >>: ";
    int money;
    cin >> money;
    if (money == 0)
    {
        system("CLS");
        bank_menu1(acc);
    }

    if (money % 1000 != 0)
    {
        system("CLS");
        cout << "Wrong amount.\nPlease try again\n";
        bal_top_up_bank(acc);
    }
    acc_bal[acc] += money;
    cout << "-}-> AMOUNT OF MONEY ON YOUR BALANCE -->:" << acc_bal[acc] << " UZS" << endl << endl;
    int sum = money;
    while (sum >= 100000)
    {
        if (_100000 > 0)
        {
            _100000++;
            sum -= 100000;
        }
        else break;
    }
    while (sum >= 50000)
    {
        if (_50000 > 0)
        {
            _50000++;
            sum -= 50000;
        }
        else break;
    }
    while (sum >= 20000)
    {
        if (_20000 > 0)
        {
            _20000++;
            sum -= 20000;
        }
        else break;

    }
    while (sum >= 10000)
    {
        if (_10000 > 0)
        {
            _10000++;
            sum -= 10000;
        }
        else break;
    }
    while (sum >= 5000)
    {
        if (_5000 > 0)
        {
            _5000++;
            sum -= 5000;
        }
        else break;
    }
    while (sum >= 2000)
    {
        if (_2000 > 0)
        {
            _2000++;
            sum -= 2000;
        }
        else break;
    }
    while (sum >= 1000)
    {
        if (_1000 > 0)
        {
            _1000++;
            sum -= 1000;
        }
        else break;
    }
    anything_bank(acc);
}



void payment_services_bank(string acc)
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |      PAYMENT      |\n";
    cout << setw(50) << "    |        FOR        |\n";
    cout << setw(50) << "    |     SERVICES      |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
    cout << setw(50) << ">1< <PAYMENT> >1<" << endl;
    cout << setw(50) << ">2< <UTILITIES> >2<" << endl;
    cout << "-> OPTION: ";
    string uti = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && uti == "0")
        {
            system("CLS");
            bank_menu1(acc);
        }
        if (a >= '0' && a <= '2' && i < 1)
        {
            uti += a;
            cout << a;
            i++;
        }
        if (a == '\b' && i > 0)
        {
            uti.pop_back();
            i--;
            cout << "\b \b";
        }
        if (a == '\r' && i == 1)
        {
            break;
        }
    }
    cout << endl;
    int b;
    b = (int(uti[0]) - 48);
    switch (b)
    {
    case 1:
    {
        system("CLS");
        cout << setw(49) << "     ___________________\n";
        cout << setw(50) << "    |                   |\n";
        cout << setw(50) << "    |      PAYMENT      |\n";
        cout << setw(50) << "    |        FOR        |\n";
        cout << setw(50) << "    |     SERVICES      |\n";
        cout << setw(50) << "    |___________________|\n";
        cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
        cout << "-> TOP UP PHONE BALANCE -> 1" << endl;
        cout << "-> ATTO -> 2" << endl;
        cout << "-> INTERNET PROVIDER -> 3\n";
        cout << "-> option: ";
        string ch = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '\r' && ch == "0")
            {
                system("CLS");
                payment_services_bank(acc);
            }
            if (a >= '0' && a <= '3' && i < 1)
            {
                ch += a;
                cout << a;
                i++;
            }
            if (a == '\b' && i > 0)
            {
                ch.pop_back();
                i--;
                cout << "\b \b";
            }
            if (a == '\r' && i == 1)
            {
                break;
            }
        }
        cout << endl;
        int b = int(ch[0]) - 48;
        switch (b)
        {
        case 1:
        {
            system("CLS");
            string phone_number = "";
            int sum;
            cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << " -}-> PLEASE ENTER PHONE NUMBER: " << endl;
            cout << "(+998)";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (phone_number == "0" && a == '\r')
                {
                    system("CLS");
                    payment_services_bank(acc);
                }
                if (a >= '0' && a <= '9' && i < 9)
                {
                    phone_number += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    phone_number.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i == 9)
                {
                    break;
                }
            }
            cout << endl;
            if (phone_number == "0")
            {
                system("CLS");
                payment_services_bank(acc);
            }
            cout << " -}-> AMOUNT TO TOP UP THE PHONE NUMBER:  ";
            cin >> sum;
            if (sum > acc_bal[acc])
            {
                system("CLS");
                cout << setw(50) << "^_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_^ " << endl;
                cout << setw(50) << "|NOT ENOUGH MONEY ON YOUR ACCOUNT|" << endl;
                cout << setw(50) << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
                payment_services_bank(acc);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[acc] -= sum;
                anything_bank(acc);
            }
            break;
        }
        case 2:
        {
            system("CLS");
            string transport_card_num = "";
            int mon;
            cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << "--> ENTER YOUR CARD NUMBER <ATTO>: ";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (transport_card_num == "0" && a == '\r')
                {
                    system("CLS");
                    payment_services_bank(acc);
                }
                if (a >= '0' && a <= '9' && i < 16)
                {
                    transport_card_num += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    transport_card_num.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i == 16)
                {
                    break;
                }
            }
            cout << endl;
            cout << "AMOUNT YOU WANT TO TOP UP TO THE TRANSPORT CARD : ";
            cin >> mon;
            if (mon > acc_bal[acc])
            {
                system("CLS");
                cout << setw(50) << ">>-}-> NOT ENOUGH MONEY ON YOUR BALANCE <-{-<<" << endl;
                payment_services_bank(acc);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[acc] -= mon;
                anything_bank(acc);
            }
            break;
        }
        case 3:
        {
            system("CLS");
            string phone_number = "";
            int sum;
            cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << " Internet account's number: ";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (phone_number == "0" && a == '\r')
                {
                    system("CLS");
                    payment_services_bank(acc);
                }
                if (a >= '0' && a <= '9' && i < 9)
                {
                    phone_number += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    phone_number.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << "AMOUNT  YOU WANT TO TOP UP TO YOUR ACCOUNT : ";
            cin >> sum;
            if (sum > acc_bal[acc])
            {
                system("CLS");
                cout << setw(50) << "<|><|>NOT ENOUGH MONEY ON ACCOUNT<|><|> " << endl;
                payment_services_bank(acc);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[acc] -= sum;
                anything_bank(acc);
            }
            break;
        }
        default:
            system("CLS");
            cout << "WRONG INPUT\n";
            payment_services_bank(acc);
            break;
        }
    }
    case 2:
    {
        system("CLS");
        cout << setw(49) << " _____________" << endl;
        cout << setw(50) << "|             |" << endl;
        cout << setw(50) << "|  UTILITIES  |" << endl;
        cout << setw(50) << "|_____________|" << endl;
        cout << endl;
        cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;

        cout << "1.! ! !GAS! ! !" << endl;
        cout << "2.> > >ELECTRICITY< < <" << endl;
        cout << "3.< < <WATER> > >" << endl;
        cout << "4.! ! !GARBAGE PAYMENT! ! !" << endl;
        string uti = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '\r' && uti == "0")
            {
                system("CLS");
                payment_services_bank(acc);
            }
            if (a >= '0' && a <= '4' && i < 1)
            {
                uti += a;
                cout << a;
                i++;
            }
            if (a == '\b' && i > 0)
            {
                uti.pop_back();
                i--;
                cout << "\b \b";
            }
            if (a == '\r' && i == 1)
            {
                break;
            }
        }
        cout << endl;
        int b;
        b = (int(uti[0]) - 48);
        switch (b)
        {
        case 1:
        {
            system("CLS");
            int c;
            cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << "GAS PAYMENT" << endl;
            cout << "ENTER PERSONAL ACCOUNT : " << endl;
            string A = "";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (a == '\r' && A == "0")
                {
                    system("CLS");
                    payment_services_bank(acc);
                }
                if (a >= '0' && a <= '9' && i < 10)
                {
                    A += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    A.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << setw(50) << "YOUR TARIFF: 295 UZS" << endl;
            cout << setw(55) << "How much do you want to top up?" << " (UZS)" << endl;
            cin >> c;
            if (c > acc_bal[acc])
            {
                system("CLS");
                cout << setw(50) << "{{{}}} NOT ENOUGH MONEY {{{}}}" << endl;
                payment_services_bank(acc);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[acc] -= c;
                anything_bank(acc);
            }
            break;
        }
        case 2:
        {
            system("CLS");
            int cs;
            cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << "ELECTRICITY PAYMENT" << endl;
            cout << "ENTER PERSONAL ACCOUNT : " << endl;
            string A = "";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (a == '\r' && A == "0")
                {
                    system("CLS");
                    payment_services_bank(acc);
                }
                if (a >= '0' && a <= '9' && i < 10)
                {
                    A += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    A.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << "YOUR TARIFF: 400 UZS" << endl;
            cout << "How much do you want to top up?" << "(UZS)" << endl;
            cin >> cs;
            if (cs > acc_bal[acc])
            {
                system("CLS");
                cout << setw(50) << "You have no enough money." << endl;
                payment_services_bank(acc);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[acc] -= cs;
                anything_bank(acc);
            }
            break;
        }
        case 3:
        {
            system("CLS");
            int csh;
            cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << "WATER PAYMENT" << endl;
            cout << "ENTER PERSONAL ACCOUNT : " << endl;
            string A = "";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (a == '\r' && A == "0")
                {
                    system("CLS");
                    payment_services_bank(acc);
                }
                if (a >= '0' && a <= '9' && i < 10)
                {
                    A += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    A.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << "YOUR TARIFF: 257 UZS" << endl;
            cout << "How much do you want to top up?" << "(UZS)" << endl;
            cin >> csh;
            if (csh > acc_bal[acc])
            {
                system("CLS");
                cout << setw(50) << "You have no enough money." << endl;
                payment_services_bank(acc);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[acc] -= csh;
                anything_bank(acc);
            }
            break;
        }
        case 4:
        {
            system("CLS");
            int csh;
            cout << setw(60) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << setw(55) << "__________________________" << endl;
            cout << setw(55) << "< < <  GARBAGE PAYMENT   > > >" << endl;
            cout << setw(55) << "__________________________" << endl;
            cout << "ENTER PERSONAL ACCOUNT : " << endl;
            string A = "";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (a == '\r' && A == "0")
                {
                    system("CLS");
                    payment_services_bank(acc);
                }
                if (a >= '0' && a <= '9' && i < 10)
                {
                    A += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    A.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << "-----> YOUR TARIFF: 128 UZS <-----" << endl;
            cout << "HOW MUCH DO YOU WANT TO TOP UP?" << "(UZS)" << endl;
            cin >> csh;
            if (csh > acc_bal[acc])
            {
                system("CLS");
                cout << setw(60) << "<_____NOT ENOUGH MONEY_____>" << endl;
                bank_menu1(acc);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[acc] -= csh;
                anything_bank(acc);
            }
            break;
        }
        default:
            system("CLS");
            cout << setw(60) << "__WRONG INPUT__\n";
            payment_services_bank(acc);
            break;
        }
        break;
    }
    }
}



void info_bank(string acc)//Shows information of the BANK user
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |    INFORMATION    |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(50) << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
    cout << setw(43) << "YOUR PASSPORT SERIES NUMBER:" << acc << endl;
    cout << setw(50) << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
    cout << endl;
    cout << setw(50) << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
    cout << setw(40) << "YOUR PASSWORD:" << acc_pass[acc] << endl;
    cout << setw(50) << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
    anything_bank(acc);
}

//ATM FUNCTIONS

void atm_menu()//Atm menu
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |        ATM        |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(56) << "< < < BACK TO MAIN MANU - '0' > > >" << endl;
    cout << setw(56) << "-----------------------------------" << endl << endl;
    cout << "INSERT YOUR CARD NUMBER: \n";
    cout << "(16 digits)\n";
    string card = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && card == "0")
        {
            system("CLS");
            main_menu();
        }
        if (a >= '0' && a <= '9' && i < 16)
        {
            card += a;
            ++i;
            cout << a;
        }
        if (i % 4 == 0 && i != 16 && i != 0)
        {
            cout << '-';
        }
        if (a == '\b' && i >= 1)
        {
            if (i % 4 == 0 && i != 16)
            {
                cout << "\b \b";
                cout << "\b \b";
            }
            card.pop_back();
            --i;
            cout << "\b \b";
        }
        if (a == '\r' && card != "" && i == 16)
        {
            break;
        }
    }
    cout << endl;
    if (card == "0") main_menu();
    else  if (acc_pass[card] == "")
    {
        cout << setw(55) << " < AS THAT IS YOUR FIRST SESSION > \n";
        cout << setw(55) << " _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl << endl;
        cout << setw(50) << " << CREATE A PIN >> \n\n";
        new_pin1(card);
    }
    else
    {
        cout << "YOUR PIN, PLEASE:\n";
        string pin = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a >= '0' && a <= '9')
            {
                pin += a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                pin.pop_back();
                cout << "\b \b";
                i--;
            }
            if (a == '\r' && pin != "")
            {
                break;
            }
        }
        cout << endl;
        if (acc_pass[card] != "")
        {
            while (acc_pass[card] != pin)
            {
                pin = "";
                cout << setw(60) << "BACK TO MAIN MENU - '0' ";
                cout << setw(60) << "<<  WRONG PIN >>   \n";
                for (int i = 0;;)
                {
                    a = _getch();
                    if (a == '\r' && pin == "0")
                    {
                        system("CLS");
                        main_menu();
                    }
                    if (a >= '0' && a <= '9')
                    {
                        pin += a;
                        ++i;
                        cout << "*";
                    }
                    if (a == '\b' && i >= 1)
                    {
                        pin.pop_back();
                        cout << "\b \b";
                        --i;
                    }
                    if (a == '\r' && pin != "")
                    {
                        break;
                    }
                }
                cout << endl;
            }
            if (pin == acc_pass[card])
            {
                system("CLS");
                atm_menu1(card);
            }
        }
    }
}

void atm_menu1(string card)//Atm menu 1
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |      ATM MENU     |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(57) << "____ CHOOSE OPERATION TO COMPLETE ____" << endl << endl;
    cout << " ->0<-        ->MAIN MENU<-      ->0<-" << endl << endl;
    cout << " ->1<-         ->BALANCE<-       ->1<-" << endl << endl;
    cout << " ->2<-       ->CHANGE PIN<-      ->2<-" << endl << endl;
    cout << " ->3<-    ->CASH WITHDRAWAL<-    ->3<-" << endl << endl;
    cout << " ->4<-     ->MONEY EXCHANGE<-    ->4<-" << endl << endl;
    cout << " ->5<-    ->PAYMENT SERVICES<-   ->5<-" << endl << endl;
    cout << " ->6<- ->BALANCE REPLENISHMENT<- ->6<-" << endl << endl;
    cout << " ->7<-      ->INFORMATION<-      ->7<-" << endl << endl;

    cout << "YOUR OPERATION :";

    string ch = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a >= '0' && a <= '7' && i < 1)
        {
            ch += a;
            cout << a;
            i++;
        }
        if (a == '\b' && i > 0)
        {
            ch.pop_back();
            i--;
            cout << "\b \b";
        }
        if (a == '\r' && i == 1)
        {
            break;
        }
    }
    if (ch == "1")
    {
        system("CLS");
        bal_check(card);
    }
    else if (ch == "2")
    {
        system("CLS");
        new_pin(card);
    }
    else if (ch == "3")
    {
        system("CLS");
        cout << setw(49) << "     ___________________\n";
        cout << setw(50) << "    |                   |\n";
        cout << setw(50) << "    |       CASH        |\n";
        cout << setw(50) << "    |    WITHDRAWAL     |\n";
        cout << setw(50) << "    |___________________|\n";
        cout << endl;
        cout << setw(47) << "<0>-ATM MENU-<0>" << endl;
        cout << setw(50) << "< HOW MUCH TO WITHDRAW? >" << endl;
        cout << "Operation takes 1%\n";
        cout << "1. 50000" << endl;
        cout << "2. 100000" << endl;
        cout << "3. 200000" << endl;
        cout << "4. 300000" << endl;
        cout << "5. 400000" << endl;
        cout << "6. 500000" << endl;
        cout << "7. Other amount" << endl;
        cout << "-> Option: ";

        string ch = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a >= '0' && a <= '7' && i < 1)
            {
                ch += a;
                cout << a;
                i++;
            }
            if (a == '\b' && i > 0)
            {
                ch.pop_back();
                i--;
                cout << "\b \b";
            }
            if (a == '\r' && i == 1)
            {
                break;
            }
        }
        if (ch == "1")
        {
            system("CLS");
            withdraw(50000, card);
        }
        else if (ch == "2")
        {
            system("CLS");
            withdraw(100000, card);
        }
        else if (ch == "3")
        {
            system("CLS");
            withdraw(200000, card);
        }
        else if (ch == "4")
        {
            system("CLS");
            withdraw(300000, card);
        }
        else if (ch == "5")
        {
            system("CLS");
            withdraw(400000, card);
        }
        else if (ch == "6")
        {
            system("CLS");
            withdraw(500000, card);
        }
        else if (ch == "7")
        {
            system("CLS");
            int money;
            cout << setw(49) << "     ___________________\n";
            cout << setw(50) << "    |                   |\n";
            cout << setw(50) << "    |       CASH        |\n";
            cout << setw(50) << "    |    WITHDRAWAL     |\n";
            cout << setw(50) << "    |___________________|\n";
            cout << setw(53) << "<0> -> ATM MENU <- <0>" << endl;
            cout << setw(60) << "Please insert multiple 1000 number." << endl;
            cout << "-> MONEY: ";
            cin >> money;
            while (true)
            {
                if (money % 1000 == 0) break;
                system("CLS");
                cout << setw(60) << ">>> WRONG INPUT <<<" << endl;
                cout << setw(60) << "<<< TRY AGAIN >>>" << endl;
                cout << "-> MONEY: ";
                cin >> money;
            }
            if (money == 0)
            {
                system("CLS");
                atm_menu1(card);
            }
            system("CLS");
            withdraw(money, card);
        }
        else if (ch == "0")
        {
            system("CLS");
            atm_menu1(card);
        }
    }
    else if (ch == "4")
    {
        system("CLS");
        exchange(card);
    }
    else if (ch == "5")
    {
        system("CLS");
        payment_services(card);
    }
    else if (ch == "6")
    {
        system("CLS");
        bal_top_up(card);
    }

    else if (ch == "7")
    {
        system("CLS");
        info(card);
    }
    else if (ch == "0")
    {
        system("CLS");
        main_menu();
    }
}

void info(string card)//Shows information of the ATM user
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |    INFORMATION    |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << "---> YOUR CARD NUMBER :\n";
    for (int i = 0; i < 16; i++)
    {
        if (i % 4 == 0 && i != 0)
        {
            cout << '-';
        }
        cout << card[i];
    }
    cout << endl;
    cout << "_--_--_--_--_--" << endl;
    cout << "YOUR PIN:" << acc_pass[card] << endl;
    cout << "_--_--_--_--_--" << endl;
    anything_atm(card);
}

void new_pin(string card)//Sets new pin in atm
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |      NEW PIN      |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(56) << "< < < BACK TO MAIN MANU - '0' > > >" << endl << endl;
    cout << "-}-> YOUR CURRENT PIN:\n";
    string pass3 = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && pass3 == "0")
        {
            system("CLS");
            atm_menu1(card);
        }
        if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) && i < 4)
        {
            pass3 += a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            pass3.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && pass3 != "" && i <= 4)
        {
            break;
        }
    }
    cout << endl;
    if (pass3 == acc_pass[card])
    {
        cout << " -> YOUR NEW PIN:\n";
        string pass = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '\r' && pass == "0")
            {
                system("CLS");
                atm_menu1(card);
            }
            if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) && i < 4)
            {
                pass += a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                pass.pop_back();
                cout << "\b \b";
                --i;
            }
            if (a == '\r' && pass != "" && i <= 4)
            {
                break;
            }
        }
        cout << endl;
        cout << "\n REPEAT YOUR NEW PIN: \n";
        string pass1 = "";
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '/r' && pass1 == "0")
            {
                system("CLS");
                atm_menu1(card);
            }
            if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) && i < 4)
            {
                pass1 += a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                pass1.pop_back();
                cout << "\b \b";
                --i;
            }
            if (a == '\r' && pass1 != "" && i <= 4)
            {
                break;
            }
        }
        cout << endl;
        if (pass != pass1)
        {
            system("CLS");
            cout << setw(65) << " #=#=# YOUR TWO PINS ARE NOT THE SAME #=#=#" << endl;
            cout << setw(65) << "      #=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#      " << endl;
            cout << setw(50) << "|__TRY AGAIN__| \n";
            new_pin1(card);
        }
        else
        {
            acc_pass[card] = pass;
            cout << setw(65) << " - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << setw(67) << "<- <- <-  YOUR PIN WAS SUCCESSFULLY CHANGED  -> -> ->\n";
            cout << setw(65) << " - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            anything_atm(card);
        }
    }
    else
    {
        system("CLS");
        cout << setw(50) << "WRONG PIN\n";
        new_pin(card);
    }
}

void new_pin1(string card)//Sets new pin in atm
{
    cout << "\n YOUR NEW PIN, PLEASE:\n";
    string pass = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && pass == "0")
        {
            system("CLS");
            main_menu();
        }
        if (a >= '0' && a <= '9' && i < 4)
        {
            pass += a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            pass.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && pass != "" && i <= 4)
        {
            break;
        }
    }
    cout << endl;
    cout << "\n REPEAT YOUR PIN: \n";
    string pass1 = "";
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && pass1 == "0")
        {
            system("CLS");
            main_menu();
        }
        if (a >= '0' && a <= '9' && i < 4)
        {
            pass1 += a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            pass1.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && pass1 != "" && i <= 4)
        {
            break;
        }
    }
    cout << endl;
    if (pass != pass1)
    {
        system("CLS");
        cout << setw(65) << " #=#=# YOUR TWO PINS ARE NOT THE SAME #=#=#" << endl;
        cout << setw(65) << "      #=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#     " << endl;
        cout << setw(50) << "|__TRY AGAIN__| \n";
        new_pin1(card);
    }
    else
    {
        acc_pass[card] = pass;
        cout << setw(65) << " - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << setw(65) << "<- <- <-  YOUR PIN WAS SUCCESSFULLY SET  -> -> ->\n";
        cout << setw(65) << " - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        anything_atm(card);
    }
}

void withdraw(int sum, string card)//Monet withdrawal in atm
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |       CHECK       |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << "Operation cost: " << sum * 0.01 << " UZS" << endl;
    int k1 = 0;
    int k2 = 0;
    int k5 = 0;
    int k10 = 0;
    int k20 = 0;
    int k50 = 0;
    int k100 = 0;
    if (sum > acc_bal[card])
    {
        system("CLS");
        cout << setw(70) << "<<>><<>>UNFORTUNATELY YOU HAVE NO MONEY TO WITHDRAW<<>><<>>" << endl;
        cout << setw(70) << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        atm_menu1(card);
    }
    else
    {
        acc_bal[card] -= sum * 0.01;
        while (sum >= 100000)
        {
            if (_100000 > 0)
            {
                _100000--;
                sum -= 100000;
                acc_bal[card] -= 100000;
                k100++;
            }
            else break;
        }
        while (sum >= 50000)
        {
            if (_50000 > 0)
            {
                _50000--;
                sum -= 50000;
                acc_bal[card] -= 50000;
                k50++;
            }
            else break;
        }
        while (sum >= 20000)
        {
            if (_20000 > 0)
            {
                _20000--;
                sum -= 20000;
                acc_bal[card] -= 20000;
                k20++;
            }
            else break;

        }
        while (sum >= 10000)
        {
            if (_10000 > 0)
            {
                _10000--;
                sum -= 10000;
                acc_bal[card] -= 10000;
                k10++;
            }
            else break;
        }
        while (sum >= 5000)
        {
            if (_5000 > 0)
            {
                _5000--;
                sum -= 5000;
                acc_bal[card] -= 5000;
                k5++;
            }
            else break;
        }
        while (sum >= 2000)
        {
            if (_2000 > 0)
            {
                _2000--;
                sum -= 2000;
                acc_bal[card] -= 2000;
                k2++;
            }
            else break;
        }
        while (sum >= 1000)
        {
            if (_1000 > 0)
            {
                _1000--;
                sum -= 1000;
                acc_bal[card] -= 1000;
                k1++;
            }
            else break;
        }
        if (sum == 0)
        {
            cout << "You have got:\n";
            if (k100 > 0) cout << k100 << " - 100.000 UZS banknote(s)\n";
            if (k50 > 0) cout << k50 << " - 50.000 UZS banknote(s)\n";
            if (k20 > 0) cout << k20 << " - 20.000 UZS banknote(s)\n";
            if (k10 > 0) cout << k10 << " - 10.000 UZS banknote(s)\n";
            if (k5 > 0) cout << k5 << " - 5.000 UZS banknote(s)\n";
            if (k2 > 0) cout << k2 << " - 2.000 UZS banknote(s)\n";
            if (k1 > 0) cout << k1 << " - 1.000 UZS banknote(s)\n";
            cout << "Your balance:\n" << acc_bal[card] << " UZS" << endl;
            anything_atm(card);
        }
        else
        {
            cout << "Unfortunately, there is no enough banknotes in ATM.\nSorry, for inconvenience\n";
        }
    }
}

void anything_atm(string card)//Asks for other operation completion in atm
{
    cout << setw(60) << "DO YOU HAVE OTHER OPERATIONS TO COMPLETE ?" << endl;
    cout << setw(30) << "1 - YES - 1";
    cout << setw(30) << "2 - NO - 2 " << endl;
    cout << "-YOUR ANSWER :";
    string ch = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a >= '1' && a <= '2' && i < 1)
        {
            ch += a;
            cout << a;
            i++;
        }
        if (a == '\b' && i > 0)
        {
            ch.pop_back();
            i--;
            cout << "\b \b";
        }
        if (a == '\r' && i == 1)
        {
            break;
        }
    }
    if (ch == "1")
    {
        system("CLS");
        atm_menu1(card);
    }
    else if (ch == "2")
    {
        system("CLS");
        cout << endl;
        cout << setw(65) << "<- <- <- THANK YOU FOR BANKING AND BEING WITH US -> -> -> " << endl;
        main_menu();
    }
}

void bal_check(string card)//Prints balance in atm
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |      BALANCE      |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(45) << " -YOUR BALANCE :" << endl;
    cout << setw(35) << "-> ->" << acc_bal[card] << " UZS" << "<- <-" << endl << endl;
    anything_atm(card);
}

void bal_top_up(string card)//Top ups balance in atm
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |      BALANCE      |\n";
    cout << setw(50) << "    |   REPLENISHMENT   |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(56) << "< < < BACK TO MAIN MANU - '0' > > >" << endl << endl;
    cout << " -> -> ->  Please insert banknotes starting from 1000 UZS up to 100000 UZS\n\n";
    cout << ">> AMOUNT >>: ";
    int money;
    cin >> money;
    if (money == 0)
    {
        system("CLS");
        atm_menu1(card);
    }
    else if (money % 1000 != 0)
    {
        system("CLS");
        cout << "Wrong amount.\nPlease try again\n";
        bal_top_up(card);
    }
    acc_bal[card] += money;
    cout << "-}-> AMOUNT OF MONEY ON YOUR BALANCE -->:" << acc_bal[card] << " UZS" << endl << endl;
    int sum = money;
    while (sum >= 100000)
    {
        if (_100000 > 0)
        {
            _100000++;
            sum -= 100000;
        }
        else break;
    }
    while (sum >= 50000)
    {
        if (_50000 > 0)
        {
            _50000++;
            sum -= 50000;
        }
        else break;
    }
    while (sum >= 20000)
    {
        if (_20000 > 0)
        {
            _20000++;
            sum -= 20000;
        }
        else break;

    }
    while (sum >= 10000)
    {
        if (_10000 > 0)
        {
            _10000++;
            sum -= 10000;
        }
        else break;
    }
    while (sum >= 5000)
    {
        if (_5000 > 0)
        {
            _5000++;
            sum -= 5000;
        }
        else break;
    }
    while (sum >= 2000)
    {
        if (_2000 > 0)
        {
            _2000++;
            sum -= 2000;
        }
        else break;
    }
    while (sum >= 1000)
    {
        if (_1000 > 0)
        {
            _1000++;
            sum -= 1000;
        }
        else break;
    }
    anything_atm(card);
}

string lowercase(string word)//Returns all string in lower case
{
    for (int b = 0; b < word.size(); b++)
    {
        word[b] = tolower(word[b]);
    }
    return word;
}

void payment_services(string card)
{
    cout << setw(49) << "      ___________________\n";
    cout << setw(50) << "    <|                   |>\n";
    cout << setw(50) << "    <|      PAYMENT      |>\n";
    cout << setw(50) << "    <|        FOR        |>\n";
    cout << setw(50) << "    <|     SERVICES      |>\n";
    cout << setw(50) << "    <|___________________|>\n";
    cout << setw(55) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
    cout << setw(50) << ">1<     <PAYMENT>    >1<" << endl;
    cout << setw(50) << ">2<    <UTILITIES>   >2<" << endl;
    cout << setw(50) << ">3< <MONEY TRANSFER> >3<" << endl;
    cout << "-> OPTION: ";
    string uti = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && uti == "0")
        {
            system("CLS");
            atm_menu1(card);
        }
        if (a >= '0' && a <= '3' && i < 1)
        {
            uti += a;
            cout << a;
            i++;
        }
        if (a == '\b' && i > 0)
        {
            uti.pop_back();
            i--;
            cout << "\b \b";
        }
        if (a == '\r' && i == 1)
        {
            break;
        }
    }
    cout << endl;
    int b;
    b = (int(uti[0]) - 48);
    switch (b)
    {
    case 1:
    {
        system("CLS");
        cout << setw(48) << "     ___________________\n";
        cout << setw(50) << "    <|                   |>\n";
        cout << setw(50) << "    <|      PAYMENT      |>\n";
        cout << setw(50) << "    <|        FOR        |>\n";
        cout << setw(50) << "    <|     SERVICES      |>\n";
        cout << setw(50) << "    <|___________________|>\n";
        cout << setw(54) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
        cout << "-------------------------> TOP UP PHONE BALANCE ------> 1" << endl;
        cout << "-------------------------> ATTO ----------------------> 2" << endl;
        cout << "-------------------------> INTERNET PROVIDER ---------> 3\n";
        cout << "-------------------------> option: ";
        string ch = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '\r' && ch == "0")
            {
                system("CLS");
                payment_services(card);
            }
            if (a >= '0' && a <= '3' && i < 1)
            {
                ch += a;
                cout << a;
                i++;
            }
            if (a == '\b' && i > 0)
            {
                ch.pop_back();
                i--;
                cout << "\b \b";
            }
            if (a == '\r' && i == 1)
            {
                break;
            }
        }
        cout << endl;
        int b = int(ch[0]) - 48;
        switch (b)
        {
        case 1:
        {
            system("CLS");
            string phone_number = "";
            int sum;
            cout << setw(60) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << " ---> PLEASE ENTER PHONE NUMBER: " << endl;
            cout << "+998";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (phone_number == "0" && a == '\r')
                {
                    system("CLS");
                    payment_services(card);
                }
                if (a >= '0' && a <= '9' && i < 9)
                {
                    phone_number += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    phone_number.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i == 9)
                {
                    break;
                }
            }
            cout << endl;

            cout << " ---> AMOUNT TO TOP UP THE PHONE NUMBER:  ";
            cin >> sum;
            if (sum > acc_bal[card])
            {
                system("CLS");
                cout << setw(55) << "|*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*|" << endl;
                cout << setw(55) << "|NOT ENOUGH MONEY ON YOUR BALANCE!|" << endl;
                cout << setw(55) << "|*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*|" << endl;
                payment_services(card);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[card] -= sum;
                anything_atm(card);
            }
            break;
        }
        case 2:
        {
            system("CLS");
            string transport_card_num = "";
            int mon;
            cout << setw(50) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << "---> ENTER YOUR CARD NUMBER <ATTO>: ";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (transport_card_num == "0" && a == '\r')
                {
                    system("CLS");
                    payment_services(card);
                }
                if (a >= '0' && a <= '9' && i < 16)
                {
                    transport_card_num += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    transport_card_num.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i == 16)
                {
                    break;
                }
            }
            cout << endl;

            cout << "AMOUNT YOU WANT TO TOP UP TO THE TRANSPORT CARD : ";
            cin >> mon;
            if (mon > acc_bal[card])
            {
                system("CLS");
                cout <<setw(65)<< ">>-----> NOT ENOUGH MONEY ON YOUR BALANCE <-----<<" << endl;
                payment_services(card);

            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[card] -= mon;
                anything_atm(card);
            }
            break;
        }
        case 3:
        {
            system("CLS");
            string phone_number = "";
            int sum;
            cout << setw(50) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << " INTERNET ACCOUNT'S NUMBER: ";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (phone_number == "0" && a == '\r')
                {
                    system("CLS");
                    payment_services(card);
                }
                if (a >= '0' && a <= '9' && i < 9)
                {
                    phone_number += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    phone_number.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << "AMOUNT  YOU WANT TO TOP UP TO YOUR ACCOUNT : ";
            cin >> sum;
            if (sum > acc_bal[card])
            {
                system("CLS");
                cout << setw(55) << "|^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^|" << endl;
                cout << setw(55) << "|NOT ENOUGH MONEY ON YOUR BALANCE!|" << endl;
                cout << setw(55) << "|^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^|" << endl;
                payment_services(card);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[card] -= sum;
                anything_atm(card);
            }
            break;
        }
        default:
            system("CLS");
            cout << "WRONG INPUT\n";
            payment_services(card);
            break;
        }
    }
    case 2:
    {
        system("CLS");
        cout << setw(48) << " _____________" << endl;
        cout << setw(50) << "::             ::" << endl;
        cout << setw(50) << "::  UTILITIES  ::" << endl;
        cout << setw(50) << "::_____________::" << endl;
        cout << endl;
        cout << setw(56) << "< < < BACK TO MENU - '0' > > >" << endl << endl;

        cout << "1.*~*~*~* GAS *~*~*~*" << endl;
        cout << "2.*~*~*~* ELECTRICITY *~*~*~*" << endl;
        cout << "3.*~*~*~* WATER *~*~*~*" << endl;
        cout << "4.*~*~*~* GARBAGE *~*~*~*" << endl;
        string uti = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '\r' && uti == "0")
            {
                system("CLS");
                payment_services(card);
            }
            if (a >= '0' && a <= '4' && i < 1)
            {
                uti += a;
                cout << a;
                i++;
            }
            if (a == '\b' && i > 0)
            {
                uti.pop_back();
                i--;
                cout << "\b \b";
            }
            if (a == '\r' && i == 1)
            {
                break;
            }
        }
        cout << endl;
        int b;
        b = (int(uti[0]) - 48);
        switch (b)
        {
        case 1:
        {
            system("CLS");
            int c;
            cout << setw(50) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << setw(50) << "__________________" << endl;
            cout << setw(50) << "<<< GAS PAYMENT >>>" << endl;
            cout << setw(50) << "__________________" << endl;
            cout << "ENTER PERSONAL ACCOUNT : " << endl;
            string A = "";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (a == '\r' && A == "0")
                {
                    system("CLS");
                    payment_services(card);
                }
                if (a >= '0' && a <= '9' && i < 10)
                {
                    A += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    A.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << "-----> YOUR TARIFF: 295 UZS <-----" << endl;
            cout << "HOW MUCH DO YOU WANT TO TOP UP?" << " (UZS)" << endl;
            cin >> c;
            if (c > acc_bal[card])
            {
                system("CLS");
                cout << setw(50) << "<_____NOT ENOUGH MONEY_____>" << endl;
                atm_menu1(card);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[card] -= c;
                anything_atm(card);
            }
            break;
        }
        case 2:
        {
            system("CLS");
            int cs;
            cout << setw(50) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << setw(50) << "___________________________" << endl;
            cout << setw(50) << "<<< ELECTRICITY PAYMENT >>>" << endl;
            cout << setw(50) << "___________________________" << endl;
            cout << "ENTER PERSONAL ACCOUNT : " << endl;
            string A = "";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (a == '\r' && A == "0")
                {
                    system("CLS");
                    payment_services(card);
                }
                if (a >= '0' && a <= '9' && i < 10)
                {
                    A += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    A.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << "-----> YOUR TARIFF: 400 UZS <-----" << endl;
            cout << "HOW MUCH DO YOU WANT TO TOP UP?" << "(UZS)" << endl;
            cin >> cs;
            if (cs > acc_bal[card])
            {
                system("CLS");
                cout << setw(55) << "<_____NOT ENOUGH MONEY_____>" << endl;
                atm_menu1(card);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[card] -= cs;
                anything_atm(card);
            }
            break;
        }
        case 3:
        {
            system("CLS");
            int csh;
            cout << setw(50) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << setw(50) << "__________________________" << endl;
            cout << setw(50) << "< < < WATER PAYMENT > > >" << endl;
            cout << setw(50) << "__________________________" << endl;
            cout << "ENTER PERSONAL ACCOUNT : " << endl;
            string A = "";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (a == '\r' && A == "0")
                {
                    system("CLS");
                    payment_services(card);
                }
                if (a >= '0' && a <= '9' && i < 10)
                {
                    A += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    A.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << "-----> YOUR TARIFF: 257 UZS <-----" << endl;
            cout << "HOW MUCH DO YOU WANT TO TOP UP?" << "(UZS)" << endl;
            cin >> csh;
            if (csh > acc_bal[card])
            {
                system("CLS");
                cout << setw(50) << "<_____NOT ENOUGH MONEY_____>" << endl;
                atm_menu1(card);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[card] -= csh;
                anything_atm(card);
            }
            break;
        }
        case 4:
        {
            system("CLS");
            int csh;
            cout << setw(50) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
            cout << setw(50) << "__________________________" << endl;
            cout << setw(50) << "< < <  GARBAGE PAYMENT   > > >" << endl;
            cout << setw(50) << "__________________________" << endl;
            cout << "ENTER PERSONAL ACCOUNT : " << endl;
            string A = "";
            char a;
            for (int i = 0;;)
            {
                a = _getch();
                if (a == '\r' && A == "0")
                {
                    system("CLS");
                    payment_services(card);
                }
                if (a >= '0' && a <= '9' && i < 10)
                {
                    A += a;
                    cout << a;
                    i++;
                }
                if (a == '\b' && i > 0)
                {
                    A.pop_back();
                    i--;
                    cout << "\b \b";
                }
                if (a == '\r' && i <= 10 && i > 1)
                {
                    break;
                }
            }
            cout << endl;
            cout << "-----> YOUR TARIFF: 128 UZS <-----" << endl;
            cout << "HOW MUCH DO YOU WANT TO TOP UP?" << "(UZS)" << endl;
            cin >> csh;
            if (csh > acc_bal[card])
            {
                system("CLS");
                cout << setw(50) << "<_____NOT ENOUGH MONEY_____>" << endl;
                atm_menu1(card);
            }
            else
            {
                cout << "Transaction completed.\n";
                acc_bal[card] -= csh;
                anything_atm(card);
            }
            break;
        }
        default:
            system("CLS");
            cout << "WRONG INPUT\n";
            payment_services(card);
            break;
        }
        break;
    }
    case 3:
    {
        system("CLS");
        cout <<setw(49)<< "     ___________________\n";
        cout <<setw(50)<< "    |                   |\n";
        cout <<setw(50)<< "    |       MONEY       |\n";
        cout <<setw(50)<< "    |      TRANSFER     |\n";
        cout <<setw(50)<< "    |___________________|\n";
        cout << setw(50) << "< < < BACK TO MENU - '0' > > >" << endl << endl;
        cout<<"-}-> ENTER RECIEVER'S CARD NUMBER:\n";
        string card1 = "";
        char a;
        for (int i = 0;;)
        {
            a = _getch();
            if (a == '\r' && card1 == "0")
            {
                system("CLS");
                payment_services(card);
            }
            if (a >= '0' && a <= '9' && i < 16)
            {
                card1 += a;
                ++i;
                cout << a;
            }
            if (i % 4 == 0 && i != 16 && i != 0)
            {
                cout << '-';
            }
            if (a == '\b' && i >= 1)
            {
                if (i % 4 == 0 && i != 16)
                {
                    cout << "\b \b";
                    cout << "\b \b";
                }
                card1.pop_back();
                --i;
                cout << "\b \b";
            }
            if (a == '\r' && card != "" && i == 16)
            {
                break;
            }
        }
        cout << endl;
        cout << "ENTER THE AMOUNT YOU WANT TO SEND: " << endl;
        int mon;
        cin >> mon;
        if (mon > acc_bal[card])
        {
            system("CLS");
            cout << setw(50) << "<_____NOT ENOUGH MONEY_____>" << endl;
            atm_menu1(card);
        }
        else
        {
            cout << "Transaction completed.\n";
            acc_bal[card] -= mon;
            acc_bal[card1] += mon;
            anything_atm(card);
        }
        break;
    }
    default:
        system("CLS");
        cout << setw(55) << "<_____ WRONG INPUT _____>\n";
        payment_services(card);
        break;
    }
}


void exchange(string card)
{
    cout << setw(49) << "     ___________________\n";
    cout << setw(50) << "    |                   |\n";
    cout << setw(50) << "    |       MONEY       |\n";
    cout << setw(50) << "    |     EXCHANGE      |\n";
    cout << setw(50) << "    |___________________|\n";
    cout << setw(56) << "< < < BACK TO MAIN MANU - '0' > > >" << endl << endl;
    cout << setw(53) << "____ENTER FOREIGN CURRENCY____" << endl;
    cout << "EXCHANGE RATES:\n1. 1 USD = 10750 UZS\n";
    cout << "2. 1 EUR = 12230 UZS\n";
    cout << "3. 1 GBP = 14382 UZS\n";
    cout << "4. 1 RUB = 149 UZS\n";
    cout << "5. 1 KRW = 9 UZS\n";
    cout << "6. 1 INR = 145 UZS\n";
    string money = "";
    string num = "";
    string cur = "";
    cout << ("Please insert your amount of foreign money and right after it the currency:\n");
    cout << "Input sample: '20USD'\n";
    cout << "> > >FOREIGN CURRENCY :";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        a = toupper(a);
        if (a == '\r' && num == "0" && i == 1)
        {
            system("CLS");
            atm_menu1(card);
        }
        if (a >= '0' && a <= '9')
        {
            num += a;
            ++i;
            cout << a;
        }
        if (a >= 'A' && a <= 'Z' && i > 0)
        {
            cur += a;
            ++i;
            cout << a;
        }
        if (a == '\b' && i >= 1)
        {
            cout << "\b \b";
            --i;
            cur.pop_back();
        }
        if (a == '\r' && cur != "")
        {
            break;
        }
    }
    cout << endl;
    int value = 0;
    for (int i = 0; i < num.size(); i++)
    {
        value += (int(num[i]) - 48) * pow(10, num.size() - i - 1);
    }
    if (value < 0)
    {
        system("CLS");
        cout << setw(60) << "!-!-! Wrong Input , TRY AGAIN !-!-!\n";
        exchange(card);
    }
    if (cur == "USD")
    {
        value = value * 10750;
    }
    else if (cur == "EUR")
    {
        value = value * 12230;
    }
    else if (cur == "GBP")
    {
        value = value * 14382;
    }
    else if (cur == "RUB")
    {
        value = value * 149;
    }
    else if (cur == "KRW")
    {
        value = value * 9;
    }
    else if (cur == "INR")
    {
        value = value * 145;
    }
    else
    {
        system("CLS");
        cout << setw(50) << "><><UNKNOWN CURRENCY INPUT - TRY AGAIN ><><\n";
        exchange(card);
    }
    int k1 = 0;
    int k2 = 0;
    int k5 = 0;
    int k10 = 0;
    int k20 = 0;
    int k50 = 0;
    int k100 = 0;
    while (value >= 100000)
    {
        _100000--;
        value -= 100000;
        k100++;
    }
    while (value >= 50000)
    {
        _50000--;
        value -= 50000;
        k50++;
    }
    while (value >= 20000)
    {
        _20000--;
        value -= 20000;
        k20++;
    }
    while (value >= 10000)
    {
        _10000--;
        value -= 10000;
        k10++;
    }
    while (value >= 5000)
    {
        _5000--;
        value -= 5000;
        k5++;
    }
    while (value >= 2000)
    {
        _2000--;
        value -= 2000;
        k2++;
    }
    while (value >= 1000)
    {
        _1000--;
        value -= 1000;
        k1++;
    }
    if (value != 0)
    {
        cout << "Unfortunately, there is no enough banknotes, so the rest of your sum (" << value << " UZS) are sent to your card\n";
        acc_bal[card] += value;
    }
    if (k1 != 0 || k2 != 0 || k5 != 0 || k10 != 0 || k20 != 0 || k50 != 0 || k100 != 0)
    {
        cout << "You have got:\n";
        if (k100 > 0) cout << k100 << " - 100.000 UZS banknote(s)\n";
        if (k50 > 0) cout << k50 << " - 50.000 UZS banknote(s)\n";
        if (k20 > 0) cout << k20 << " - 20.000 UZS banknote(s)\n";
        if (k10 > 0) cout << k10 << " - 10.000 UZS banknote(s)\n";
        if (k5 > 0) cout << k5 << " - 5.000 UZS banknote(s)\n";
        if (k2 > 0) cout << k2 << " - 2.000 UZS banknote(s)\n";
        if (k1 > 0) cout << k1 << " - 1.000 UZS banknote(s)\n";
    }
    cout << setw(45) << " -YOUR BALANCE :" << endl;
    cout << setw(35) << "-> ->" << acc_bal[card] << " UZS" << "<- <-" << endl << endl;
    anything_atm(card);
}





int main()
{
    main_menu();
    system("color F3");
    system("pause");
    return 0;
}
