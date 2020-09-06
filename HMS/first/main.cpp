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
    cout << "\n\n\n\n\n\nPress Enter To Continue......";
    cout << "\n\n\n";

    int ch = cin.get();
    
            
    Main first;
    first.menu1();

    
    return 0;
}