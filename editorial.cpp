#include "editorial.hpp"
#include <cstring>

using namespace std;

Editorial::Editorial(char* id, char* nombre, char* direccion){
	setId(id);
	setNombre(nombre);
	setDireccion(direccion);
	marked = false;
	mark = -1;
}
Editorial::Editorial(){
	
}
Editorial::~Editorial(){
	
}
string Editorial::getId()const{
	string retvalue(id);
	return retvalue;
}
string Editorial::getNombre()const{
	string retvalue(nombre);
	return retvalue;
}
string Editorial::getDireccion()const{
	string retvalue(direccion);
	return retvalue;
}
void Editorial::setId(char* id){
	strcpy(this->id,id);
}
void Editorial::setNombre(char* nombre){
	strcpy(this->nombre,nombre);
}
void Editorial::setDireccion(char* direccion){
	strcpy(this->direccion,direccion);
}
bool Editorial::isMarked(){
	return marked;
}
void Editorial::setMarked(bool marked){	
	this->marked = marked;
}
long int Editorial::getMark(){
	if(marked)
		return mark;
}
void Editorial::setMark(long int mark){
	if(marked){
		this->mark = mark;
	}
}