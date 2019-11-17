#include <iostream>
#include <string>

class BankAccount
{
private:
    // TODO: declare member variables
    std::string name;
    int account;
    int fund;

public:
    BankAccount(std::string s, int a, int f);
    // TODO: declare setters/ mutator
    void Name(std::string s);
    void Account(int a);
    void Fund(int f);

    // TODO: declare getters/ accessor
    std::string Name() const;
    int Account() const;
    int Fund() const;
};

/*
Either use initializer list or setter/ mutator for constructor
*/

// BankAccount::BankAccount(std::string s, int a, int f) : name(s), account(a), fund(f) {}

BankAccount::BankAccount(std::string s, int a, int f)
{
    BankAccount::Name(s);
    BankAccount::Account(a);
    BankAccount::Fund(f);
}

// TODO: implement setters
void BankAccount::Name(std::string s) { BankAccount::name = s; }
void BankAccount::Account(int a) { BankAccount::account = a; }
void BankAccount::Fund(int f) { BankAccount::fund = f; }
// TODO: implement getters
std::string BankAccount::Name() const { return BankAccount::name; }
int BankAccount::Account() const { return BankAccount::account; }
int BankAccount::Fund() const { return BankAccount::fund; }

int main()
{
    // TODO: instantiate and output a bank account
    BankAccount customer("Gaurav", 10, 10);
    std::cout << "Name:" << customer.Name() << "\n";
    std::cout << "Account:" << customer.Account() << "\n";
    std::cout << "Fund:" << customer.Fund() << "\n";
}