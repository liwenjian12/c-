// queue.cpp -- Queue and Customer methods
#include "queue.h"
#include <cstdlib>      //for rand()

// Queue methods
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

Queue::~Queue()
{
	Node * temp;
	while (front != NULL)
	{
		temp = front;        // save address of front item     
		front = front->next; // reset pointer to next item
		delete temp;         // delete former front
	}
}

bool Queue::isempty()const
{
	return items == 0;
}
bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

// add item to queue
bool Queue::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node;    //create node
// on failure,new throws std::bad_alloc exception
	add->item = item;         //set node pointer
	add->next = NULL;         //or nullptr
	items++;
	if (front == NULL)       //if queue is empty
		front = add;         //place item at front
	else
		rear->next = add;
	rear = add;
	return true;
}

// place front item into item variable and remove from queue
bool Queue::dequeue(Item & item)
{
	if (front == NULL)
	     return false;
	item = front->item ;
	items--;
	Node * temp = front;
	front = front->next ;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
	}
