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
		std::vector<std::pair<int, int>> covered = { std::make_pair(hole_x,hole_y), std::make_pair(start_x,start_y) };
		countHSW_recurse(start_x,start_y,covered);
	}
	HoleySpiderWalk() = delete;
	HoleySpiderWalk(const HoleySpiderWalk& other) = delete;
	HoleySpiderWalk(HoleySpiderWalk&& other) = delete;
	HoleySpiderWalk& operator=(const HoleySpiderWalk& other) = delete;
	HoleySpiderWalk& operator=(HoleySpiderWalk&& other) = delete;
	~HoleySpiderWalk(){ }
public:
	int countHSW_recurse(const int& curr_x, const int& curr_y,
		std::vector<std::pair<int, int>> covered)
	{
		if (covered.size() == _dim_x * _dim_y)
		{
			if (curr_x == _finish_x && curr_y == _finish_y)
			{
				return 1;
			}
			return 0;
		}
		return 0;
	}
private:
	const int _dim_x;
	const int _dim_y;
	const int _finish_x;
	const int _finish_y;
};
#endif // !COUNTHSW_H
