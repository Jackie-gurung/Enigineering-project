#pragma once 
#include<iostream>

class Main {

    public:
        char name[20];
        long contact{0};
        // long identityNo{0};
        int roomNo{0};
    // methods 
        void menu1();
        void adminMenu();
        void customerMenu();

        // Main(); //Default constructor

    
};

class Admin : public Main {
    public:
        void login();       //to set up password
        void Amenu1();      //to display menu of Admin
        //first Menu of Admin
        int check(int);
        void AviewRecord();
        void AeditRecord();
        void AviewRoom();

        //menu of edit record
        void EditCR();
        void DeleteCR();
        void ResetAll();
};

class Customer : public Main{
    public:
        void Cmenu1();

        int check(int);
        void availableRoom();
        void bookRoom();
        void otherFaci();
};

