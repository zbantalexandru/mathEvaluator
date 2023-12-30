#include "pch.h"
#include "../ParenthesisChecker.cpp"
#include "../MathInterpretter.cpp"
#include "../MathematicalOperations.cpp"
using namespace std;
TEST(ParenthesisChecker, ParenthesisProblem) {
	std::pair<string, bool> testInputOutput[100];
	int counterNumberTests = 0;

	testInputOutput[counterNumberTests].first = (string)"(";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)")";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"()";
	testInputOutput[counterNumberTests].second = true;

	testInputOutput[++counterNumberTests].first = (string)")(";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"((";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"))";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"())";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"(()";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"()(";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)")()";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"()()";
	testInputOutput[counterNumberTests].second = true;

	testInputOutput[++counterNumberTests].first = (string)"(())";
	testInputOutput[counterNumberTests].second = true;

	testInputOutput[++counterNumberTests].first = (string)"())(";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)")(()";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)")()(";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"(())(";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"(()()";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"(()())";
	testInputOutput[counterNumberTests].second = true;

	testInputOutput[++counterNumberTests].first = (string)"(())()))";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"(()))(";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"()))((";
	testInputOutput[counterNumberTests].second = false;
	testInputOutput[++counterNumberTests].first = (string)"(((())()))";
	testInputOutput[counterNumberTests].second = true;


	for (int iterator = 0; iterator < counterNumberTests; iterator++)
	{
		EXPECT_EQ(areParanthesisValid(testInputOutput[iterator].first), testInputOutput[iterator].second);
	}
}
TEST(CalculationChecker, CalculationProblem)
{
	string input = "1+2*3";
	short startPoz = 0;
	float result=breakStringInClassesAndCalculate(input, startPoz);
	float expectedRes = 0;
	EXPECT_FLOAT_EQ(result, 7.0f);

	input = "1*2+3";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 5.0f);

	input = "10*2*3";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 60.0f);

	input = "11*12+13";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 11*12+13);

	input = "1-2+3";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 2.0f);

	input = "-1+2+3";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 4.0f);

	input = "1*2/3";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 2.0f / 3.0f);

	input = "1-1-1-1";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, -2.0f); 
	
	input = "-1-1-1+1+1+5*3";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 14.0f);

	input = "1-0";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 1.0f);

	input = "0-1";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, -1.0f);

	input = "0+1";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 1.0f);

	input = "-0+1";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 1.0f);
	input = "-2*3";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, -6.0f);
	input = "15*10+11*10-240";
	startPoz = 0;
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 20.0f);
	
}