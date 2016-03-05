#pragma once
#include <string>

using namespace std;

class Keynode{
  public:
  	Keynode();
	Keynode(char* key, long int offset);
	~Keynode();
	string getKey()const;
	long int getOffset()const;
	void setOffset(long int);
	void setKey(char*);
  private:
  	char key[18];
  	long int offset;
};