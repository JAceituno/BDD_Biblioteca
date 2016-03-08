#include <iostream>
#include "book.hpp"
#include "editorial.hpp"
#include "header_book.hpp"
#include "header_editorial.hpp"
#include "index_file.hpp"
#include "keynode.hpp"
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main_menu();
int other_menu();
void armar_availList(vector<long int>& al_libros, vector<long int>& al_edit, HeaderBook& hb, HeaderEditorial& he);

int main(int argc, char const *argv[]){
	int selec;
	vector<long int> al_libros;
	vector<long int> al_edit;
	Index_file if_books("bindex.dat");
	Index_file if_editorials("eindex.dat");
	ifstream archivo_libro("book.dat",ios::in|ios::binary);
	ifstream archivo_edito("editorial.dat",ios::in|ios::binary);
	HeaderBook hb;
	HeaderEditorial he;
	archivo_libro.read(reinterpret_cast<char*>(&hb),sizeof(HeaderBook));
	archivo_edito.read(reinterpret_cast<char*>(&he),sizeof(HeaderEditorial));
	armar_availList(al_libros, al_edit, hb, he);
	while(selec = main_menu()){
		if(selec == 1){
			if(!other_menu()){

			}
			else{
				
			}
		}
		else if(selec == 2){
			if(!other_menu()){

			}
			else{
				
			}
		}
		else if(selec == 3){
			if(!other_menu()){

			}
			else{
				
			}
		}
		else if(selec == 4){
			if(!other_menu()){

			}
			else{
				
			}
		}
		else if(selec == 5){
			if(!other_menu()){

			}
			else{
				
			}
		}
		else if(selec == 6){
			ifstream oldfile;
			ofstream newfile;
			if(!other_menu()){
				oldfile.open("book.dat",ios::binary|ios::in);
				newfile.open("newbook.dat",ios::binary|ios::out);
				newfile.write((char*)&hb,sizeof(HeaderBook));
				vector<Book> libros;
				while(!oldfile.eof()){
					Book temp_book;
					oldfile.read(reinterpret_cast<char*>(&temp_book),sizeof(Book));
					if(!temp_book.isMarked()){
						libros.push_back(temp_book);
					}
				}
				oldfile.close();
				for (int i = 0; i < libros.size(); ++i)	{
					newfile.write((char*)&libros[i],sizeof(Book));
				}
				newfile.flush();
				newfile.close();
				remove("book.dat");
				rename("newbook.dat","book.dat");
			}
			else{
				oldfile.open("editorial.dat",ios::binary|ios::in);
				newfile.open("neweditorial.dat",ios::binary|ios::out);
				newfile.write((char*)&he,sizeof(HeaderEditorial));
				vector<Editorial> editoriales;
				while(!oldfile.eof()){
					Editorial temp_editorial;
					oldfile.read(reinterpret_cast<char*>(&temp_editorial),sizeof(Editorial));
					if(!temp_editorial.isMarked()){
						editoriales.push_back(temp_editorial);
					}
				}
				oldfile.close();
				for (int i = 0; i < editoriales.size(); ++i)	{
					newfile.write((char*)&editoriales[i],sizeof(Editorial));
				}
				newfile.flush();
				newfile.close();
				remove("editorial.dat");
				rename("neweditorial.dat","editorial.dat");
			}
		}
		else if(selec == 7){
			exit(0);
		}
	}
	return 0;
}

int main_menu(){ //método de io
	cout << "*-~.~-*-~.~-*-~.~-*MENU*-~.~-*-~.~-*-~.~-*\n"
		 << "1. Crear registro\n"
		 << "2. Leer registro\n"
		 << "3. Actualizar registro\n"
		 << "4. Borrar registro\n"
		 << "5. Listar cruzado\n"
		 << "6. Compactar\n"
		 << "7. Salir\n"
		 << "Ingrese opcion: ";
	int ans = 0;
	cin >> ans;
	while(ans < 1 || ans > 7){
		cout << "Opcion no valida, ingrese de nuevo: ";
		cin >> ans;
	}
	return ans;
}
int other_menu(){//método de io
	cout << "*-~.~-*-~.~-*-~.~-*MENU*-~.~-*-~.~-*-~.~-*\n"
		 << "1. Libro\n"
		 << "2. Editorial\n"
		 << "Ingrese opcion: ";
	int ans = 0;
	cin >> ans;
	while(ans < 1 || ans > 2){
		cout << "Opcion no valida, ingrese de nuevo: ";
		cin >> ans;
	}
	return ans-1;
}
void armar_availList(vector<long int>& al_libros, vector<long int>& al_edit, HeaderBook& hb, HeaderEditorial& he){
	while(true){
		if(hb.getOffset() != -1){
			al_libros.push_back(hb.getOffset());
		}
		else{
			break;
		}
	}
	while(true){
		if(he.getOffset() != -1){
			al_edit.push_back(he.getOffset());
		}
		else{
			break;
		}
	}
}