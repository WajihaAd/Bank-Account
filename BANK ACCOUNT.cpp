#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
class BankAccount {
private:
  int Balance;
  static int transaction;
  double interestRate;

public:
  BankAccount() : Balance(500), interestRate(0.05) {}
  void display();
  int deposit(int amount);
  int withdrawal(int amount);
  static void transactions();
  void displayInterestEarned(int months) const;
  ~BankAccount() {}
};
int BankAccount::transaction = 0;
void BankAccount::transactions() {
  cout << "Your Transaction: " << transaction << endl;
  cout << "PRESS ANY KEY TO CONTINUE" << endl;
  cin.ignore();
  cin.get();
}
void BankAccount::displayInterestEarned(int months) const {
  double interestEarned = Balance * interestRate * months;
  cout << "Interest Earned for " << months << " months: $" << interestEarned
       << endl;
  cout << "PRESS ANY KEY TO CONTINUE" << endl;
  cin.ignore();
  cin.get();
}
void BankAccount::display() {
  cout << "Your Account Balance is "
       << ":" << Balance << endl;
  cout << "PRESS ANY KEY TO CONTINUE" << endl;
  cin.ignore();
  cin.get();
}
int BankAccount::deposit(int a) {
  Balance += a;
  ++transaction;
  cout << "Deposit of $" << a << " successful." << endl;
  cout << "PRESS ANY KEY TO CONTINUE" << endl;
  cin.ignore();
  cin.get();
  return Balance;
}
int BankAccount::withdrawal(int b) {
  if (Balance >= b) {
    Balance -= b;
    ++transaction;
    cout << "Withdrawal of $" << b << " successful." << endl;
  } else {
    cout << "Insufficient funds!" << endl;
  }
  cout << "PRESS ANY KEY TO CONTINUE" << endl;
  cin.ignore();
  cin.get();
  return Balance;
}

int main() {
  BankAccount account;
  int choice, amount, months;

  do {
    system("cls");
    cout << "\t\t\t\t\t\tBank Account" << endl;
    cout << "\nMenu:\n";
    cout << "1. Display account balance\n";
    cout << "2. Display number of transactions\n";
    cout << "3. Display interest earned for this period\n";
    cout << "4. Make a deposit\n";
    cout << "5. Make a withdrawal\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      account.display();
      break;
    case 2:
      account.transactions();
      break;
    case 3:
      cout << "Enter the number of months: ";
      cin >> months;
      account.displayInterestEarned(months);
      break;
    case 4:
      cout << "Enter deposit amount: ";
      cin >> amount;
      account.deposit(amount);
      break;
    case 5:
      cout << "Enter withdrawal amount: ";
      cin >> amount;
      account.withdrawal(amount);
      break;
    case 6:
      cout << "Exiting program...\n";
      break;
    default:
      cout << "Invalid choice! Please try again.\n";
      cin.ignore();
      cin.get();
    }
  } while (choice != 6);
  return 0;
}