//字符串逆置
#include<iostream>
#include<string>
using namespace std;
void reverse(char *s, char *t)//使用地址的原因是，数组存储数据地址是连续的
{
	char c;
	if (s < t)
	{
		c = *s;
		*s = *t;
		*t = c;
		reverse(++s,--t);//先参数运算然后进行函数，在设置参数时便可进行参数运算，
	}
}
void reverse(char* s)
{

	reverse(s, s + strlen(s) - 1);//分别代表首个和尾个字符的地址
}
void main()
{

	char str1[20];
	cout << "输入一个字符串：";
	cin >> str1;
	cout << "原字符串为：" << str1 << endl;
	reverse(str1);
	cout << "倒序反转后：" << str1 << endl;
}


//计算一句英语句子的字母总数
int tj(string &b)//函数构造
{
	int count = 0;
	for (int i = 0; i <= b.length(); i++)
	{
		if ((b[i] >= 'A'&&b[i] <= 'Z') || (b[i] >= 'a'&&b[i] <= 'z'))
			count += 1;
	}
	return count;
}
int main()
{
	string a;
	cout << "请输入一条英语句子" << endl;
	getline(cin, a);
	cout << "计算结果是：" << tj(a)<< endl;;
	return 0;
}
