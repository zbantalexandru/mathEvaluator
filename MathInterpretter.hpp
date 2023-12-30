#pragma once
#include <iostream>
#include <vector>
#include "MathematicalOperations.hpp"

/// <summary>
/// Data type that holds the information extracted from the input string given by the user
/// It has the following fields:
/// Mathematical Signs (sign itself, left position of the number and right position of the number)
/// Paranthesis
/// Numbers
/// Original order of execution of the calculus
/// </summary>
struct cathegorizedStringPartitions {
	std::vector<float> numbers;
	std::vector<std::pair<char,std::pair<unsigned int, unsigned int>>> mathematicalSigns;
};

float breakStringInClassesAndCalculate(std::string inputString, short& pozOfCursorInInput);
