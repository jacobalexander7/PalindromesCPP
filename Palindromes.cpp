// Jacob Coomer - Data Structures Program 6 - 11/9/21

#include <iostream>
#include <string>
#include "queuetype.h"
#include "stacktype.h"
using namespace std; 

int main()
{
    queueType<char> queueLetters;  // create the objects
    stackType<char> stackLetters; 


    string word;
    bool palindrome = true;  // used to check at the end

    cout << "Enter a word or phrase to check for a palindrome. Special characters will be excluded." << endl;
    getline(cin, word);
    for (int i = 0; i < (int)word.length(); i++)
    {
        char letter = word[i];  
        if (!isalnum(letter))  // check for unused characters
        {
            continue;
        }
        if (isalpha(letter)) { letter = tolower(letter); } // format to reduce errors

        queueLetters.addQueue(letter); // add each char to the objects
        stackLetters.push(letter); 
    }

    while (!queueLetters.isEmptyQueue())  // run until object is cleared
    {
        // if the front and top don't match, word is not a palindrome
        if (!(queueLetters.front() == stackLetters.top())) 
        {
            palindrome = false; 
            break;
        }
        queueLetters.deleteQueue(); // remove the char we checked; 
        stackLetters.pop();
    }

    if (palindrome)
    {
        cout << word + " is a palindrome." << endl;
    }
    else
    {
        cout << word + " is not a palindrome." << endl;
    }
    

}

