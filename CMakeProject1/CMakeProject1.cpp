// CMakeProject1.cpp: 定义应用程序的入口点。
//
// 以#开头乃预处理指令
#include "CMakeProject1.h"
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	_add();
	//_while();
	//_if();
	//_hello();
	//_point();
	//_array();
	//_ref();
	//_param_show();
	//_memory();r
	//_class();
	return 0;
}
void _add()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	// use keyboard input two value to put in v1,v2
	std::cin >> v1 >> v2;
	// output the sum of this two value
	std::cout << "The sum of " << v1 << " and " << v2
		<< " is " << v1 + v2 << std::endl;
}

void _while()
{
	int sum = 0, val = 1;
	// 只要val的值小于等于10，while循环就会继续执行
	while (val <= 10) {
		sum += val;
		++val;
	}
	std::cout << "Sum of 1 to 10 inclusive is "
		<< sum << std::endl;
	sum = 0;
	for (int i = -100; i <= 100; i++)
		sum += i;
	cout << "sum is " << sum << endl;
}

void _if()
{
	int currVal = 0, val = 0;
	if (std::cin >> currVal) {
		int cnt = 1;
		while (std::cin >> val) {
			if (val == currVal)
				++cnt;
			else {
				std::cout << currVal << " occurs "
					<< cnt << " times " << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs "
			<< cnt << " times " << std::endl;
	}
}

void _hello()
{
	cout << "Hello CMake." << endl;
	system("pause");
}

void _point()
{
	// point 指针
	int v;
	std::cin >> v;
	int* p;	// 声明指针变量
	p = &v;
	cout << "*p:" << *p << endl;	// *p取值
	cout << "p:" << p << endl;		// p取地址
}

void _array()
{
	// array 数组
	int a[10];
	cout << sizeof(a) << endl;
	double b[5] = { 3.2, 33.12, 5.1, 94.2, 312.4 };
	cout << b[3] << endl;
	cout << b[8] << endl;
	cout << "-----------------" << endl;
	cout << b << endl;
	cout << *b << endl;
	cout << *(b + 1) << endl;
	cout << *(b + 5) << endl;
	cout << "-----------------" << endl;
	int c[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	cout << c[1][2] << endl;
	cout << c[1] << endl;

}

void _ref()
{
	// 引用/别名
	int a = 3;
	double b = 4.1;
	int& m = a;
	double& n = b;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	a = 5;
	b = 3.3;
	cout << "a的别名m:" << m << endl;
	cout << "b的别名n:" << n << endl;
}

// swap the value
void _swap_value(int a, int b)
{
	int z = a;
	a = b;
	b = z;
}

void _swap_point(int* a, int* b)
{
	int z = *a;
	*a = *b;
	*b = z;
}

void _swap_ref(int& a, int& b)
{
	int z = a;
	a = b;
	b = z;
}

void _param_show()
{
	int a = 3, b = 4;
	_swap_value(a, b);
	cout << "a:" << a << ", b:" << b << endl;

	int c = 3, d = 4;
	_swap_point(&c, &d);
	cout << "c:" << c << ", d:" << d << endl;

	int e = 3, f = 4;
	_swap_ref(e, f);
	cout << "e:" << e << ", f:" << f << endl;
}

void _stack()
{
	int* ptr_a = NULL;
	{
		int a = 3;	// 栈中声明一个变量a，当执行出作用域后，变量会被自动清理
		ptr_a = &a;
		cout << "内部:*ptr_a:" << *ptr_a << endl;
	}
	cout << "外部:*ptr_a:" << *ptr_a << endl;
}

void _heap()
{
	int* ptr_a = NULL;
	{
		// 在堆中声明一个变量，初始化值为3，并把该变量的指针传递给ptr_a指针变量
		ptr_a = new int(4);
	}
	cout << "*ptr_a:" << *ptr_a << endl;
	delete ptr_a;	// 如果不执行这句便会造成内存泄漏
}

void _leak() {
	for (int i = 1; i < 1000000; i++) {
		int* a = new int[100000];
		// int a[100000];
		// delete[] a;
		Sleep(1);
	}
}

void _memory()
{
	// _stack();
	// _heap();
	_leak();
}

struct Person
{
	// 默认public、设置成private后外部不能访问、protected权限介于两者之间
//private:
	// 属性
	string name;
	int age;
	//public:
		// 无参构造函数
	Person() {
		this->name = "jjking";
		this->age = 32;
	}

	// 有参构造函数
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	// 内部函数
	void say() {
		cout << this->name << "说我今年" << age << "岁了。" << endl;
	}

	// 析构函数
	~Person() {
		cout << "person对象已被释放" << endl;
	}
};

void _class()
{
	{
		Person* liu = new Person("liu", 21);
		liu->name = "刘泉";
		liu->age = 21;
		liu->say();
	}
	cout << "-----------------------------" << endl;
	{
		Person* quan = new Person("泉", 21);
		quan->say();
		(*quan).say();
	}
	cout << "*****************************" << endl;
}
