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

#include <utility>	// std::pair makes coordinates easier.
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

class HoleySpiderWalk
{
public:
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
	HoleySpiderWalk() = delete;
	HoleySpiderWalk(const HoleySpiderWalk& other) = delete;
	HoleySpiderWalk(HoleySpiderWalk&& other) = delete;
	HoleySpiderWalk& operator=(const HoleySpiderWalk& other) = delete;
	HoleySpiderWalk& operator=(HoleySpiderWalk&& other) = delete;
	~HoleySpiderWalk(){ }
public:
	int getResult() { return _result; }
public:
	void countHSW_recurse(const int& curr_x, const int& curr_y,
		std::vector<std::pair<int, int>> covered)
	{
		covered.push_back(std::make_pair(curr_x, curr_y));
		if (covered.size() == _dim_x * _dim_y)
		{
			if (curr_x == _finish_x && curr_y == _finish_y)
			{
				++_result;
			}
		}
		if (curr_y + 1 < _dim_y &&
			std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x, curr_y + 1)) == std::end(covered))
		{
			countHSW_recurse(curr_x, curr_y + 1, covered);	// SOUTH
		}
		if (curr_x - 1 >= 0 && curr_y + 1 < _dim_y &&
			std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x - 1, curr_y + 1)) == std::end(covered))
		{
			countHSW_recurse(curr_x - 1, curr_y + 1, covered);	// SOUTHWEST
		}
		if (curr_x - 1 >= 0 &&
			std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x - 1, curr_y)) == std::end(covered))
		{
			countHSW_recurse(curr_x - 1, curr_y, covered);	// WEST
		}
		if (curr_x - 1 >= 0 && curr_y - 1 >= 0 &&
			std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x - 1, curr_y - 1)) == std::end(covered))
		{
			countHSW_recurse(curr_x - 1, curr_y - 1, covered);	// NORTHWEST
		}
		if (curr_y - 1 >= 0 &&
			std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x, curr_y - 1)) == std::end(covered))
		{
			countHSW_recurse(curr_x, curr_y - 1, covered);	// NORTH
		}
		if (curr_x + 1 < _dim_x && curr_y - 1 >= 0 &&
			std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x + 1, curr_y - 1)) == std::end(covered))
		{
			countHSW_recurse(curr_x + 1, curr_y - 1, covered);	// NORTHEAST
		}
		if (curr_x + 1 < _dim_x &&
			std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x + 1, curr_y)) == std::end(covered))
		{
			countHSW_recurse(curr_x + 1, curr_y, covered);	// EAST
		}
		if (curr_x + 1 < _dim_x && curr_y + 1 < _dim_y &&
			std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x + 1, curr_y + 1)) == std::end(covered))
		{
			countHSW_recurse(curr_x + 1, curr_y + 1, covered);	// SOUTHEAST
		}
	}
private:
	const int _dim_x;
	const int _dim_y;
	const int _finish_x;
	const int _finish_y;
	int _result = 0;
};
#endif // !COUNTHSW_H
