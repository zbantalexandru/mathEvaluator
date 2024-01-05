#include "pch.h"
#include "../ValidityChecker.cpp"
#include "../MathInterpretter.cpp"
#include "../MathematicalOperations.cpp"
using namespace std;
TEST(EquationcorectnessChecker, EquationcorectnessProblem) {
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

	testInputOutput[++counterNumberTests].first = (string)"1+2*3";
	testInputOutput[counterNumberTests].second = true;

	testInputOutput[++counterNumberTests].first = (string)"1++1";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"-23+56";
	testInputOutput[counterNumberTests].second = true;

	testInputOutput[++counterNumberTests].first = (string)"-(-3)";
	testInputOutput[counterNumberTests].second = true;

	testInputOutput[++counterNumberTests].first = (string)"(-2)";
	testInputOutput[counterNumberTests].second = true;

	testInputOutput[++counterNumberTests].first = (string)"(-3)-(-4)";
	testInputOutput[counterNumberTests].second = true;

	testInputOutput[++counterNumberTests].first = (string)"/2-(3+(4*4))";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"4/4/4/";
	testInputOutput[counterNumberTests].second = false;

	testInputOutput[++counterNumberTests].first = (string)"()+()";
	testInputOutput[counterNumberTests].second = false;
	bool result = false;
	for (int iterator = 0; iterator < counterNumberTests; iterator++)
	{	
		result = isTheEquationValid(testInputOutput[iterator].first);
		if (result != testInputOutput[iterator].second)
		{
			cout << testInputOutput[iterator].first << " " << iterator << endl;
		}
		EXPECT_EQ(result, testInputOutput[iterator].second);
	}
}
TEST(CalculationChecker, CalculationProblem)
{
	string input = "1+2*3";
	short startPoz = 0;
	bool statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	float result=breakStringInClassesAndCalculate(input, startPoz);
	float expectedRes = 0;
	EXPECT_FLOAT_EQ(result, 7.0f);

	input = "1*2+3";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 5.0f);

	input = "10*2*3";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 60.0f);

	input = "11*12+13";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 11*12+13);

	input = "1-2+3";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 2.0f);

	input = "-1+2+3";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 4.0f);

	input = "1*2/3";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 2.0f / 3.0f);

	input = "1-1-1-1";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, -2.0f); 
	
	input = "-1-1-1+1+1+5*3";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 14.0f);

	input = "1-0";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 1.0f);

	input = "0-1";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, -1.0f);

	input = "0+1";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 1.0f);

	input = "-0+1";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 1.0f);
	input = "-2*3";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, -6.0f);
	input = "15*10+11*10-240";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 20.0f);
	input = "15*(10+11)*10-240";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 2910.0f);
	input = "2*(3-2)*(10-240)";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, -460.0f);
	input = "2*(3+(4+4)*2)-2";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 36.0f);
	input = "2*((4+4)*2)-2";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 30.0f);
	input = "2*((4+4))-2";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, 14.0f);
	input = "-(2+3)";
	startPoz = 0;
	statementValidityCheck = isTheEquationValid(input);
	EXPECT_EQ(statementValidityCheck, true);
	result = breakStringInClassesAndCalculate(input, startPoz);
	EXPECT_FLOAT_EQ(result, -5.0f);
}