#include "cls_stack_i.hpp"
#include <iostream>
using namespace std;

int main()
{
	try {
		Wai::cls_stack mLL;

		mLL.push(1);
		mLL.push(2);
		mLL.push(3);
		cout << "Displaying Stack: " << endl;
		mLL.display_stack();
		cout << endl << endl;
		mLL.pop();
		mLL.pop();
		mLL.pop();
		mLL.pop();
		cout << "Displaying Stack(after Pop): " << endl;
		mLL.display_stack();
		//	cout << "SIZE = " << mLL.size() << endl;
	}
	catch (Wai::ERROR_STACK_OVERFLOW ex)
	{
		cerr << "STACK IS FULL!" << endl;
	}
	catch (Wai::ERROR_STACK_UNDERFLOW ex)
	{
		cerr << "STACK IS EMPTY!" << endl;

	}
	catch (...)
	{
		cerr << "ERROR" << endl;
	}


}