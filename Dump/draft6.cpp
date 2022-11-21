#include<bits/stdc++.h>
using namespace std;
int bookingID=0;
void header();
void interfaceWindow_01();
class booking{
    public:
    string name;
    int dateOfarrival;
    int dateOfdeparture;
    int bill;
    int yourBookingID;

    booking(string name,int arrival,int dateOfdeparture,int & bookingID){
        this->name=name;
        this->dateOfarrival=arrival;
        this->dateOfdeparture=dateOfdeparture;
        this->bill=500*(dateOfdeparture-dateOfarrival);
        this->yourBookingID=bookingID+1;
        bookingID++;
        cout<<"YOUR BOOKING IS DONE \n";
        cout<<"YOUR ID NUMBER IS \n"<<yourBookingID;
        cout<<"PRESS ANY KEY TO CONTINUE\n";
        system("pause");
    }
};
vector<booking*>v;
//-----------------------------------------------------------------------------------------
void DetailCollection(){
    system("CLS");
    header();
    string MyName;
    string temporary;
    int arrival;
    bool flag=false;
    int departure;
    cout<<"TARRIF IS 500 Rs. PER DAY\n";
    cout<<"TO CONTINUE BOOKING PRESS Y ELSE PRESS N::\n";
    cin>>temporary;
    if(temporary=="y"||temporary=="Y"){
    cout<<"Enter your details\n";
    cout<<"Enter your name(enter _ for spaces)-->>               ";
    cin>>MyName;
    cout<<"Enter your arrival date-->>                           ";
    cin>>arrival;
    cout<<"Enter your date of departure-->>                      ";
    cin>>departure;
    v.push_back(new booking(MyName,arrival,departure,bookingID));
    interfaceWindow_01();
    }
    else {interfaceWindow_01();}
     cout<<"PRESS ANY KEY TO CONTINUE\n";
        system("pause");
}
//-----------------------------------------------------------------------------------------
void header()
 {
    system("CLS");
   cout<<"\n                       :::::::::::::::::::::::::::::::::::::";
   cout<<"\n                       ::                                 ::";
   cout<<"\n                       ::     ***********************     ::";
   cout<<"\n                       ::     @                     @     ::";
   cout<<"\n                       ::     @   HOTEL MANAGEMENT  @     ::";
   cout<<"\n                       ::     @                     @     ::";
   cout<<"\n                       ::     @        SYSTEM       @     ::";
   cout<<"\n                       ::     @                     @     ::";
   cout<<"\n                       ::     ***********************     ::";
   cout<<"\n                       ::                                 ::";
   cout<<"\n                       :::::::::::::::::::::::::::::::::::::\n\n";
 }
//-----------------------------------------------------------------------------------------
void addToFile(int t1){
   fstream f;
   ofstream fout;
   ifstream fin;
      fin.open("a1.txt");
      fout.open ("a1.txt",ios::app);
      if(fin.is_open()){
          fout<<v[t1-1]->name<<" "<<v[t1-1]->dateOfarrival<<" "<<v[t1-1]->dateOfdeparture<<" "<<v[t1-1]->bill<<" "<<v[t1-1]->yourBookingID;
          cout<<"\nDATA SAVED\n";
           fin.close();
           fout.close();
      }
      
}

//-----------------------------------------------------------------------------------------
int menu(){
    system("CLS");
    header();
    int a,b,c=0;
    string st;
    cout<<"SELECT YOUR REQUIRED FOOD ACCORDING TO THE SERIAL NUMBER\n";
    cout<<"1)Pizza\n --->500 Rs. \n";
    cout<<"2)Pasta\n --->700 Rs. \n";
    cout<<"3)Burger\n --->50 Rs. \n";
    cout<<"4)Sprite\n --->30 Rs. \n";
    cout<<"5)Coca cola\n --->35 Rs. \n";
    cout<<"6)Samosa\n --->25 Rs. \n";
    cout<<"7)Chips\n --->15 Rs. \n";
    cout<<"8)Roti\n --->5 Rs. \n";
    cout<<"9)Dal\n --->250 Rs. \n";
    int arr[9]={500,700,50,30,35,25,15,5,250};
    do{cout<<"\n ENTER THE SERIAL NUMBER\n";
    cin>>a;
    cout<<"\n ENTER QUANTITY YOU WANT \n";
    cin>>b;
     c=c+(b*arr[a-1]);
    cout<<"TO CONTINUE ORDERING PRESS::Y ELSE PRESS N\n";
    cin>>st;
    }while(st=="Y"||st=="y");
    
    return c;
}
//-----------------------------------------------------------------------------------------
void order(){
    system("CLS");
    header();
    int yourBILL=0;
    string s;
    cout<<"TO PLACE AN ORDER PRESS::Y else PRESS N\n";
    cin>>s;
    
        if(s=="Y"||s=="y"){
        yourBILL= yourBILL + menu();
        cout<<"\n YOUR TOTAL BILLING AMOUNT IS ::"<<yourBILL<<"\n";
	}
     cout<<"PRESS ANY KEY TO CONTINUE\n";
        system("pause");
    interfaceWindow_01();
}
//-----------------------------------------------------------------------------------------
void orderWithBooking(){
    system("CLS");
    header();
    int m;
    cout<<"ENTER YOUR BOOKING ID \n";
    cin>>m;
    if(v.size()>=m){
       v[m-1]->bill = v[m-1]->bill+menu();
    }
    else {cout<<"INVALID BOOKING ID\n";}
        cout<<"PRESS ANY KEY TO CONTINUE\n";
        system("pause");
    interfaceWindow_01();
}
//-----------------------------------------------------------------------------------------
void generateBillWithBooking(){
    system("CLS");
    header();
    int t;
    cout<<"ENTER YOUR BOOKING ID\n";
    cin>>t;
    if(v.size()>=t){
    cout<<"\v YOUR BILL\n";
    cout<<"NAME::                 "<<v[t-1]->name<<"\n";
    cout<<"DATE OF ARRIVAL::      "<<v[t-1]->dateOfarrival<<"\n";
    cout<<"DATE OF DEPARTURE::    "<<v[t-1]->dateOfdeparture<<"\n";
    cout<<"YOUR BOOKING ID::      "<<v[t-1]->yourBookingID<<"\n";
    cout<<"YOUR BILLING AMOUNT::  "<<v[t-1]->bill<<"\n";
    addToFile(t);
    }
    else {cout<<"INVALID BOOKING ID\n";}
         cout<<"PRESS ANY KEY TO CONTINUE\n";
        system("pause");
    interfaceWindow_01();
}
//-----------------------------------------------------------------------------------------
void interfaceWindow_01(){
    system("CLS");
    header();
    int k;
    cout<<"   SELECT AS PER YOUR CHOICE\n";
    cout<<"1) MAKE A BOOKING \n";
    cout<<"2) PLACE AN ORDER with BOOKING ID\n";
    cout<<"3) PLACE AN ORDER \n";
    cout<<"4) GENERATE BILL FOR BOOKING \n";
    do{cin>>k;
    switch(k){
        case 1: DetailCollection();
            break;
        case 2: orderWithBooking();
             break;
        case 3: order();
            break;
        case 4: generateBillWithBooking();
            break;
        default : cout<<"INVALID OPTION \n";
    }}while(k>4 || k<1);
}
//-----------------------------------------------------------------------------------------
int main(){
    interfaceWindow_01();
    return 0;
}