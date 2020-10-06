/*
	File:		counthsw.cpp
	Author:		Millard A. Arnold V
	Started:	2020-10-05
	Updated:	2020-10-05
	Project:	CS-311 Project 4

	Source file for holy spider walk.
*/

#include "counthsw.h"

//	Documentation in header file
int countHSW(int dim_x, int dim_y, int hole_x, int hole_y, int start_x, int start_y, int finish_x, int finish_y)
{
	return HoleySpiderWalk(dim_x, dim_y, hole_x, hole_y, start_x, start_y, finish_x, finish_y).getResult();
}

//	Documentation in header file
void HoleySpiderWalk::countHSW_recurse(const int& curr_x, const int& curr_y, std::vector<std::pair<int, int>> covered)
{
	covered.push_back(std::make_pair(curr_x, curr_y));

	/*
		BASE CASE
		Checks if all spaces are covered and spider is at the finish position
		IF both are true, adds one to _result and returns.
	*/
	if (covered.size() == _dim_x * _dim_y && curr_x == _finish_x && curr_y == _finish_y)
	{
		++_result;
		return;
	}

	//	South
	if (curr_y + 1 < _dim_y &&
		std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x, curr_y + 1)) == std::end(covered))
	{
		countHSW_recurse(curr_x, curr_y + 1, covered);
	}

	//	Southwest
	if (curr_x - 1 >= 0 && curr_y + 1 < _dim_y &&
		std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x - 1, curr_y + 1)) == std::end(covered))
	{
		countHSW_recurse(curr_x - 1, curr_y + 1, covered);
	}

	//	West
	if (curr_x - 1 >= 0 &&
		std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x - 1, curr_y)) == std::end(covered))
	{
		countHSW_recurse(curr_x - 1, curr_y, covered);
	}

	//	Northwest
	if (curr_x - 1 >= 0 && curr_y - 1 >= 0 &&
		std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x - 1, curr_y - 1)) == std::end(covered))
	{
		countHSW_recurse(curr_x - 1, curr_y - 1, covered);
	}

	//	North
	if (curr_y - 1 >= 0 &&
		std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x, curr_y - 1)) == std::end(covered))
	{
		countHSW_recurse(curr_x, curr_y - 1, covered);
	}

	//	Northeast
	if (curr_x + 1 < _dim_x && curr_y - 1 >= 0 &&
		std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x + 1, curr_y - 1)) == std::end(covered))
	{
		countHSW_recurse(curr_x + 1, curr_y - 1, covered);
	}

	//	East
	if (curr_x + 1 < _dim_x &&
		std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x + 1, curr_y)) == std::end(covered))
	{
		countHSW_recurse(curr_x + 1, curr_y, covered);
	}

	//	Southeast
	if (curr_x + 1 < _dim_x && curr_y + 1 < _dim_y &&
		std::find(std::begin(covered), std::end(covered), std::make_pair(curr_x + 1, curr_y + 1)) == std::end(covered))
	{
		countHSW_recurse(curr_x + 1, curr_y + 1, covered);
	}
}
