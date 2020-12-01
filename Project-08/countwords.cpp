/*
	File:		countwords.cpp
	Author:		Millard A. Arnold V
	Started:	2020-11-30
	Updated:	2020-12-01
	Project:	CS-311 Project 8
	
	Source file for excercise A
	Reads a file & gives the wordcounts of each word.
*/

#ifndef COUNTWORDS_CPP
#define COUNTWORDS_CPP

#include <fstream>	// for ifstream
#include <iostream>	// for cout
#include <string>	// for getline & string
#include <map>		// for map

/*
	main function

	Exception Neutral
	No Throw Guarantee
*/
int main(int argc, char** argv)
{
	std::string filename;
	std::cout << "Please enter a filename and then press enter" << std::endl;
	std::getline(std::cin, filename);
	std::ifstream infile(filename);
	std::string word;
	std::map<std::string, int> words;
	while (infile>>word)
	{
		// Make sure read worked
		if (infile)
		{
			// Add word to map
			if (words.count(word) != 0)
			{
				++words[word];
			}
			else
			{
				words[word] = 1;
			}
		}
		// Check if end of file
		else if (infile.eof())
		{
			break;
		}
	}
	// Print all words & quantities
	for (std::pair<std::string, int> wordpair : words)
	{
		std::cout << wordpair.first << ": " << wordpair.second << std::endl;
	}
}

#endif