class Employee{
public:
	/*Employee(string name, string place, string city, string code)
		: name(name), place(place), city(city), code(code){}*/
	Employee(){}
	~Employee(){}
	void setName(string n){ name = n; }
	void location(string p){ place = p; }
	void City_name(string c){ city = c; }
	void postcode(string d){ code = d; }
	void display();


private:
	string name, place, city, code;

};
void Employee::display(){
	cout << name << "\t" << place << "\t" << city << "\t" << code;
}
int main()
{
	
	string name, place, city, code;
	cout << "请输入你的姓名、地址、城市和邮政编码\n";
	cin >> name >> place >> city >> code;
	/*Employee e(name,place,city,code);*/
	Employee e;
	e.setName(name);
	e.location(place);
	e.City_name(city);
	e.postcode(code);
	e.display();

	return 0;
}






得到的知识：构造函数若无花括号，则只是声明，需具体实现Employ：：Employ(){}.
            构造函数后的name（name）为初始化
