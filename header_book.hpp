#pragma once

#include "book.hpp"

class HeaderBook{
  public:
	HeaderBook();
	~HeaderBook();
	bool isDirty();
	void setDirty();
	long int getOffset();
	void setOffset(long int);

  	const int SIZE_OF_RECORD = sizeof(Book);	
  	int REC_COUNT;
  private:
  	bool dirty;
  	long int offset;
};