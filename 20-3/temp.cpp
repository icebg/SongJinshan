#include<iostream>
using namespace std;
int main()
{
	int x;
	const int a =1000;
	const int* const p = &a;

	int* tmp = (int*)p;
	*tmp = 2000;

	x=a;

	return 0;
}
