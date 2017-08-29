// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
//this queue will contain Customer items

class Customer 
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0;}

	void set ( long when);
	long when() const { return arrive;}
	int ptime() const { return processtime;}
};

typedef Customer Item;

class Queue
{
private:
// class scope definitions
	//Node is a nested structure definition local to this c
	struct Node { Item item; struct Node * next;};  //create a node struct
	enum {Q_SIZE = 10};
// private class member
    Node * front;
	Node * rear;
	int items;
	const int qsize;
	// preemptive definitions to prevent public copying
	Queue(const Queue & q):qsize(0){ };
	Queue & operator=(const Queue & q) { return * this;}
public:
	Queue(int qs = Q_SIZE);     //create queue with a qs limit
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &item);    //add item to end
	bool dequeue(Item &item);
};
#endif