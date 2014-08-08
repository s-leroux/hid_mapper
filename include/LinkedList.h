#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <string.h>

template <typename TYPE>
class LinkedList
{
private:
	struct link
	{
		TYPE *item;
		link *next;
	};
	
	link *head;
	link * current;
	
public:
	LinkedList(void);
	~LinkedList(void);
	
	void AddItem(TYPE *item);
	void Reset(void);
	
	void StartEnum(void);
	const TYPE *Enum(void);
};

template <typename TYPE>
LinkedList<TYPE>::LinkedList(void)
{
	head = 0;
	current = 0;
}

template <typename TYPE>
LinkedList<TYPE>::~LinkedList(void)
{
	Reset();
}

template <typename TYPE>
void LinkedList<TYPE>::AddItem(TYPE *item)
{
	link *cur;
	
	cur = new link;
	cur->item = item;
	cur->next = head;
	
	head = cur;
}

template <typename TYPE>
void LinkedList<TYPE>::Reset(void)
{
	link *cur,*next;
	
	cur = head;
	while(cur)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
	
	head = 0;
}

template <typename TYPE>
void LinkedList<TYPE>::StartEnum(void)
{
	current = head;
}

template <typename TYPE>
const TYPE *LinkedList<TYPE>::Enum(void)
{
	if(current==0)
		return 0;
	
	TYPE *item;
	item = current->item;
	current = current->next;
	
	return item;
	
}

#endif
