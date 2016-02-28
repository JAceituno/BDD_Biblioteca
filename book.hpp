#pragma once


class Book{

  public:
	Book(char* isbn,char* nombre,char* autor,char* id_editorial);
	~Book();
	char* getIsbn()const;
	char* getNombre()const;
	char* getAutor()const;
	char* getId_editorial()const;
	void setIsbn(char* isbn);
	void setNombre(char* nombre);
	void setAutor(char* autor);
	void setId_editorial(char* id_editorial);
  private:
  	char* isbn;
  	char* nombre;
  	char* autor;
  	char* id_editorial;
};