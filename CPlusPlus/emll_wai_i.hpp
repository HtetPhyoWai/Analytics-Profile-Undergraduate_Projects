#pragma once
#include "emll_wai_s.hpp"
#include <string>
#include <iostream>
#include <fstream>

namespace Wai {

	

	// ****************************** PUBLIC *********************************

	// ******* Constructors and Operators
	cls_LinkedList::cls_LinkedList() 
	{
		//empty constructor - there is nothing to initialize upon constructor call
	}

	cls_LinkedList::cls_LinkedList(const cls_LinkedList& inSourceLL) {
		//Copy Consturctor (Deep Copy method) is required for all object ASSIGMENTS, PASSISNG AS BY VALUE ARGUMENT, SEH is used and required when class utilizes dynamic memory and pointers
		//NOTE: this-> always referes to the current, active linked list
		cls_LL_node* target_NODE = nullptr;

		target_NODE = inSourceLL._tail;
		while (target_NODE != nullptr) {
			this->addnodeattail(*target_NODE->payload);
			target_NODE = target_NODE->previous;
		}
	}

	cls_LinkedList& cls_LinkedList::operator =(const cls_LinkedList& rhsSourceLL) {
		//Assignment (=) operator to allow assignment of 1 linked list to another using the DEEP COPY approach
		//NOTE: this-> always referes to the current, active linked list
		cls_LL_node* lhsLLTarget_NODE = nullptr;
		
		lhsLLTarget_NODE = rhsSourceLL._tail;
		while (lhsLLTarget_NODE != nullptr) {
			this->addnodeattail(*lhsLLTarget_NODE->payload);
			lhsLLTarget_NODE = lhsLLTarget_NODE->previous;
		}
		return *this;
	}
	// ******* Constructors and Operators

	// ******* Getters
	cls_LL_node* cls_LinkedList::head(void) 
	{
		//head getter
		return _head;
	}

	cls_LL_node* cls_LinkedList::tail(void)
	{
		//tail getter
		return _tail;
	}

	bool cls_LinkedList::is_empty(void) 
	{
		//return content state of the list
		bool is_empty_retval = true;
		//if the HEAD pointer and TAIL pointer is NULL then the list is empty
		if (_head == nullptr && _tail == nullptr) {
			is_empty_retval = true;
		}
		else {
			is_empty_retval = false;
		}
		return is_empty_retval;
	}

	int cls_LinkedList::size(void) 
	{
		//tail getter
		return _size;
	}
	// ******* Getters

	// ******* Node Instantiation and Finders, Traverser
	void cls_LinkedList::add_node(addlocation ListPosition, long PayloadValue)
	{
		switch (ListPosition) {
		case at_head:
			addnodeathead(PayloadValue);
			break;
		case inorder:
			addnodeinorder(PayloadValue);
			break;
		case at_tail:
			addnodeattail(PayloadValue);
			break;
		}
	}
	// ******* Node Instantiation

	// ******* Node Finders, Traverser, Removers
	
	cls_LL_node* cls_LinkedList::find_node(long PayloadValueToFind) 
	{

		return findnode(PayloadValueToFind);
	}

	bool cls_LinkedList::remove_node(cls_LL_node* ptr2node) 
	{

		return removenode(ptr2node);
	}

	bool cls_LinkedList::remove_node(long PayloadToRemove) 
	{

		return removenode(findnode(PayloadToRemove));
	}
	// ******* Node Finders, Traverser, Removers

	// ******* LIST I/O -- Console displayer, saver, retriever
	void cls_LinkedList::display_list(direction PrintDirection, printorientation PrintOrientation) 
	{

		displaylist(PrintDirection, PrintOrientation);
	}

	bool cls_LinkedList::save(std::string foutNAME, fileformat fformat)
	{

		bool retval = false;
		return savelisttofile(foutNAME, fformat);
	}

	bool cls_LinkedList::retrieve(std::string finNAME, fileformat fformat, addlocation listloadmethod)
	{
		return retrievefromfile(finNAME, fformat, listloadmethod);
	}
	// ******* LIST I/O -- Console displayer, saver, retriever

	// ******* LIST Destructor
	cls_LinkedList::~cls_LinkedList() {

		destroylinkedlist();
	}
	// ******* LIST Destructor

	// ************************************************************************

	// ****************************** PRIVATE *********************************


bool cls_LinkedList::destroylinkedlist() 
{
		//helper to destroy the payloads, nodes, and list
		bool destroylist_retval = false;
		cls_LL_node* currentnode = _tail;
		if (_head != nullptr && _tail != nullptr) {//the list has no nodes 
			while (currentnode != nullptr)
			{
				cls_LL_node* nodetodelete = currentnode;
				delete nodetodelete->payload;
				currentnode = currentnode->previous;
				delete nodetodelete;
				_size = _size - 1; //decrement the list size
			}
		}
		_head = NULL;
		_tail = NULL;
		destroylist_retval = true;

		return destroylist_retval;
}

bool cls_LinkedList::removenode(cls_LL_node* nodetodelete) 
{
		//helper to remove a specific node based on its pointer address
		bool removenode_retval = false;
		if (nodetodelete == nullptr || _size == 0) {
			removenode_retval = false;
		}
		else {
			if (nodetodelete == _head) {
				if (nodetodelete->next != nullptr) { //there is only a single head node in the list
					nodetodelete->next->previous = nullptr;
				}
				_head = nodetodelete->next;
			}
			else if (nodetodelete == _tail) {
				if (nodetodelete->previous != nullptr) { //there is only a sindle tail node in the list
					nodetodelete->previous->next = nullptr;
				}
				_tail = nodetodelete->previous;
			}
			else {
				//node to delete is between two nodes
				nodetodelete->next->previous = nodetodelete->previous;
				nodetodelete->previous->next = nodetodelete->next;
			}

			delete nodetodelete->payload;
			delete nodetodelete;
			_size = _size - 1; //decrement the list size
			removenode_retval = true;
		}
		return removenode_retval;
}

	bool cls_LinkedList::removenode(long payloadtoremove)
	{
		//helper to remove a specific node based on its payload value

		/*  pseudocode algorithm

		declare variable "removenode_retval" of type bool and initialize to false to store operation status
		declare pointer to cls_LL_node "nodetoremove" = nullptr
		nodetoremove = findnode(payloadtoremove)
		return removenode(nodetoremove)

		** end pseudocode algorithm*/
		bool removenode_retval = false;
		cls_LL_node* notetoremove = nullptr;
		
		notetoremove = findnode(payloadtoremove);
		
		return removenode(notetoremove);

	}

	cls_LL_node* cls_LinkedList::findnode(long payloadtofind) 
	{
		//help to find the first node based on its payload value

		/*  pseudocode algorithm

		declare variable "found" of type bool and initialize to false
		declare pointer to cls_LL_node "foundnodeADDR" and initialize to nullptr
		declare pointer to cls_LL_node "currentnode" and initialize to HEAD

		while the currentnode != nullptr and found == false
			if pointer to currentnode->payload == payload to find then
				foundnodeADDR = currentnode
				found = true
			end if
			assign currennode = currentnode->next
		end while

		return foundnodeADDR

		** end pseudocode algorithm*/

		bool found = false;
		cls_LL_node* foundnodeADDR = nullptr;
		cls_LL_node* currentnode = _head;

		while (currentnode != nullptr && found == false)
		{
			if (*currentnode->payload == payloadtofind)
			{
				foundnodeADDR = currentnode;
				found = true;
			}
			currentnode = currentnode->next;
		}
		return foundnodeADDR;

	}

	void cls_LinkedList::addnodeathead(long PayloadValue) 
	{
		//add a node at the HEAD of the list

		/*  pseudocode algorithm

		declare a pointer to cls_LL_node "newLLnode" dymanically allocate a new instance
		assign newLLnode->payload = dynamically a new instance of a long(payload)

		if HEAD = nullptr then
			HEAD=newLLnode
			TAIL=newLLnode
		else
		  HEAD->previous = newLLnode
		  newLLnode->next = HEAD
		  HEAD = newLLNode
		end if

		increment size

		** end pseudocode algorithm  */
		
		cls_LL_node* newLLnode = new cls_LL_node();
		newLLnode->payload = new long (PayloadValue);


		if (_head == nullptr)
		{
			_head = newLLnode;
			_tail = newLLnode;
		}
		else
		{
			_head->previous = newLLnode;
			newLLnode->next = _head;
			_head = newLLnode;
		}

		_size = _size + 1;
		

	}

	void cls_LinkedList::addnodeattail(long PayloadValue) 
	{
		//add a node at the TAIL of the list

		/*  pseudocode algorithm

		declare a pointer to cls_LL_node "newLLnode" and dymanically allocate a new instance
		assign newLLnode->payload = dynamically allocate a new instance of a long(payload)

		if TAIL = nullptr then
			HEAD=newLLnode
			TAIL=newLLnode
		else
		  TAIL->next = newLLnode
		  newLLnode->previous = TAIL
		  TAIL = newLLNode
		end if

		increment size

		** end pseudocode algorithm*/
	
		cls_LL_node* newLLnode = new cls_LL_node();
		newLLnode->payload = new long (PayloadValue);
		

		if (_tail == nullptr) 
		{
			_head = newLLnode;
			_tail = newLLnode; 
		}
		else   
		{
			_tail->next = newLLnode;
			newLLnode->previous = _tail;
			_tail = newLLnode;
		}
	
		_size = _size + 1;

	}

	void cls_LinkedList::addnodeinorder(long PayloadValue) 
	{
		//add a new node to the list at the HEAD if PayloadValue <= HEAD->Payload
		//add a new node to the list at the TAIL if PayloadValue >= Tail->Payload
		//otherwise add a new node to the list between FoundNode and FoundNode->NEXT === FoundNode <-> NewNode <-> FoundNode->Next


		/*  pseudocode algorithm

		if HEAD=nullptr or PayloadValue <= pointer to HEAD->payload then
		  addnodeathead(PayloadValue)
		else if TAIL=nullptr or PayloadValue >= pointer to TAIL->payload then
		  addnodeattail(PayloadValue)
		else
		 declare variable "POSFound" of type bool and initialize to false


		 declare a pointer to cls_LL_node "foundnodeInssertPOS" = HEAD
		 while foundnodeInsertPOS != nullptr and POSFound=false
		  if PayloadValue >= pointer to foundnodeINSERTPOS->payload and PayloadValue <= pointer to foundnodeInsertPost->next->payload then
			declare a pointer to cls_LL_node "newLLnode" and dymanically allocate a new instance
			assign newLLnode->payload = dynamically allocate a new instance of a long(payload)

			assign newLLnode->next = foundnodeInsertPOS->next
			assign newLLnode->previous = foundnodeInsertPOS
			assign foundnodeInsertPOS->next-previous = newLLnode
			assign foundnodeInsertPOS->next = newLLnode
			POSFound = true
			increment size
		  end if

		  foundnodeInsertPOS = foundnodeInsertPOS->next
		 end while
		** end pseudocode algorithm	*/
		
		if ((_head == nullptr) || (PayloadValue <= *_head->payload) )
		{
			addnodeathead(PayloadValue);
		}
		else if ((_tail == nullptr) || (PayloadValue >= *_head->payload))
		{
			addnodeattail(PayloadValue);
		}
		else
		{
			bool POSFound = false;

			cls_LL_node* foundnodeInssertPOS = _head;

			while ((foundnodeInssertPOS != nullptr) && (POSFound = false))
			{
				if ((PayloadValue >= *foundnodeInssertPOS->payload) && (PayloadValue <= *foundnodeInssertPOS->next->payload))
				{
					cls_LL_node* newLLnode =new cls_LL_node();
					
					newLLnode->payload = new long(PayloadValue);

					newLLnode->next = foundnodeInssertPOS->next; 
					newLLnode->previous = foundnodeInssertPOS;

					foundnodeInssertPOS->next->previous = newLLnode;
					foundnodeInssertPOS->next = newLLnode;
					
					POSFound = true;
					
					_size = _size + 1;

				}
				foundnodeInssertPOS = foundnodeInssertPOS->next;
			}
		
		}

		

		
		
	}

	void cls_LinkedList::displaylist(direction PrintDirection, printorientation PrintOrientation) 
	{
		//helper to display list nodes' payload values to console given specified direction and orientation
		cls_LL_node* startnode = nullptr;
		cls_LL_node* nodetodisplay = nullptr;
		char delimiter = ' ';

		if (PrintDirection == from_head && PrintOrientation == vertical) {
			startnode = _head;
			delimiter = '\n';
		}
		else if (PrintDirection == from_head && PrintOrientation == horizontal) {
			startnode = _head;
			delimiter = ' ';
		}
		else if (PrintDirection == from_tail && PrintOrientation == vertical) {
			startnode = _tail;
			delimiter = '\n';
		}
		else if (PrintDirection == from_tail && PrintOrientation == horizontal) {
			startnode = _tail;
			delimiter = ' ';
		}
		nodetodisplay = startnode;

		if (PrintDirection == from_head) {
			while (nodetodisplay != nullptr) {
				std::cout << *nodetodisplay->payload << delimiter;
				nodetodisplay = nodetodisplay->next;
			}
			std::cout << std::endl;
		}
		else if (PrintDirection == from_tail) {
			while (nodetodisplay != nullptr) {
				std::cout << *nodetodisplay->payload << delimiter;
				nodetodisplay = nodetodisplay->previous;
			}
			//append end line to output for final separation
			std::cout << std::endl;
		}
	}

	/* 
	------------- *
		Binary file formats	are used to save the values of variables in their native binary format as opposed to their text representation.In other words,
		a long data type value will be saved in a text file in a format that humans can read and understand; the value 2938727 is a text representation
		of a LONG, but not internally a LONG value;  recall we have	to convert the text or string representation of the value by converting and assigning
		it to a variable declared as a LONG data type.When we save a LONG to a binary formatted file, we save the actual internal representation of the LONG
		value just like it is stored in the variable.This, when we look at a "binary" file, we cannot actually identify the value saved since it is represented
		in its native binary format.
	* ------------- */

	bool cls_LinkedList::savelisttofile(std::string foutNAME, fileformat fformat) 
	{
		/* ------------- *
		//helper to save the entire list to either a TEXT or BINARY file
		This is a helper method to save each nodes' payload value to either a TEXT or BINARY file
		The savelisttomfile method for each file type works similarly - they
		open a file in the designed format
		 -iterate over the LIST while the current node !=null
		 -write the payload data value to the file
		 -close file
		* ------------- */

		bool retval = false;
		std::ofstream fout;
		fout.exceptions(std::ifstream::failbit); //enable stream failbit for explicit SEH of file operations

		switch (fformat) {
		case text:
			try {
				fout.open(foutNAME); //default FileFormat is TEXT
				cls_LL_node* outnode = _head;
				while (outnode != nullptr) {
					fout << *outnode->payload << std::endl;
					outnode = outnode->next;
				}
				fout.close();
				retval = true;
			}
			catch (std::exception ex) {
				throw ex;
			}
			catch (const std::ios_base::failure &err) {
				throw err;
			}
			break;
		case binary:
			try {
				cls_LL_node* outnode = _head;
				long temppayload = 0;
				fout.open(foutNAME, std::ios_base::binary); //set the FileFormat to binary
				while (outnode != nullptr) {
					//writes the actual binary value stored in memory and not "text" - thus writes the number of bytes given "size of the data type" starting at its memory location
					fout.write(reinterpret_cast<const char *>(outnode->payload), sizeof(*outnode->payload));
					outnode = outnode->next;
				}
				fout.close();
				retval = true;
			}
			catch (std::exception ex) {
				throw ex;
			}
			catch (const std::ios_base::failure &err) {
				throw err;
			}
			break;
		}
		return retval;
	}
	bool cls_LinkedList::retrievefromfile(std::string finNAME, fileformat fformat, addlocation listloadmethod) {
		/* ------------- *
		This is a helper method to create a new list using payload values retrieved from a TEXT or BINARY file
		The retrivefromfile method for each file type works similarly - they
		open a file in the designed format
		 -iterate over the file while !EOF
		 -read in the payload data value
		 -add new node to list with designated load method, and payload value
		 -close file
		* ------------- */

		bool retval = false;
		std::ifstream fin;
		fin.exceptions(std::ifstream::failbit); //enable stream failbit for explicit SEH of file operations

		std::string strvalueIN = "";
		long payloadvalueIN = 0;

		switch (fformat) {
		case text:
			try {
				fin.open(finNAME); //default FileFormat is TEXT
				while (!fin.eof()) {
					getline(fin, strvalueIN);
					if (strvalueIN.length() > 0) {
						payloadvalueIN = stol(strvalueIN);
						this->add_node(listloadmethod, payloadvalueIN);
					}
				}
				retval = true;
			}
			catch (std::exception ex) {
				throw ex;
			}
			catch (const std::ios_base::failure &err) {
				throw err;
			}
			break;
		case binary:
			try {
				cls_LL_node* outnode = _head;
				fin.open(finNAME, std::ios_base::binary); //set the FileFormat to binary
				fin.seekg(0, std::ios::beg);
				while (!fin.eof()) {
					//reads the actual binary value (nubmer of bytes) given "size of the data type" and not its "text" representation - NO "stol(var)" needed
					fin.read(reinterpret_cast<char*>(&payloadvalueIN), sizeof(long));
					this->add_node(listloadmethod, payloadvalueIN);
				}
				fin.close();
				retval = true;
			}
			catch (...) {

			}
			break;
		}
		return retval;
	}


	// ************************************************************************
}
