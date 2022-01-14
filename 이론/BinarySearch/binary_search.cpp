#include<iostream>
#include<vector>
using namespace std;

bool BinarySearchRecursion(const int n, const int start, const int end, vector<int> S)
{
	if(start == end)
	{
		if(S[start] == n)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int mid = (start + end) / 2;

	if(n < S[mid])
	{
		return BinarySearchRecursion(n, start, mid, S);
	}
	else if(n > S[mid])
	{
		return BinarySearchRecursion(n, mid+1, end, S);
	}

}

bool BinarySearch(const int n, vector<int> &S)
{
	int start = 0, end = S.size();
	while(start < end)
	{
		int mid = (start + end) / 2;

		if(n < S[mid])
		{
			end = mid;
		}
		else if(n > S[mid])
		{
			start = mid+1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> S = { 1,2,3,4,5,6,7,8,9,10 };
	int n = 0;
	cin >> n;
	if(BinarySearch(n, S))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}

	if(BinarySearchRecursion(n, 0, S.size(), S))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}