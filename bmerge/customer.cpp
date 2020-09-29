#include "hotel.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include<string>
#include<string.h>


using namespace std;

int Customer::check(int r)
{
    int flag = 0;

    ifstream fin("Record.bin", ios::in);

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

int Customer::checkb(int r, int ids)
{
    int flag = 0;

    ifstream fin("Record.bin", ios::in);

    while (!fin.eof())
    {
        fin.read((char *)this, sizeof(Main));
        if (roomNo == r && id == ids)
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
    ofstream fout("Record.bin",ios::app);

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
        // getline(cin,name);
        // cin.get(name,sizeof(name));
        // cin.getline(name,sizeof(name));
        cout << " Phone No: ";
        cin >> contact;
        cout << " Passport / citizenship no. : ";
        cin >> id;

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

void Customer::checkin()
{
    system("cls");
    int r; 
    int ids;
    int flag;
    ofstream fout("Recordc.bin",ios::app);
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
    cout << "\n Enter your Passport / citizenship no.:" << endl;
    cin >> ids;
    flag = checkb(r,ids);

    if (flag){
        roomNo = r;
        cout << " Name: ";
        cin >> name;
        cout << " Phone No: ";
        cin >> contact;
        id = ids;

        fout.write((char*)this, sizeof(Main));
        cout << "\n checked in successfully..";
        
    }
    else
    {
      cout << "\n Sorry..!!!Room is already booked by someone else. " << endl;  
    }

    cout << "\n Press any key to continue.....!!";
    getch();
    fout.close();
}

void Customer::checkout()
{
    system("cls");
    int r;
    int flag=0;
    int day{0};
    int bill{0};

    ifstream infile;
    infile.open("recordc.bin" , ios::in | ios:: binary);

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
            cout << "Enter no. of days you stayed : ";
            cin >> day;
            if(r == 101 || r == 102)
                bill = day*2000;
            else if (r == 103 || r == 104)
                bill = day*3500;
            else if (r == 105 || r == 106)
                bill = day*5500;
            else if (r == 107 || r == 108)
                bill = day*1000;
            else if (r == 109 || r == 110)
                bill = day*2000;
            else if (r == 111 || r == 112)
                bill = day*3000;
            system("cls");
            cout << "\n\n\t\t----------HOTEL Aa-Ka-Ma----------" <<endl;
            cout << "\n\tThanks for your stay." << endl;
            cout << "\nRoom no. : " << r << endl; 
            cout << "\n\n\t\tyour final bill is Rs." << bill << endl;
        }else{
            cout << "\nNo such room."<< endl;
        }
        infile.close();

       //for deleting in checkin list 
        std::fstream infile;
        infile.open("Recordc.bin" , std::ios::in);
        infile.seekg(0, std::ios::beg); 

        if (!infile)
        {
            std::cout << "Unable to open file." << std::endl;
            exit(1);
        }else{
            std::ofstream outf("tempc.bin", std::ios::app | std::ios::binary);
            while (infile.read((char *) this, sizeof(Main)))
            {
                if (roomNo == r)
                    flag = 1;
                else
                    outf.write((char *)this, sizeof(Main));
            }
            infile.close();
            outf.close();
            if (flag == 0)
            {
                remove("tempc.bin");
                std::cout << "\n\t\tNo such record exists";
            }
            else
            {
                remove("recordc.bin");
                rename("tempc.bin", "recordc.bin");
                std::cout << "\n\t\tRecord deleted in checkin list successfully";
            }
        }
    }
    // deleting in the booking list.
    std::fstream in;
    in.open("Record.bin" , std::ios::in);
    in.seekg(0, std::ios::beg);
    if (!infile)
    {
        std::cout << "Unable to open file." << std::endl;
        exit(1);
    }else{
        std::ofstream out("temp.bin", std::ios::app | std::ios::binary);
        while (in.read((char *) this, sizeof(Main)))
        {
            if (roomNo == r)
                flag = 1;
            else
                out.write((char *)this, sizeof(Main));
        }
        in.close();
        out.close();
        if (flag == 0)
        {
            remove("temp.bin");
            std::cout << "\n\t\tNo such record exists";
        }
        else
        {
            remove("record.bin");
            rename("temp.bin", "record.bin");
            std::cout << "\n\t\tRecord deleted successfully";
        }
    }

    cout << "\n Press any key to continue.....!!";
        getch();
}



