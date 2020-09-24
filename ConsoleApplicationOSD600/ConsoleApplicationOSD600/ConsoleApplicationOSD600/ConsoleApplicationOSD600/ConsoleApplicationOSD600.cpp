// ConsoleApplicationOSD600.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>    
#include <regex>
#include <Windows.h>

//#define GREEN   "\033[32m"
//#define RED     "\033[31m"



using namespace std;

int main()
{
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("URLFile.txt");

    while (getline(MyReadFile, myText))
    {
        // Process str
        //if (std::regex_match("http://www.google.com", std::regex("(http|https):\/\/(\w+\.)*(\w*)\/([\w\d]+\/{0,1})+")))

            //    std::cout << GREEN << "valid URL \n";
            // Output the text from the file
            cout << myText;

    }
    // Close the file
    MyReadFile.close();
   
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
