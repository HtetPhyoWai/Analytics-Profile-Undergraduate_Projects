#include <iostream>
#include <typeinfo>
#include <string>
#include "wai_bst_i.hpp"

using namespace std;


int main()

{

	try {

		/* ***************** TEST THE BST_Node class...
		
		Wai::BST_node<int, int> node0;

		Wai::BST_node<string, string> node1("Mirielli", "Ed");

		cout << "key= " << node0.key() << " value= " << node0.value() << endl;
		cout << "key= " << node1.key() << " value= " << node1.value() << endl;
		node0.value(node0.value() + 1);
		node0.value(node0.value() + 1);
		node0.value(node0.value() + 1);

		Wai::BST_node<int, int> node01 = node0;

		cout << "key= " << node01.key() << " value= " << node01.value() << endl;
		node01.value(node01.value() + 1);


		node1.value("Edward");
		cout << "Comparing node 0 and node01 after assigning int-values" << endl;
		cout << "key= " << node0.key() << " value= " << node0.value() << endl;
		cout << "key= " << node01.key() << " value= " << node01.value() << endl;
		cout << endl<< "Node1 vale changes from Ed to Edward: " << endl;
		cout << "key= " << node1.key() << " value= " << node1.value() << endl;



		node0.~BST_node();
		node1.~BST_node();
		cout << endl << "Calling Nodes after Destructor " << endl; 
		cout << "key= " << node1.key() << " value= " << node1.value() << endl;
		/*/

		/* Test the BST class... 		*/
		
				Wai::BST_node<int,int>* node3 = nullptr;
				Wai::BST_node<int, int>* node4 = nullptr;
				Wai::cls_BST<int,int> mBST(true); //allow duplicates
//				Wai::cls_BST<int,int> mBST(false); //do not allow duplicates

				int keyarray[] = {20,8,22,4,12,10,10};

				for (int i = 0; i < 7; i++) {
					mBST.insert(keyarray[i], keyarray[i]*3);
				}

				for (int i = 0; i < 7; i++) {
					node3 = mBST.find_key(keyarray[i]);
					cout << node3;
					cout << "  parent= " << node3->parent();
					cout << "  left= " << node3->left();
					cout << "  right= " << node3->right();
					cout << "  key= " << node3->key();
					cout << " value= " << node3->value() << endl;
				}
				cout << "Tree is empty? " << mBST.is_empty() << endl;
				cout << "Tree Size =  " << mBST.tree_size() << endl;
				cout << "Tree Height =  " << mBST.tree_height(mBST.root()) << endl;
				cout << "Minimum Node Value =  " << mBST.minimum()->key() << endl;
				cout << "Maximum Node Value =  " << mBST.maximum()->key() << endl;
				cout << "Root is " << mBST.root() << " Root key = " << mBST.root()->key();
				cout << endl;

				cout << "Tree Height from NODE = " << mBST.find_key(8)->key() << " = " << mBST.tree_height(mBST.find_key(8)) << endl;

				cout << "----------------------" << endl;
				mBST.display(mBST.inorder, mBST.descending, mBST.vertical);
				cout << endl;
				cout << "----------------------" << endl;

				
				node3 = mBST.find_value(136);
				if (node3 != nullptr) {
				cout << "----------------------" << endl;
				cout << "Find node by value..." << endl;
				cout << node3;
				cout << "  parent= " << node3->parent();
				cout << "  key= " << node3->key();
				cout << " value= " << node3->value() << endl;
				cout << "----------------------" << endl;
				}
				else {
					cout << "----------------------" << endl;
					cout << "Find node by value... node value not found." << endl;
					cout << "----------------------" << endl;
				}

				node4 = mBST.find_key(12);
				cout << "successsor of ";
				cout << node4 << " ( " << node4->key() << ")";
				node4 = mBST.successor(node4);
				cout << " is " << node4;
				cout << "  parent= " << node4->parent();
				cout << "  key= " << node4->key();
				cout << " value= " << node4->value() << endl;


				node4= mBST.find_key(8);
				cout << "predecessor of ";
				cout << node4 << " ( " << node4->key() << ")";
				node4 = mBST.predecessor(node4);
				cout << " is " << node4;
				cout << "  parent= " << node4->parent();
				cout << "  key= " << node4->key();
				cout << " value= " << node4->value() << endl;

				mBST.~cls_BST();
//				mBST.display(mBST.inorder, mBST.ascending, mBST.horizontal);

				//*/


	} //end try
	catch (Wai::EXCEPTION_KEY_ALREADY_EXISTS_NO_DUPLICATE_KEYS_ALLOWED e) 
	{
		cerr << "No Duplicate Keys Allowed in Tree." << endl;
	}
	catch (Wai::EXCEPTION_ATTEMPT_TO_READ_VALUE_NULLPOINTER e)
	{
		cerr << "Error Accessing VALUE" << endl;
	}
	catch (Wai::EXCEPTION_ATTEMPT_TO_READ_KEY_NULLPOINTER e) 
	{
		cerr << "Error Accessing KEY" << endl;
	}

	//cls_data<char> mychar('e');
	//cls_data<int> myint(4223);
	//cls_data<float> myfloat(39.4);
	//cls_data<string> mystring("THis is a strng!");
	//cls_data<cls_data<string>> myclass(mystring);
	//cls_data<string> myempty(); //fails on compiler -- must provide a value for initizing the data

	//cout << typeid(mychar.data).name() << " value= " << mychar.data << endl;
	//cout << typeid(myint.data).name() << " value= " << myint.data << endl;
	//cout << typeid(myfloat.data).name() << " value= " << myfloat.data << endl;
	//cout << typeid(mystring.data).name() << " value= " << mystring.data << endl;
	//cout << typeid(myclass.data).name() << " value= " << myclass.data.data << endl;
	//cout << typeid(myempty.data).name() << " value= " << myempty.data << endl;

}
