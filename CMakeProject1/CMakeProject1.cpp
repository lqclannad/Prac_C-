// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"

// 使用命名空间std
// 使用方法 std::xxx << xxx;
using namespace std;

int main()
{
	cout << "Hello CMake。" << endl;
	_if();
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