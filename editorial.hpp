#pragma once

class Editorial{
  public:
	Editorial(char* id, char* nombre, char* direccion);
	Editorial();
	~Editorial();
	char* getId()const;
	char* getNombre()const;
	char* getDireccion()const;
	bool isMarked();
	void setMarked(bool);
	void setId(char*);
	void setNombre(char*);
	void setDireccion(char*);
  private:
  	char* id;
  	char* nombre;
  	char* direccion;	
	bool marked;
};