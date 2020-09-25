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
    int r; 
    int flag;
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
        cout << "\n Sorry..!!!Room is already booked or no such room." << endl;
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
    system("cls");
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
            cout << ch << endl; // SHOW OTHER FACILITIES 
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


void Customer::finalbill(){
    system("cls");
    ifstream infile;
    infile.open("record.dat" , ios::in | ios:: binary);

    int r;
    int flag=0;
    int bill{0};

    cout << "Enter your room no : " ;
    cin >> r;
    
    if(!infile){
        cout << "unable to open file";
        cout << "\n Press any key to continue.....!!";
        getch();
        // Cmenu1();
    }
    else{
        while(!infile.eof()){
            infile.read((char *)this, sizeof(Main));
            if(roomNo == r){
                flag = 1;
                break;
            }   
        } 

        if(flag){
            if(r == 101 || r == 102)
                bill = 2000;
            else if (r == 103 || r == 104)
                bill = 3500;
            else if (r == 105 || r == 106)
                bill = 5500;
            else if (r == 107 || r == 108)
                bill = 1000;
            else if (r == 109 || r == 110)
                bill = 2000;
            else if (r == 111 || r == 112)
                bill = 3000;
            system("cls");
            cout << "\n\n\t\t----------HOTEL Aa-Ka-Ma----------" <<endl;
            cout << "\n\tThanks for your stay." << endl;
            cout << "\nRoom no. : " << r << endl; 
            cout << "\n\n\t\tyour final bill is Rs." << bill << endl;
        }else{
            cout << "\nNo such room."<< endl;
        }

        infile.close();
        cout << "\n Press any key to continue.....!!";
        getch();
    }
}