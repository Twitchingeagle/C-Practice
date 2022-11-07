//
//  main.cpp
//  Hangman
//
//  Created on 11/5/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdio.h>
#define MAX_GUESSES 4
int guesses = 0;

/*
 Random number generation
 */
int Random(int a, int b)
{
    thread_local std::mt19937 eng{std::random_device{}()};
    std::uniform_int_distribution<int> dist(a, b);
    return dist(eng);
}

/*
 Return a random word for the player to guess
 */
std::string ChooseWord()
{
    std::vector<std::string>wordVector;
    std::string choice;

    // Filling vector with words
    wordVector.push_back("GUESS");
    wordVector.push_back("CONSTERNATION");
    wordVector.push_back("ENJOYMENT");
    wordVector.push_back("PROGRAMMER");
    wordVector.push_back("DELETE");
    wordVector.push_back("DUBIOUS");
    wordVector.push_back("SILENCE");
    
    return wordVector[Random(0, wordVector.size())];
}

/*
 Finds a match and updates the blank string
 */
int findmatch(const char& guess, const std::string& secretword, std::string& unknown)
{
    int matches = 0;
    for(int i = 0; i < secretword.length(); i++)
    {
        if (guess == (unknown[i])) // This has already been guessed
        {
            matches = 0;
        }
        else if (guess == secretword[i])
        {
            matches++;
            unknown[i] = guess;
        }
    }
    return matches;
}

int main()
{
    int guesses = 4;
    std::string hidden = ChooseWord();
    std::string blank(hidden.length(), '_');
    std::cout << "Welcome to Hangman!" << std::endl;
    std::cout << "A random word has been generated for you to guess, it is " <<
    hidden.length() << " characters long." << std::endl;
    std::cout << "Press any letter to begin." << std::endl;

    while (guesses > 0 && hidden != blank) // Continue until player wins or fails
    {
        char guess;
        std::cout << blank << std::endl;
        std::cin >> guess;
        
        if (findmatch(toupper(guess), hidden, blank) > 0)
        {
            std::cout << blank << std::endl;
        }
        else
        {
            std::cout << "Guess a new letter. You have " << guesses << " chances left." << std::endl;
            guesses--;
        }
    }
    if (hidden == blank)
    {
        std::cout << "Congratulations! You won! " << std::endl;
    }
    std::cin.get();
    return 0;
}
