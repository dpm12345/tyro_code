矩阵创建及转置

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

vector<vector<int>> juzheng_change(vector<vector<int>>&a)
{
	vector<vector<int>>b(a[0].size(), vector<int>(a.size()));
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			b[j][b[0].size() - i - 1] = a[i][j];         //进行数值传递
		}
	}
	return b;
}
int main()
{
	int m, n,num;
	cout << "请分别输入矩阵的行、列数：";
	cin >> m >> n;                   //确定矩阵大小
	vector<vector<int>>a(m,vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			a[i][j] = num;              //矩阵内元素确认
		}
	}
	vector<vector<int>>b(n, vector<int>(m));
	b= juzheng_change(a);
	cout << "转置后的矩阵:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j] << "  ";              //输出
		}
		cout << endl;
	}
}



      对齐输出：
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<string>
using namespace std;

int cal(int n)
{
	return (to_string(n).length());
}

vector<vector<int>> juzheng_change(vector<vector<int>>&a)
{
	vector<vector<int>>b(a[0].size(), vector<int>(a.size()));
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			b[j][b[0].size() - i - 1] = a[i][j];         //进行数值传递
		}
	}
	return b;
}
int main()
{
	int m, n;
	int  num,ans;
	cout << "请分别输入矩阵的行、列数：";
	cin >> m >> n;                   //确定矩阵大小
	vector<vector<int>>a(m,vector<int>(n));
	cout << "输入矩阵各位置的值:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			a[i][j] = num; //矩阵内元素确认
			ans = max(ans, num);
		}
	}
	vector<vector<int>>b(n, vector<int>(m));
	b= juzheng_change(a);
	int x = cal(ans);
	cout << "转置后的矩阵:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(x)<<b[i][j]<<" ";              //输出
		}
		cout << endl;
	}
}
