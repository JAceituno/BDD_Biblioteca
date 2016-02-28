#pragma once

class Editorial{
  public:
	Editorial(char* id, char* nombre, char* direccion);
	~Editorial();
	char* getId()const;
	char* getNombre()const;
	char* getDireccion()const;
	void setId();
	void setNombre();
	void setDireccion();
  private:
  	char* id;
  	char* nombre;
  	char* direccion;	
	
};