#include "keynode.hpp"
#include <cstring>

using namespace std;

Keynode::Keynode(char* key, long int offset){
	setKey(key);
	this->offset = offset;
}
Keynode::~Keynode(){
	delete[] this->key;
}
char* Keynode::getKey()const{
	return key;
}
long int Keynode::getOffset()const{
	return offset;
}
void Keynode::setOffset(long int offset){
	this->offset = offset;
}
void Keynode::setKey(char* key){
	char* key = new char[18];
	strcpy(this->key, key);
}