#include <iostream>
#include <string>
#include <queue>

using std::cout; 
using std::cin; 
using std::endl; 
using std::string;

struct PrinterJob
{
	string filename; 
	int pageCount;

	PrinterJob(string filename, int pageCount)
		:filename(filename), pageCount(pageCount)
	{};

	bool operator < (const PrinterJob& otherJob) const
	{
		return this->pageCount < otherJob.pageCount; 
		//assign jobs with higher page count a higher priority 
	}
	//note the const - needed for compatability with std::priority_queue
};


/*->pass by value - so no modification of original queue
->a function named `printTheQueue` that prints a print queue :)
*/
void printTheQueue(std::priority_queue<PrinterJob> printQueue)
{
	while (!printQueue.empty())
	{
		cout << printQueue.top().filename
			<< "\t"
			<< printQueue.top().pageCount << endl;
		//note the `top` -> not `front` (as in std::queue)
		printQueue.pop(); 
	}
}


int main()
{
	//assign jobs with LOWER page count a higher priority 
	//(because the job will finish faster and get out of the way)
	std::queue<int> q; 
	
	srand(time(0)); 

	PrinterJob firstJob{ "birds.doc", rand() % 100};
	//(using random page count)
	PrinterJob secondJob{ "silt.txt", rand() % 100 };
	PrinterJob thirdJob{ "dictionary.doc", rand() % 100 };

	std::priority_queue<PrinterJob> printQueue; 	
	printQueue.push(firstJob); 
	//`push` generates MSVC error C2676!
	// can overload < operator to specify "ordering criterion"
	
	printQueue.push(secondJob);
	printQueue.push(thirdJob);

	printTheQueue(printQueue); 



	return 0; 
}