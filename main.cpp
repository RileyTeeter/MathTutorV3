
/**************************************************************************************
Program: Math Tutor Version 3
Programmers: Riley Teeter & River Wallerstedt
Date: 10/22/24 *Last updated version
Github URL: https://github.com/RileyTeeter/MathTutorV3
Description: A simple math tutor for elementary students. Version 3 gets the user's name
and asks the user to answer a randomized math question. This version will repeat the question
after a wrong attempt and will generate a new question if the answer is correct. This version
will also level up or down depending on how many questions the user correctly answers
**************************************************************************************/

#include <iostream> // required for couts & cins
#include <cstdlib> // allows for randomizer
#include <ctime> // enables use of time function
#include <string> // allows for strings to be used
#include <limits> // required for numeric limits
#include <cctype>

using namespace std; // sets standard namespace

int main() {
    // Starting the main function

    //*********************************************************************

    // Declares and initializes variables
    string userName = "unknown"; // Declaring and initializing variables
    int leftNum = 0;
    int rightNum = 0;
    int mathType = 0;
    int correctAnswer = 0;
    int userAnswer = 0;
    int temp = 0;
    string userYN = "?";
    char mathSymbol = '?';
    const int MAX_ATTEMPTS = 3;
    const int LEVEL_RANGE_CHANGE = 10;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;
    int currentRange = LEVEL_RANGE_CHANGE;

    srand(time(0)); // Generates a unique seed so its random.

    //*********************************************************************

    // Set of cout statements to display the Silly Math ASCII art and welcome banner
    cout << "*******************************************" << endl;
    cout << " _____ _ _ _      ___  ___      _   _    " << endl;
    cout << "/  ___(_| | |     |  /// |     | | | |   " << endl;
    cout << "| `--. _| | |_   _| .  . | __ _| |_| |__ " << endl;
    cout << " `--. | | | | | | | |//| |/ _` | __| '_ | " << endl;
    cout << " ___/ | | | | |_| | |  | | (_| | |_| | | |" << endl;
    cout << "/____/|_|_|_|__, /|_|  |_/,__,_|,__|_| |_|" << endl;
    cout << "            __/ /                       " << endl;
    cout << "           |___/                       " << endl;
    cout << "*******************************************" << endl;
    cout << "*    Welcome to Silly Math Tutor V3 by    *" << endl;
    cout << "*         RivJams and RileyTeeter         *" << endl;
    cout << "*******************************************" << endl;
    cout << endl;

    // Asks prompt whether to display the jokes or not
    cout << "Do you wanna hear some math puns? (y/n): ";
    cin >> userYN;

    if (userYN == "y") {
        //response to 'y' as input
        cout << "Great! Here they are:" << endl;
    } else {
        cout << "That's too bad." << endl;
        cout << "You're gonna hear them anyway!" << endl;
    }
    cout << endl;

    // Couts to display jokes. After user input, jokes appear. Maybe add functionality later to reveal answers to jokes after pressing enter.
    cout << "*******************************************" << endl;
    cout << endl;
    cout << "Question: Do you think monsters are good at math?" << endl;
    cout << "Answer: No, unless you Count Dracula." << endl;
    cout << endl;
    cout << "Question: Which knight created the round table?" << endl;
    cout << "Answer: Sir Cumference." << endl;
    cout << endl;
    cout << "Question: What do you call a number who can't stay in place?" << endl;
    cout << "Answer: A roamin' numeral." << endl;
    cout << endl;
    cout << "*******************************************" << endl;
    cout << endl;

    // Beginning the interactive portion of the program
    cout << "Please enter your name to begin: ";
    getline(cin, userName); // Clears out leftover carriage return
    getline(cin, userName); // Get user input for name
    cout << endl;

    // Puts the user's name into the welcome message
    cout << "Welcome " << userName << ", to the Silly Math Tutor!" << endl;
    cout << endl;

    //*********************************************************************

    do { //Beginning of central loop that repeats number generation and math problems

        //Portion of code dedicated to random number generation
        leftNum = (rand() % currentRange) + 1; //randomizes first number
        rightNum = (rand() % currentRange) + 1; //randomizes second number

        //enum to replace the mathType integer
        enum mthType {MT_ADD, MT_SUB, MT_MUL, MT_DIV};
        mthType questionType;

        questionType = static_cast<mthType>(rand() % 4); //Randomizes question type

        switch (questionType) {
            // assigns math symbol
            case MT_ADD:
                mathSymbol = '+'; //assigns an addition problem
            correctAnswer = leftNum + rightNum; // adds the numbers and stores correct answer
            break;

            case MT_SUB:
                mathSymbol = '-'; //assigns a subtraction problem
            // This is used to make sure the left number is larger than the right, preventing negative numbers.
            if (leftNum < rightNum) {
                temp = leftNum;
                leftNum = rightNum;
                rightNum = temp;
            }
            correctAnswer = leftNum - rightNum;
            break;

            case MT_MUL:
                mathSymbol = '*'; //assigns a multiplication problem
            correctAnswer = leftNum * rightNum;
            break;

            case MT_DIV:
                mathSymbol = '/'; //assigns a division problem
            // Following code makes sure division problem doesn't generate a fraction
            correctAnswer = leftNum;
            leftNum *= rightNum;
            break;

            default: // This is here to catch any errors
                cout << "Invalid question type: " << mathType << endl;
            cout << "Contact RivJams or RileyTeeter about the error" << endl;
            cout << "Program ended with a -1 error" << endl;
            return -1;
        }

        //*********************************************************************

        for (int i = 1; i <= MAX_ATTEMPTS; i++) { //Loops until user gets answer correct or until 3 wrong attempts
            cout << endl;
            cout << "[Level #" << mathLevel << "] " << userName << ", what does "
            << leftNum << " " << mathSymbol << " " << rightNum << " = ";


            // Loop until the user enters numeric data "From the assignment document"
            while (!(cin >> userAnswer)) {
                cin.clear(); // clear the cin error flag
                cin.ignore(numeric_limits<streamsize>::max() ,
                        '\n'); // ignore the max input, up to 'n'
                cout << "\tInvalid input!" << endl;
                cout << "\tPlease enter a number: ";
            } // end of get userAnswer while loop

            cout << endl; // extra space in between the answer and the confirmation message

            // Tests to see if user answer is correct
            if (userAnswer == correctAnswer) {
                totalCorrect++;
                cout << "Correct!" << endl;
                cout << "You're a real Math Whizz!" << endl;
                break;
            } else if (i == MAX_ATTEMPTS) {
                    cout << "Oops!" << endl;
                    cout << "Looks like someone needs to study." << endl;
                    cout << "The correct answer was " << correctAnswer << "." << endl; //gives the user the right answer
                    totalIncorrect++;
                }
                else { //Else runs until user is out of attempts or until user gets the question correct
                    cout << "That was incorrect. You have " << MAX_ATTEMPTS - i << " attempts left." << endl;
                }
        }

        // Leveling Up/Down based on attempts
        if (totalCorrect == 3) { //Levels up if correct answers = 3
            mathLevel++;
            totalCorrect = 0; //Resets totalCorrect and totalIncorrect
            totalIncorrect = 0;
            currentRange += LEVEL_RANGE_CHANGE; //Adds 10 to current range
            cout << "You are now on Level " << mathLevel << "!" << endl;
            cout << "New range is 1 to " << currentRange << endl;
        }
        else if (totalIncorrect >= 3 && mathLevel > 1) { //Levels down after 3 wrong attempts. Will not level down on first level
            mathLevel--;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange -= LEVEL_RANGE_CHANGE; //Subtracts 10 from current range
            cout << "You are now on Level " << mathLevel << "!" << endl;
            cout << "New range is 1 to " << currentRange << endl;
        }

        getline(cin, userYN);

        //Asking user if they want to continue
        while (true) {
            cout << "Do you want to continue (y = yes | n = no)?";
            getline(cin, userYN);

            //to lower case the users input
            for (int i = 0; i < userYN.size(); i++) {
                userYN.at(i) = tolower(userYN.at(i));
            }
            if (userYN == "y" || userYN == "yes" || userYN == "no" || userYN == "n") {
                break;
            }else {
                cout << "Invalid input, please try again..." << endl;
                cout << endl;
            } //end of if (y, yes, n, no)
        }// end of inner while loop to validate yes, no

    }

    while (userYN == "y" || userYN == "yes"); //Loop goes until userYN no longer equals "yes"

    // End of program. Leave message to user. Couts break up the end message to display better in console.
    cout << endl;
    cout << "Thank you, " << userName << ", for playing Silly Math Tutor!" << endl;
    cout << endl;
    cout << "Be sure to come back in the near future" << endl;
    cout << "for more updates, and most importantly," << endl; // promises future improvements, the next being Version 3
    cout << "MORE FUN!" << endl;

    return 0;

}