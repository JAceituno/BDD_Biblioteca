#pragma once
#include <string>

using namespace std;

class Editorial{
  public:
	Editorial(char* id, char* nombre, char* direccion);
	Editorial();
	~Editorial();
	string getId()const;
	string getNombre()const;
	string getDireccion()const;
	bool isMarked();
	int getMark();
	void setMark(long int);
	void setMarked(bool);
	void setId(char*);
	void setNombre(char*);
	void setDireccion(char*);
  private:
  	char id[18];
  	char nombre[50];
  	char direccion[50];	
	bool marked;
	long int mark;
};