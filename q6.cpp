/*Given Q queries of the following types:
• CREATE X Y
o Create a user account with a user ID X and an initial balance of Y dollars.
o If the user is already present with the user ID X then add Y dollars to their account.
o You need to return true only when you create a new account (which means a user with a user
ID X is not present); otherwise, return false.
• DEBIT X Y
o Debit Y dollars from the user's bank account with user ID X.
o If the user with user ID X is not present or has less than Y dollars, then do nothing and return
false.
o Otherwise, debit Y dollars and return true.
• CREDIT X Y
o Credit Y dollars to the user's bank account with user ID X.
o If the user with user ID X is not present, then do nothing and return false.
o Otherwise, credit Y dollars and return true.
• BALANCE X
o Return the user's bank balance with the user ID X.
o If the user with user ID X is not present, then return -1.
Class description
• Bank: Represents information about the users
• Public functions: Refers to the types of queries (described above) that must be implemented
Input format for custom testing
Note: Use this input format if you are testing against custom input or writing code in a language
where we don’t provide boilerplate code.
• The first line contains a single integer Q, denoting the number of elements in the array.
• Each of the next Q lines contains the query (case-sensitive for strings).
Output format
Return the result for each function method based on the query*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Bank {
private:
    unordered_map<int, int> accounts;

public:
    bool CREATE(int user, int amount) {
        if (accounts.find(user) == accounts.end()) {
            accounts[user] = amount;
            return true;
        }
        accounts[user] += amount;
        return false;
    }

    bool DEBIT(int user, int amount) {
        if (accounts.find(user) == accounts.end() || accounts[user] < amount) {
            return false;
        }
        accounts[user] -= amount;
        return true;
    }

    bool CREDIT(int user, int amount) {
        if (accounts.find(user) == accounts.end()) {
            return false;
        }
        accounts[user] += amount;
        return true;
    }

    int BALANCE(int user) {
        if (accounts.find(user) == accounts.end()) {
            return -1;
        }
        return accounts[user];
    }
};

int main() {
    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    Bank bank;

    while (Q--) {
        string type;
        cout << "\nEnter query type (CREATE / DEBIT / CREDIT / BALANCE): ";
        cin >> type;

        if (type == "CREATE") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter initial amount: ";
            cin >> y;

            bool result = bank.CREATE(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "DEBIT") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter amount to debit: ";
            cin >> y;

            bool result = bank.DEBIT(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "CREDIT") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter amount to credit: ";
            cin >> y;

            bool result = bank.CREDIT(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "BALANCE") {
            int x;
            cout << "Enter user ID: ";
            cin >> x;

            int result = bank.BALANCE(x);
            cout << "Balance: " << result << endl;
        }
        else {
            cout << "Invalid query type!" << endl;
        }
    }

    return 0;
}