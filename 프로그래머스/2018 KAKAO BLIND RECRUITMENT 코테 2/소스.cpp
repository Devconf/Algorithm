#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	char option[3] = { ' ',' ',' ' };
	string dartResult;
	int result = 0;

	cin >> dartResult;

	for(int i = 0; i < 3; i++)
	{
		string  point = dartResult.substr(0, 2);
		
		cout << point;

		/*if(dartResult[i] == '#' || dartResult[i] != '*')
		{
			01 2 34 5 67 8
			3,5,7
		}
		*/
	}
}