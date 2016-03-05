#include "keynode.hpp"
#include <cstring>
#include <string>

using namespace std;

Keynode::Keynode(char* key, long int offset){
	setKey(key);
	this->offset = offset;
}
Keynode::Keynode(){
}
Keynode::~Keynode(){
}
string Keynode::getKey()const{
	string retval(key);
	return retval;
}
long int Keynode::getOffset()const{
	return offset;
}
void Keynode::setOffset(long int offset){
	this->offset = offset;
}
void Keynode::setKey(char* key){
	strcpy(this->key, key);
}