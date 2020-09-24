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
			std::cout << GREEN << "good url 1";
		}
		else {
			std::cout << RED << "bad url ";
		}
	}
	else if (prefix1 != "https://" || prefix2 != "http://") {
		std::cout << "Unknown";	//the url is missing the protocol http
	}

  
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
