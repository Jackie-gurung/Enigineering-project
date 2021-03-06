#include "hotel.h"
#include<iostream>
#include<conio.h>
#include <string.h>

// first page 
void Main::menu1(){
    top1:
    system("CLS");
    int selection{};
    do{
        std::cout << "\n\t -------HOTEL Aa-Ka-Ma-------" << std::endl;
        std::cout << "\n\n---------------------------------------------------"<<std::endl;
        std::cout << "\n\n\t\t1. Adminstrator's Menu";
        std::cout << "\n\t\t2. Customer's Menu" ;
        std::cout << "\n\t\t0. Exit" ;
        std::cout << "\n\n\t\tEnter Your Choice: ";
        std::cin >> selection;

        switch (selection){
            case 1: adminMenu();
                break;
            case 2: customerMenu();
                break;
            case 0: exit;
                break;
            default:
            {
                std::cout << "\n\n\n\t\tWrong Choice...";
                std::cout << "\n\tPress Enter Key To Continue..."; 
                int ch = std::cin.get();
                goto top1;
            }   
        }
    }while(selection != 0);
} 

void Main::adminMenu(){
    Admin a;
    a.login();
    a.Amenu1();
};



void Admin::login(){
    int userInput;
    int password = 0000;
    int chance =1;
    system("CLS");
    start:
        
        std::cout << "Enter Password to verify that you are ADMIN : " <<std::endl;
        std::cin >> userInput;
        system("CLS");
        if(userInput != password)
        {
            std::cout << "Password incorrect" << std::endl;
            std::cout << "You have " << 3 - chance << " chance left." << std::endl;
            chance++;
            if (chance <= 3)
                goto start;
            menu1();
        }
        else {
            std::cout << "Password Matched..." << std::endl;
            std::cout << "You are entering as Admin.." << std::endl;
        }
}

void Admin::Amenu1(){
    top2:
    system("CLS");
    int selection;
    do{
        std::cout << "\n\t -------HOTEL Aa-Ka-Ma-------" << std::endl;
        std::cout << "\n\n------------------ ADMIN -------------------------" << std::endl;
        std::cout << "\n\n\t\t1. View Customer's Booking Record.";
        std::cout << "\n\t\t2. Edit Customer's Booking Record";
        std::cout << "\n\t\t3. View Booked Room";
        std::cout << "\n\t\t4. View checked in list";
        std::cout << "\n\t\t0. Exit";
        std::cout << "\n\n\t\tEnter Your Choice: ";
        std::cin >> selection;

        switch (selection)
        {
        case 1:
            AviewRecord();
            break;
        case 2:
            AeditRecord();
            break;
        case 3:
            AviewRoom();
            break;
        case 4:
            Acheckinlist();
            break;
        case 0:
            exit(1);
            break;
        default:
        {
            std::cout << "\n\n\n\t\tWrong Choice...";
            std::cout << "\n\tPress Enter Key To Continue...";
            getch();
            goto top2;
            
        }
        }
    }while(selection != 0);
}

void Main::customerMenu()
{
    Customer a;
    a.Cmenu1();  
};

void Customer::Cmenu1()
{
    top3:
    system("cls");
    int selection;
    std::cout << "\n\t -------HOTEL Aa-Ka-Ma-------" << std::endl;
    std::cout << "\n\n------------------ CUSTOMER -------------------------" << std::endl;
    std::cout << "1.   View room" << std::endl;
    std::cout << "2.   Book room" << std::endl; //CUSTOMER PAGE
    std::cout << "3.   Other facilities" << std::endl;
    std::cout << "4.   checkin" << std::endl;
    std::cout << "5.   checkout" << std::endl;
    std::cout << "0.   Exit" << std::endl;
    std::cout << "\n\n\t\tEnter Your Choice: ";
    std::cin >> selection;
    switch (selection)
    {
    case 1:
        availableRoom();
        goto top3;
        break;
    case 2:
        bookRoom();
        goto top3;
        break;
    case 3:
        otherFaci();
        goto top3;
        break;
    case 4:
        checkin();
        goto top3;
        break;
    case 5:
        checkout();
        goto top3;
        break;
    case 0:
        exit(1);
        goto top3;
        break;
    default:
        std::cout << "\n\n\n\t\tWrong Choice...";
        std::cout << "\n\tPress Enter Key To Continue...";
        getch();
        goto top3;
    }
}