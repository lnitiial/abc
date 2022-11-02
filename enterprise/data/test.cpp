#include <iostream>
using namespace std;

int main(int argc,const char* argv[])
{
	char sex = 1;
	const char* str = sex ? "男":"女";
	cout << str << endl;
}
