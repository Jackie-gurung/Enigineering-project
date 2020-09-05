#include<iostream>
#include<cmath>
#include<cstring>
#include<string>                                             //INCLUDING HEADER FILES
#include<conio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

string avr;
double proom[6]={2000, 3500, 5500, 1000, 2000, 3000};
double pfaci[7]={0,0,100,500,3000,5000,500};                            //INITILIZING THE PRICE OF ROOMS, FACILITIES
int checking[6]={2,3,4,1,1,2};
char z, email[15];


class customer{
    private:
       string cname,tname,n1,n2,ch;
       char mob_no[10], idno[8],date[8];                                //CUSTOMER CLASS 
       int rn,rt;
       int f,m,tfac=0;
       
    public:
       void availableroom();
       void bookroom();
       void otherfaci();


}c1;

void customer::availableroom()
{
    ifstream  avfile("rtype.txt");
    getline(avfile,avr);
    cout<<endl;                                                         //TO SHOW AVAILABLE ROOMS
    while(!avfile.eof())
    {
    	cout<<"\n"<<avr;
    	getline(avfile,avr);
	}
    avfile.close();
   
    getch();
}




void customer::bookroom()
{	
    //ask information

          cout<<"please choose a room type from above";
          cin>>rn;
          cout<<endl;
          cout<<"please enter the number of room to book";
          cin>>rt;
          cout<<endl;
          
          if(checking[rn-1]>=rt)                                           //TO BOOK ROOM BY CUSTOMER
          {
         system("cls");                               
          cout<< "the total amount for your room is:  "<<proom[rn]*rt<<endl;      
          cout<<"PLEASE ENTER YOUR FULL NAME  :";
         cin.ignore();
         getline(cin, cname);
          
          cout<<endl;
          cout<<"PLEASE ENTER YOUR MOBILE NUMBER  :";
          cin>>mob_no;
          
          cout<<endl;
          cout<<"PLEASE ENTER THE NAME OT TRAVEL AGENCY  :";
          cin.ignore();
          getline(cin,tname);
          cout<<endl;
          
          cout<<"PLEASE ENTER YOUR PASSPORT/CITIZENSHIP NO  :";
          cin>>idno;
          cout<<endl;
          
          cout<<"PLEASE ENTER THE DATE OF CHECKIN (FORMATE MM/DD/YYYY)     :";
          cin>>date;
          cout<<endl;
          
          cout<<"PLEASE ENTER YOUR EMAIL ID  :";
          cin>>email;
          cout<<endl;
          
          cout<<"***************CONGRATULATION YOUR ROOM HAS BEEN BOOKED************"<<endl;
		  cout<<"************* PLEASE PAY THE CASH AT THE TIME OF CHECKIN************"<<endl;
           getch();
         }
        else
		{
			cout<<"SORRY!! THEIR IS  NOT ENOUGH ROOM AVAILABLE AT THIS MAOMENT"<<endl;
			cout<<"PLEASE HAVE A LOOK IN AVAILABLE ROOMS LIST";
			 getch();
		 } 
  int counter;
    fstream recfile("record.txt",ios::app);
    recfile<<endl;
    recfile<<"NAME :"<<cname<<endl;
    recfile<<"DATE :"<<date<<endl;
    recfile<<"MOBILE NO :"<<mob_no<<endl;
    recfile<<"ID.NO :"<<idno<<endl;
    recfile<<"TRAVEL AGENCY :"<<tname<<endl;
    recfile<<"EMAIL ID :"<<email<<endl;
    recfile<<rt<<"number of rooms were booked of "<<rn<<"type and total amounts to"<<proom[rn]*rt<<endl;
    recfile.close();
}
  
  
 

void customer::otherfaci()
{  
    ifstream facifile("faci.txt");
    getline(facifile,ch);
    cout<<endl;
    cout<<endl;
    
    while(!facifile.eof())
    {
    	getline(facifile,ch);
    	if(ch!="pfaci")
		{
    	cout<<ch<<endl;                                               // SHOW OTHER FACILITIES AND CALCULATE TOTAL PRICE
        }
        else
        {
        	break;
		}
	}
	cout<<"PLEASE GIVE THE S.NO OF THE DESIRED FACILITIES WHIOUT SPACE";
    cin>>f;
    while(f!=0)
    {
    	m=f%10;
    	f=int(f/10);
    	tfac=tfac+pfaci[m];	
	}
    cout<<endl;
    cout<<"THE TOTAL AMOUNT OF YOUR FACILITIES ARE    :"<<tfac<<endl;
     getch();
}

int main()
{   
    top2:
    
    int x1,x2;
    cout<<"***********************WELCOME TO**********************************"<<endl;
    cout<<"**************************HMS***********************************"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;                                                      //WELCOME PAGE
    cout<<"PLEASE MAKE A CHOICE"<<endl;
    cout<<"1.   ADMINISTRATION"<<endl;
    cout<<"2.   CUSTOMER"<<endl;
    cout<<"0.   EXIT"<<endl;
    cin>>x1;



    switch(x1)
    {
        case 1:
		system("cls"); 
		cout<<"happy"<<endl;
	
                break;
        case 2:
        	top3:
        	system("cls");
    
            cout<<endl;
             
             cout<<"PLEASE SELECT ONE"<<endl;
             cout<<"1.   VIEW AVAILABLE ROOM"<<endl;
             cout<<"2.   BOOK ROOM"<<endl;                                //CUSTOMER PAGE
             cout<<"3.   OTHER FACILITIES"<<endl;
             cout<<"4.   EXIT"<<endl;
             cin>>x2;
             switch(x2)
             {    
                 case 1:
                 	system("cls");
                 	c1.availableroom();
                 	goto top3;
                 	break;
                 case 2:
				 system("cls");
				  cout<<"WELCOME TO ROOM BOOKING MENU"<<endl;
                         c1.bookroom();
                         goto top3;
                         break;
                 case 3: 
				 system("cls");
				 cout<<"THE OTHER FACILITIES IN THIS HOTEL ARE"<<endl;
                        c1.otherfaci();
                        goto top3;
                         break;
                 case 4: 
				 system("cls");
				 goto top2;
                 default:
                 	system("cls");
                  cout<<"****************ERROR!   ERROR!!    ERROR!!!*************"<<endl;
             }
            
        case 0: break;

        default:
        system("cls");
            cout<<"****************ERROR!   ERROR!!    ERROR!!!*************"<<endl;
      
    };

}
