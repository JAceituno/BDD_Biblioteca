#pragma once

#include "book.hpp"

class HeaderBook{
  public:
	HeaderBook();
	~HeaderBook();
	bool isDirty();
	void setDirty(bool);
	long int getOffset();
	void setOffset(long int);

  	int SIZE_OF_RECORD;	
  	int REC_COUNT;
  private:
  	bool dirty;
  	long int offset;
};