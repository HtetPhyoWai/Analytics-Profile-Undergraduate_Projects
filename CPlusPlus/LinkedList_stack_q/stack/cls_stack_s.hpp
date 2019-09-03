#pragma once
#include "emll_wai_i.hpp"

using namespace std;

namespace Wai 
{
	class cls_stack :public cls_LinkedList
	{
	public: 
		cls_stack();
		cls_stack(const cls_stack&);
		
		using cls_LinkedList::operator=;

		void push(long);
		long pop(void);

		void Maximum_size(int);
		int Maximum_size(void);

		cls_LL_node* top();

		void display_stack();

	private:
		cls_LL_node* _top = NULL;
		int _maximum_size = INT_MAX;
	};

	class ERROR_STACK_OVERFLOW{};
	class ERROR_STACK_UNDERFLOW{};



}