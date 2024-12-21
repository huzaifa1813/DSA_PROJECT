// Project 
// Bank Management System
#include <iostream>
#include<string>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

using namespace std;
class Transactions{
    public:
    string type;
    int amount;

    Transactions() : type(""), amount(0) {}

    Transactions(string type, int amount)
    {
        this->type = type;
        this->amount = amount;
    }
};
class Node
{
public:
    long acc_num;
    string name;
    string address;
    long long ph_num;
    long amount;
    int pin;
    queue<Transactions> transactionHistory;

    Node() : acc_num(0), name(""), address(""), ph_num(0), amount(0), pin(0) {}

    Node(long acc_num, string name, string address, long long ph_num, long amount, int pin)
    {
        this->acc_num = acc_num;
        this->name = name;
        this->address = address;
        this->ph_num = ph_num;
        this->amount = amount;
        this->pin = pin;

    };
        long getBalance() const
    {
        return amount;
    }
        
    void performTransaction(unordered_map<long, Node *> &accountHash, set<long> &bst)
{
    int maxAttempts = 3;
    int enteredPin;

    for (int attempt = 1; attempt <= maxAttempts; attempt++)
    {
        cout << "Enter your PIN (Attempt " << attempt << "/" << maxAttempts << "): ";
        cin >> enteredPin;

        // Check if entered PIN is correct
        if (enteredPin == pin)
        {
            cout << "PIN verification successful. Proceeding with the transaction." << endl;
            return;
        }
        else
        {
            cout << "Incorrect PIN. ";

            if (attempt < maxAttempts)
            {
                cout << "Please try again." << endl;
            }
            else
            {
                cout << "Maximum attempts reached. Exiting program." << endl;
                return;
            }
        }
    }

    int opt2;
    cout << "1. Cash Deposit " << endl;
    cout << "2. Cash Withdrawal " << endl;
    cout << "3. Fund Transfer " << endl;
    cout << "4. Exit" << endl;
    cout << "Enter option : ";
    cin >> opt2;

    Transactions temp;

    switch (opt2)
    {
    case 1:
        // Cash Deposit
        cout << "Enter the amount you want to deposit: ";
        int deposit;
        cin >> deposit;
        amount += deposit;
        cout << "Amount $" << deposit << " deposited successfully!\nYour current balance is: $" << amount << endl;
        temp = Transactions("DEPOSIT", deposit);
        transactionHistory.push(temp);
        break;

    case 2:
        // Cash Withdrawal
        cout << "Enter the amount you want to withdraw: ";
        int withdraw;
        cin >> withdraw;
        if (amount >= withdraw)
        {
            amount -= withdraw;
            cout << "Amount $" << withdraw << " withdrawn successfully!\nYour current balance is: $" << amount << endl;
            temp = Transactions("WITHDRAW", withdraw);
            transactionHistory.push(temp);
        }
        else
        {
            cout << "Insufficient Balance for the withdrawal!" << endl;
            return;
        }
        break;

    case 3:
    {
        // Fund Transfer
        cout << "Enter the account number of the receiver: ";
        long receiver_acc_num;
        cin >> receiver_acc_num;

        // Check if the receiver account exists
        if (bst.find(receiver_acc_num) == bst.end())
        {
            cout << "Receiver account not found!" << endl;
            return;
        }

        // Check if the receiver account is the same as the sender account
        if (receiver_acc_num == acc_num)
        {
            cout << "Cannot transfer funds to the same account!" << endl;
            return;
        }

        // Check if the sender has sufficient balance for the transfer
        cout << "Enter the amount you want to transfer: ";
        int transfer_amount;
        cin >> transfer_amount;

        if (transfer_amount > 0 && amount >= transfer_amount) // Ensure transfer_amount is positive
        {
            amount -= transfer_amount;
            cout << "Amount $" << transfer_amount << " transferred successfully!\nYour current balance is: $" << amount << endl;
            temp = Transactions("TRANSFER", transfer_amount);
            transactionHistory.push(temp);

            // Update the receiver's account balance
            Node *receiverNode = accountHash[receiver_acc_num];
            receiverNode->amount += transfer_amount;

            cout << "Funds received from account number " << acc_num << ". \nReceiver's new balance is: $" << receiverNode->amount << endl;
        }
        else
        {
            cout << "Invalid amount or insufficient balance for the transfer!" << endl;
            return;
        }
        break;
    }

    default:
        cout << "Invalid option" << endl;
        break;
    }
}
};

    


    int main(){



        return 0;
    }