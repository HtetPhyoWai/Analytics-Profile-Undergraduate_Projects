#pragma once

#include "cls_stack_s.hpp"
#include <string>

using namespace std;

namespace Wai
{
	cls_stack::cls_stack() : cls_LinkedList()
	{	}
	
	cls_stack::cls_stack(const cls_stack& inSourceLL) : cls_LinkedList(inSourceLL)
	{	}

	void cls_stack::push(long PayloadValue)
	{
		if (this->size() == _maximum_size)
		{
		throw ERROR_STACK_OVERFLOW();
		}
		else
		{
			this->add_node(at_head, PayloadValue);
			_top = this->head();

		}
	
	}
	
	long cls_stack::pop(void)
	{
		long returnpayload = NULL;

		if (this->size() == 0 )
		{
			throw ERROR_STACK_UNDERFLOW();

		}
		else
		{
			returnpayload = *this->_top->payload;
			this->remove_node(_top);
			_top = this->head();

			
		}
		return returnpayload;
	}


	void cls_stack::Maximum_size(int max)
	{
		_maximum_size = max;
	}
	int cls_stack::Maximum_size(void)
	{
		return _maximum_size;
	}

	cls_LL_node* cls_stack::top()
	{
		return this->head();
	}

	void cls_stack::display_stack()
	{
		this->display_list(from_head, vertical);
	}

}