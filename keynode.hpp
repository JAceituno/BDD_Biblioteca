#pragma once

class Keynode{
  public:
  	Keynode();
	Keynode(char* key, long int offset);
	~Keynode();
	char* getKey()const;
	long int getOffset()const;
	void setOffset(long int);
	void setKey(char*);
  private:
  	char* key;
  	long int offset;
};