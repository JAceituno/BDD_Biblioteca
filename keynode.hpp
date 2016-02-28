#pragma once

class Keynode{
  public:
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