#include <iostream>
#include <string>
#include <algorithm> // for transform, sort
using namespace std;

// Function to convert string to uppercase
string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Function to convert string to lowercase
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to search superhero by name
int searchByName(string names[], int size, string searchName) {
    for (int i = 0; i < size; i++) {
        if (toLowerCase(names[i]) == toLowerCase(searchName)) {
            return i;
        }
    }
    return -1;
}

// Function to find superheroes by superpower
void searchBySuperpower(string powers[], string names[], int size, string searchPower) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (toLowerCase(powers[i]).find(toLowerCase(searchPower)) != string::npos) {
            cout << "- " << names[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No superheroes found with that superpower.\n";
    }
}

// Function to sort superheroes alphabetically
void sortSuperheroes(string names[], string powers[], string weaknesses[], int years[], string universes[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (names[j] > names[j+1]) {
                swap(names[j], names[j+1]);
                swap(powers[j], powers[j+1]);
                swap(weaknesses[j], weaknesses[j+1]);
                swap(years[j], years[j+1]);
                swap(universes[j], universes[j+1]);
            }
        }
    }
}

// Function to display superheroes
void displaySuperheroes(string names[], string powers[], string weaknesses[], int years[], string universes[], int size, bool uppercase) {
    for (int i = 0; i < size; i++) {
        string name = uppercase ? toUpperCase(names[i]) : toLowerCase(names[i]);
        string power = uppercase ? toUpperCase(powers[i]) : toLowerCase(powers[i]);
        string weakness = uppercase ? toUpperCase(weaknesses[i]) : toLowerCase(weaknesses[i]);
        string universe = uppercase ? toUpperCase(universes[i]) : toLowerCase(universes[i]);

        cout << "Name: " << name << endl;
        cout << "Superpower: " << power << endl;
        cout << "Weakness: " << weakness << endl;
        cout << "Year Introduced: " << years[i] << endl;
        cout << "Comic Universe: " << universe << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
    const int SIZE = 10;

    // Parallel arrays
    string names[SIZE] = {
        "Squirrel Girl", "Moon Knight", "Plastic Man", "Booster Gold", "The Phantom",
        "Darkhawk", "Big Barda", "Blue Beetle", "Mister Miracle", "Nova"
    };

    string powers[SIZE] = {
        "Control over squirrels", "Enhanced strength at night", "Body elasticity", "Time travel tech",
        "Peak human condition", "Energy blasts", "Super strength", "Technologically advanced suit",
        "Escape artistry", "Nova Force energy"
    };

    string weaknesses[SIZE] = {
        "Overconfidence", "Mental instability", "Heat", "Arrogance", "Mortal injuries",
        "Energy dependence", "Loyalty to friends", "Inexperience", "Claustrophobia", "Power overload"
    };

    int years[SIZE] = {
        1992, 1975, 1941, 1986, 1936,
        1991, 1971, 1966, 1971, 1976
    };

    string universes[SIZE] = {
        "Marvel", "Marvel", "DC", "DC", "Other",
        "Marvel", "DC", "DC", "DC", "Marvel"
    };

    int choice;
    do {
        cout << "\n--- Superhero Database Menu ---\n";
        cout << "1. Search for a superhero by name\n";
        cout << "2. Find superheroes by superpower\n";
        cout << "3. Sort superheroes alphabetically\n";
        cout << "4. Display all superheroes in UPPERCASE\n";
        cout << "5. Display all superheroes in lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline character from input buffer

        if (choice == 1) {
            string searchName;
            cout << "Enter superhero name to search: ";
            getline(cin, searchName);
            int index = searchByName(names, SIZE, searchName);
            if (index != -1) {
                cout << "\nFound Superhero:\n";
                cout << "Name: " << names[index] << endl;
                cout << "Superpower: " << powers[index] << endl;
                cout << "Weakness: " << weaknesses[index] << endl;
                cout << "Year Introduced: " << years[index] << endl;
                cout << "Comic Universe: " << universes[index] << endl;
            } else {
                cout << "Superhero not found.\n";
            }
        }
        else if (choice == 2) {
            string searchPower;
            cout << "Enter superpower keyword to search: ";
            getline(cin, searchPower);
            cout << "\nSuperheroes with the power '" << searchPower << "':\n";
            searchBySuperpower(powers, names, SIZE, searchPower);
        }
        else if (choice == 3) {
            sortSuperheroes(names, powers, weaknesses, years, universes, SIZE);
            cout << "Superheroes sorted alphabetically by name.\n";
        }
        else if (choice == 4) {
            displaySuperheroes(names, powers, weaknesses, years, universes, SIZE, true);
        }
        else if (choice == 5) {
            displaySuperheroes(names, powers, weaknesses, years, universes, SIZE, false);
        }
        else if (choice == 6) {
            cout << "Exiting superhero database. Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}