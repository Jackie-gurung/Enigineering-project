#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

string ar[6]={"single", "double", "triple", "single", "double", "triple"};
double proom[6]={2000, 2500, 3000, 1000, 1500, 2000};
int totalroom[6]={6,5,4,5,7,3};
int avali_room[6];
string faci[7]={"swimming pool","wifi","extra shower","camp fire","house on rent","vehicles on rent","tour guid"};
double pfaci[7]={0,0,100,500,3000,5000,500};
char fa[7];

class coustmer{
    private:
       string name,n1,n2, adress, occu;
       long int mob_no, idno, mpin,otp=123, bankacc;
       int rn,rt;

    public:
       void avaiableroom();
       void bookroom();
       void otherfaci();


}c1;

void coustmer::avaiableroom()
{
    cout<<"sn.no        "<<"room type       "<<"total room      "<<"avaliable room      "<<"unit price"<<endl;
             for(int i=0;i<6;i++)
             {
                  cout<<i<<".   "<<ar[i]<<"             "<<totalroom[i]<<"                  "<<avali_room[i]<<"                 "<< proom[i]<<endl;
             };
}


void coustmer::bookroom()
{
    //ask information
    top3:
          cout<<"please choose a room type from above";
          cin>>rn;
          cout<<endl;
          cout<<"please enter the number of room to book";
          cin>>rt;
          cout<<endl;
          cout<< "the total amount for your room is:  "<<proom[rn]*rt<<endl;

          cout<<"to pay the amount. please enter the bank acc no";
          cin>>bankacc;
          cout<<"please enter the mpin";
          cin>>mpin;


   if(mpin!=otp)
   {
       cout<<"sorry, process failed"<<endl;
       goto top3;
   }
   else
   {
       cout<<"PLEASE ENTER YOUR FULL NAME  :";
       cout<<endl;
       cin>>n1>>n2;
       cout<<endl;
       cout<<"PLEASE ENTER YOUR MOBILE NUMBER  :";
       cin>>mob_no;
       cout<<endl;
       cout<<"PLEASE ENTER YOUR PERSONAL IDCARD NO  :";
       cin>>idno;
       cout<<endl;
       cout<<"PLEASE ENTER YOUR OCCUPATION  :";
       cin>>occu;
       cout<<endl;
  
  }
}
void coustmer::otherfaci()
{ 
    cout<<"1.  swimming pool      "<<"free"<<endl;
    cout<<"2.  wifi              "<<"free"<<endl;
    cout<<"3.  extra shower (hot)"<<"rs 100 per head"<<endl;
    cout<<"4.  camp fire         "<<"rrs 500 per 50 kg firewood"<<endl;
    cout<<"5.  house on rent     "<<"rs 3000 per day"<<endl;
    cout<<"6.  vehicles on rent  "<<"rs 5000 per day"<<endl;
    cout<<"7.  tour guide        "<<"rs 500 per day"<<endl;

    cout<<"please select the facilities from above";
    cin>>fa[7];
    cout<<endl;
    cout<<"the total amount of ur facilities are"<<endl;
}

using namespace std;

int main()
{   
    top2:
    
    int x1,x2;
    cout<<"***********************WELCOME TO**********************************"<<endl;
    cout<<"**************************HMS***********************************"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"PLEASE MAKE A CHOICE"<<endl;
    cout<<"1.   ADMINISTRATION"<<endl;
    cout<<"2.   COUSTMER"<<endl;
    cout<<"0.   EXIT"<<endl;
    cin>>x1;



    switch(x1)
    {
        case 1: cout<<"happy"<<endl;
                break;
        case 2:
            c1.avaiableroom();
              
             cout<<endl;
             cout<<"PLEASE SELECT ONE"<<endl;
             cout<<"1.   BOOK ROOM"<<endl;
             cout<<"2.   OTHER FACILITIES"<<endl;
             cout<<"0.   EXIT"<<endl;
             cin>>x2;
             switch(x2)
             {    
                 
                 case 1: cout<<"WELCOME TO ROOM BOOKING MENU"<<endl;
                         c1.bookroom();
                         break;
                 case 2: cout<<"THE OTHER FACILITIES IN THIS HOTEL ARE"<<endl;
                        c1.otherfaci();
                         break;
                 case 0: goto top2;
                 default:
                  cout<<"ERROR!   ERROR!!    ERROR!!!"<<endl;
             }
            
        case 0: break;

        default:
        
            cout<<"error  error  error"<<endl;
      
    };

}
