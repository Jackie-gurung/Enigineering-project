#pragma once 
#include<iostream>

class Main {

    public:
        void menu1();
        void adminMenu();
        void customerMenu();

        // Main(); //Default constructor

    
};

class Admin : public Main {
    public:
        void login();       //to set up password
        void Amenu1();      //to display menu of Admin

        void AviewRecord();
        void AeditRecord();
        void AviewRoom();
        void AstaffManagement();
};

class AMenu : public Admin {

};