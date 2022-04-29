#include <iostream>
#include <vector>
#include "Stack.h"
#include "Node.h"
#include "Queue.h"

int main(){
	//STACK
	//push method
	std::cout << "TESTING PUSH METHOD" << "\n";
	Stack *stack0 = new Stack();
	std::cout << "pushing Node with data value '3' to stack0" << "\n";
	stack0->push(3);
	std::cout << "stack0 current size: " << stack0->getSize() << "\n";
	std::cout << "stack0 elements: " << stack0->to_string() << "\n";
	std::cout << "\n";
	
	std::cout << "pushing Node with data value '4' to stack0" << "\n";
	stack0->push(4);
	std::cout << "stack0 current size: " << stack0->getSize() << "\n";
	std::cout << "stack0 elements: " << stack0->to_string() << "\n";
	std::cout << "\n";
		
	std::cout << "pushing Node with data value '5' to stack0" << "\n";
	stack0->push(5);
	std::cout << "stack0 current size: " << stack0->getSize() << "\n";
	std::cout << "stack0 elements: " << stack0->to_string() << "\n";
	std::cout << "\n";
		
	std::cout << "pushing Node with data value '6' to stack0" << "\n";
	stack0->push(6);
	std::cout << "stack0 current size: " << stack0->getSize() << "\n";
	std::cout << "stack0 elements: " << stack0->to_string() << "\n";
	std::cout << "\n";
		
	//pop method
	std::cout << "TESTING POP METHOD" << "\n";
	std::cout << "popping top element" << "\n";
	stack0->pop();
	std::cout << "stack0 current size: " << stack0->getSize() << "\n";
	std::cout << "stack0 elements: " << stack0->to_string() << "\n";
	std::cout << "\n";
	
	std::cout << "popping top element" << "\n";
	stack0->pop(); 
	std::cout << "stack0 current size: " << stack0->getSize() << "\n";
	std::cout << "stack0 elements: " << stack0->to_string() << "\n";
	std::cout << "\n";
	
	//Exception Handling Message
	std::cout << "TESTING POP METHOD EXCEPTION HANDLING (STACK SIZE IS 0)" << "\n";
	Stack *stackException = new Stack();
	std::cout << "stack1 current size: " << stackException->getSize() << "\n";
	std::cout << "stack1 elements: " << stackException->to_string() << "\n";
	std::cout << "popping top element (return value of -1 means an exception is caught)" << "\n";
	std::cout << stackException->pop() << "\n"; //Exception Message should appear in console
	std::cout << "\n";
		
	//Top method + Exception Handling Messages
	std::cout << "TESTING TOP METHOD" << "\n";
	Stack *stackException1 = new Stack();
	std::cout << "stack2 current size: " << stackException1->getSize() << "\n";
	std::cout << "stack2 elements: " << stackException1->to_string() << "\n";
	std::cout << "retrieving data value for top element..." << "\n";
	std::cout << stackException1->top() << "\n";
	std::cout << "\n";
		
	std::cout << "pushing Node with data value '50' to stack2" << "\n";
	stackException1->push(50);
	std::cout << "stack2 current size: " << stackException1->getSize() << "\n";
	std::cout << "stack2 elements: " << stackException1->to_string() << "\n";
	std::cout << "retrieving data value for top element (return value of -1 means an exception is caught)" << "\n";
	std::cout << stackException1->top() << "\n";
	std::cout << "\n";
	
	//Deleting Stacks
	std::cout << "Deleting stack0" << "\n";
	delete stack0;
	std::cout << "stack0 current size: " << stack0->getSize() << "\n";
	std::cout << "stack0 elements: " << stack0->to_string() << "\n";
	std::cout << "\n";
	
	std::cout << "Deleting stack1" << "\n";
	delete stackException;
	std::cout << "stack1 current size: " << stackException->getSize() << "\n";
	std::cout << "stack1 elements: " << stackException->to_string() << "\n";
	std::cout << "\n";
	
	std::cout << "Deleting stack2" << "\n";
	delete stackException1;
	std::cout << "stack2 current size: " << stackException1->getSize() << "\n";
	std::cout << "stack2 elements: " << stackException1->to_string() << "\n";
	std::cout << "\n";
	
	//QUEUE
	std::cout << "TESTING QUEUE OF SIZE 4" << "\n";
	Queue *queue = new Queue();
	std::cout << "Enqueuing integers '1', '2', '3', and '4' to queue" << "\n";
	queue->enqueue(1);
	queue->enqueue(2);
	queue->enqueue(3);
	queue->enqueue(4);
	std::cout << "Printing queue ";
	std::cout << queue->to_string() << "\n";
	std::cout << "\n";
	
	std::cout << "Dequeuing each integer one by one until queue is empty" << "\n";
	queue->dequeue();
	std::cout << "Printing queue ";
	std::cout << queue->to_string() << "\n";
	
	queue->dequeue();
	std::cout << "Printing queue ";
	std::cout << queue->to_string() << "\n";
	
	queue->dequeue();
	std::cout << "Printing queue ";
	std::cout << queue->to_string() << "\n";
	
	queue->dequeue();
	std::cout << "Printing queue ";
	std::cout << queue->to_string() << "\n";
	return 0;
}	

