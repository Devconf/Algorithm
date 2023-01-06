#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int s;

	cin >> s;

	int sum = 0;
	int answer = 0;
	for(int i = 1; ; i++)
	{
		if(sum + i <= s)
		{
			sum += i;
			answer = i;
		}
		else
		{
			break;
		}
	}
	cout << answer;
}