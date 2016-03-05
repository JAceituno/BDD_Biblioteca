#include "header_editorial.hpp"
#include "editorial.hpp"

HeaderEditorial::HeaderEditorial(){
	this->dirty = true;
	this->REC_COUNT = 0;
	this->offset = -1;
	this->SIZE_OF_RECORD = sizeof(Editorial);
}
HeaderEditorial::~HeaderEditorial(){

}
bool HeaderEditorial::isDirty(){
	return dirty;
}
void HeaderEditorial::setDirty(bool dirty){
	this->dirty = dirty;
}
long int HeaderEditorial::getOffset(){
	return offset;
}
void HeaderEditorial::setOffset(long int offset){
	this->offset = offset;
}