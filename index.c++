#include<bits/stdc++.h>
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

    }
}
}