
//在限定时间内计算两点间的距离，并核对
#include<iostream>
#include<cmath>
#include<Windows.h>
#include<time.h>
using namespace std;
class point{
public:
	point(int x, int y, int a, int b)
		:x(x), y(y), a(a), b(b){
		cout << "求该两点(" << x << "," << y << ")" << "  " << "(" << a << "," << b << ")的距离\n";
		cout << "你有4秒钟计算答案，计算机将在4秒后给出答案\n";
		Sleep(1000);
		cout << "你还有3秒钟计算答案，计算机将在3秒后给出答案\n";
		Sleep(1000);
		cout << "你还有2秒钟计算答案，计算机将在2秒后给出答案\n";
		Sleep(1000);
		cout << "你还有1秒钟计算答案，计算机将在1秒后给出答案\n";
		Sleep(1000);
		cout << "时间到\n";
		
	}
	friend double dist_cal(const point &q);
private:
	int x, y,a,b;

};
double dist_cal(const point &q){

	return  sqrt(abs((q.x - q.a)*(q.x - q.a)) + abs((q.y - q.b)*(q.y - q.b)));
}

int main()
{
	int x, y, a, b;
	int n = 1;
	while (n)
	{

		cout << "所求的两点的坐标，请计算\n";
		srand(time(NULL));
		x = rand() % 10;
		y = rand() % 10;
		a = rand() % 10;
		b = rand() % 10;
		point A(x, y, a, b);
		cout << "距离为" << dist_cal(A)<<endl<<"请自行核对"<<endl;
		cout << "请选择是否继续(0为退出，其他为继续)";
		cin >> n;
	}
	return 0;
}
