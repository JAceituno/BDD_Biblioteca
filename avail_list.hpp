#pragma once

#include <vector>

using namespace std;

class avail_list{
  public:
	avail_list();
	~avail_list();
  private:
  	int pop();
  	int peek();
  	void push(int integer);
  	void queue(int integer);
  	int dequeue();
};