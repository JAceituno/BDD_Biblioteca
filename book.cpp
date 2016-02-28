#include "book.hpp"
#include <cstring>

using namespace std;

Book::Book(char* isbn,char* nombre,char* autor,char* id_editorial){
	setIsbn(isbn);
	setNombre(nombre);
	setAutor(autor);
	setId_editorial(id_editorial);
}
Book::~Book(){

}
char* Book::getIsbn()const{
	return isbn;
}
char* Book::getNombre()const{
	return nombre;
}
char* Book::getAutor()const{
	return autor;
}
char* Book::getId_editorial()const{
	return id_editorial;
}
void Book::setIsbn(char* isbn){
	this->isbn = new char[18];
	strcpy(this->isbn,isbn);
}
void Book::setNombre(char* nombre){
	this->nombre = new char[30];
	strcpy(this->nombre,nombre);
}
void Book::setAutor(char* autor){
	this->autor = new char[30];
	strcpy(this->autor,autor);
}
void Book::setId_editorial(char* id_editorial){
	this->id_editorial = new char[18];
	strcpy(this->id_editorial,id_editorial);
}