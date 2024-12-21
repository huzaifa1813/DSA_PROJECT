// Project 
// Bank Management System
#include <iostream>

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
    long amount;
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