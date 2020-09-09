#include "hotel.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>

using namespace std;

int Customer::check(int r)
{

    int flag = 0;

    ifstream fin("Record.dat", ios::in);

    while (!fin.eof())
    {
        fin.read((char *)this, sizeof(Main));
        if (roomNo == r)
        {
            flag = 1;
            break;
        }
    }
    fin.close();
    return (flag);
}

void Customer::availableRoom()
{
    system("cls");
    string avr;
    ifstream avfile("rtype.txt");
    getline(avfile, avr);
    cout << endl; //TO SHOW AVAILABLE ROOMS
    while (!avfile.eof())
    {
        cout << "\n"
             << avr;
        getline(avfile, avr);
    }
    avfile.close();
    cout << "\n Press any key to continue.....!!";
    getch();
}

void Customer::bookRoom()
{

    system("cls");
    int r, flag;
    ofstream fout("Record.dat",ios::app);

    cout << "\n THE AVAILABLE ROOM TYPE ARE: ";
    cout << "\n ----------------------";
    cout << "\n S.NO  ROOM TYPE                 room no.    PRICE / DAY ";
    cout << "\n 1.    single attached room 2   {101,102}    2000";
    cout << "\n 2.    double attached room 2   {103,104}    3500 ";
    cout << "\n 3.    triple attached room 2   {105,106}    5500";
    cout << "\n 5.    single room          2   {107,108}    1000";
    cout << "\n 5.    double room          2   {109,110}    2000";
    cout << "\n 6.    triple room          2   {111,112}    3000";
    cout << "\n Enter The Room no. you want to stay in :- " << endl;
    cin >> r;
    flag = check(r);

    if (flag){
        cout << "\n Sorry..!!!Room is already booked" << endl;
    }
    else
    {
        roomNo = r;
        cout << " Name: ";
        cin >> name;
        cout << " Phone No: ";
        cin >> contact;

        fout.write((char*)this, sizeof(Main));
        cout << "\n Room is booked...!!!";
    }

    cout << "\n Press any key to continue.....!!";
    getch();
    fout.close();
}

void Customer::otherFaci()
{
    string ch;
    ifstream facifile("faci.txt");
    getline(facifile, ch);
    cout << endl;
    cout << endl;

    while (!facifile.eof())
    {
        getline(facifile, ch);
        if (ch != "pfaci")
        {
            cout << ch << endl; // SHOW OTHER FACILITIES AND CALCULATE TOTAL PRICE
        }
        else
        {
            break;
        }
    }
    cout << endl;
    cout << "\n Press any key to continue.....!!";
    getch();
}