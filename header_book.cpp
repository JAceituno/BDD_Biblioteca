#include "header_book.hpp"

HeaderBook::HeaderBook(){
	this->dirty = true;
	this->REC_COUNT = 0;
	this->offset = -1;
}
HeaderBook::~HeaderBook(){

}
bool HeaderBook::isDirty(){
	return dirty;
}
void HeaderBook::setDirty(bool dirty){
	this->dirty = dirty;
}
long int HeaderBook::getOffset(){
	return offset;
}
void HeaderBook::setOffset(long int offset){
	this->offset = offset;
}