#include "hotel.h"
#include <iostream>
#include<fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>

void Admin::AviewRecord(){
    system("CLS");
    std::ifstream infile;
    infile.open("record.dat",std::ios::in);
    
    std::string title{"Customer's Record of Hotel Aa-Ka-Ma"};
    int titleWidth = sizeof(title);
    int totalWidth {75};

    std::cout << std::setw((totalWidth - titleWidth) / 2) << "" << title << std::endl << std::endl;
    std::cout << std::setw(totalWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    std::cout << std::setw(5)  << std::left << "S.N"
              << std::setw(20) << std::left << "Name"
              << std::setw(20) << std::left << "Contact"
              << std::setw(5)  << std::right << "Room" << std::endl;

    std::cout << std::setw(totalWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    if (!infile)
    {
        std::cout << "Unable to open file." << std::endl;
        exit(1);
    }

    int sncount {0};
    while (!infile.eof())
    {
        infile.read((char*)this,sizeof(Main));
        sncount++;
        std::cout << std::setw(5) << std::left << sncount
                  << std::setw(20) << std::left << name
                  << std::setw(20) << std::left<< contact
                  << std::setw(5)  << std::right << roomNo << std::endl;
    }
    std::cout << "\n\tPress Enter Key To Continue...";
    getch();
    system("cls");
}

void Admin::AeditRecord()
{
    topedit:
    system("CLS");
    int selection;
        std::cout << "\n\t ------- Edit record -------" << std::endl;
        std::cout << "\n\n\t\t1. Edit Customer's Record.";
        std::cout << "\n\t\t2. Delete Customer's Record";
        std::cout << "\n\t\t3. Re-set all";
        std::cout << "\n\t\t0. Exit";
        std::cout << "\n\n\t\tEnter Your Choice: ";
        std::cin >> selection;

        switch (selection)
        {
        case 1:
            EditCR();
            goto topedit;
        case 2:
            DeleteCR();
            goto topedit;
        case 3:
            ResetAll();
            goto topedit;
        case 0:
            Amenu1();
            break;
        default:
        {
            std::cout << "\n\n\n\t\tWrong Choice...";
            std::cout << "\n\tPress Enter Key To Continue...";
            // int ch = std::cin.get();
            getch();
            goto topedit;
        }
        }

}

void Admin::EditCR(){
    system("CLS");
    std::fstream infile;
    infile.open("Record.dat", std::ios::in | std::ios::out | std::ios::binary);

    long position;
    long flag{0};
    int r;

    std::cout << "Enter room no. to edit record" <<std::endl;
    std::cin >> r;

    if (!infile)
    {
        std::cout << "Unable to open file." << std::endl;
        exit(1);
    }

    while (!infile.eof())
    {
        position = infile.tellg();
        infile.read((char*)this,sizeof(Main));
        if(roomNo = r){
            std::cout << "\n Now, \nYou can edit record of person living in the particular room.\n Enter new details";
            std::cout << " Name : ";
            std::cin >> name;
            std::cout << " Phone No : ";
            std::cin >> contact;
            infile.seekg(position);
            infile.write((char*)this,sizeof(Main));
            std::cout << "\n\n editing Record successful.";
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    std::cout << "\n Sorry Room no. not found or vacant...!!";
    infile.close();

    std::cout << "\n\tPress Enter Key To Continue...";
    getch();
    // int ch = std::cin.get();
}

void Admin::DeleteCR()
{
    char ch;
    system("CLS");
    std::fstream infile;
    infile.open("Record.dat" , std::ios::in | std::ios::out);

    std::cout << "Enter room no. to delete record" << std::endl;
    int r;
    std::cin >> r;

    int flag = 0;

    if (!infile)
    {
        std::cout << "Unable to open file." << std::endl;
        exit(1);
    }

    while (!infile.eof())
    {
        infile.read((char *)this, sizeof(Main));
        if (roomNo = r)
        {
            std::cout << "\nRoom no. : " <<roomNo;
            std::cout << "\n Name : " << name;
            std::cout << "\n Phone No." << contact;
            std::cout << "\n Are you sure you want to delete this record ? (y/n)";
            std::cin >> ch;
            if (ch == 'n' || ch == 'N')
            {
                AeditRecord();
            }
            else if (ch == 'y' || ch == 'Y')
            {
                infile.write((char *)this, sizeof(Main));
                flag =1;
            }
            else
            {
                std::cout << "\n\n\n\t\tWrong Choice...";
                std::cout << "\n\tPress Enter Key To Continue...";
                getch();
                AeditRecord();
            }
        }
    }

    infile.close();
    if (flag == 0)
        std::cout << "\n Sorry room no. not found or vacant...!!";
    else
    {
        remove("Record.dat");
        rename("temp.dat", "Record.dat");
    }
    
    std::cout << "\n\tPress Enter Key To Continue...";
    getch();
    // int ch = std::cin.get();
}


void Admin::ResetAll()
{
    system("CLS");
    char ch;
    Admin reset;
    reset.login();
    std::cout << "\nAre you sure you want to reset records?(y/n):";
    std::cin >> ch;
    if(ch == 'n' || ch == 'N'){
        AeditRecord();
    }
    else if (ch == 'y' || ch == 'Y'){
        std::ofstream outfile;
        outfile.open("Record.dat");
        outfile << ""<< std::endl;
        outfile.close();
    }else{
        std::cout << "\n\n\n\t\tWrong Choice...";
        std::cout << "\n\tPress Enter Key To Continue...";
        int ch = std::cin.get();
    }
    std::cout << "\n\tPress Enter Key To Continue...";
    getch();
    // int ch = std::cin.get();
}


void Admin::AviewRoom()
{
    system("CLS");
    std::ifstream infile;
    infile.open("Record.dat", std::ios::in);

    if (!infile)
    {
        std::cout << "Unable to open file." << std::endl;
        exit(1);
    }

    std::string title{"Room Allocated"};
    int titleWidth = sizeof(title);
    int totalWidth{55};

    std::cout << std::setw((totalWidth - titleWidth) / 2) << "" << title << std::endl
              << std::endl;
    std::cout << std::setw(totalWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(5) << std::left << "S.N"
              << std::setw(20) << std::left << "Room"
              << std::setw(20) << std::left << "Name"
              << std::setw(20) << std::left << "Contact"
              //   << std::setw(20) << std::left << "Passport/Citizenship no."
              << std::endl;

    std::cout << std::setw(totalWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    int sncount{0};
    while (!infile.eof())
    {
        infile.read((char*)this,sizeof(Main));
        sncount++;
        std::cout << std::setw(5) << std::left << sncount 
                  << std::setw(5) << std::left << roomNo
                  << std::setw(20) << std::left << name
                  << std::setw(20) << std::left << contact
                  //   << std::setw(20) << std::left << identityNo
                  << std::endl;
    }

    std::cout << "\n\tPress Enter Key To Continue...";
    getch();
    infile.close();
    // int ch = std::cin.get();
}

