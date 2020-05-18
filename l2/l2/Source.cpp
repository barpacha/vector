#include "vector.cpp"
#include <iostream>

void main()
{
	Vector<int> a;
	a.push_back(1);
	a.push_back(2);
	for (Vector<int>::Iterator b = a.begin(); b != a.end(); b++)
		std::cout << *b << std::endl;
	system("pause");

}