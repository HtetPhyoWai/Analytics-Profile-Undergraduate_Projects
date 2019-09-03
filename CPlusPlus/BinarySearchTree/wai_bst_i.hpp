#pragma once
using namespace std;

#include "wai_bst_s.hpp"
#include <string>
#include <iostream>

namespace Wai
{

	//	public:
	template <class K, class V>
	BST_node<K, V>::BST_node<K, V>() {
		allocate_keyvalue({}, {});
	};

	template <class K, class V>
	BST_node<K, V>::BST_node<K, V>(K key, V value) {
		allocate_keyvalue(key, value);
	};

	template <class K, class V>
	BST_node<K, V>::BST_node(BST_node<K, V>& INcopynode) {

		this->allocate_keyvalue(INcopynode.key(), INcopynode.value());
		this->parent(INcopynode.parent());
		this->left(INcopynode.left());
		this->right(INcopynode.right());

	};

	template <class K, class V>
	BST_node<K, V>& BST_node<K, V>::operator = (const BST_node<K, V>& lhsnode) {
		BST_node<K, V> assignedNode;
		assignedNode = allocate_keyvalue(*lhsnode->key(), *lhsnode->value());
		assignedNode->parent = lhsnode.parent();
		assignedNode->left = lhsnode.left();
		assignedNode->right = lhsnode.right();

		return assignedNode;
	};

	template <class K, class V>
	BST_node<K, V>* BST_node<K, V>::parent(void) {
		return get_parent();
	};

	template <class K, class V>
	void BST_node<K, V>::parent(BST_node<K, V>* parentnode) {
		set_parent(parentnode);
	};

	template <class K, class V>
	BST_node<K, V>* BST_node<K, V>::left(void) {
		return get_left();
	};

	template <class K, class V>
	BST_node<K, V>* BST_node<K, V>::right(void) {
		return get_right();
	};

	template <class K, class V>
	void BST_node<K, V>::left(BST_node<K, V>* leftnode) {
		set_left(leftnode);
	};

	template <class K, class V>
	void BST_node<K, V>::right(BST_node<K, V>* rightnode) {
		set_right(rightnode);
	};


	template <class K, class V>
	void BST_node<K, V>::key(K key) {
		set_key(key);
	};

	template <class K, class V>
	K BST_node<K, V>::key(void) {
		return get_key();
	};

	template <class K, class V>
	V BST_node<K, V>::value(void) {
		return get_value();
	};

	template <class K, class V>
	void BST_node<K, V>::value(V inVAL) {
		set_value(inVAL);
	};

	template <class K, class V>
	BST_node<K, V>::~BST_node() {
		delete _key;
		_key = nullptr;
		delete this->_value;
		_value = nullptr;
	};

	// **************	private:   **************

		//private key getter
	template <class K, class V>
	K BST_node<K, V>::get_key(void) {

		/* Begin algorithm

		if key != null then
				return pointer to key
			else
			 throw EXCEPTION_ATTEMPT_TO_READ_KEY_NULLPOINTER()
			endif

		* END algorithm*/

			if (_key != NULL)
			{
				return *_key;
			}
	
			else 
			{
			throw EXCEPTION_ATTEMPT_TO_READ_KEY_NULLPOINTER();
			}

	};

	//private value getter
	template <class K, class V>
	V BST_node<K, V>::get_value(void) {

		/* Begin algorithm

				if value != null then
						return pointer to value
					else
					 throw  EXCEPTION_ATTEMPT_TO_READ_VALUE_NULLPOINTER()
					endif

		* END algorithm*/
		if (_value != NULL)
		{
			return *_value;
		}
		else
		{
			throw EXCEPTION_ATTEMPT_TO_READ_VALUE_NULLPOINTER();
		}
	};

	//private value setter
	template <class K, class V>
	void BST_node<K, V>::set_key(K inKey) {
		/* Begin algorithm

		  pointer to key = inKey

		* END algorithm*/

		*_key = inKey;

	};

	template <class K, class V>
	void BST_node<K, V>::set_value(V inVAL) {
		/* Begin algorithm

			pointer to value = inValue

		* END algorithm*/

		*_value = inVAL;

	};

	template <class K, class V>
	void BST_node<K, V>::set_left(BST_node<K, V>* leftnode) {
		/* Begin algorithm

				left = leftnode

		* END algorithm*/


		_left = leftnode;

	};

	template <class K, class V>
	void BST_node<K, V>::set_right(BST_node<K, V>* rightnode) {
		/* Begin algorithm

			   right = rightnode

		* End algorithm */

		_right = rightnode;

	};

	template <class K, class V>
	void BST_node<K, V>::set_parent(BST_node<K, V>* parentnode) {
		/* Begin algorithm

			parent = parentnode

		* End algorithm */

		_parent = parentnode;

	};

	template <class K, class V>
	BST_node<K, V>* BST_node<K, V>::get_left(void) {
		/* Begin algorithm

			return left

		* End algorithm */


		return _left;

	};

	template <class K, class V>
	BST_node<K, V>* BST_node<K, V>::get_right(void) {

		/* Begin algorithm

			return right

		* End algorithm */


		return _right;

	};


	template <class K, class V>
	BST_node<K, V>* BST_node<K, V>::get_parent(void) {

		/* Begin algorithm

				return parent

			* End algorithm */

		return _parent;


	};

	//private key,value allocator-called by constructor(k,v)
	template <class K, class V>
	void BST_node<K, V>::allocate_keyvalue(K key, V value) {

		/* Begin algorithm

			this->key = dynamic allocate new K(key)
			this->value = dynamic allocate new V(value)

		* End algorithm */

		this->_key = new K(key);
		this->_value = new V(value);


	};



	//***** END BST_NODE ******************************************************

	//***** BEGIN cls_BST ***********************************************************

	//Public:

	template <class K, class V>
	cls_BST<K, V>::cls_BST<K, V>() {
		_root = nullptr;
		_allowduplicates = true;
	};

	template <class K, class V>
	cls_BST<K, V>::cls_BST<K, V>(bool allowduplicates) {
		_root = nullptr;
		_allowduplicates = allowduplicates;
	};

	template <class K, class V>
	bool cls_BST<K, V>::is_empty(void) {
		return !_root;
	};

	template <class K, class V>
	int cls_BST<K, V>::tree_size(void) {
		return _treesize;
	};

	template <class K, class V>
	int cls_BST<K, V>::tree_height(BST_node<K, V>* node) {
		return get_tree_height(node);
	};

	template <class K, class V>
	bool cls_BST<K, V>::insert(K key, V value) {
		if (!_allowduplicates && find_node_key_recursion(key, _root) != nullptr) {
			throw EXCEPTION_KEY_ALREADY_EXISTS_NO_DUPLICATE_KEYS_ALLOWED();
		}
		return insert_new_node_recursion(key, value, _root);
		//return insert_new_node(key, value,_root); //** Keep for testing purposes this is the iterative version
	};

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::root(void) {
		return _root;
	};

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::parent(BST_node<K, V>* currentnode) {
		return currentnode->parent();
	};

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::successor(BST_node<K, V>* startnode) {
		return get_successor(startnode);
	};

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::predecessor(BST_node<K, V>* startnode) {
		return get_predecessor(startnode);
	};

	template <class K, class V>
	bool cls_BST<K, V>::remove(K key) {
		return remove_node(key, _root);
	};

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::find_key(K key) {
		return find_node_key_recursion(key, _root);
	};

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::find_value(V value) {
		return find_node_value(value, _root);
	};

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::minimum(void) {
		return get_minimum_key(_root);
	};

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::maximum(void) {
		return get_maximum_key(_root);
	};

	template <class K, class V>
	void cls_BST<K, V>::display(SearchOrder SO, DisplayOrder DO, DisplayDirection DD) {
		if (!this->is_empty()) {
			display_tree(_root, SO, DO, DD);
		}
		else {
			std::cout << "Tree is empty" << std::endl;
		}
	};

	template <class K, class V>
	cls_BST<K, V>::~cls_BST() {
		destroy_tree(this->_root);
	};

	//***** cls_BST *****
	//*****  PRIVATE ******

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::insert_new_node_recursion(K key, V value, BST_node<K, V>* rootIN) 
	{
		/* Begin algorithm

			Delcate newnode as BSTNode<Template> pointer = null
			if rootIN = null then
				newnode = dynamic allocate new BSTNode<Template>(key,value)
				if (root = null then
					root = newnode
				endif
				increment treesize
				return newnode
			else if key <= rootIN->key
				Delcate tempnode as BSTNode<Template> pointer = insert_new_node_recursion(key,valye,rootIN->left)
				set tempnode->parent = rootIN
				set rootIN->left = tempnode
			else
				Delcate tempnode as BSTNode<Template> = insert_new_node_recursion(key,valye,rootIN->left)
				set tempnode->parent = rootIN
				set rootIN->right = tempnode
			endif

			// End algorithm */
		//BST_node<K, V>* currentnode = _root;
		//BST_node<K, V>* parentnode = nullptr;
		//

		BST_node<K, V>* newnode = nullptr;

		if (rootIN == NULL)
		{
			newnode = new BST_node<K, V>(key, value);


			if (_root == NULL)
			{
				_root = newnode;
			}	
			_treesize++;
			return newnode;
		}
		else if (key <= rootIN->key())
		{
			BST_node<K, V>* tempnode = insert_new_node_recursion(key, value, rootIN->left());
			tempnode->parent(rootIN) ;
			rootIN->left(tempnode) ;
		}
		else
		{
			BST_node<K, V>* tempnode = insert_new_node_recursion(key, value, rootIN->right());
			tempnode->parent(rootIN) ;
			rootIN->right(tempnode) ;
		}	



	};//END insert_new_node_recursion

	//**************************** Below is iterative version of the insert_new_node algorithm **************************
	template <class K, class V>
	bool cls_BST<K, V>::insert_new_node_iterate(K key, V value, BST_node<K, V>* rootIN) {
		bool retval = false;
		BST_node<K, V>* currentnode = _root;
		BST_node<K, V>* parentnode = nullptr;
		BST_node<K, V>* newnode = new BST_node<K, V>(key, value);

		if (currentnode == nullptr) {
			_root = newnode;
			retval = true;
			_treesize++;
		}
		else {
			currentnode = _root;

			while (currentnode != nullptr) {
				parentnode = currentnode;
				if (newnode->key() <= currentnode->key()) {
					currentnode = currentnode->left();
				}
				else {
					currentnode = currentnode->right();
				}
			}
			if (newnode->key() == parentnode->key()) {
				throw EXCEPTION_KEY_ALREADY_EXISTS_NO_DUPLICATE_KEYS_ALLOWED();
			}
			else if (newnode->key() <= parentnode->key()) {
				newnode->parent(parentnode);
				parentnode->left(newnode);
				retval = true;
				_treesize++;
			}
			else {
				newnode->parent(parentnode);
				parentnode->right(newnode);
				retval = true;
				_treesize++;
			}
		}
		return retval;
	};//END insert_new_node_iterate
	//*****************************************************************************************

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::find_node_key_recursion(K key, BST_node<K, V>* rootIN) {

		/* Begin algorithm

			if rootIN = null then
				return null
			endif

			if key <= rootIN->key
				return find_key_node_recursion(key, rootIN->left)
			else if key > rootIN->key then
				return find_key_node_recursion(key, rootIN->right)
			else
				return rootIN
			endif

		//* End algorithm */
		if (rootIN == NULL) 
		{
			return NULL;
		}

			if (key < rootIN->key())
			{
				return find_node_key_recursion(key, rootIN->left());
			}
			else if (key > rootIN->key())
			{ 
				return find_node_key_recursion(key, rootIN->right());
			}
			else
			{
				return rootIN;
			}
		

	};//END find_node_key_recursion

//**************************** Below is iterative version of the find_node_key algorithm **************************
	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::find_node_key_iterate(K key, BST_node<K, V>* rootIN) {
		BST_node<K, V>* currentnode = nullptr;
		BST_node<K, V>* returnnode = nullptr;
		if (rootIN == nullptr) {
			returnnode = _root;
		}
		else {
			currentnode = rootIN;
			while (currentnode != nullptr) {
				//parentnode = currentnode;
				if (key == currentnode->key()) {
					returnnode = currentnode;
					currentnode = nullptr;
				}
				else if (key <= currentnode->key()) {
					currentnode = currentnode->left();
				}
				else {
					currentnode = currentnode->right();
				}
			}
		}
		return returnnode;
	};//END find_node_key_iterate
//************************************************************************

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::find_node_value(V value, BST_node<K, V>* rootIN) {

		/* Begin algorithm

			if rootIN = null then
				return null
			endif

			if value <= rootIN->value
				return find_node_value((value, rootIN->left)
			else if key > rootIN->key then
				return find_node_value((value, rootIN->right)
			else
				return rootIN
			endif

		//* End algorithm */

		if (rootIN == NULL)
		{
			return NULL;
		}

		if (value <= rootIN->value())
		{
			return find_node_value(value, rootIN->left());
		}
		else if (value > rootIN->value())
		{
			return find_node_value(value, rootIN->right());
		}
		else
		{
			return rootIN;
		}

	};//END find_node_value

	template <class K, class V>
	bool cls_BST<K, V>::remove_node(K key, BST_node<K, V>* rootIN) {

		bool retval = false;


			//Base case
		if (rootIN == nullptr) 
		{
				return false;
		}

		if (key < rootIN->key()) 
		{  // data is somewhere in left sub tree.
			return remove_node(key, rootIN->left());
		}
		else if (key > rootIN->key()) { //  data is somewhere in right sub tree.
			return remove_node(key, rootIN->right());
		}
		else 
		{
			// case 1: no children - this is a single leaf
			if (rootIN->left() == nullptr && rootIN->right() == nullptr)
			{
				/* Begin algorithm
					if roonIN != root then
						if rootIN->parent->left = rootIN then
								set rootIN->parent->left = null
						endif
						if rootIN->parent->right = rootIN then
								set rootIN->parent->right = null
						endif
					endif root not null
					else root not null
						root = null
					endelse
					rootIN->Destructor()
					deallocate rootIN
					root = null
					deallocate treesize
					return true
				//* End algorithm */

				if (rootIN != _root)
				{
					if (rootIN->parent->left() = rootIN)
					{
						rootIN->parent->left() = NULL;
					}
					if (rootIN->parent->right() = rootIN)
					{
						rootIN->parent->right() = NULL;
					}

				}
				else 
				{
					_root = NULL;
				}
				rootIN->Destructor();
				delete rootIN;
				root = NULL;
				delete _treesize;
				return true;
			} //end case 1


			// case 2: one child (right)
			else if (rootIN->left() == nullptr)
			{

				/* Begin algorithm

					declare tempnode as BSTNode template pointer = rootIN
					rootIN = rootIN->right

					set rootIN->parent=tempnode->parent
					set rootIN->parent->right = rootIN

					tempnode->Destructor()
					if tempnode = root then
						root=rootIN
						set rootIN->parent = null
					endif
					deallocate tempnode
					tempnode=null
					decrement treesize
					return true

				//* End algorithm */

				BST_node<K, V>* tempnode = rootIN;
				rootIN = rootIN->right();

				rootIN->parent() = tempnode->parent();
				rootIN->parent->right() = rootIN;
				
				tempnode->Destructor();
				
				if (tempnode = _root)
				{
					_root = rootIN;
					rootIN->parent() = NULL;
				}
				delete tempnode;
				tempnode = NULL;
				_treesize--;
				return true;
			}


			// case 3: one child (left)
			else if (rootIN->right() == nullptr)
			{
				/* Begin algorithm

					declare tempnode as BSTNode template pointer = rootIN
					rootIN = rootIN->left
					set rootIN->parent = tempnode->parent
					set rootIN->parent->left = rootIn
					tempnode->Destructor()
					if tempnode = root then
						root = rootIN
						set rootIN->parent = null
					endif
					deallocate tempnode
					tempnode = null
					decrement treesize
					return true
				//* End algorithm */
				BST_node<K, V>* tempnode = rootIN;
				rootIN = rootIN->left();
				rootIN->parent() = tempnode->parent();
				rootIN->parent->left() = rootIN;
				tempnode->Destructor();
				if (tempnode = _root)
				{
					_root = rootIN;
					rootIN->parent() = NULL;
				}
				delete tempnode;
				tempnode = NULL;
				_treesize--;
				return true;
			}


			// case 4: two children
			else 
			{

				/* Begin algorithm

					declare tempnode as BSTNode template pointer = get_maximum_key(rootIN->left)
					set rootIN->key = tempnode->key
					set rootIN->value = tempnode->value
					return remove_node(tempnode->key,rootIN->key)

				//* End algorithm */
				BST_node<K, V>* tempnode = get_maximum_key(rootIN->left());

				rootIN->key() = tempnode->key();
				rootIN->value() = tempnode->value();

				return remove_node(tempnode->key, rootIN->key());
				
			}
		}
	};//END remove_node

	template <class K, class V>
	int cls_BST<K, V>::get_tree_height(BST_node<K, V>* node) 
	{

		/* Begin algorithm

			if node = null then
				return 0
			else
				declare lDepth as integer = tree_height(node->left)
				declare rDepth as integer = tree_height(node->right)

				if ldepth > rdepth then
					return lDepth+1
				else
					return rDepth+1
				endif
			endif

		//* End algorithm */

		if (node == NULL)
		{
			return 0;
		}
		else
		{
			int lDepth = tree_height(node->left());
			int rDepth = tree_height(node->right());

				if (lDepth > rDepth)
				{ 
					return lDepth + 1; 
				}
				else
				{
					return rDepth + 1;
				}
				
		}



	};//END get_tree_height

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::get_minimum_key(BST_node<K, V>* startnode) {

		/* Begin algorithm

			Delcare currentnode as BSTNode<Template> pointer = startnode
			while currentnode->left not null
				currentnode = currentnode->left
			endwhile

			return currentnode

		//* End algorithm */

		BST_node<K, V>* currentnode = startnode;
		while (currentnode->left() != NULL)
		{

			currentnode = currentnode->left();

		}

		return currentnode;


	};//END get_minimum_key

	template <class K, class V>
	BST_node<K, V>* cls_BST<K, V>::get_maximum_key(BST_node<K, V>* startnode) {

		/* Begin algorithm

			Delcare currentnode as BSTNode<Template> pointer = startnode
			while currentnode->right not null
				currentnode = currentnode->right
			endwhile
		return currentnode

		//* End algorithm */


		BST_node<K, V>* currentnode = startnode;

		while (currentnode->right() != NULL)
		{

			currentnode = currentnode->right();

		}

		return currentnode;

	};//END get_maximum_key


	template <class K, class V>
	BST_node<K, V>*  cls_BST<K, V>::get_successor(BST_node<K, V>* startnode) {

		/* Begin algorithm

			if startnode->left not null then
			  return get_minimum_key(startnode-right)
			endif

			Delcare successor as BSTNode<Template> pointer = startnode->parent
			while successor not null AND startnode = successor->right
				startnode = successor
				successor = successor->parent
			endwhile

			return successor

		//* End algorithm */

		if (startnode->right() != NULL)
		{
			return get_minimum_key(startnode->right());
		}

		BST_node<K, V>* successor = startnode->parent();
		while (successor != NULL && startnode == successor->right())
		{
			startnode = successor;
			successor = successor->parent();
		}

		return successor;



	};//END get_successor

	template <class K, class V>
	BST_node<K, V>*  cls_BST<K, V>::get_predecessor(BST_node<K, V>* startnode) {

		/* Begin algorithm

			if startnode-right not null then
			  return get_maximum_key(startnode-left)
			endif

			Delcare predecessor as BSTNode<Template> pointer = startnode->parent
			while predecessor not null AND startnode = predecessor->right
				startnode = predecessor
				predecessor = predecessor->parent
			endwhile

			return predecessor

		//* End algorithm /*/


		if (startnode->right() != NULL)
		{
			return get_maximum_key(startnode->left());
		}

		BST_node<K, V>* predessor = startnode->parent();
		while (predessor != NULL && startnode == predessor->right())
		{
			startnode = predessor;
			predessor = predessor->parent();
		}

		return predessor;


	};//END get_predecessor


	template <class K, class V>
	void cls_BST<K, V>::display_tree(BST_node<K, V>* node, SearchOrder SO, DisplayOrder DO, DisplayDirection DD)
	{

		/* Begin algorithm

			declare count as static integer = 0
			declare delimiter as string = " "

			if displaydirection = vertical then
			 delimter = newline
			endif /*/


			/*/switch (searchorder)
			 begin CASE searchorder = inorder
				if node not null then
					if displayorder = ascending then
					  display_tree(node->left,SO,DO,DD)
					  output node->key + delimter
					  increment count
					  if count = this->treesize then
						count = 0
						output newline
					  endif
					  display_tree(node->right,SO,DO,DD)
					endif
				 else
				   display_tree(node->right,SO,DO,DD)
				   output node->key + delimter
				   increment count
				   if count = this->treesize then
						count = 0
						output newline
				   endif
					display_tree(node->left,SO,DO,DD)
				  endelse
				endif
			  end CASE searchorder = inorder
			  /*/
		static int count = 0;

		string delimiter = " "; 

		

		if (DD == vertical)
			{
				delimiter = '\n' ;
			}


		switch (SO)
		{
		case inorder:
			if (node != NULL)
			{
				if (DO == ascending)
				{
					display_tree(node->left(), SO, DO, DD);
					cout << node->key() << delimiter;
					count++;
					if (count == this->_treesize)
					{
						count = 0;
						cout << '\n' << endl;
					}
					display_tree(node->right(), SO, DO, DD);
				}

				else
				{
					display_tree(node->right(), SO, DO, DD);
					cout << node->key() << delimiter;
					count++;
					if (count == this->_treesize)
					{
						count = 0;
						cout << '\n' << endl;
					}
					display_tree(node->left(), SO, DO, DD);
				}
			}

			break;


			/*/begin CASE searchorder = preorder
			  if node not null then
				  if displayorder = ascending then
					output node->key + delimter
					increment count
					if count = this->treesize then
					  count = 0
					  output newline
					endif
					display_tree(node->left,SO,DO,DD)
					display_tree(node->right,SO,DO,DD)
				  endif
			   else
				 output node->key + delimter
				 increment count
				 if count = this->treesize then
					  count = 0
					  output newline
				  endif
				  display_tree(node->right,SO,DO,DD)
				  display_tree(node->left,SO,DO,DD)
				endelse
			  endif
			end CASE searchorder = preorder
			/*/
		case preorder:
			if (node != NULL)
			{
				if (DO == ascending)
				{
					cout << node->key() << delimiter ;
					count++;

					if (count == this->_treesize)
					{
						count = 0;
						cout << '\n' << endl;
					}
					display_tree(node->left(), SO, DO, DD);
					display_tree(node->right(), SO, DO, DD);
				}
				else
				{

					cout << node->key() << delimiter ;
					count++;
					if (count == this->_treesize)
					{
						count = 0;
						cout << '\n' << endl;
					}
					display_tree(node->right(), SO, DO, DD);
					display_tree(node->left(), SO, DO, DD);

				}
			}

			
			break;
			/*/begin CASE searchorder = postorder
			  if node not null then
				  if displayorder = ascending then
					display_tree(node->left,SO,DO,DD)
					display_tree(node->right,SO,DO,DD)
					output node->key + delimter
					increment count
					if count = this->treesize then
					  count = 0
					  output newline
					endif
				  endif
			   else
				  display_tree(node->right,SO,DO,DD)
				  display_tree(node->left,SO,DO,DD)
				  output node->key + delimter
				  increment count
				  if count = this->treesize then
					  count = 0
					  output newline
				  endif
				endelse
			  endif
			end CASE searchorder = postorder*/

		case postorder:
			if (node != NULL)
			{
				if (DO == ascending)
				{
					display_tree(node->left(), SO, DO, DD);
					display_tree(node->right(), SO, DO, DD);
					cout << node->key() << delimiter;
					count++;

					if (count == this->_treesize)
					{
						count = 0;
						cout << '\n' << endl;
					}

				}
				else
				{
					display_tree(node->right(), SO, DO, DD);
					display_tree(node->left(), SO, DO, DD);
					cout << node->key() << delimiter;
					count++;
					if (count == this->_treesize)
					{
						count = 0;
						cout << '\n' << endl;
					}


				}
			}
			break;
			// end switch(seachorder)/
		}

	


			//* End algorithm */
	};	//END display_tree

		template <class K, class V>
		void cls_BST<K, V>::destroy_tree(BST_node<K, V>* node) {

			/* Begin algorithm

				if node not null then
					destroy_tree(node->left)
					destroy_tree(node->right)
					node->~Destroctor()
					if node = root then
						root = nullptr
					endif

					deallocate node
					node = null

					decrement treesize
				endif

			//* End algorithm */

			if (node != NULL)
			{
				destroy_tree(node->left());
				destroy_tree(node->right());
				node->~BST_node();

				if (node == _root)

				{
					_root = nullptr;
				}

				delete node;
				node = NULL;

				_treesize--;
			}



		}; //END destroy_tree
	
}
//end namespace