#include "cls_queue_i.hpp"
#include <iostream>
using namespace std;

int main()
{

		Wai::cls_queue mLL;

		mLL.enqueue(1);
		mLL.enqueue(2);
		mLL.enqueue(3);
		cout << "Displaying Queue(after ENQUEUE): " << endl;
		mLL.display_queue();
		cout << endl << endl;
		mLL.dequeue();

		cout << "Displaying Queue(after DEQUEUE): " << endl;
		mLL.display_queue();
	//	cout << "SIZE = " << mLL.size() << endl;
	

}
