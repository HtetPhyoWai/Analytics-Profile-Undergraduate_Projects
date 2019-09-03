#include "emll_wai_i.hpp"
#include <iostream>
using namespace std;

int main() 
{

	Wai::cls_LinkedList mLL;

//	mLL.add_node(mLL.at_head, 1);
//	mLL.add_node(mLL.at_head, 2);
//	mLL.add_node(mLL.at_head, 3);
//	mLL.display_list(mLL.from_head, mLL.horizontal);
//	mLL.remove_node(1);
//	mLL.remove_node(2);
//	mLL.remove_node(3);
//	cout << mLL.size();

	mLL.add_node(mLL.at_tail, 100);
	mLL.add_node(mLL.at_tail, 200);
	mLL.add_node(mLL.at_tail, 300);
	cout << "Size after adding at tail " << mLL.size() << endl;
//	mLL.remove_node(100);
//	mLL.remove_node(200);
//	mLL.remove_node(300);
//	cout << mLL.size();
	mLL.display_list(mLL.from_head, mLL.horizontal);


//	mLL.add_node(mLL.inorder, 3);
	//mLL.display_list(mLL.from_tail, mLL.horizontal);
//	mLL.add_node(mLL.inorder, 55);
	//mLL.display_list(mLL.from_tail, mLL.horizontal);
//	mLL.add_node(mLL.inorder, 99);
//	mLL.add_node(mLL.inorder, 7);
	//mLL.display_list(mLL.from_tail, mLL.horizontal);
//	mLL.add_node(mLL.inorder, 44);
//	mLL.add_node(mLL.inorder, 6);
//	mLL.add_node(mLL.inorder, 3);
//	mLL.add_node(mLL.inorder, 99);
//	cout << "SIZE = " << mLL.size() << endl;

//	mLL.remove_node(99);
//	cout << "HEAD = " << mLL.head() << endl;
//	mLL.remove_node(mLL.head());
//	cout << "SIZE = " << mLL.size() << endl;
//	cout << "HEAD = " << mLL.head() << endl;
//	mLL.remove_node(mLL.head());
//	cout << "SIZE = " << mLL.size() << endl;
//	cout << "HEAD = " << mLL.head() << endl;
//	mLL.remove_node(mLL.tail());
//	cout << "SIZE = " << mLL.size() << endl;
//	cout << "TAIL = " << mLL.tail() << endl;

	//cout << "TAIL = " << mLL.tail() << endl;

	//cout << "Payload = " << *mLL.head()->next->payload << endl;

	cout << "From HEAD to TAIL " << endl;
	mLL.display_list(mLL.from_head, mLL.horizontal);
	mLL.display_list(mLL.from_head, mLL.vertical);
	cout << "From TAIL to HEAD " << endl;
	mLL.display_list(mLL.from_tail, mLL.horizontal);
	mLL.display_list(mLL.from_tail, mLL.vertical);


	//cout << "SAVE List Staus = "  << mLL.save("MiriLL01.txt", mLL.text) << endl;
	Wai::cls_LinkedList infileLL01;
	try {
		/*infileLL01.retrieve("miriLL01.txt", infileLL01.text, infileLL01.inorder);
		cout << "List of NODE Data after reading in TEXT file = miriLL01.txt" << endl;
		infileLL01.display_list(infileLL01.from_head, infileLL01.vertical);
	*/

	/*Wai::cls_LinkedList infileLL02;
	infileLL02 = infileLL01;
	infileLL01.add_node(infileLL01.inorder, 28);
	infileLL02.add_node(infileLL02.inorder, 128);
	cout << "List of NODE Data after copying infileLL02 = infileLL01" << endl;
	infileLL01.display_list(infileLL01.from_head, infileLL01.vertical);
	infileLL02.display_list(infileLL02.from_head, infileLL02.vertical);*/

		Wai::cls_LinkedList binfileLLDataOUT;
		Wai::cls_LinkedList binfileLLDataIN;

		binfileLLDataOUT.add_node(binfileLLDataOUT.inorder, 500);
		binfileLLDataOUT.add_node(binfileLLDataOUT.inorder, 100);
		binfileLLDataOUT.add_node(binfileLLDataOUT.inorder, 300);
		cout << "Write LIST Node Data to BINARY FILE " << endl;
		binfileLLDataOUT.save("miriLLdataBINARY.bin", binfileLLDataOUT.binary);

		cout << "Read & Display LIST Node Data from BINARY FILE " << endl;
		binfileLLDataIN.retrieve("miriLLdataBINARY.bin", binfileLLDataIN.binary, binfileLLDataIN.inorder);
		binfileLLDataIN.display_list(binfileLLDataIN.from_head, binfileLLDataIN.vertical);
	}
	catch (exception e) 
	
	{
		cerr << "   ***  File NOT FOUND or other FILE IO Error == " << e.what() << "   ***" << endl;
	}
	/*cout << "REMOVE NODE " << endl;
	mLL.remove_node(7);

	cout << "HEAD = " << mLL.head() << endl;
	cout << "TAIL = " << mLL.tail() << endl;
	cout << "SIZE = " << mLL.size() << endl;
	mLL.display_list(mLL.from_head, mLL.horizontal);*/

	/*Wai::cls_LL_node* startNODE = mLL.head();
	cout << "This is the LIST from MAIN - from head to tail" << endl;
	while (startNODE != nullptr) {
		cout << *startNODE->payload << " - ";
		startNODE = startNODE->next;
	}
	cout << endl;

	startNODE = mLL.tail();
	cout << "This is the LIST from MAIN - from tail to head" << endl;
	while (startNODE != nullptr) {
		cout << *startNODE->payload << " - ";
		startNODE = startNODE->previous;
	}
	cout << endl;
*/
}
