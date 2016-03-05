#pragma once
#include <string>

using namespace std;


class Book{

  public:
  	Book();
	Book(char* isbn,char* nombre,char* autor,char* id_editorial);
	~Book();
	string getIsbn()const;
	string getNombre()const;
	string getAutor()const;
	string getId_editorial()const;
	bool isMarked();
	void setMarked(bool);
	int getMark();
	void setMark(long int);
	void setIsbn(char* isbn);
	void setNombre(char* nombre);
	void setAutor(char* autor);
	void setId_editorial(char* id_editorial);
  private:
  	char isbn[18];
  	char nombre[30];
  	char autor[30];
  	char id_editorial[18];
  	bool marked;
  	long int mark;
};