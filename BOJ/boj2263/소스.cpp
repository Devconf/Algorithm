#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int In_Order[100001];
int Post_Order[100001];
int Pre_Order[100001];
int n;

int number(pair<int,int> a)
{
	int num = (a.second - a.first + 1);
	return num > 0?num:0;
}


void FindChildNode(pair<int,int> in, pair<int,int> post)
{
	int left_num = 0, right_num = 0;//왼쪽 자식과 오른쪽 자식 남은 갯수를 저장한다.
	pair<int, int> in_left, post_left, in_right, post_right;// 자식 노드 구간
	int mid = Post_Order[post.second];
	cout << mid << " ";

	in_left = in_right = in;
	in_left.second = In_Order[mid] - 1;// in order의 왼쪽 자식의 끝 
	in_right.first = In_Order[mid] + 1;//in order의 오른쪽 자식의 시작

	left_num = number(in_left); // in order의 왼쪽 자식의 갯수
	right_num = number(in_right);// in order의 오른쪽 자식의 갯수

	//이후 in order에 따른 post를 구해준다.

	if(left_num > 0)
	{
		post_left.second = post.second - 1 - right_num;
		post_left.first = post_left.second + 1 - left_num;
		FindChildNode(in_left, post_left);
	}
	if(right_num > 0)
	{
		post_right.second = post.second - 1;
		post_right.first = post.second - right_num;
		FindChildNode(in_right, post_right);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(In_Order, 0, sizeof(In_Order));
	memset(Post_Order, 0, sizeof(Post_Order));
	memset(Post_Order, 0, sizeof(Post_Order));

	cin >> n;

	for(int i = 1; i<= n; i++)
	{
		int num;
		cin >> num;
		In_Order[num] = i;// 위치를 담고있음
	}

	for(int i = 1; i <= n; i++)
	{
		cin >> Post_Order[i];
	}

	FindChildNode({ 1,n }, { 1,n });
}