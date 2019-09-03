#pragma once
#include "emll_wai_i.hpp"

using namespace std;

namespace Wai
{
	class cls_queue :public cls_LinkedList
	{
	public:
		cls_queue();
		cls_queue(const cls_queue&);

		using cls_LinkedList::operator=;


		void enqueue(long);
		long dequeue(void);

		cls_LL_node* front();
		cls_LL_node* back();

		void display_queue();

	private:
		cls_LL_node* _front = NULL;
		cls_LL_node* _back = NULL;
	};




}