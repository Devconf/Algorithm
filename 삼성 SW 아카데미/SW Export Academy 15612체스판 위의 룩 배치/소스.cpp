///////////////////////////////////////////////////////////////////////////////////////////////
//// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
//// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
//// ǥ�� �Է� ����
//// int a;
//// float b, c;
//// double d, e, f;
//// char g;
//// char var[256];
//// long long AB;
//// cin >> a;                            // int ���� 1�� �Է¹޴� ����
//// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
//// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
//// cin >> g;                            // char ���� 1�� �Է¹޴� ����
//// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
//// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
///////////////////////////////////////////////////////////////////////////////////////////////
//// ǥ�� ��� ����
//// int a = 0;                            
//// float b = 1.0, c = 2.0;               
//// double d = 3.0, e = 0.0; f = 1.0;
//// char g = 'b';
//// char var[256] = "ABCDEFG";
//// long long AB = 12345678901234567L;
//// cout << a;                           // int ���� 1�� ����ϴ� ����
//// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
//// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
//// cout << g;                           // char ���� 1�� ����ϴ� ����
//// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
//// cout << AB;                          // long long ���� 1�� ����ϴ� ����
///////////////////////////////////////////////////////////////////////////////////////////////
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<cmath>
//#include<tuple>
//
//using namespace std;
//
//int main(int argc, char** argv)
//{
//	int test_case;
//	int T;
//	/*
//		�Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
//		������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
//		//�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
//		freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
//		���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
//		freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
//		��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
//	*/
//	//freopen("input.txt", "r", stdin);
//	cin >> T;
//	/*
//		���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
//	*/
//	for(test_case = 1; test_case <= T; ++test_case)
//	{
//		vector<vector<char>> arr(8,vector<char>(8));
//		vector<tuple<int, int, int>> v;
//
//		string result;
//
//		for(int i = 0; i < 8; i++)
//		{
//			string row;
//			cin >> row;
//			for(int j = 0; j < row.size(); j++)
//			{
//				arr[i][j] = row[j];
//				if(row[j] == 'O')
//				{
//					v.push_back(make_tuple(i, j, abs(i - j)));
//				}
//			}
//		}
//
//		for(int j = 0; j < v.size(); j++)
//		{
//			for(int k = 0; k < v.size(); k++)
//			{
//				if(j != k)
//				{
//					if(get<0>(v[j]) != get<0>(v[k]))
//					{
//						if(get<1>(v[j]) != get<1>(v[k]))
//						{
//							if(get<2>(v[j]) != get<2>(v[k]))
//							{
//								result = "yes";
//							}
//							else
//							{
//								result = "no";
//								break;
//							}
//						}
//						else
//						{
//							result = "no";
//							break;
//						}
//					}
//					else
//					{
//						result = "no";
//						break;
//					}
//				}
//			}
//			if(result == "no")
//			{
//				break;
//			}			
//		}
//		
//
//
//		for(auto row : v)
//		{
//			int i, j, k;
//			tie(i, j, k) = row;
//			cout << i <<j <<k;
//		}
//		
//		cout << "#" << test_case << " " << result << "\n";
//	}
//	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
//}
/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<tuple>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
		�Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
		������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
		//�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
		freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
		���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
		freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
		��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
		���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<char>> arr(8, vector<char>(8));
		vector<int> v(8,0);

		bool checkRow = false;
		bool checkCol = false;
		int rookCnt = 0;

		for(int i = 0; i < 8; i++)
		{
			string row;
			cin >> row;
			int count = 0;
			for(int j = 0; j < row.size(); j++)
			{
				arr[i][j] = row[j];
				if(row[j] == 'O')
				{
					if(v[j] >= 1)
					{
						checkCol = true;
						continue;
					}
					else
					{
						v[j]++;
					}
					count++;
					rookCnt++;
				}
			}
			if(count > 1)//���� �ߺ� Ȯ��
			{
				checkRow = true;
			}
		}

		if(!checkRow && !checkCol &&rookCnt==8)
		{
			cout << "#" << test_case << " yes\n";
		}
		else
		{
			cout << "#" << test_case << " no\n";
		}
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}