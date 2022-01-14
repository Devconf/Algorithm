#include<iostream>
#include<chrono>
using namespace std;

int arr[100000] = { 0, };

int Fibonacci(const int n)
{
	if(n <= 1)
	{
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int OptimizedFibonacci(const int n)
{
	for(int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	cout<<Fibonacci(n)<<"\n";
	chrono::system_clock::time_point end = chrono::system_clock::now();
	chrono::nanoseconds nano = end - start;
	cout << nano.count()<<"\n";


	arr[0] = 1;
	arr[1] = 1;
	chrono::system_clock::time_point start1 = chrono::system_clock::now();
	cout << OptimizedFibonacci(n) << "\n";
	chrono::system_clock::time_point end1 = chrono::system_clock::now();
	chrono::nanoseconds nano1 = end1 - start1;
	cout << nano1.count() << "\n";
}