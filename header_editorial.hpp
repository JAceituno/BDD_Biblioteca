#pragma once

#include "editorial.hpp"

class HeaderEditorial{
  public:
	HeaderEditorial();
	~HeaderEditorial();
	bool isDirty();
	void setDirty();
	long int getOffset();
	void setOffset(long int);

  	const int SIZE_OF_RECORD = sizeof(Editorial);	
  	int REC_COUNT;
  private:
  	bool dirty;
  	long int offset;
};