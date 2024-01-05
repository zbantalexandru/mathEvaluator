#include "ValidityChecker.hpp"
#include"GlobalVariablePanel.hpp"
bool isGivenCharAMathematicalSign(char stringEntity)
{
	for (int i = 0; i < strlen(admittedMathSigns); i++)
		if (stringEntity == admittedMathSigns[i])
			return true;
	return false;
}
/// <summary>
/// Validity checker for the paranthesis and math signs
/// </summary>
/// <param name="entireString">Entire String got from the user</param>
/// <returns>Returns True if string is valid otherwise returns False</returns>
bool isTheEquationValid(std::string entireString)
{
	int depth = 0;
	if (entireString[0] == '/' || entireString[0] == '*' || entireString[0] == '+')
		return false;
	if (entireString[entireString.size()-1] == '/' || entireString[entireString.size() - 1] == '*' || entireString[entireString.size() - 1] == '+')
		return false;
	if(entireString[0]== '(')
		depth++;
	if (entireString[0] == ')')
		return false;
	for (int iterator = 1; iterator < entireString.size(); iterator++)
	{
		switch (entireString[iterator]) {
		case '(':
			depth++;
			break;
		case ')':
			depth--;
			break;
		case '+':
		case '*':
		case '/':
			if (entireString[iterator - 1] == '(')
				return false;
		default:
			//the below if statement blocks all letters and unexpected characters. In the future this will be uncommented and replced with some check for unknown words (ex sin/cos/log vs sii/com/rog)
			if (//(entireString[iterator] < 'a' || entireString[iterator] > 'z') &&
				//(entireString[iterator] < 'A' || entireString[iterator] > 'Z') && 
				(entireString[iterator] < '0' || entireString[iterator] > '9') &&
				isGivenCharAMathematicalSign(entireString[iterator])==false &&
				entireString[iterator]!='(' &&
				entireString[iterator]!=')')
				return false;
			if (isGivenCharAMathematicalSign(entireString[iterator])==true && (isGivenCharAMathematicalSign(entireString[iterator - 1]) ||  entireString[iterator + 1] == ')'))
				return false;
		}
		if (depth < 0) return false;
	}
	return (depth == 0);
}
