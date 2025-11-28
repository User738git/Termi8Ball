// Includes external libs.
#include <iostream>
#include <string>
#include <random>
#include <limits>
#include <locale>
#include <sstream>
#include <stdlib.h>
#include <unistd.h> // for usleep

// Udefines max since 1 lib got confused.
#undef max

// Prevents writing ::std in front of everything.
using namespace std;

// Lists/arrays and variables for the project.
string list[8] = { "No, according to fate.", "Yes, according to fate.", "It is certain.", "Without a doubt.", "Uncertainly...", " Undoubtedly!", "   Probably...", "   Perhaps..." };
string response = list[rand() % 8];
string notimp;
char yesno;


// Main integer
int main() {

    // Launguage stuff. Didn't know much about this (copy-paste).
    try {
        locale::global(locale("C")); // Uses the locale "C".
    } catch (const std::runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

	// A random seed. Uses a seed to make results random.
    srand(static_cast<unsigned int>(time(0)));

	// a do-while loop. makes the program "restartable".
    do {
        system("clear");

        // Prints text.
        cout << "\nMagic 8 Ball\n";
        cout << "-------------\n";

        // Only a measure to get unknown letters into "cout" to be included, but really, it can probably be done without.
        string inkl = "Enter a question to be predicted:\n\n";
        cout << inkl;

	    // I got some help from someone else with this. I don't really know what getline does, but I guess it includes the entire line (with spaces).
        getline(cin, notimp);

        // Prints the "-" according to how long the input is +13 because "you answered:" is included.
        for (size_t i = 0; i <= notimp.length()+13; i++) {
            cout << '-';
        }

        // cout includes "unknown" ASCII-symbols.
        cout << '\n';
        cout << "You answered: " << notimp << "\n\n";
        cout << "The 8 ball is shaking!\n";

        // Makes the program wait 5 deciseconds.
        usleep(500000); // usleep uses microseconds as an argument

        // Repeats "." three times at 5 decisecond intervals.
        for (int dot = 0; dot < 3; dot++) {
            cout << ".\n";
            usleep(500000);
        };

        // Selects a random object in the array "list" using the seed mentioned earlier.
        int index = rand() % (sizeof(list) / sizeof(list[0]));

        // To make the 8-ball vibe:
        string response = list[index];
	    string balltop = "   ,.----.,\n .´'      ｀.\n|    .--.    |\n";
        string ballbott = "|    '--'    |\n `._      _.´   \n   `'----'´   \n";

        cout << balltop;
        cout << response << "\n";
        cout << ballbott;

        // Asks the user for a new prediction.
        string inkl2 = "\nDo you want to ask a new question (y for yes, n for no)?\n\n";
        cout << inkl2;
        cin >> yesno;

        // Removes unnecessary input if it hasn't been removed automatically before.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // If the variable is "y" or "Y", this is printed...
        if (yesno == 'y' || yesno == 'Y') {
            cout << "\nRestarting...\n";
            cout << "-------------------\n\n";
            system("clear");
        }

        // If the variable is "n" or "N", this is printed and the program is stopped.
        if (yesno == 'n' || yesno == 'N') {
            cout << "\nExiting...\n";
            usleep(1000000); // usleep tar mikrosekunder som argument
            break;
        }

        // End of do-while-loop.
    } while (yesno == 'y' || yesno == 'Y');
    yesno = ' ';
    cin.clear();

    // Returns zero
    return 0;
}
