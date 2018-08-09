/*PROGRAM NAME: ATM system PURPOSE: To maintain the bank account*/
#include<iostream>
#include<fstream>
#include<string>
 #include<cstdio>
 #include<exception>
  #include<stdlib.h>
  using namespace std;
  class user { public: string name; int pin; user(string tname="",int tpin='0')
   { name=tname; pin=tpin; }
   void printdetails() {
  cout<<"\nAccount Holder Name is: "<<name;
  cout<<"nPassword is ****";
   }
   friend int finding(user u[10],user b,int n);
    };
    class atm:public user {
    public: int accntno;
    int balance;
    void readdetails() {
    cout<<"nEnter the Account Number";
     cin>>accntno;
     cout<<"nEnter the Balance Initially";
      cin>>balance;
       }
       void checkbalance(int e){
       user u[10];
       cout<<"nBalance in the Account is "<<balance;
       cout<<"nAccount Number of Yours is"<<accntno;
       }
       void withdrawcash() {
    int withdraw;
     cout<<"nEnter the amount to be withdrawn";
     cin>>withdraw;
     if(withdraw%100!=0)
     cout<<"nPlease Enter the amount to be withdrawn in multiples of 100";
      else if(withdraw>balance)
      cout<<"nInsufficient Balance in your account";
      else {
      balance=balance-withdraw;
      cout<<"nPlease collect the cash";
       cout<<"nYour Current Balance is "<<balance;
        }
        }
         void depositcash() {
         int deposit;
         cout<<"nEnter the Amount To be Deposited";
         cin>>deposit;
          balance=balance+deposit;
           cout<<"nYour Current Balance is "<<balance;
            }
            };
             int finding(user u[10],user b,int n) {
 int i;
  for(i=0;i<n;i++) {
   if(u[i].name==b.name && u[i].pin==b.pin) {
   return i;
    break;
    }
    }
    return -1;
    }
    int menu() {
    int i;
    cout<<"nttWelcome to INDIAN ATMtt"<<endl;
     cout<<"nEnter Your Choice"<<endl;
     cout<<"1.Check Balance"<<endl;
     cout<<"2.Withdraw Cash"<<endl;
     cout<<"3.Deposit Cash"<<endl;
     cout<<"4.To exit and to switch to other user"<<endl;
     cout<<"5.To Exit Totally"<<endl;
      cin>>i;
      return i;
      }
       main()
       {
        fstream file1("details.txt",ios::in|ios::out|ios::binary|ios::trunc);
         int i,tpin,k=0,e,d,r=0;
         int n=10;
 char s;
 atm c[10];
 string na;
 int j[10];
 for(i=0;i<10;i++){
  j[i]=0;
   }
    user u[10]={ user("Rakhav",1234),user("Krishna",1235),user("Keshav",1236),user("Hari",1237),user("Riya", 1238),user("Pavithran",1239),user("Sundhar",1240),user("Balan",1241),user("Karthik",1242),user("Vignesh",1243)};
     user a[10];
      for (i=0;i<10;i++) {
      file1.write((char *) &u[i],sizeof(user));
       } for(i=0;i<10;i++){
        file1.seekg(i*sizeof(user),ios::beg);
         file1.read((char *) &a[i],sizeof(user));
          }
          for(i=0;i<10;i++) {
          a[i].printdetails();
    } Rakhav:
 cout<<"nEnter the UserName";
 cin>>na;
  cout<<"nEnter the pin";
   cin>>tpin;
   user b(na,tpin);
   k=finding(a,b,n);
   e=k;
    try {
    if (k==-1)
    throw 21;
     }
     catch(int) {
     cout<<"nINVALID PASSWORD";
     exit(0);
     }
     if (j[e]==0) {
     c[e].readdetails();
      j[e]=j[e]+1;
      }
       do {
        loop: d=menu();
         switch(d) {
          case 1: cout<<"nAccount Holder Name is "<<na;
           cout<<"nPassword is ****"; c[k].checkbalance(e);
            break;
            case 2: c[k].withdrawcash();
             break;
             case 3: c[k].depositcash();
              break;
              case 4: cout<<"nnttThank You!!! for using our ATMnn";
              goto Rakhav;
              break;
              case 5:
              exit(0);
              default: cout<<"nInvalid Entry!!";
              goto loop;
              break;
 }
 cout<<"nDo you wish to have another transaction? (1/0)";
  cin>>r;
   }while(r);
    }



















