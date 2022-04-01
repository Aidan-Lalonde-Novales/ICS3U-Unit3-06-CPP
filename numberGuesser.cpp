// Copyright (c) 2022 Aidan Lalonde-Novales All rights reserved
//
// Created by Aidan Lalonde-Novales
// Created on 2022-03-31
// This program prompts a user to guess a number
// and tells them if they are correct or not (random number).

#include <iostream>
#include <random>
#include <string>

int main() {
    // this function gets a guess then checks if it is right
    std::string guessedNumberstring;
    int guessedNumber;
    int randomNumber;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0, 9]
    randomNumber = idist(rgen);

    // input
    std::cout << "Enter a number between 0-9: ";
    std::cin >> guessedNumberstring;

    // process & output
    try {
        guessedNumber = std::stoi(guessedNumberstring);
        if (guessedNumber == randomNumber) {
            std::cout << "You Guessed Correctly!" << std::endl;
        } else {
            std::cout << "You Guessed Incorrectly. " <<
            "The correct number was " << randomNumber <<
            "." << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "Please input an Integer.";
    }
    std::cout << "\nDone." << std::endl;
}
