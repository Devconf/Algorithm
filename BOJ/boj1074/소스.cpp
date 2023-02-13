#include<iostream>
#include<cmath>
using namespace std;

int n, r, c;

void solution( int a, int b, int num, int divide)
{
	if(divide == 0)
	{
		cout << num;
		return;
	}
	int position;
	int x =a-divide;	
	int y = b-divide;
	
	if(r <= x && c <= y) //1��и�
	{
		position = 1;
	}
	if(r <= x && c > y) // 2��и�
	{
		position = 2;
	}
	if(r > x && c <= y) // 3��и�
	{
		position = 3;
	}
	if(r > x && c > y) // 4��и�
	{
		position = 4;
	}

	switch(position)
	{
	case 1:
		solution(a - divide, b - divide, num - pow(divide, 2) * 3, divide / 2);
		break;
	case 2:
		solution(a - divide, b, num - pow(divide, 2) * 2, divide / 2);
		break;
	case 3:
		solution(a, b - divide, num - pow(divide, 2) * 1, divide / 2);
		break;
	case 4:
		solution(a, b, num - pow(divide, 2) * 0, divide / 2);
		break;
	default:
		break;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r >> c;

	solution( pow(2, n)-1, pow(2, n)-1, pow(pow(2, n), 2) - 1, pow(2, n)/2); //x��ǥ, y��ǥ, ���� ������ ����, ������ ����
}