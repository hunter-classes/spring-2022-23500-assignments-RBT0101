#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

TEST_CASE("Testing Stack"){
	Stack *stack0 = new Stack();
	//TESTING PUSH METHOD
	stack0->push(3);
	CHECK(stack0->top() == 3);
	
	stack0->push(4);
	CHECK(stack0->top() == 4);
	
	stack0->push(5);
	CHECK(stack0->top() == 5);
	
	//TESTING POP METHOD
	CHECK(stack0->pop() == 5);
	CHECK(stack0->pop() == 4);
	CHECK(stack0->pop() == 3);
	
	//TESTING ISEMPTY METHOD
	CHECK(stack0->is_empty() == true);
}

TEST_CASE("Testing Queue of Size 4"){
	//TESTING FRONT METHOD
	Queue *queue0 = new Queue();
	queue0->enqueue(1);
	
	Queue *queue1 = new Queue();
	queue1->enqueue(5);
	
	Queue *queue2 = new Queue();
	queue2->enqueue(9);
		
	CHECK(queue0->front() == 1);
	CHECK(queue1->front() == 5);
	CHECK(queue2->front() == 9);
	
	Queue *queue3 = new Queue();
	queue0->enqueue(2);
	queue0->enqueue(3);
	queue0->enqueue(4);

	//TESTING DEQUEUE AND IS_EMPTY AND IS_FULL METHODS
	CHECK(queue0->is_full());
	CHECK(queue0->dequeue() == 1);
	CHECK(queue0->dequeue() == 2);
	CHECK(queue0->dequeue() == 3);
	CHECK(queue0->dequeue() == 4);
	CHECK(queue0->is_empty());
}



