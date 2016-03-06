#include <iostream>
#include <cstdlib>
#include <ctime>
#include "book.hpp"
#include "editorial.hpp"
#include "header_book.hpp"
#include "header_editorial.hpp"
//#include "index_file.hpp"
//#include "keynode.hpp"
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector> 

using namespace std;

int main(int argc, char const *argv[]){
	
	srand(time(0));

	ofstream out_editorial("editorial.dat",ios::out|ios::binary);
	ofstream out_book("book.dat",ios::out|ios::binary);

	HeaderEditorial he;
	HeaderBook hb;

	out_editorial.write((char*)&he,sizeof(HeaderEditorial));
	out_book.write((char*)&hb,sizeof(HeaderBook));


	string nombres_editorial[6][5] = {{"Editorial ","el ","libro ","dorado ","la "},
									{"conocimiento ","poder ","guaymuras ","cualquiera ","el "},
									{"escritor ","alegre ","las ","noches ","de "},
									{"lectura ","leer ","en ","familia ","vacaciones "},
									{"en ","casa ","junto ","chimenea ","feliz "},
									{"oro ","misterio ","cuando ","vuelves ","escorpion "}};

	string direccion_editorial[6][5] = {{"cuarta ","quinta ","sexta ","septima ","octava "},
									{"entrada ","salida ","bloque ","casa ","calle "},
									{"blvd ","contiguo ","atras ","en frente ","al lado "},
									{"principal ","edificio ","museo ","hospital ","pulperia "},
									{"esquina ","recto ","doble ","cruce ","puente "},
									{"Tegucigalpa ","Berlin ","Dubai ","Tokio ","Madrid "}};

	string nombres_libros[6][5] = {{"the ","lord ","of ","the ","rings "},
									{"dante's ","inferno ","el  ","codigo ","DaVinci "},
									{"del ","amor ","y ","otros ","demonios "},
									{"frankenstein ","dracula ","moby ","dick ","el "},
									{"juguete ","rabioso ","nombre ","de ","la "},
									{"rosa ","vision ","de ","los ","vencidos "}};

	string nombres_autores[6][5] = {{"Rowling ","Tolkien ","Gabriel ","Garcia ","Marquez "},
									{"Paulo ","Coelho ","Roberto  ","Arit ","Umberto "},
									{"Eco ","Leonardo ","Isabel ","Allende ","Juan "},
									{"Gabriel ","Ramon ","Valbuena ","Soto ","Morales "},
									{"Miguel ","Portilla ","Mijail ","Bulgakov ","Paz "},
									{"Laforet ","Bradbury ","William ","Rulfo ","Sartre "}};

	vector<Editorial> editoriales;
	vector<Book> libros;

	cout << "ez" << endl;


	for (int i = 0; i < 10; ++i){
		for (int j = 0; j < 10; ++j){
			for (int k = 0; k < 10; ++k){
				for (int l = 0; l < 10; ++l){
					for (int m = 0; m < 10; ++m){
						if(editoriales.size() >= 10000){
							break;
						}

						int row;
						int col;

						stringstream nombre;
						stringstream direccion;

						char temp[18];
						temp[0] = '0';
						temp[1] = '0';
						temp[2] = '0';
						temp[3] = '-';
						temp[4] = '0';
						temp[5] = '-';
						temp[6] = '0';
						temp[7] = '0';
						temp[8] = '-';
						temp[9] ='0';
						temp[10] = '0';
						temp[11] = m + '0';
						temp[12] = l + '0';
						temp[13] = k + '0';
						temp[14] = j + '0';
						temp[15] = '-';
						temp[16] = i + '0';
						temp[17] = '\0';

						int cont = 0;
						while(cont < 4){
							row = rand()%6;
							col = rand()%5;
							nombre << nombres_editorial[row][col];
							cont++;
						}
						cont = 0;
						while(cont < 4){
							row = rand()%6;
							col = rand()%5;
							direccion << direccion_editorial[row][col];
							cont++;
						}

						editoriales.push_back(Editorial(temp,const_cast<char *>(nombre.str().c_str()),const_cast<char *>(direccion.str().c_str())));
						
					}
				}
			}
		}
	}

	cout << "did it 1" << endl;

	for (int i = 0; i < 10000; ++i){
		out_editorial.write((char*)&editoriales[i],sizeof(Editorial));
	}

	cout << "did it 2" << endl;

	for (int i = 0; i < 10; ++i){
		for (int j = 0; j < 10; ++j){
			for (int k = 0; k < 10; ++k){
				for (int l = 0; l < 10; ++l){
					for (int m = 0; m < 10; ++m){
						if(libros.size() >= 50000){
							break;
						}
						int row;
						int col;

						stringstream nombre;
						stringstream autor;

						char temp[18];
						temp[0] = '0';
						temp[1] = '0';
						temp[2] = '0';
						temp[3] = '-';
						temp[4] = '0';
						temp[5] = '-';
						temp[6] = '0';
						temp[7] = '0';
						temp[8] = '-';
						temp[9] = '0';
						temp[10] = '0';
						temp[11] = m + '0';
						temp[12] = l + '0';
						temp[13] = k + '0';
						temp[14] = j + '0';
						temp[15] = '-';
						temp[16] = i + '0';
						temp[17] = '\0';

						int cont = 0;
						while(cont < 4){
							row = rand()%6;
							col = rand()%5;
							nombre << nombres_libros[row][col];
							cont++;
						}
						cont = 0;
						while(cont < 2){
							row = rand()%6;
							col = rand()%5;
							autor << nombres_autores[row][col];
							cont++;
						}

						int ed_id = rand()%10000;

						libros.push_back(Book(temp,const_cast<char *>(nombre.str().c_str()),const_cast<char *>(autor.str().c_str()),const_cast<char *>(editoriales[ed_id].getId().c_str())));
						
						
					}
				}
			}
		}
	}

	cout << "did it 3" << endl;

	for (int i = 0; i < 50000; ++i){
		out_book.write((char*)&libros[i],sizeof(Book));
	}

	cout << "did it 4" << endl;

	out_editorial.flush();
	out_book.flush();

	out_editorial.close();
	out_book.close();

	cout << "done" << endl;

	return 0;
}
