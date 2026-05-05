/*Assume that there are 100 slots available for every movie.
Given Q queries of the following types:
• BOOK X Y
o Allow a customer with a unique ID X to book a ticket for a movie with the movie ID Y.
o If the customer has already booked a ticket for the same movie or the movie is sold out,
return false.
o Otherwise, mark the ticket as booked and return true.
• CANCEL X Y
o Allow a customer with a unique ID X to cancel a booked ticket for a movie with the movie ID
Y.
o If the customer has not booked a ticket for the movie, return false.
o Otherwise, mark the ticket as canceled and return true.
• IS_BOOKED X Y
o Check if a customer with a unique ID X has booked a ticket for the movie with the movie ID Y.
o Return true if booked; otherwise, return false.
• AVAILABLE_TICKETS Y
o Return the number of available tickets for the movie with the movie ID Y.
Class description
• MovieTicket: Represents information about the users and movies
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
#include <unordered_set>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> bookings;
    unordered_map<int, int> seats;

public:
    bool BOOK(int user, int movie) {
        // initialize seats if movie appears first time
        if (seats.find(movie) == seats.end()) {
            seats[movie] = 100;
        }

        if (bookings[movie].count(user)) return false;
        if (seats[movie] == 0) return false;

        bookings[movie].insert(user);
        seats[movie]--;

        return true;
    }

    bool CANCEL(int user, int movie) {
        if (!bookings[movie].count(user)) return false;

        bookings[movie].erase(user);
        seats[movie]++;

        return true;
    }

    bool IS_BOOKED(int user, int movie) {
        return bookings[movie].count(user);
    }

    int AVAILABLE_TICKETS(int movie) {
        if (seats.find(movie) == seats.end()) return 100;
        return seats[movie];
    }
};

int main() {
    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    MovieTicket mt;

    while (Q--) {
        string type;
        cout << "\nEnter query type (BOOK / CANCEL / IS_BOOKED / AVAILABLE_TICKETS): ";
        cin >> type;

        if (type == "BOOK") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter movie ID: ";
            cin >> y;

            bool result = mt.BOOK(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "CANCEL") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter movie ID: ";
            cin >> y;

            bool result = mt.CANCEL(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "IS_BOOKED") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter movie ID: ";
            cin >> y;

            bool result = mt.IS_BOOKED(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "AVAILABLE_TICKETS") {
            int y;
            cout << "Enter movie ID: ";
            cin >> y;

            int result = mt.AVAILABLE_TICKETS(y);
            cout << "Available tickets: " << result << endl;
        }
        else {
            cout << "Invalid query type!" << endl;
        }
    }

    return 0;
}