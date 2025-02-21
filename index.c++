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

// For print Bill
void printBill(){
    system("cls");
    int count = 0;
    bool close = false;
    while(!close){
        system("cls");
        int choice;
        cout<<"\t1.Add Bill."<<endl;
        cout<<"\t2.Close Session."<<endl;
        cout<<"\tEnter Choice: ";
        cin>>choice;
        if(choice == 1){
            string item;
            int quant;
            cout << "\tEnter Item :";
            cin >> item;
            cout << "\tEnter Quantity :";
            cin >> quant;


            ifstream in ("Desktop\GIT PUSH\Super-Market-Billing-System\Bill.txt");
            ofstream out("Desktop\GIT PUSH\Super-Market-Billing-System\Billtemp.txt"); 

            string line;
            bool found = false;
            
            //Read the file line by line
            while(getline(in , line)){
                // Extract word
                stringstream ss;
                ss << line;

                string itemName;
                int itemRate;
                int itemQuant;
                char delimiter; // for " : "

                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                // Find Item
                if(item == itemName){
                    found = true;
                    if(quant == itemQuant){
                        int ammount = itemRate*quant;
                        cout << "\t Item | Rate | Quantity | Ammount"<<endl;
                        cout <<"\t" << itemName << "\t" << itemRate << "\t" << quant <<"\t" << ammount<<endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += ammount;
                        out <<"\t" <<itemName << " : " <<itemRate << " : " <<itemQuant<<endl<<endl;

                    }
                    else{
                        // Not quantity
                        cout << "\tSorry,"<<item <<"Ended !!" <<endl;
                    }
                }
                else{
                    out<<line;
                }
            }
            if(!found){
                cout <<"\t Item is not found!!"<<endl;
            }
            out.close();
            in.close();
            remove("Desktop\GIT PUSH\Super-Market-Billing-System\Bill.txt");
            rename("Desktop\GIT PUSH\Super-Market-Billing-System\Billtemp.txt","Desktop\GIT PUSH\Super-Market-Billing-System\Bill.txt");
        }
        else if(choice==2){
            close = true;
            cout <<"\tCounting Total Bill"<<endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout<<"\tTotal Bill ---------------------------- : Rs" <<count <<endl <<endl;
    cout <<"\tThanks For Shopping";
    Sleep(5000);

}

int main(){
Bill b;
bool exit = false;
while(!exit){
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
    else if(val == 2){
        printBill();
    }
    else if(val==3){
        system("cls");
        exit = true;
        cout<<"\tGood Luck!"<<endl;
        Sleep(3000);
    }
}
}