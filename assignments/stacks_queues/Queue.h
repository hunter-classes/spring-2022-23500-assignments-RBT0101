#pragma once 

class Queue
{
	private:
		int arr[4];
		int head;
		int tail;
		bool full;
	public:
		Queue();
		void enqueue(int d);
		int dequeue();
		int front();
		bool is_empty();
		bool is_full();
		std::string to_string();
};

