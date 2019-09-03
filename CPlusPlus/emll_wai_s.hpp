#pragma once
#include <iostream>
#include <fstream>
#include <string>




namespace Wai 
{
	/* ------------- *
	The class "cls_LL_node" is purely a data class with each member data items declared as pointers.
	This class is completely managed and manipulated by the cls_LinkedList class - creation and destruction of nodes and payload is performed by cls_LinkedList methods
	Given the cls_LL_node contains pointers to "next" and "previous" we can use this node class to offer construction of singly and doubly linked list
	and circular LL with modifications to methods in the cls_LinkedList class.
	* ------------- */

	
	class cls_LL_node
	{
	public:
		/*+*/ cls_LL_node* next = nullptr ;
		/*+*/ cls_LL_node* previous = nullptr ;
		/*+*/ long* payload;

		friend class cls_Linkedlist;
	};

	/* ------------- *
	The cls_LinkedList is the definition of the Linked List.  A linked list class is responsible for construction, traversal, manipulation, and destruction of
	linked nodes.  The majority of the public members are simply interfaces to the detailed private helper methods that perform all the actual work.  This
	structural code arrangement (encapsulation and data hiding) permits significant code reuse within the class and offers ready customization of operations
	in future "child" (polymorphism) classes.
	* ------------- */

	class cls_LinkedList 
	{

	public:
		/* ------------- *
		The use of enumerated data types permit us to allow ease of use specification for where a new node is added to the list, the direction of the traversal of lists
		in which order and orientation a list should be displayed on the console, and even the format file for saving and retrieving lists from persistent file storage.
		Note: the file formats of "text" and "binary" have been specified.  The "text" format should be familiar to you.  The "binary" format is likely new.  See the
		details on this in the SAVE/Retrieve implementation file discussion.
		* ------------- */
		enum addlocation { at_head, inorder, at_tail }; //designates how to add a linked list node
		enum direction { from_head, from_tail }; //designates direction by which to iterate over linked list nodes
		enum printorientation { vertical, horizontal }; //designates how to display link link list payload
		enum fileformat { binary, text };

		cls_LinkedList(); //default constructor for create the linked list (not nodes)
		cls_LinkedList(const cls_LinkedList&); //Copy Constructor permitting ASSIGMENT of 1 linked list to another using DEEP copy method
		cls_LinkedList& operator =(const cls_LinkedList&); //assignment (=) operator to assignment of 1 linked list to another

		cls_LL_node* head(); //GETTER returns pointer to the head (front) node of the linked list
		cls_LL_node* tail(); //GETTER returns pointer to the tail (end) node of the linked list

		bool is_empty(); //return content state of list
		int size();	//return the size (number of nodes) in the list

		void add_node(addlocation, long); //add a node to the linked list designating location in list 
//		cls_LL_node* find_node(long); //return pointer to the first node in the list based on its payload value or nullptr if NONE found
//		bool remove_node(cls_LL_node*); //remove a specific node from the last based on its pointer address - return true or false indicating removal status
//		bool remove_node(long); //remove a specific node from the last based on its payload value - return true or false indicating removal status
	
		void display_list(direction, printorientation); //display payload of all link list nodes starting from designated direction and displaying either all on 1 line with space separater (horizontal) or 1 per line (vertical)
		bool save(std::string, fileformat); //save Linked List payload to a text or binary file
		bool retrieve(std::string, fileformat, addlocation); //retrieve Linked List payload and construct Link List from a text or binary file

//		~cls_LinkedList(); //destructor for the linked list - delete all node payloads and node comprising the list

	private:
		/*=*/	cls_LL_node* _head = nullptr; //pointer to the HEAD of the list
		/*=*/	cls_LL_node* _tail = nullptr; //pointer to the TAIL of the list
		/*=*/	int _size = 0; //stores the size (number of nodes in list) 

	
	//helper methods to do the grunt work...

//		/*+*/	bool destroylinkedlist(); //helper to destroy the payloads, nodes, and list - returns T/F for status of completion		
//		/*+*/	bool removenode(cls_LL_node*); //helper to remove a specific node based on its pointer address - returns T/F for status of completion
//		/*+*/	bool removenode(long); //helper to remove a specific node based on its payload value  - returns T/F for status of completion
//		/*+*/	cls_LL_node* findnode(long); //helper to find a node based on its payload value - returns pointer address of the found node
//		/*+*/	void addnodeathead(long); //add a node at the HEAD of the list
		/*+*/	void addnodeattail(long); //add a node at the TAIL of the list
//		/*+*/	void addnodeinorder(long); //add a node to the list in ORDER of its payload value



		/*=*/	void displaylist(direction, printorientation); //helper to display list nodes' payload values to console given specified direction and orientation
		/*=*/	bool savelisttofile(std::string, fileformat); //helper to save the entire list to either a TEXT or BINARY file
		/*=*/	bool retrievefromfile(std::string, fileformat, addlocation); //helper to create new list and retrieve the entire list from a TEXT or BINARY file
	};

}



