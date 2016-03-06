#include "book.hpp"
#include <cstring>
#include <string>

using namespace std;

Book::Book(char* isbn,char* nombre,char* autor,char* id_editorial){
	setIsbn(isbn);
	setNombre(nombre);
	setAutor(autor);
	setId_editorial(id_editorial);
	marked = false;
	mark = -1;
}
Book::Book(){
	
}
Book::~Book(){
	
}
string Book::getIsbn()const{
	string retval(isbn);
	return retval;
}
string Book::getNombre()const{
	string retval(nombre);
	return retval;
}
string Book::getAutor()const{
	string retval(autor);
	return retval;
}
string Book::getId_editorial()const{
	string retval(id_editorial);
	return retval;
}
void Book::setIsbn(char* isbn){
	strcpy(this->isbn,isbn);
}
void Book::setNombre(char* nombre){
	strcpy(this->nombre,nombre);
}
void Book::setAutor(char* autor){
	strcpy(this->autor,autor);
}
void Book::setId_editorial(char* id_editorial){
	strcpy(this->id_editorial,id_editorial);
}
bool Book::isMarked(){
	return marked;
}
void Book::setMarked(bool marked){
	this->marked = marked;
}
int Book::getMark(){
	if(marked)
		return mark;
}
void Book::setMark(long int mark){
	if(marked){
		this->mark = mark;
	}
}