int main()
{
	int m, n;//m表示排，n表示列
	cout << "请输入排数和列数：";
	cin >> m >> n;
	srand((unsigned int)time(NULL));
	vector<int>a(m*n);
	for (int i = 0; i < m*n; i++)
		a[i] = rand() % 100;
	
	cout << "该矩阵为" << endl<< "  " << "A" << "  =" << endl << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "\t"<<"[";
		for (int j = 0; j < n; j++)
		{
			cout << setw(4)<<a[i*n + j];
		}
		cout << "]"<<endl;
	}
	return 0;
}
