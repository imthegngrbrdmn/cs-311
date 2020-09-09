/*
File:		msarray.h
Author:		Millard A. Arnold V
Started:	2020-09-09
Updated:	2020-09-09
Project:	CS-311 Project 2

Header file for moderately smart array
*/

#ifndef MSARRAY_H
#define MSARRAY_H

class MSArray
{
public:
	/*
		Default ctor
		Create MSArray of size 8
		All items should be default constucted
	*/
	MSArray();
	
	/*
		1 Parameter ctor
		Pre: 
			non-negative integer giving number of items in array
		All items should be default constructed
	*/
	MSArray(int size);

	/*
		2 Parameter ctor
		Pre: 
			non-negative integer giving number of items in array
		All items should be set to value of second parameter
	*/


	//	Big 5
	~MSArray();
	MSArray(const MSArray& other);
	MSArray(MSArray&& other);
	MSArray& operator=(const MSArray& other);
	MSArray& operator=(MSArray&& other);

private:

};

#endif