// ConsoleApplicationOSD600.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cstddef>         // std::size_t

#define GREEN   "\033[32m"
#define RED     "\033[31m"



using namespace std;

int main()
{
	std::string url;
	std::cout << "Enter URL: ";
	getline(std::cin, url);

	string prefix1 = url.substr(0, 8);
	string prefix2 = url.substr(0, 7);

	if (prefix1 == "https://") {
		size_t dot = url.find_last_of('.');
		size_t slash = url.substr(dot).find("\/");
		string domain = url.substr(0, slash - 1);
		string path = url.substr(slash);

		if (2 != slash - 1 ||
			3 != slash - 1 ||
			4 != slash - 1) {
			//add line to print error
			std::cout << "good url 1";
		}
		else {
			std::cout << "bad url ";
		}
	}
	else if (prefix2 == "http://") {
		size_t dot = url.find_last_of('.');
		size_t slash = url.substr(dot).find("\/");
		string domain = url.substr(0, slash - 1);
		string path = url.substr(slash);

		if (2 != slash - 1 ||
			3 != slash - 1 ||
			4 != slash - 1) {
			//add line to print error
			std::cout << "good url 1";
		}
		else {
			std::cout << "bad url ";
		}
	}
	else if (prefix1 != "https://" || prefix2 != "http://") {
		std::cout << "bad url 3";	//the url is missing the protocol http
	}

	// Use a while loop together with the getline() function to read the file line by line
   // while (getline(MyReadFile, myText)) {
	   // if(argv[1] = std::regex("(http|https):\/\/(\w+\.)(\w)\/([\w\d]+\/{0,1})+"))
		// Output the text from the file
	  //  cout << GREEN << myText;
   // }

	// Close the file
   // MyReadFile.close();
	//std::ifstream file("text.txt");
	//std::string str;
   // while (std::getline(file, str)) {

		//Checking if each line is valid URL
		//if (std::regex_match("http://www.google.com", std::regex("(http|https):\/\/(\w+\.)(\w)\/([\w\d]+\/{0,1})+")))

	 //   std::cout << str << "\n";
		//std::cout << GREEN << "valid URL \n";

		//if not URL address, then printing the line in red
   // }
	//return 0;
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
