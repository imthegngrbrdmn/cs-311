/*
	File:		counthsw.cpp
	Author:		Millard A. Arnold V
	Started:	2020-10-05
	Updated:	2020-10-05
	Project:	CS-311 Project 4

	Source file for holy spider walk.
*/

#include "counthsw.h"

int countHSW(int dim_x, int dim_y, int hole_x, int hole_y, int start_x, int start_y, int finish_x, int finish_y)
{
	std::vector<std::pair<int, int>> covered;
	return countHSW_recurse(dim_x, dim_y, hole_x, hole_x, start_x, start_y, finish_x, finish_y, covered);
}