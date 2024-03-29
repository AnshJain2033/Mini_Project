#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
//-------------------------------------------------------------------------
//Declaration of all the functions:-
int     bookingID=0;
void    header();
void    My_exit();
void    interfaceWindow_01();
void    DetailCollection();
void    addToFile(int t1);
void    makeBillForBooking();
int     menu(bool flag,int room);
void    order();
void    orderWithBooking();
void    generateBillWithBooking();
//-------------------------------------------------------------------------
//Public declared array
string dishes[9]={"Pizza","Pasta",
                "Burger","Sprite",
                "Coca cola","Samosa",
                "Chips","Roti","Dal"};
//-------------------------------------------------------------------------
/*  booking class this class is used to store the individual details of the
 *  customer this is done by creation of an object of this class
 */
class booking{
    public:
    string name;
    int     dateOfarrival;
    int     monthOfarrival;
    int     dateOfdeparture;
    int     monthOfdeparture;
    int     yearOfarrival;
    int     yearOfdeparture;
    int     bill;
    int     yourBookingID;
    vector<vector<pair<int,pair<int,int>>>>myOrdersBooking;
    booking(string name,int arrival,int dateOfdeparture,int & bookingID){
        this->name=name;
        this->dateOfarrival=arrival;
        this->dateOfdeparture=dateOfdeparture;
        this->bill=500*(dateOfdeparture-dateOfarrival);
        this->yourBookingID=bookingID+1;
        bookingID++;
        cout<<"YOUR BOOKING IS DONE \n";
        cout<<"YOUR ID NUMBER IS \n"<<yourBookingID<<"\n";
        
        system("pause");
    }
};
vector<booking*>v; // vector having object as pointer to class booking
//-------------------------------------------------------------------------
 /* 
  * My_exit() function is used for returning 
  * back to the main Interface Window. 
  */
void My_exit(){    
interfaceWindow_01();            
}
//-------------------------------------------------------------------------
/*  DetailCollection() This function is used to collect details from the 
 *  user and create an object of that user and store value of its data
 *  members there
 */
void DetailCollection(){
    system("CLS");
    header();
    string  MyName;
    string  temporary;
    int     arrival;
    bool    flag=false;
    int     departure;
    cout<<"TARRIF IS 500 Rs. PER DAY\n";
    cout<<"TO CONTINUE BOOKING PRESS Y ELSE PRESS N::TO EXIT PRESS 0\n";
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
    system("pause");
    interfaceWindow_01();
    }
    else if(temporary=="0"){My_exit();}
    else {interfaceWindow_01();}
}
//-------------------------------------------------------------------------
void header() 
 {
    system("CLS");
   cout<<"\n                      :::::::::::::::::::::::::::::::::::::";
   cout<<"\n                      ::                                 ::";
   cout<<"\n                      ::     ***********************     ::";
   cout<<"\n                      ::     @                     @     ::";
   cout<<"\n                      ::     @   HOTEL MANAGEMENT  @     ::";
   cout<<"\n                      ::     @                     @     ::";
   cout<<"\n                      ::     @        SYSTEM       @     ::";
   cout<<"\n                      ::     @                     @     ::";
   cout<<"\n                      ::     ***********************     ::";
   cout<<"\n                      ::                                 ::";
   cout<<"\n                      :::::::::::::::::::::::::::::::::::::\n\n";
 }
//-------------------------------------------------------------------------
/*  addToFile() :- This function is used to append a record file for 
 *  business purpose.
 *  This function generates a .txt file and keeps recording the booking 
 *  details and billing details in form of space saperated columns
 */
void addToFile(int t1){
    fstream fp;
    fp.open("data.txt", fstream::app);
    fp<<v[t1-1]->name<<" "
      <<v[t1-1]->dateOfarrival
      <<" "<<v[t1-1]->dateOfdeparture
      <<" "<<v[t1-1]->bill
      <<" "<<v[t1-1]->yourBookingID<<endl;
    fp.close();   
}
//-------------------------------------------------------------------------
/*
 *  makeBillForBooking() This function is used to generated a copy of the
 *  bill of the user.
 *  It generates a .txt file which could be used to print a bill.
 *  The bill consist of romm tarrif per day, orders details places by the 
 *  user, total billing amount.
 */
void makeBillForBooking(){
     system("CLS");
    header();
    fstream fp1;
    int     t2;
    int     counter=1;

    cout<<"ENTER YOUR BOOKING ID NUMBER :: \n \v TO EXIT PRESS 0\n";
    cin>>t2;
    if(v.size()>=t2){
    fp1.open("YourBill.txt",fstream::app);
    fp1<<"-------------------RECEIPT------------------------------"<<endl;
    fp1<<"Room Tarrif per day                           >> 500 Rs."<<endl;
    fp1<<"S.no------ITEM--------QUANITY----------MRP---------TOTAL"<<endl;
    for(int j=0;j<v[t2-1]->myOrdersBooking.size();j++){
            for(int i=0;i<v[t2-1]->myOrdersBooking[j].size();i++){
                int quantity=v[t2-1]->myOrdersBooking[j][i].second.first;
                int mrp=v[t2-1]->myOrdersBooking[j][i].second.second;
                int serial_no=(v[t2-1]->myOrdersBooking[j][i].first);
                int product=mrp*quantity;
                if(quantity!=0){
                    fp1<<counter<<
                    ")----------"<<dishes[serial_no-1]
                    <<"---------"<<quantity
                    <<"---------"<<mrp
                    <<"---------"<<product<<endl;     
                    counter++;
                    v[t2-1]->myOrdersBooking[j][i].second.first=0;
                }
            }
    }
    fp1<<"-------------------------------------------------------"<<endl;
    fp1<<"------------------------------------------------Amount Is:-  "
       <<v[t2-1]->bill<<endl;
    cout<<"COPY OF YOUR BILL IS CREATED\n";
    }
    else if(t2==0){My_exit();}
    else {cout<<"INVALID BOOKING ID \n";}
    system("pause");
    interfaceWindow_01();
} 
//-------------------------------------------------------------------------
/*
 *  menu():- This function is basically used to display the menu for the 
 *  order.Also we can give many entries in single run of this function.
 *  Also this function helps to store the entries which are used in bill 
 *  generation. 
 */
int menu(bool flag,int room){
    system("CLS");
    header();
    int     a,b,c=0;
    string  st;
    vector<pair<int,pair<int,int>>>singleOrder;
    
   
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
   
    singleOrder.push_back(make_pair(a,make_pair(b,arr[a-1])));
     c=c+(b*arr[a-1]);
    cout<<"TO CONTINUE ORDERING PRESS::Y ELSE PRESS N\n";
    cin>>st;
    }while(st=="Y"||st=="y");
    if(flag==true && room!=0){
        v[room-1]->myOrdersBooking.push_back(singleOrder);
    }
  
    return c;
}
//-------------------------------------------------------------------------
/*
 *  order() This function is basically used to take order of the user not 
 *  having any booking ID.It takes order and just displays the billing 
 *  amount. 
 */
void order(){
    system("CLS");
    header();
    int     yourBILL=0;
    string  s;
    cout<<"TO PLACE AN ORDER PRESS::Y else PRESS N \n TO EXIT PRESS 0\n";
    cin>>s;
    
        if(s=="Y"||s=="y"){
        bool flag2=false;
        yourBILL= yourBILL + menu(flag2,0);
        cout<<"\n YOUR TOTAL BILLING AMOUNT IS ::"<<yourBILL<<"\n";
	}
     else if(s=="0"){My_exit();}
        system("pause");
    interfaceWindow_01();
}
//-------------------------------------------------------------------------
/*
 *  orderWithBooking() this function provides facility to the user to place
 *  an order using Booking ID. The total payable amount generated each 
 *  time user places an order gets updated in the final billing of the 
 *  customer. 
 */
void orderWithBooking(){
    system("CLS");
    header();
    int     m;
    cout<<"ENTER YOUR BOOKING ID ::\n TO EXIT PRESS 0\n";
    cin>>m;
    if(v.size()>=m){
        bool flag1=true;
       v[m-1]->bill = v[m-1]->bill+menu(flag1,m);
    }
    else if(m==0){ My_exit();}
    else {cout<<"INVALID BOOKING ID\n";}
       
        system("pause");
    interfaceWindow_01();
}
//-------------------------------------------------------------------------
/*
 *  generateBillWithBooking():- This function is used to generate a bill of
 *  of the user using Booking ID of the user it display the bill also it 
 *  store the billing details in a separate .txt file 
 */
void generateBillWithBooking(){
    system("CLS");
    header();
    int     t;
    cout<<"ENTER YOUR BOOKING ID::\n TO EXIT PRESS 0\n";
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
    else if(t==0){My_exit();}
    else {cout<<"INVALID BOOKING ID\n";}
         
        system("pause");
    
    interfaceWindow_01();
}
//-------------------------------------------------------------------------
/*
 *  interfaceWindow_01() this function is used to create an interface for 
 *  for user to interact with the program it directs the flow of program
 *  according to the users choice.
 */
void interfaceWindow_01(){
    system("CLS");
    header();
    int     k;
    
    cout<<" SELECT AS PER YOUR CHOICE\n";
    cout<<"1) MAKE A BOOKING \n";
    cout<<"2) PLACE AN ORDER with BOOKING ID\n";
    cout<<"3) PLACE AN ORDER \n";
    cout<<"4) GENERATE BILL FOR BOOKING \n";
    cout<<"5) PRINT MY BILL(WITH BOOKING ID) \n";
    cout<<"TO EXIT PRESS 0\n";
    do{cin>>k;
    switch(k){
        case 0: exit(0);
            break;
        case 1: DetailCollection();
            break;
        case 2: orderWithBooking();
             break;
        case 3: order();
            break;
        case 4: generateBillWithBooking();
            break;
        case 5: makeBillForBooking();
            break;
       // default : cout<<"INVALID OPTION \n";
    }}while(k>5 || k<1);
}
//-------------------------------------------------------------------------
int main(){
    interfaceWindow_01();
    return 0;
}