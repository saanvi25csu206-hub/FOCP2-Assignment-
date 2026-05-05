#include <iostream>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    
    // Take user's name as input
    string name;
    cout << "Enter your name: ";
    cin >> name;

    // Array of roast templates
    string roasts[] = {
        "{name}, you run faster from studies than WiFi signals!",
        "{name}, your brain has more loading time than a slow computer.",
        "{name}, even Google cannot find your talent.",
        "{name}, you are proof that sleep is more important than homework.",
        "{name}, your jokes need software updates."
    };

    // Total number of roasts
    int totalRoasts = 5;

    // Generate random number
    srand(time(0));
    int randomIndex = rand() % totalRoasts;

    // Select random roast
    string roast = roasts[randomIndex];

    // Replace {name} with actual name
    int pos = roast.find("{name}");
    roast.replace(pos, 6, name);

    // Display final roast
    cout << "\nFunny Roast:\n";
    cout << roast << endl;

    return 0;
}