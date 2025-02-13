#include<bits/stdc++.h>
#include<windows.h>
#include <fstream>
#include <sstream>
using namespace std;

// Define class
class Bill{
private:
    string Item;
    int Rate , Quantity;
// Constructor
public:
    Bill():Item(""),Rate(0),Quantity(0){

    }
// Setter Function for Item
void setItem(string item){
    Item = item;
}
// Setter Function for Rate
void setRate(int rate){
    Rate = rate;
}
// Setter Function for Quantity
void setquantity(int quantity){
    Quantity = quantity;
}

// Get function for item, rate, quantity which return the value
string getItem(){
    return Item;
}
int getRate(){
    return Rate;
}
int getquantity(){
    return Quantity;
}
};
// Define adding function 
void addItem(Bill b){
    bool close = false;
    while(!close){
        int ch; //ch for choice
        cout<<"\t1.Add."<<endl;
        cout<<"\t2.close."<<endl;
        cout<<"\tEnter Choice: ";
        cin>>ch;

        // 
        if(ch == 1){
            system("cls");
            string item;
            int rate , quant;

            // For item
            cout << "\tEnter Item Name :";
            cin >> item;
            b.setItem(item); 

            // For rate
            cout<<"\tEnter rate of item :";
            cin >> rate;
            b.setRate(rate);

            // For Quantity
            cout <<"\tEnter Quantity of Item : ";
            cin >> quant;
            b.setquantity(quant);
            
            //Store the data in text file , ios :: app //(append)
            ofstream out("Desktop\GIT PUSH\Super-Market-Billing-System\Bill.txt", ios::app);

            if((!out)){
                cout<<"\tError 404";
            }
            else{
                out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getquantity()<<endl <<endl;

            }
            out.close();
            cout<<"\t!!Items added successfully!!"<<endl;;
            // Display for some time
            Sleep(3000); //3000ms

        }

        // Second Condition
        else if(ch == 2){
            system("cls");
            close = true;
            cout<<"\tBack to main menu"<<endl;
            Sleep(3000);
        }
    }
}

int main(){
Bill b;
while(true){
    system("cls"); //The command "cls" stands for "clear screen" and is used in Windows Command Prompt
    int val;
    cout<<"\tWelcome To GIT Super Market Billing System"<<endl;
    cout<<"\t**************************************"<<endl;
    cout<<"\t\t1.Add Item."<<endl;
    cout<<"\t\t2.Print Bill."<<endl;
    cout<<"\t\t3.Exit."<<endl;
    cout<<"\t\tEnter Choice: ";
    cin>>val;
    
    if(val == 1){
        system("cls");
        Sleep(3000);
        addItem(b);
    }
    
}
}