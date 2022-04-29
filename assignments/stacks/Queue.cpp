#include <iostream>
#include "Queue.h"

Queue::Queue()
{
	head = 0;
	tail = 0;
	full = false;
}

void Queue::enqueue(int data)
{
	if (is_full()) return;
	else{
		arr[tail] = data;
		tail++;
		
		if (tail >= 4) full = true;
		tail = tail%4;
	}
}

int Queue::dequeue()
{
	if (is_empty() && !full) return -1;	//-1 if queue is empty
	else{
		int output = arr[head];
		arr[head] = 0;
		head++;
		head = head % 4;
		
		full = false;
		return output;
	}
}

int Queue::front()
{
	if (is_empty()) return -1; //-1 if queue is empty
	else{
		return arr[head];
	}
}

bool Queue::is_empty()
{
	return (head == tail);
}

bool Queue::is_full()
{
	return full;
}

std::string Queue::to_string(){
	std::string output = "";
	for (auto v : arr){
		output = output + std::to_string(v) + " ";
	}
	
	return output;
}
