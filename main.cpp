//
// Created by riwall01 on 10/11/2024.
//
/**************************************************************************************
Program: Math Tutor Version 1
Programmer: Riley Teeter
Date: 8.26.24
replit URL:
https://replit.com/@riteet01/MathTutorAssignment#Programming%20Fundamentals/main.cpp
Description: A simple math tutor for young children. In version 1 it displays
the title of the program, a math joke,  it gets the users name, asks a math
question, and the display end of program message.
**************************************************************************************/

#include <iostream> // required for couts & cins
#include <cstdlib> // allows for randomizer
#include <ctime> // enables use of time function
#include <string> // allows for strings to be used

using namespace std; // sets standard namespace

int main() {
    // Starting the main function

    //*********************************************************************

    // Declares and initializes variables
    string userName = "unknown"; // Declaring and initializing variables
    int leftNum = 0;
    int rightNum = 0;
    int mType = 0;
    char mSymbol = '?';
    int correctAnswer = 0;
    int userAnswer = 0;
    int temp = 0;
    char userYN = '?';

    srand(time(0)); // Generates a unique seed so its random.
}