#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {

    // Take student name as input
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // List of excuse templates
    string excuses[] = {
        "{name} forgot the homework at home.",
        "{name}'s dog ate the assignment.",
        "{name}'s laptop suddenly stopped working.",
        "{name} had a power cut while doing homework.",
        "{name} accidentally deleted the file.",
        "{name} was helping a friend with studies.",
        "{name} got stuck in traffic for hours.",
        "{name} was not feeling well yesterday.",
        "{name}'s internet stopped working.",
        "{name} thought the submission was tomorrow."
    };

    // Total number of excuses
    int totalExcuses = 10;

    // Generate random number
    srand(time(0));
    int randomIndex = rand() % totalExcuses;

    // Select random excuse
    string excuse = excuses[randomIndex];

    // Replace {name} with actual name
    int pos = excuse.find("{name}");
    excuse.replace(pos, 6, name);

    // Display final excuse
    cout << "\nGenerated Excuse:\n";
    cout << excuse << endl;

    return 0;
}