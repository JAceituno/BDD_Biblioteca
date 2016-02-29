#include "editorial.hpp"
#include <cstring>

using namespace std;

Editorial::Editorial(char* id, char* nombre, char* direccion){
	setId(id);
	setNombre(nombre);
	setDireccion(direccion);
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
void Editorial::setId(){
	this->id = new char[18];
	strcpy(this->id,id);
}
void Editorial::setNombre(){
	this->nombre = new char[30];
	strcpy(this->nombre,nombre);
}
void Editorial::setDireccion(){
	this->direccion = new char[30];
	strcpy(this->direccion,direccion);
}