#include <iostream>
#include <vector>


int main()
{
	std::vector<int> i;
	i.push_back(1);
	i.push_back(2);
	i.push_back(3);
	for (auto a : i)
	{
		std::cout << a << "\n";
	};
	return 0;
}
