/*
	File:		countwords.cpp
	Author:		Millard A. Arnold V
	Started:	2020-11-30
	Updated:	2020-12-01
	Project:	CS-311 Project 8
	
	Source file for excercise A
*/

#ifndef COUNTWORDS_CPP
#define COUNTWORDS_CPP

#include <fstream>	// for ifstream
#include <iostream>	// for cout
#include <string>	// for getline & string
#include <map>		// for map

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
		if (infile)
		{
			if (words.count(word) != 0)
			{
				++words[word];
			}
			else
			{
				words[word] = 1;
			}
		}
		else if (infile.eof())
		{
			break;
		}
	}
	for (std::pair<std::string, int> wordpair : words)
	{
		std::cout << wordpair.first << ": " << wordpair.second << std::endl;
	}
}

#endif