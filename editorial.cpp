#include "editorial.hpp"
#include <cstring>

using namespace std;

Editorial::Editorial(char* id, char* nombre, char* direccion){
	setId(id);
	setNombre(nombre);
	setDireccion(direccion);
}
Editorial::Editorial(){
	this->id = new char[18];
	this->nombre = new char[30];
	this->direccion = new char[30];
}
Editorial::~Editorial(){
	delete[] this->id;
	delete[] this->nombre;
	delete[] this->direccion;
}
char* Editorial::getId()const{
	return id;
}
char* Editorial::getNombre()const{
	return nombre;
}
char* Editorial::getDireccion()const{
	return direccion;
}
void Editorial::setId(char* id){
	this->id = new char[18];
	strcpy(this->id,id);
}
void Editorial::setNombre(char* nombre){
	this->nombre = new char[30];
	strcpy(this->nombre,nombre);
}
void Editorial::setDireccion(char* direccion){
	this->direccion = new char[30];
	strcpy(this->direccion,direccion);
}
bool Editorial::isMarked(){
	return marked;
}
void Editorial::setMarked(bool marked){
	this->marked = marked;
}