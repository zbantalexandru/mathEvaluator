#include "MathInterpretter.hpp"
#include "GlobalVariablePanel.hpp"
void calculationOfNumbers(cathegorizedStringPartitions& inputData, int iteratorOfSign, float (*calculation)(float,float))
{
	inputData.numbers[inputData.mathematicalSigns[iteratorOfSign].second.first] =
		calculation(
			inputData.numbers[inputData.mathematicalSigns[iteratorOfSign].second.first],
			inputData.numbers[inputData.mathematicalSigns[iteratorOfSign].second.second]
		);//first number is excanged with the result of the equation
	inputData.numbers.erase(inputData.numbers.begin() + inputData.mathematicalSigns[iteratorOfSign].second.second);//erase the second number
	inputData.mathematicalSigns[iteratorOfSign].first=176;//unable to erase the pair but the sign is changed to something inposible, so it is ignored
	for (int ii = iteratorOfSign; ii < inputData.mathematicalSigns.size(); ii++)
	{
		inputData.mathematicalSigns[ii].second.first--;
		inputData.mathematicalSigns[ii].second.second--;
	}
}

float returnResultOfCalculation(cathegorizedStringPartitions inputData, unsigned int& indexParanthesis, unsigned int& indexNumbers, unsigned int& indexSigns, unsigned int& indexConfiguration)
{
	for (int iterator = 0; iterator < inputData.mathematicalSigns.size(); iterator++)
	{
		switch (inputData.mathematicalSigns[iterator].first) {
		case '*':
			calculationOfNumbers(inputData, iterator, multiplication);
			iterator--;
			break;
		case '/':
			calculationOfNumbers(inputData, iterator, division);
			iterator--;
			break;
		}
	}
	for (int iterator = 0; iterator < inputData.mathematicalSigns.size(); iterator++)
	{
		switch (inputData.mathematicalSigns[iterator].first) {
		case '+':
			calculationOfNumbers(inputData, iterator, adition);
			iterator--;
			break;
		case '-':
			calculationOfNumbers(inputData, iterator, substraction);
			iterator--;
			break;
		}
	}
	return inputData.numbers[0];
}

float breakStringInClassesAndCalculate(std::string inputString, short &pozOfCursorInInput)
{
	cathegorizedStringPartitions foundCathegories;
	bool isMathSign=false, isNumerDiscoverInProgress=false, isNegativeNumber=false;
	unsigned int indexParanthesis=0, indexNumbers=0, indexSigns=0, indexConfiguration=0;
	int discoveredNumber = 0;
	float resultParanthesis = 0;
	if (inputString[pozOfCursorInInput] == '-') //if there is the case of -1+2*3 or 1+2*(-1) i have to easily identify the -
	{
		isNegativeNumber = true;
		pozOfCursorInInput++;
	}
	for (; pozOfCursorInInput < inputString.size(); pozOfCursorInInput++)
	{
		switch (inputString[pozOfCursorInInput])
		{
		case '('://WIP not yet tested
			pozOfCursorInInput++;
			resultParanthesis = breakStringInClassesAndCalculate(inputString, pozOfCursorInInput);
			if (isNegativeNumber)
			{
				resultParanthesis = -resultParanthesis;
			}
			foundCathegories.numbers.push_back(resultParanthesis);
			break;
		case ')'://WIP not yet tested
			if (isNumerDiscoverInProgress)
			{
				if (isNumerDiscoverInProgress)
				{
					if (isNegativeNumber)
					{
						discoveredNumber = -discoveredNumber;
						isNegativeNumber = false;
					}
					foundCathegories.numbers.push_back(discoveredNumber);
					discoveredNumber = 0;
					isNumerDiscoverInProgress = false;
				}
			}
			return returnResultOfCalculation(foundCathegories, indexParanthesis, indexNumbers, indexSigns, indexConfiguration);
		default:
			if (inputString[pozOfCursorInInput] < '9' && inputString[pozOfCursorInInput] >= '0')
			{
				isNumerDiscoverInProgress = true;
				discoveredNumber = discoveredNumber * 10 + (inputString[pozOfCursorInInput] - '0');
			}
			else {
				if (isNumerDiscoverInProgress)
				{
					if (isNegativeNumber)
					{
						discoveredNumber = -discoveredNumber;
						isNegativeNumber = false;
					}
					foundCathegories.numbers.push_back(discoveredNumber);
					discoveredNumber = 0;
					isNumerDiscoverInProgress = false;
				}
				if (inputString[pozOfCursorInInput] == '-')
				{
					isNegativeNumber = true;
				}
				for (short signIndex = 0; signIndex < strlen(admittedMathSigns); signIndex++)
				{
					if (inputString[pozOfCursorInInput] == admittedMathSigns[signIndex])
					{
						isMathSign = true;
						std::pair<char, std::pair<unsigned int, unsigned int>> pairToAdd;
						pairToAdd.first = admittedMathSigns[signIndex];
						if (inputString[pozOfCursorInInput] == '-')
						{
							pairToAdd.first = '+';//the substraction is the sum un the number in the left and some negative rumber in the right
						}
						pairToAdd.second.first = foundCathegories.numbers.size() - 1;//pozition of the element I just added
						pairToAdd.second.second = foundCathegories.numbers.size();
						foundCathegories.mathematicalSigns.push_back(pairToAdd);
					}
				}
			}
			break;
		}	
	}
	if (isNumerDiscoverInProgress)
	{
		if (isNegativeNumber)
		{
			discoveredNumber = -discoveredNumber;
			isNegativeNumber = false;
		}
		foundCathegories.numbers.push_back(discoveredNumber);
		discoveredNumber = 0;
		isNumerDiscoverInProgress = false;
	}
	return returnResultOfCalculation(foundCathegories, indexParanthesis, indexNumbers, indexSigns, indexConfiguration);
}

