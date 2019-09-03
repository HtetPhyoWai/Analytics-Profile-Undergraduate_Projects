#pragma once

namespace Wai {

	template <class K, class V>
	class BST_node {

	public:
		BST_node();
		BST_node(K, V);

		BST_node(BST_node<K, V>&);
		BST_node<K, V>& operator = (const BST_node<K, V>&);


		BST_node<K, V>* left(void);
		BST_node<K, V>* right(void);
		BST_node<K, V>* parent(void);
		void left(BST_node<K, V>*);
		void right(BST_node<K, V>*);
		void parent(BST_node<K, V>*);

		K key(void);
		void key(K);
		V value(void);
		void value(V);

		~BST_node();

	private:
		K* _key = nullptr;
		V* _value = nullptr;
		BST_node<K, V>* _parent = nullptr;
		BST_node<K, V>* _left = nullptr;
		BST_node<K, V>* _right = nullptr;

		K get_key(void);
		void set_key(K);
		V get_value(void);
		void set_value(V);

		void set_left(BST_node<K, V>*);
		void set_right(BST_node<K, V>*);
		void set_parent(BST_node<K, V>*);
		BST_node<K, V>* get_left(void);
		BST_node<K, V>* get_right(void);
		BST_node<K, V>* get_parent(void);

		void allocate_keyvalue(K, V);

	};

	template <class K, class V>
	class cls_BST {
	public:
		enum SearchOrder { preorder, inorder, postorder };
		enum DisplayOrder { ascending, descending };
		enum DisplayDirection { horizontal, vertical };

		cls_BST<K, V>();
		cls_BST<K, V>(bool);

		bool insert(K key, V value);
		bool remove(K key);

		BST_node<K, V>* find_key(K key);
		BST_node<K, V>* find_value(V value);

		BST_node<K, V>* root(void);
		BST_node<K, V>* parent(BST_node<K, V>*);
		BST_node<K, V>* successor(BST_node<K, V>*);
		BST_node<K, V>* predecessor(BST_node<K, V>*);

		int tree_height(BST_node<K, V>*);
		BST_node<K, V>* minimum(void);
		BST_node<K, V>* maximum(void);
		int tree_size();
		bool is_empty(void);
		void display(SearchOrder, DisplayOrder, DisplayDirection);

		~cls_BST();

	private:
		BST_node<K, V>* _root = nullptr;
		bool _allowduplicates = true;
		int _treesize = 0;

		bool insert_new_node_iterate(K key, V value, BST_node<K, V>*);
		BST_node<K, V>* insert_new_node_recursion(K, V, BST_node<K, V>*);

		bool remove_node(K, BST_node<K, V>*);
		BST_node<K, V>* find_node_key_recursion(K key, BST_node<K, V>*);
		BST_node<K, V>* find_node_key_iterate(K key, BST_node<K, V>*);
		BST_node<K, V>* find_node_value(V value, BST_node<K, V>*);
		BST_node<K, V>* get_successor(BST_node<K, V>* currentnode);
		BST_node<K, V>* get_predecessor(BST_node<K, V>* currentnode);
		int get_tree_height(BST_node<K, V>* currentnode);

		BST_node<K, V>* get_minimum_key(BST_node<K, V>*);
		BST_node<K, V>* get_maximum_key(BST_node<K, V>*);

		void display_tree(BST_node<K, V>*, SearchOrder, DisplayOrder, DisplayDirection);

		void destroy_tree(BST_node<K, V>*);
	};

	class EXCEPTION_ATTEMPT_TO_READ_VALUE_NULLPOINTER {};
	class EXCEPTION_ATTEMPT_TO_READ_KEY_NULLPOINTER {};
	class EXCEPTION_KEY_ALREADY_EXISTS_NO_DUPLICATE_KEYS_ALLOWED {};
	class EXCEPTION_ATTEMPT_TO_DELETE_ROOT {};
}