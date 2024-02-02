using namespace std;

#include <iostream>
#include <cstdlib>
#include <string> 

int main() {
    int choice; //the choice is an int because the display menu is going to be chosen with with a number
    string command; // the command is a string because it is going to execute a system command

    do {
        // Here is the display menu that will be displayed and allow users to pick which command they want to execute
        cout << "Menu:\n"
            << "1. List directory contents\n"
            << "2. Print working directory\n"
            << "3. Create a new directory\n"
            << "4. Display a message\n"
            << "5. Concatenate and display content of a file\n"
            << "6. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) { //here is where the main functions are listed, With the switch it allows for the user to to pick a number and match it with the proper case
        case 1:
            command = "dir";
            break;
        case 2:
            command = "cd";
            break;
        case 3:
        {
            cout << "Enter the name of the new directory: ";
            cin.ignore(); // gives a buffer when creating a new directory, I found that if you want to type the name of your directory it will fail because it immediately runs into the next line of code so I added a buffer
            getline(cin, command); // Read entire line
            command = "mkdir \"" + command + "\""; // Quote the directory name
        }
        break;
        case 4:
            cout << "Enter your message: ";
            cin.ignore(); //allows a buffer when e
            getline(cin, command);
            command = "echo " + command;
            break;
        case 5:
            cout << "Enter the file name: ";
            cin >> command;
            command = "type " + command;
            break;
        case 6:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            cin.clear(); //this clears the error. So if you type in an invalid input it will clear it 
            cin.ignore(); //this gives a buffer before printing the next line so it does not go into an infinite loop.
            continue; // restart the loop
        }

        // Execute the command
        if (choice != 2) { // Execute command unless it's "Print working directory"
            cout << "Executing command: " << command << endl;
            int result = system(command.c_str());

            if (result != 0) {
                cerr << "Command failed to execute.\n";
            }
        }
        else { // Handle "Print working directory"
            cout << "Current working directory:\n";
            system("cd"); // Print working directory
        }

    } while (choice != 6);

    return 0;
}