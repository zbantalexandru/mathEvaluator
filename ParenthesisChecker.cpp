#include "ParenthesisChecker.hpp"

bool areParanthesisValid(std::string allParanthesis)
{
	int depth = 0;
	for (int iterator = 0; iterator < allParanthesis.size(); iterator++)
	{
		if (allParanthesis[iterator] == '(')
			depth++;
		else depth--;
		if (depth < 0) return false;
	}
	return (depth == 0);
}