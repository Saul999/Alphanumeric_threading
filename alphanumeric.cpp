//source used: assistance from ChatGPT

#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <sstream>

//global variables
std::vector<std::string> words;  //vector that stores words
std::atomic<size_t> currentIndex(0);  //global index for current word being processed
std::atomic<bool> done(false);  //flag to signal threads to exit

//function to process words starting with an alphabet
void alpha() 
{
    while (!done) 
    {
        std::string currentWord;
        size_t localIndex;

        //atomically load and increment the currentIndex
        localIndex = currentIndex.fetch_add(1);

        if (localIndex < words.size()) 
        {
            currentWord = words[localIndex];

            if (isalpha(currentWord[0])) 
            {
                std::cout << "alpha: " << currentWord << std::endl;
            }
        }
    }
}

//function to process words starting with a number
void numeric() 
{
    while (!done) 
    {
        std::string currentWord;
        size_t localIndex;

        //atomically load and increment the currentIndex
        localIndex = currentIndex.fetch_add(1);

        if (localIndex < words.size()) 
        {
            currentWord = words[localIndex];

            if (isdigit(currentWord[0])) 
            {
                std::cout << "numeric: " << currentWord << std::endl;
            }
        }
    }
}

int main(int argc, char *argv[]) 
{
    //read phrase from command line or user input
    std::string inputPhrase;

    if (argc > 1) 
    {
        //read from command line argument
        inputPhrase = argv[1];
    } 
    else 
    {
        //read from user input
        std::cout << "Enter string: ";
        std::getline(std::cin, inputPhrase);
    }

    //split the input phrase into words
    std::istringstream iss(inputPhrase);
    std::string word;

    while (iss >> word) 
    {
        words.push_back(word);
    }

    //create threads
    std::thread alphaThread(alpha);
    std::thread numericThread(numeric);

    //wait for threads to finish
    alphaThread.join();
    numericThread.join();

    //set the flag to signal threads to exit
    done = true;

    return 0;
}
