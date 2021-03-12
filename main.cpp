/*
    Name: Peter Yang
    Date: March 8, 2021
    Description: Create a passphrase generator using the Diceware™ word lists.
*/

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include<cstdlib>
#include<ctime>
#include <fstream>

using namespace std;

void throwError(HANDLE hConsole, int colour) {
    // Description: Outputs error message to user
    SetConsoleTextAttribute(hConsole, 12); // Use red font
    cout<<"\nERROR: Invalid entry. Please try again.\n"<<endl;
    SetConsoleTextAttribute(hConsole, colour); // Use different text colour for user input
}

void askAgain(HANDLE hConsole, string &answer, vector<string> options, int colour) {
    // Description: Continually prompts user until input is valid

    // Empty vector triggers languages input validation
    while (options.empty()) {
        // Check if each character is 0, 1, or 2
        bool isCorrectlyNumbered = true;
        for (int i = 0; i < answer.length(); i++) {
            // If character is not 0, 1, or 2, set isCorrectlyNumbered to false
            if (answer[i] != '0' && answer[i] != '1' && answer[i] != '2')
                isCorrectlyNumbered = false;
        }

        // If input is invalid, throw error and make user retype
        if (!isCorrectlyNumbered || answer.length() < 1 || answer.length() > 3) {
            throwError(hConsole, colour);
            getline(cin, answer);
        } else {
            // Otherwise, end function call
            return;
        }
    }

    // While user input is not in vector of possible answers
    while(find(options.begin(), options.end(), answer) == options.end()) {
        // Display error message
        throwError(hConsole, colour);

        // Get new input from user
        getline(cin, answer);
    }
}

void fileToMap(map<string,string> &wordList, string file) {
    // Description: Passes contents from file to map
    string line, key, value;

    // Read from text file
    ifstream textFile(file);

    // Pass to map
    while ( textFile >> key >> value ) {
        wordList[key] = value;
    }

    // Close file
    textFile.close();
}

int main() {
    // Play music asynchronously (Windows-only)
    PlaySound("soundtrack.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);

    // Seed pseudorandom number generator
    srand(time(0));

    // Handle in order to colour text (Windows-only)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Initialize user's text colour preference to light grey
    int textColour = 7;

    // Declare userName variable
    string userName;

    // Declare userAnswer variable
    string userAnswer;

    // ***** Home Screen *****

    // Introduce user to Passphoria
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"Welcome to Passphoria! We believe passphrases bring euphoria."<<endl;
    SetConsoleTextAttribute(hConsole, 12); // Use red font
    cout<<"Copyright 2021. All Rights Reserved.\n"<<endl;

    // Explain how program works from a high-level
    SetConsoleTextAttribute(hConsole, 10); // Use green font
    cout<<"HOW IT WORKS: The Basic Steps"<<endl;
    cout<<"1. Enter 1 for Get Started, 0 for Exit"<<endl;
    cout<<"2. Enter how many words you would like in your passphrase"<<endl;
    cout<<"3. Confirm your passphrase"<<endl;
    cout<<"4. There will be opportunities to customize your passphrase, so make sure to pay attention to the instructions!\n"<<endl;

    // Pro tip for user
    cout<<"PRO TIP: Visit https://github.com/peteryangfounder/Passphoria for external documentation.\n"<<endl;

    // Ask user if they are ready to begin
    SetConsoleTextAttribute(hConsole, 7); // Use default font
    cout<<"Ready to begin?\n"<<endl;
    cout<<"1 - Get Started"<<endl;
    cout<<"0 - Exit\n"<<endl;

    // Update userAnswer variable
    getline(cin, userAnswer);

    // While answer is invalid, ask again
    vector<string> options{ "0", "1" }; // Vector of possible answers
    askAgain(hConsole, userAnswer, options, textColour);

    // If answer is 0, exit program
    if (userAnswer == "0")
        return 0;

    // ***** Customize User Experience *****

    // Display helper text
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\nYou\'re one step closer to generating a secure passphrase! But before we dive in, we want to give you a chance to customize your experience. Please configure the following settings.\n"<<endl;

    // Allow user to select their text colour
    cout<<"1. What text colour do you want?\n"<<endl;
    cout<<"2 - Cyan"<<endl;
    cout<<"1 - Magenta"<<endl;
    cout<<"0 - Default\n"<<endl;

    SetConsoleTextAttribute(hConsole, 7); // Use default font
    getline(cin, userAnswer);

    // While answer is invalid, ask again
    options = { "0", "1", "2" }; // Update vector of possible answers
    askAgain(hConsole, userAnswer, options, textColour);

    // Update user's text colour preference
    switch(stoi(userAnswer)) {
        case 0:
            // 7 represents light grey
            textColour = 7;
            break;
        case 1:
            // 5 represents magenta
            textColour = 5;
            break;
        case 2:
            // 3 represents cyan
            textColour = 3;
            break;
        default:
            textColour = 7;
    }

    // Configure user's music setting
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\n2. Do you want to continue listening to music?\n"<<endl;
    cout<<"1 - Yes"<<endl;
    cout<<"0 - No\n"<<endl;

    SetConsoleTextAttribute(hConsole, textColour); // Use user's custom text colour
    getline(cin, userAnswer);

    // While answer is invalid, ask again
    options = { "0", "1" }; // Update vector of possible answers
    askAgain(hConsole, userAnswer, options, textColour);

    // If user says no, stop playing music
    if (userAnswer == "0")
        PlaySound(NULL, 0, 0);

    // Get user's name
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\n3. What is your name? In other words, what should we call you?\n"<<endl;

    SetConsoleTextAttribute(hConsole, textColour); // Use user's custom text colour
    getline(cin, userName);

    // ***** Customize Passphrase *****

    // Construct passphrase map
    map<string, string> passphrase;

    // Display helper text
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\nAlright "<<userName<<", let\'s generate your passphrase. To make it as unique as possible, please answer the following questions.\n"<<endl;

    // Get user's passphrase length
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"1. How many words should your passphrase be? Please enter a number between 6-10.\n"<<endl;

    SetConsoleTextAttribute(hConsole, textColour); // Use user's custom text colour
    getline(cin, userAnswer);

    // While answer is invalid, ask again
    options = { "6", "7", "8", "9", "10" }; // Update vector of possible answers
    askAgain(hConsole, userAnswer, options, textColour);

    // Save passphrase length to map
    passphrase["length"] = userAnswer;

    // Get passphrase spacing
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\n2. How many spaces should separate each word? Please enter a number between 1-5.\n"<<endl;

    SetConsoleTextAttribute(hConsole, textColour); // Use user's custom text colour
    getline(cin, userAnswer);

    // While answer is invalid, ask again
    options = { "1", "2", "3", "4", "5" }; // Update vector of possible answers
    askAgain(hConsole, userAnswer, options, textColour);

    // Save passphrase spacing to map
    passphrase["spacing"] = string(stoi(userAnswer), ' ');

    // Get passphrase capitalization
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\n3. How would you like your passphrase capitalized?\n"<<endl;
    cout<<"1 - Lowercase"<<endl;
    cout<<"0 - Uppercase\n"<<endl;

    SetConsoleTextAttribute(hConsole, textColour); // Use user's custom text colour
    getline(cin, userAnswer);

    // While answer is invalid, ask again
    options = { "0", "1" }; // Update vector of possible answers
    askAgain(hConsole, userAnswer, options, textColour);

    // Save passphrase spacing to map
    passphrase["capitalization"] = userAnswer;

    // Get passphrase languages
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\n4. What language(s) should your passphrase be in? For more than one language, simply type the numbers consecutively (e.g., 21 for English-Latin).\n"<<endl;
    cout<<"2 - English"<<endl;
    cout<<"1 - Latin"<<endl;
    cout<<"0 - German\n"<<endl;

    SetConsoleTextAttribute(hConsole, textColour); // Use user's custom text colour
    getline(cin, userAnswer);

    // While answer is invalid, ask again
    options.clear();
    askAgain(hConsole, userAnswer, options, textColour);

    // Save passphrase languages to map
    passphrase["languages"] = userAnswer;

    // Create a map for each language and pass in corresponding word list data
    map<string,string> englishWordList;
    map<string,string> latinWordList;
    map<string,string> germanWordList;

    for (int i = 0; i < passphrase["languages"].length(); i++) {
        if (passphrase["languages"].substr(i, 1) == "2" && englishWordList.empty())
            fileToMap(englishWordList, "2.txt");
        else if (passphrase["languages"].substr(i, 1) == "1" && latinWordList.empty())
            fileToMap(latinWordList, "1.txt");
        else if (passphrase["languages"].substr(i, 1) == "0" && germanWordList.empty())
            fileToMap(germanWordList, "0.txt");
    }

    // Get special character preference
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\n5. Append a special character to the end of each word? (!, @, #, $, %)\n"<<endl;
    cout<<"1 - Yes"<<endl;
    cout<<"0 - No\n"<<endl;

    SetConsoleTextAttribute(hConsole, textColour); // Use user's custom text colour
    getline(cin, userAnswer);

    // While answer is invalid, ask again
    options = { "0", "1" }; // Update vector of possible answers
    askAgain(hConsole, userAnswer, options, textColour);

    // If user wants special characters, save string of possibilities to map
    if (userAnswer == "1")
        passphrase["specialChars"] = "!@#$%";
    else
        // Save answer to map
        passphrase["specialChars"] = userAnswer;

    // ***** Generate Passphrase *****

    // Declare userPassphrase variable
    string userPassphrase;

    // Declare randomCode variable
    string randomCode;

    // For # of words in passphrase
    for (int i = 0; i < stoi(passphrase["length"]); i++) {
        // Generate random code
        for (int i = 0; i < 5; i++) {
            randomCode = randomCode + to_string(rand() % 6 + 1);
        }

        // Determine which word list to use
        int indexOfWordList = rand() % passphrase["languages"].length();
        string wordList = passphrase["languages"].substr(indexOfWordList, 1);

        // Append word to passphrase
        if (wordList == "2")
            userPassphrase = userPassphrase + englishWordList[randomCode];
        else if (wordList == "1")
            userPassphrase = userPassphrase + latinWordList[randomCode];
        else if (wordList == "0")
            userPassphrase = userPassphrase + germanWordList[randomCode];

        // Append a special character if user requested it
        if (passphrase["specialChars"] != "0") {
            // Generate random index
            int randomIndex = rand() % passphrase["specialChars"].length();

            // Append special character
            userPassphrase = userPassphrase + passphrase["specialChars"][randomIndex];
        }

        // Add spacing after word (except for final iteration)
        if (i != stoi(passphrase["length"]) - 1) {
            userPassphrase = userPassphrase + passphrase["spacing"];
        }

        // Reset randomCode
        randomCode.clear();
    }

    // Capitalize passphrase if user requested it
    if (passphrase["capitalization"] == "0") {
        for (int i = 0; i < userPassphrase.length(); i++) {
            userPassphrase[i] = toupper(userPassphrase[i]);
        }
    }

    // ***** Reveal Passphrase *****

    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\n"<<userName<<", your passphrase is: ";
    SetConsoleTextAttribute(hConsole, 15); // Use white font
    cout<<userPassphrase<<endl;

    // Determine passphrase strength and inform user
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\nPassphrase Strength: ";

    // 40+ characters is excellent
    if (userPassphrase.length() >= 40) {
        SetConsoleTextAttribute(hConsole, 10); // Use green font
        cout<<"EXCELLENT :)\n"<<endl;
    // 20-39 characters is strong
    } else if (userPassphrase.length() >= 20 && userPassphrase.length() <= 39) {
        cout<<"STRONG\n"<<endl;
    // Otherwise, passphrase is weak
    } else {
        SetConsoleTextAttribute(hConsole, 12); // Use red font
        cout<<"WEAK :(\n"<<endl;
    }

    // Ask user to confirm passphrase
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"To confirm your passphrase, please take a moment to retype it below.\n"<<endl;

    SetConsoleTextAttribute(hConsole, textColour); // Use user's custom text colour
    getline(cin, userAnswer);

    // While answer is invalid, ask again
    options = { userPassphrase }; // Update vector of possible answers
    askAgain(hConsole, userAnswer, options, textColour);

    // Output success message and bid user farewell
    SetConsoleTextAttribute(hConsole, 14); // Use yellow font
    cout<<"\nLooks good! Thank you for using Passphoria, and always remember to use a password/passphrase manager!"<<endl;

    return 0;
}
