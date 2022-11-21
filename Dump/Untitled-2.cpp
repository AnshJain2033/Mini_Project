#include<bits/stdc++.h>
using namespace std;
int bookingID=0;
vector<booking*>v;
class booking{
    string name;
    int dateOfarrival;
    int dateOfdeparture;
    int bill;
    int yourBookingID;

    booking(string name,int dataOfarrival,int dateOfdeparture,int & bookingID){
        this.name=name;
        this.dateOfarrival=dateOfarrival;
        this.dateOfdeparture=dateOfdeparture;
        this.bill=500*(dateOfdeparture-dateOfarrival);
        this.yourBookingID=bookingID;
        bookingID++;
        cout<<"YOUR BOOKING IS DONE \n"
        cout<<"YOUR ID NUMBER IS "<<yourBookingID;
    }
};
//-----------------------------------------------------------------------------------------
void DetailCollection(){
    system("CLS");
    header();
    string MyName;
    int arrival;
    int departure;
    cout<<"Enter your details \n";
    cout<<"Enter your name \n";
    cin>>MyName;
    cout<<"Enter your arrival date \n";
    cin>>arrival;
    cout<<"Enter your date of departure \n";
    cin>>departure;
    v.push_back(new booking(MyName,arrival,departure,bookingID));
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
int menu(){
    system("CLS");
    header();
    int a,b;
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
    cout<<"\n ENTER THE SERIAL NUMBER\n";
    cin>>a;
    cout<<"\n ENTER QUANTITY YOU WANT \n";
    cin>>b;
    int c;
    c=(b*arr[a-1]);
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
    do{
        if(s=="Y"||s=="y"){
        yourBILL= yourBILL + menu();
        cout<<"Do you want to continue placing more orders\n";
        cin>>s;
        }
    }while(s=="Y"||s=="y");
    cout<<"\n YOUR TOTAL BILLING AMOUNT IS ::"<<yourBILL<<"\n";
}
//-----------------------------------------------------------------------------------------
void orderWithBooking(){
    system("CLS");
    header();
    int m;
    cout<<"ENTER YOUR BOOKING ID \n";
    cin>>m;
    if(v.size()>=m){
        ((v[m-1])->bill)+menu();
    }
    else {cout<<"INVALID BOOKING ID\n";}
}
//-----------------------------------------------------------------------------------------
void generateBillWithBooking(int t){
    system("CLS");
    header();
    if(v.size()>=t){
    cout<<"\v YOUR BILL\n";
    cout<<"NAME::                 "<<v[t-1]->name<<"\n";
    cout<<"DATE OF ARRIVAL::      "<<v[t-1]->dateOfarrival<<"\n";
    cout<<"DATE OF DEPARTURE::    "<<v[t-1]->dateOfdeparture<<"\n";
    cout<<"YOUR BOOKING ID::      "<<v[t-1]->yourBookingID<<"\n";
    cout<<"YOUR BILLING AMOUNT::  "<<v[t-1]->bill<<"\n";
    }
}
//-----------------------------------------------------------------------------------------
void interfaceWindow_01(){
    system("CLS")
    header();
    int k;
    cout<<"\v SELECT AS PER YOUR CHOICE\n";
    cout<<"1) MAKE A BOOKING \n";
    cout<<"2) PLACE AN ORDER with BOOKING ID\n";
    cout<<"3) PLACE AN ORDER \n";
    cout<<"4) GENERATE BILL FOR BOOKING "
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