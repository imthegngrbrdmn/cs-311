/*
	File:		counthsw.h
	Author:		Millard A. Arnold V
	Started:	2020-10-05
	Updated:	2020-10-05
	Project:	CS-311 Project 4

	Header file for holy spider walk.
*/
#ifndef COUNTHSW_H
#define COUNTHSW_H

#include <utility>	// std::pair
#include <vector>	// std::vector
#include <algorithm>// std::find

/*
	Function countHSW
	takes the coordinates for hole,
	start, and finish. Also takes 
	the dimensions.
	pre:
		0	<=	hole_x		<	dim_x
		0	<=	hole_y		<	dim_y
		0	<=	start_x		<	dim_x
		0	<=	start_y		<	dim_x
		0	<=	finish_x	<	dim_x
		0	<=	finish_x	<	dim_x
*/
int countHSW(int dim_x, int dim_y,
	int hole_x, int hole_y,
	int start_x, int start_y,
	int finish_x, int finish_y);

/*
	Class HoleySpiderWalk
	Given a board
	Calculates the number of paths 
	and stores them in _result

	Invariants:
		0	<=	_finish_x	<	dim_x
		0	<=	_finish_x	<	dim_x
*/
class HoleySpiderWalk
{
//	Ctor and Dtor
public:
	/*
		Ctor
		Calculates number of possible Holey Spider Walk
		paths for given board
		pre:
			0	<=	hole_x		<	dim_x
			0	<=	hole_y		<	dim_y
			0	<=	start_x		<	dim_x
			0	<=	start_y		<	dim_x
			0	<=	finish_x	<	dim_x
			0	<=	finish_x	<	dim_x
	*/
	HoleySpiderWalk(const int dim_x, const int dim_y,
		const int hole_x, const int hole_y,
		const int start_x, const int start_y,
		const int finish_x, const int finish_y)
		:_dim_x(dim_x), _dim_y(dim_y),
		_finish_x(finish_x), _finish_y(finish_y)
	{
		std::vector<std::pair<int, int>> covered = { std::make_pair(hole_x,hole_y) };
		countHSW_recurse(start_x,start_y,covered);
		
	}

	/*
		Dctor
		Does nothing
	*/
	~HoleySpiderWalk() { }

//	Big 5 Delete All
	HoleySpiderWalk() = delete;
	HoleySpiderWalk(const HoleySpiderWalk& other) = delete;
	HoleySpiderWalk(HoleySpiderWalk&& other) = delete;
	HoleySpiderWalk& operator=(const HoleySpiderWalk& other) = delete;
	HoleySpiderWalk& operator=(HoleySpiderWalk&& other) = delete;

//	Public Member Function
public:
	/*
		Member function getResult
		returns the number of paths
	*/
	int getResult() { return _result; }

//	Private Member Function
private:
	/*
		Mmeber funtion countHSW_recurse
		Implementation in source file

		Calculates number of paths for Holey Spider Walk
		Checks each space from position and 
		calls function for each available space
		BASE CASE: covered.size() == area of board
		pre:
			0	<=	curr_x	<	_dim_x
			0	<=	curr_y	<	_dim_y
			covered contains unique values
	*/
	void countHSW_recurse(const int& curr_x, const int& curr_y,
		std::vector<std::pair<int, int>> covered);

//	Private Data Members
	const int _dim_x;
	const int _dim_y;
	const int _finish_x;
	const int _finish_y;
	int _result = 0;
};
#endif
