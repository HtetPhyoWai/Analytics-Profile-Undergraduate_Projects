#pragma once

#include "cls_queue_s.hpp"
#include <string>

using namespace std;

namespace Wai
{
	cls_queue::cls_queue() : cls_LinkedList()
	{	}

	cls_queue::cls_queue(const cls_queue& inSourceLL) : cls_LinkedList(inSourceLL)
	{	}


	void cls_queue::enqueue(long PayloadValue)
	{
		this->add_node(at_tail, PayloadValue);
		_front = this->head();
		_back = this->tail();
	}


	long cls_queue::dequeue(void)
	{
		long returnpayload = NULL;

		returnpayload = *this->_front->payload;
		this->remove_node(_front);
		_front = this->head();


		return returnpayload;
	}


	cls_LL_node* cls_queue::front()
	{
		return this->head();
	}
	cls_LL_node* cls_queue::back()
	{
		return this->tail();
	}
	void cls_queue::display_queue()
	{
		this->display_list(from_head, vertical);
	}

}

