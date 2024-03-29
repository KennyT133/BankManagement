#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class bank{
    private: //Bank accounts will have name, pin to access bank, account number to define each bank account, and balance of the bank account
    std::string accountName;
    int balance,pin;
     static int accountNumber;
    public:
    bank(std::string inputName, int inputPin); //Create the bank account
    void deposit(int pin, int amount,int inputAccountNumber); //Deposit the amount into bank account
    void withdraw(int pin, int amount,int inputAccountNumber);
    void display_info();
    void deleteAccount();
    int getAccountNumber();
    int getPin();
};
int bank::accountNumber = 0;
bank::bank(string inputName, int inputPin){
    accountName = inputName;
    pin = inputPin;
    balance = 0;
    accountNumber++;
}
void bank::deposit(int inputPin, int amount, int inputAccountNumber){
    if(inputAccountNumber == accountNumber && pin == inputPin){
        balance += amount;
        cout << "\nThe amount deposited was: " << amount << ". The new balance is now: " << balance;
    }
    else{
        cout <<"\nThe account number or PIN was inccorect.";
    }
}
void bank::withdraw(int inputPin, int amount, int inputAccountNumber){
    if(inputAccountNumber == accountNumber && pin == inputPin){
       if(balance - amount > 0){
        balance -= amount;
         cout << "\nThe amount withdrawn: " << amount << ". The new balance is now: " << balance;
       }
       else{
        cout <<"\nThe withdrawn amount is greater then the current balance. Please either deposit more into the account or withdraw a lower amount.";
       }
    }
    else{
        cout <<"\nThe account number or PIN was inccorect.";
    }
}
void bank::display_info(){
    cout << "\nAccount number: " << accountNumber;
    cout << "\nAccount name: " << accountName;
    cout << "\nAccount balance: " << balance;
}
void bank::deleteAccount(){
    accountName = "";
    accountNumber = 0;
    balance = 0;
    pin = 0;
    cout << "\nAccount has been deleted.";
}
int bank::getAccountNumber(){
    return accountNumber;
}
int bank::getPin(){
    return pin;
}
int findAccount(vector<bank>& bankAccounts, int findAccountNumber);

int findAccount(vector <bank>& bankAccounts, int findAccountNumber){
    for(int i = 0; i < bankAccounts.size();i++){
        if(bankAccounts[i].getAccountNumber() == findAccountNumber){
            cout << "\nThe bank account has been found.";
            return i;
        }
    }
    cout <<"\nThe bank account does not exist.";
    return -1;
}
int main(){
     srand(time(NULL));
    vector <bank> bankAccounts;
    int choice = 0;
    int tempAccNum;
    int tempPin;
    string tempName;
    int tempAmount;
    int index = 0;
    while(choice != 7){
        cout << "\nBank Management System in C++";
        cout << "\nCreate a Bank Account: Enter 1";
        cout << "\nDeposit into bank account: Enter 2";
        cout << "\nWithdraw from a bank account: Enter 3";
        cout << "\nDisplay current bank account information: Enter 4";
        cout << "\nDelete current bank account: Enter 5";
        cout << "\nFind a bank account: Enter 6";
        cout <<"\nExit the bank account system: Enter 7";
        cin >> choice;
       switch (choice){
        case 1:{

        
            cout << "\nPlease enter the name for the bank account";
            cin >> tempName;
            cout << "\nPlease enter the pin number for the bank account";
            cin >> tempPin;
            bankAccounts.push_back(bank(tempName,tempPin)); 
            int currAccountNum = bankAccounts[index].getAccountNumber();
            cout << "\nThe account number is " << currAccountNum;
            cout << "\nAccount has been created.";
            break;
        }
        case 2:{
            cout << "\nPlease enter the account number";
            cin >> tempAccNum;
            cout << "\nPlease enter the pin number associated with the account";
            cin >> tempPin;
            cout <<"\nPlease enter how much you would like to deposit: ";
            cin >> tempAmount;
            index = findAccount(bankAccounts,tempAccNum);
            if(index != -1){
                bankAccounts[index].deposit(tempPin,tempAmount,tempAccNum);
            }
            break;
        }
        case 3:{
            cout << "\nPlease enter the account number";
            cin >> tempAccNum;
            cout << "\nPlease enter the pin number associated with the account";
            cin >> tempPin;
            cout <<"\nPlease enter how much you would like to withdraw: ";
            cin >> tempAmount;
            index = findAccount(bankAccounts,tempAccNum);
            if(index != - 1){
                bankAccounts[index].withdraw(tempPin,tempAmount,tempAccNum);
            }
            break;
        }
        case 4:{
            cout << "\nPlease enter the account number";
            cin >> tempAccNum;
            cout << "\nPlease enter the pin number associated with the account";
            cin >> tempPin;
            index = findAccount(bankAccounts,tempAccNum);
            if(index != - 1){
                if(bankAccounts[index].getPin() == tempPin && bankAccounts[index].getAccountNumber() == tempAccNum){
                    bankAccounts[index].display_info();
                } 
                else{
                    cout << "\nIncorrect PIN or bank account number.";
                }
            }
            break;
        }
        case 5:{
            cout << "\nPlease enter the account number";
            cin >> tempAccNum;
            cout << "\nPlease enter the pin number associated with the account";
            cin >> tempPin;
            index = findAccount(bankAccounts,tempAccNum);
            if(index != - 1){
                if(bankAccounts[index].getPin() == tempPin && bankAccounts[index].getAccountNumber() == tempAccNum){
                    bankAccounts.erase(bankAccounts.begin() + index);
                } 
            }
            break;
        }
        case 6:{
             cout << "\nPlease enter the account number";
             cin >> tempAccNum;
             index = findAccount(bankAccounts,tempAccNum);
             break;
        }
        case 7:{
            cout <<"\nThank you for using my bank management system.";
            break;
        }
        default:
            cout <<"\nPlease enter a valid choice.";
       }
    }
    return 0;
}