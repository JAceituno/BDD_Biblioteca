#pragma once

#include "editorial.hpp"

class HeaderEditorial{
  public:
	HeaderEditorial();
	~HeaderEditorial();
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