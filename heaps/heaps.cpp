#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using std::cout; 
using std::cin; 
using std::endl; 
using std::string;


/*MaxHeaps are binary trees where all parent nodes have values greater than their children nodes*/
class MaxHeap
{

};

int getLeftChildIndex(int parentIndex, std::vector<int> arrayBasedTree)
{
	assert((2 * parentIndex) + 1 <= arrayBasedTree.size()); 
	return (2 * parentIndex) + 1; 
}

int getRightChildIndex(int parentIndex, std::vector<int> arrayBasedTree)
{
	assert((2 * parentIndex) + 2 <= arrayBasedTree.size());
	return (2 * parentIndex) + 2;
}

int main()
{
	std::vector<int> maxHeap14_2_a =
	{
						55,
				50,				52,
			25, 10,				11, 5,
		20, 22
	};

	cout << maxHeap14_2_a.at(getRightChildIndex(4, maxHeap14_2_a)) << endl; 

	return 0;
}