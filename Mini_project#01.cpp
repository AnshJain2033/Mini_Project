#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int bookingID=0;
void header();
void interfaceWindow_01();
struct triplet{
    int x,y,z;
};
string dishes[9]={"Pizza","Pasta","Burger","Sprite","Coca cola","Samosa","Chips","Roti","Dal"};
void makeBillForBooking();
class booking{
    public:
    string name;
    int dateOfarrival;
    int dateOfdeparture;
    int bill;
    int yourBookingID;
    vector<vector<triplet>>myOrdersBooking;
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
    fstream fp;
    fp.open("data.txt", fstream::app);
      
          fp<<v[t1-1]->name<<" "<<v[t1-1]->dateOfarrival<<" "<<v[t1-1]->dateOfdeparture<<" "<<v[t1-1]->bill<<" "<<v[t1-1]->yourBookingID<<endl;
          
        
           fp.close();
      
      
}
//-----------------------------------------------------------------------------------------
void makeBillForBooking(){
     system("CLS");
    header();
    fstream fp1;
    int t2;
    cout<<"ENTER YOUR BOOKING ID NUMBER \n";
    cin>>t2;
    if(v.size()>=t2){
    fp1.open("YourBill.txt",fstream::app);
    fp1<<"--------------------------------RECEIPT------------------------------"<<endl;
    fp1<<"Room Tarrif per day                                      >>   500 Rs."<<endl;
    fp1<<"S.no---------ITEM--------QUANITY-----------MRP-----------TOTAL"<<endl;
    for(int j=0;j<v[t2-1]->myOrdersBooking.size();j++){
    for(int i=0;i<v[t2-1]->myOrdersBooking[j].size();i++){
        int quantity=v[t2-1]->myOrdersBooking[0][i].y;
        int mrp=v[t2-1]->myOrdersBooking[0][i].z;
        int serial_no=(v[t2-1]->myOrdersBooking[0][i].x);
        int product=mrp*quantity;
    fp1<<i+1<<")----------"<<dishes[serial_no-1]<<"---------"<<quantity<<"---------------"<<mrp<<"------------"<<product<<endl;     
    }
    }
    fp1<<"----------------------------------------------------------------------"<<endl;
    fp1<<"---------------------------------------------------------Amount Is:-  "<<v[t2-1]->bill<<endl;
    cout<<"COPY OF YOUR BILL IS CREATED\n";
    }
    else {cout<<"INVALID BOOKING ID \n";}
    system("pause");
    interfaceWindow_01();
} 
//-----------------------------------------------------------------------------------------
// void makeBillForOrder{
    
// }

//-----------------------------------------------------------------------------------------
int menu(bool flag,int room){
    system("CLS");
    header();
    int a,b,c=0;
    string st;
    vector<triplet>singleOrder;
    
   
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
    // string dishes[9]={"Pizza","Pasta","Burger","Sprite","Coca cola","Samosa","Chips","Roti","Dal"};
    do{cout<<"\n ENTER THE SERIAL NUMBER\n";
    cin>>a;
    cout<<"\n ENTER QUANTITY YOU WANT \n";
    cin>>b;
    
    singleOrder.push_back({a,b,arr[a-1]});
     c=c+(b*arr[a-1]);
    cout<<"TO CONTINUE ORDERING PRESS::Y ELSE PRESS N\n";
    cin>>st;
    // }while(st=="Y"||st=="y");
    if(flag==true && room!=0){
        v[room-1]->myOrdersBooking.push_back(singleOrder);
    }
    }while(st=="Y"||st=="y");
    // else(flag==false && room==0){
    //     for(int i=0;i<singleOrder.size())
    // }
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
        bool flag2=false;
        yourBILL= yourBILL + menu(flag2,0);
        cout<<"\n YOUR TOTAL BILLING AMOUNT IS ::"<<yourBILL<<"\n";
	}
     
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
        bool flag1=true;
       v[m-1]->bill = v[m-1]->bill+menu(flag1,m);
    }
    else {cout<<"INVALID BOOKING ID\n";}
       
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
         
        system("pause");
    
    interfaceWindow_01();
}
//-----------------------------------------------------------------------------------------
void interfaceWindow_01(){
    system("CLS");
    header();
    int k;
    cout<<" SELECT AS PER YOUR CHOICE\n";
    cout<<"1) MAKE A BOOKING \n";
    cout<<"2) PLACE AN ORDER with BOOKING ID\n";
    cout<<"3) PLACE AN ORDER \n";
    cout<<"4) GENERATE BILL FOR BOOKING \n";
    cout<<"5) PRINT MY BILL(WITH BOOKING ID) \n";
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
        case 5: makeBillForBooking();
            break;
        default : cout<<"INVALID OPTION \n";
    }}while(k>5 || k<1);
}
//-----------------------------------------------------------------------------------------
int main(){
    interfaceWindow_01();
    return 0;
}