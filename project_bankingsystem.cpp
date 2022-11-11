#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

class Bank
{
private:
int num;
struct customer{
string name,ID,address;
int cash,contact;
}customer[100];
public:
Bank(){
    num=0;
}

void choice();
void perData();
void Show();
void Update();
void Search();
void Transaction();
void Delete();

};
int main(){
    Bank RBI;
    RBI.choice();
    return 0;
}
void Bank::choice(){
    char ch;
    while(1)
    {
        cout<<"\n.....PREESS ANY BUTTON....!!!!!"<<endl;

        cout<<"1.Create new account"<<endl;
        
        cout<<"2.View Customer list "<<endl;
        
        cout<<"3.Update information of existing account "<<endl;

        cout<<"4.Check the details of existing account"<<endl;

        cout<<"5.For transactions"<<endl;
        
        cout<<"6.Remove existing account "<<endl;
     
        cout<<"7.Exit"<<endl;

        ch=getch();
        
        system("CLS");

        switch(ch){
            case '1':
            Bank::perData();
            break;

            case '2':
            if(num==0){
                cout<<"NO DATA IS ENTERED"<<endl;
            }
            else{
                Bank::Show();
            }
            break;
            case '3':
             if(num==0){
                cout<<"NO DATA IS ENTERED"<<endl;
            }
            else{
                Bank::Update();
            }
            break;
            case '4':
             if(num==0){
                cout<<"NO DATA IS ENTERED"<<endl;
            }
            else{
                Bank::Search();
            }
            break;
            case '5':
             if(num==0){
                cout<<"NO DATA IS ENTERED"<<endl;
            }
            else{
                Bank::Transaction();
            }
            break;
            case '6':
             if(num==0){
                cout<<"NO DATA IS ENTERED"<<endl;
            }
            else{
                Bank::Delete();
            }
            break;

            case '7':
            exit(0);
            break;

            default:
            cout<<"Invalid Input"<<endl;
            break;

        }
        

    }
}
void Bank::perData(){
    cout<<"Enter the data of person   "<<num+1<<endl;

    cout<<"Enter name: ";
    cin>>customer[num].name;
    cout<<"ID:  ";
    cin>>customer[num].ID;
    cout<<"Address: ";
    cin>>customer[num].address;
    cout<<"contact: ";
    cin>>customer[num].contact;
    cout<<"Total cash: ";
    cin>>customer[num].cash;
    num++;

}
void Bank::Show(){
    for(int i=0;i<num;i++){
        cout<<"Data of person"<<i+1<<endl;

        cout<<"Name: "<<customer[i].name<<endl;

        cout<<"ID: "<<customer[i].ID<<endl;

        cout<<"Address: "<<customer[i].address<<endl;

        cout<<"Contact: "<<customer[i].contact<<endl;

        cout<<"cash: "<<customer[i].cash<<endl;


    }
}
void Bank::Update(){

    string id;
    cout<<"Enter ID of customer whose data you want to update "<<endl;

    cin>>id;
    for(int i=0;i<num;i++){
        if(id == customer[i].ID){
        cout<<"previous Data: "<<endl;

        cout<<"Data of person"<<i+1<<endl;

        cout<<"Name: "<<customer[i].name<<endl;

        cout<<"ID: "<<customer[i].ID<<endl;

        cout<<"Address: "<<customer[i].address<<endl;

        cout<<"Contact: "<<customer[i].contact<<endl;

        cout<<"cash: "<<customer[i].cash<<endl;

        cout<<"\nEnter new data"<<endl;
        
        cout<<"Enter name: ";
        cin>>customer[i].name;

        cout<<"ID: ";
        cin>>customer[i].ID;

        cout<<"Address: ";
        cin>>customer[i].address;

        cout<<"contact: ";
        cin>>customer[i].contact;

        cout<<"Total cash: ";
        cin>>customer[i].cash;
        
        break;

        }
        if(i==num-1){
          cout<<"No such record found"<<endl;
        }
    }
}
void Bank::Search(){
    string id;
    cout<<"Enter ID of student those data you want to search "<<endl;
    cin>>id;
    
    for(int i=0;i<num;i++){
        if(id == customer[i].ID){
        cout<<"Name: "<<customer[i].name<<endl;

        cout<<"ID: "<<customer[i].ID<<endl;

        cout<<"Address: "<<customer[i].address<<endl;

        cout<<"Contact: "<<customer[i].contact<<endl;

        cout<<"cash: "<<customer[i].cash<<endl;
        }
          if(i==num-1){
          cout<<"No such record found"<<endl;
        }
    }
    }

void Bank::Transaction(){
    int cash;
    char ch;
    string id;

    cout<<"Enter ID of customer in which you to do transaction "<<endl;
    cin>>id;
    
  for(int i=0;i<num;i++){
      if(id == customer[i].ID){
        cout<<"Name: "<<customer[i].name<<endl;

        cout<<"Address: "<<customer[i].address<<endl;

        cout<<"Contact: "<<customer[i].contact<<endl;

        cout<<" Existing cash: "<<customer[i].cash<<endl;

        cout<<"Press 1  to DEPOSIT"<<endl;
        
        cout<<"Press 2  to WITHDRAW"<<endl;
          
          ch=getch();
          switch(ch){


            case '1':
            cout<<"Enter the Amount"<<endl;

            cin>>cash;

            customer[i].cash+=cash;

            cout<<"Your new cash is"<<customer[i].cash<<endl;
            break;
            
            case '2':
            back:
            cout<<"Enter the Amount you want to withdraw"<<endl;

            cin>>cash;
            if(cash>customer[i].cash){
                cout<<"Your existing cash is just "<<customer[i].cash<<endl;
                Sleep(3000);
                goto back;
            }

            customer[i].cash-=cash;
            cout<<"Invalid input "<<endl;
            break;
          }
   break;

  }
   if(i==num-1){
          cout<<"No such record found"<<endl;
        }
  }
}
void Bank::Delete(){
    char ch;
    string id;


    cout<<"press 1 to remove specific record"<<endl;

    cout<<"press 2 to remove full record"<<endl;
    ch=getch();

    switch(ch){
        case '1':
        cout<<"Enter the ID of customer"<<endl;

        cin>>id;
        for(int i=0;i<num;i++){
              if(id == customer[i].ID){
            
            for(int j=i;j<num;j++){
               customer[j].name=customer[j+1].name; 
               customer[j].ID=customer[j+1].ID; 
               customer[j].address=customer[j+1].address; 
               customer[j].contact=customer[j+1].contact; 
               customer[j].cash=customer[j+1].cash;

               num--;

               cout<<"Your required data is deleted "<<endl;
               break;


            }

        }
        
         if(i==num-1){
          cout<<"No such record found"<<endl;
        }
        }
    break;
    case '2':
     
     num=0;
    
     cout<<"All the records are deleted"<<endl;
    
    break;

    default:
    cout<<"Invalid Input "<<endl;
    break;
    
  }

}