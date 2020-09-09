#include "hotel.h"
#include <iostream>
#include <conio.h>
#include "unistd.h" 


using namespace std;

int main(){
    
    cout << "\n\t\t\t\t-------------------------------------------";
    cout << "\n\t\t\t\t|| ------------------------------------- ||";
    cout << "\n\t\t\t\t||                                       ||";
    cout << "\n\t\t\t\t||           WEL-COME TO                 ||";
    cout << "\n\t\t\t\t||         HOTEL  Aa-Ka-Ma               ||";
    cout << "\n\t\t\t\t||       Jomsom - 4, Mustang             ||";
    cout << "\n\t\t\t\t||                                       ||";
    cout << "\n\t\t\t\t|| ------------------------------------- ||";
    cout << "\n\t\t\t\t-------------------------------------------";
    cout << "\n\n\n\n\n\nPress ANY To Continue......";
    cout << "\n\n\n";
    getch();
    
            
    Main first;
    first.menu1();

    
    return 0;
}