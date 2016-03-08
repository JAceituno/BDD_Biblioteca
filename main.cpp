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
	archivo_libro.close();
	archivo_edito.close();

	if(hb.isDirty()){
		if_books.Reindex_Book("book.dat","bindex.dat");
	}
	if(he.isDirty()){
		if_editorials.Reindex_Editorial("editorial.dat","eindex.dat");
	}

	hb.setDirty(false);
	he.setDirty(false);

	cout << "hago stp" << endl;
	armar_availList(al_libros, al_edit, hb, he);
	while(selec = main_menu()){
		if(selec == 1){
			if(!other_menu()){
				char input[14];
				char isbn[18];
				char nombre[50];
			  	char autor[50];
			  	char input_edit[14];
			  	char id_editorial[18];

			  	bool valid = false;
			  	while (!valid){
			  		cout << "Ingrese ISBN: ";
			  		cin.getline(input,14,'\n');
			  		cout << strlen(input) << endl;
			  		if(strlen(input) == 13)
			  			valid = true;
			  	}
			  	cout << "Ingrese Nombre: ";
		  		cin.getline(nombre,50,'\n');
		  		cout << "Ingrese Autor: ";
		  		cin.getline(autor,50,'\n');
			  	valid = false;
			  	while (!valid){
			  		cout << "Ingrese ID Editorial: ";
			  		cin.getline(input_edit,14,'\n');
			  		if(strlen(input_edit) == 13)
			  			valid = true;
			  	}
			  	isbn[0] = input[0];
				isbn[1] = input[1];
				isbn[2] = input[2];
				isbn[3] = '-';
				isbn[4] = input[3];
				isbn[5] = '-';
				isbn[6] = input[4];
				isbn[7] = input[5];
				isbn[8] = '-';
				isbn[9] = input[6];
				isbn[10] = input[7];
				isbn[11] = input[8];
				isbn[12] = input[9];
				isbn[13] = input[10];
				isbn[14] = input[11];
				isbn[15] = '-';
				isbn[16] = input[12];
				isbn[17] = '\0';

				id_editorial[0] = input_edit[0];
				id_editorial[1] = input_edit[1];
				id_editorial[2] = input_edit[2];
				id_editorial[3] = '-';
				id_editorial[4] = input_edit[3];
				id_editorial[5] = '-';
				id_editorial[6] = input_edit[4];
				id_editorial[7] = input_edit[5];
				id_editorial[8] = '-';
				id_editorial[9] = input_edit[6];
				id_editorial[10] = input_edit[7];
				id_editorial[11] = input_edit[8];
				id_editorial[12] = input_edit[9];
				id_editorial[13] = input_edit[10];
				id_editorial[14] = input_edit[11];
				id_editorial[15] = '-';
				id_editorial[16] = input_edit[12];
				id_editorial[17] = '\0';

				Book libro(isbn,nombre,autor,id_editorial);
				fstream out_file("book.dat",ios::in|ios::out|ios::binary);

				long int ref;
				if(al_libros.size() > 0){
					ref = al_libros.back();
					al_libros.pop_back();

					out_file.seekp(ref,ios::beg);
				}
				else{
					out_file.seekp(0,ios::end);
					ref = out_file.tellp();
				}
				hb.setDirty(true);
				Keynode node(isbn,ref);
				if_books.add(node);
				out_file.write((char*)&libro,sizeof(Book));    	//Escribir Libro

				out_file.flush();

				out_file.close();
			}
			else{
				char nombre[50];
			  	char direccion[50];
			  	char input_edit[14];
			  	char id_editorial[18];

			  	cout << "Ingrese Nombre: ";
		  		cin.getline(nombre,50,'\n');
		  		cout << "Ingrese Direccion: ";
		  		cin.getline(direccion,50,'\n');
			  	bool valid = false;
			  	while (!valid){
			  		cout << "Ingrese ID Editorial: ";
			  		cin.getline(input_edit,14,'\n');
			  		if(strlen(input_edit) == 13)
			  			valid = true;
			  	}

				id_editorial[0] = input_edit[0];
				id_editorial[1] = input_edit[1];
				id_editorial[2] = input_edit[2];
				id_editorial[3] = '-';
				id_editorial[4] = input_edit[3];
				id_editorial[5] = '-';
				id_editorial[6] = input_edit[4];
				id_editorial[7] = input_edit[5];
				id_editorial[8] = '-';
				id_editorial[9] = input_edit[6];
				id_editorial[10] = input_edit[7];
				id_editorial[11] = input_edit[8];
				id_editorial[12] = input_edit[9];
				id_editorial[13] = input_edit[10];
				id_editorial[14] = input_edit[11];
				id_editorial[15] = '-';
				id_editorial[16] = input_edit[12];
				id_editorial[17] = '\0';

				Editorial edit(id_editorial,nombre,direccion);
				fstream out_file("editorial.dat",ios::in|ios::out|ios::binary);

				long int ref;

				if(al_edit.size() > 0){
					ref = al_edit.back();
					al_edit.pop_back();

					out_file.seekp(ref,ios::beg);
				}
				else{
					out_file.seekp(0,ios::end);
					ref = out_file.tellp();
				}
				he.setDirty(true);
				Keynode node(id_editorial,ref);
				if_editorials.add(node);
				out_file.write((char*)&edit,sizeof(Editorial));					//Escribir Editorial  

				out_file.flush();	

				out_file.close();				

			}		//Escribir
		}
		else if(selec == 2){
			if(!other_menu()){

				char input[14];
				char isbn[18];

				bool valid = false;
			  	while (!valid){
			  		cout << "Ingrese ISBN: ";
			  		cin.getline(input,14,'\n');
			  		if(strlen(input) == 13)
			  			valid = true;
			  	}
			  	isbn[0] = input[0];
				isbn[1] = input[1];
				isbn[2] = input[2];
				isbn[3] = '-';
				isbn[4] = input[3];
				isbn[5] = '-';
				isbn[6] = input[4];
				isbn[7] = input[5];
				isbn[8] = '-';
				isbn[9] = input[6];
				isbn[10] = input[7];
				isbn[11] = input[8];
				isbn[12] = input[9];
				isbn[13] = input[10];
				isbn[14] = input[11];
				isbn[15] = '-';
				isbn[16] = input[12];
				isbn[17] = '\0';

				cout << isbn << endl;

				long int ref = if_books.find(isbn);
				cout << ref << endl;

				Book libro;


				if(ref != -1){
					ifstream in_file("book.dat",ios::in|ios::binary);
					in_file.seekg(ref,ios::beg);
					in_file.read(reinterpret_cast<char*>(&libro),sizeof(Book));

					in_file.close();
				}

				cout << "ISBN: " << libro.getIsbn() << endl;
				cout << "Nombre: " << libro.getNombre() << endl;
				cout << "Autor: " << libro.getAutor() << endl;
				cout << "ID Editorial: " << libro.getId_editorial() << endl;



			} 	//Leer libro
			else{
				char input[14];
				char id_editorial[18];

				bool valid = false;
			  	while (!valid){
			  		cout << "Ingrese ID Editorial: ";
			  		cin.getline(input,14,'\n');
			  		if(strlen(input) == 13)
			  			valid = true;
			  	}
			  	id_editorial[0] = input[0];
				id_editorial[1] = input[1];
				id_editorial[2] = input[2];
				id_editorial[3] = '-';
				id_editorial[4] = input[3];
				id_editorial[5] = '-';
				id_editorial[6] = input[4];
				id_editorial[7] = input[5];
				id_editorial[8] = '-';
				id_editorial[9] = input[6];
				id_editorial[10] = input[7];
				id_editorial[11] = input[8];
				id_editorial[12] = input[9];
				id_editorial[13] = input[10];
				id_editorial[14] = input[11];
				id_editorial[15] = '-';
				id_editorial[16] = input[12];
				id_editorial[17] = '\0';

				cout << id_editorial << endl;

				long int ref = if_editorials.find(id_editorial);
				cout << ref << endl;

				Editorial editorial;


				if(ref != -1){
					ifstream in_file("book.dat",ios::in|ios::binary);
					in_file.seekg(ref,ios::beg);
					in_file.read(reinterpret_cast<char*>(&editorial),sizeof(Editorial));

					in_file.close();
				}

				cout << "ID Editorial: " << editorial.getId() << endl;
				cout << "Nombre: " << editorial.getNombre() << endl;
				cout << "Direccion: " << editorial.getDireccion() << endl;
			}	//Leer editorial
		}	//Leer
		else if(selec == 3){
			if(!other_menu()){

			}
			else{
				
			}
		}
		else if(selec == 4){
			if(!other_menu()){

				char input[14];
				char isbn[18];

				bool valid = false;
			  	while (!valid){
			  		cout << "Ingrese ISBN: ";
			  		cin.getline(input,14,'\n');
			  		if(strlen(input) == 13)
			  			valid = true;
			  	}
			  	isbn[0] = input[0];
				isbn[1] = input[1];
				isbn[2] = input[2];
				isbn[3] = '-';
				isbn[4] = input[3];
				isbn[5] = '-';
				isbn[6] = input[4];
				isbn[7] = input[5];
				isbn[8] = '-';
				isbn[9] = input[6];
				isbn[10] = input[7];
				isbn[11] = input[8];
				isbn[12] = input[9];
				isbn[13] = input[10];
				isbn[14] = input[11];
				isbn[15] = '-';
				isbn[16] = input[12];
				isbn[17] = '\0';

				cout << isbn << endl;

				long int ref = if_books.find(isbn);
				cout << ref << endl;

				Book libro;


				if(ref != -1){
					ifstream in_file("book.dat",ios::in|ios::binary);
					in_file.seekg(ref,ios::beg);
					in_file.read(reinterpret_cast<char*>(&libro),sizeof(Book));

					in_file.close();
				}

				libro.setMarked(true);
				libro.setMark(hb.getOffset());
				hb.setOffset(ref);
				al_libros.push_back(ref);

				hb.setDirty(true);

				fstream out_file("book.dat",ios::out|ios::in|ios::binary);
				out_file.seekp(ref,ios::beg);
				out_file.write((char*)&libro,sizeof(Book));

				out_file.flush();
				out_file.close();

			} 	//Leer libro
			else{
				char input[14];
				char id_editorial[18];

				bool valid = false;
			  	while (!valid){
			  		cout << "Ingrese ID Editorial: ";
			  		cin.getline(input,14,'\n');
			  		if(strlen(input) == 13)
			  			valid = true;
			  	}
			  	id_editorial[0] = input[0];
				id_editorial[1] = input[1];
				id_editorial[2] = input[2];
				id_editorial[3] = '-';
				id_editorial[4] = input[3];
				id_editorial[5] = '-';
				id_editorial[6] = input[4];
				id_editorial[7] = input[5];
				id_editorial[8] = '-';
				id_editorial[9] = input[6];
				id_editorial[10] = input[7];
				id_editorial[11] = input[8];
				id_editorial[12] = input[9];
				id_editorial[13] = input[10];
				id_editorial[14] = input[11];
				id_editorial[15] = '-';
				id_editorial[16] = input[12];
				id_editorial[17] = '\0';

				cout << id_editorial << endl;

				long int ref = if_editorials.find(id_editorial);
				cout << ref << endl;

				Editorial editorial;


				if(ref != -1){
					ifstream in_file("book.dat",ios::in|ios::binary);
					in_file.seekg(ref,ios::beg);
					in_file.read(reinterpret_cast<char*>(&editorial),sizeof(Editorial));

					in_file.close();
				}

				editorial.setMarked(true);
				editorial.setMark(he.getOffset());
				he.setOffset(ref);
				al_edit.push_back(ref);

				he.setDirty(true);

				fstream out_file("editorial.dat",ios::out|ios::in|ios::binary);
				out_file.seekp(ref,ios::beg);
				out_file.write((char*)&editorial,sizeof(Editorial));

				out_file.flush();
				out_file.close();
			}
		}
		else if(selec == 5){
			if(!other_menu()){
				cout << "No disponible en la version Alpha, still in development" << endl;
			}
			else{
				cout << "No disponible en la version Alpha, still in development" << endl;	
			}
		}
		else if(selec == 6){
			ifstream oldfile;
			fstream newfile;
			if(!other_menu()){
				oldfile.open("book.dat",ios::binary|ios::in);
				newfile.open("newbook.dat",ios::binary|ios::in|ios::out);
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
				newfile.open("neweditorial.dat",ios::binary|ios::in|ios::out);
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
			if(hb.isDirty()){
				if_books.Reindex_Book("book.dat","bindex.dat");
			}
			if(he.isDirty()){
				if_editorials.Reindex_Editorial("editorial.dat","eindex.dat");
			}
			hb.setDirty(false);
			he.setDirty(false);

			fstream archivo_libro("book.dat",ios::out|ios::in|ios::binary);
			fstream archivo_edito("editorial.dat",ios::out|ios::in|ios::binary);

			archivo_edito.write((char*)&he,sizeof(HeaderEditorial));
			archivo_libro.write((char*)&hb,sizeof(HeaderBook));

			archivo_libro.flush();
			archivo_edito.flush();

			archivo_libro.close();
			archivo_edito.close();

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
	cin.ignore();
	return ans-1;
}
void armar_availList(vector<long int>& al_libros, vector<long int>& al_edit, HeaderBook& hb, HeaderEditorial& he){
	ifstream archivo_libro("book.dat",ios::in|ios::binary);
	ifstream archivo_edito("editorial.dat",ios::in|ios::binary);
	//archivo_libro.read(reinterpret_cast<char*>(&hb),sizeof(HeaderBook));
	//archivo_edito.read(reinterpret_cast<char*>(&he),sizeof(HeaderEditorial));

	if(hb.getOffset() != -1){
		al_libros.push_back(hb.getOffset());
	}
	cout << "hago stp 1" << endl;
	cout << hb.getOffset() << endl;
	while(hb.getOffset() != -1){
		Book temp_libro;
		archivo_libro.seekg(al_libros.back(), ios::beg);
		archivo_libro.read(reinterpret_cast<char*>(&temp_libro),sizeof(Book));
		if(temp_libro.getMark() != 1){
			al_libros.push_back(temp_libro.getMark());
		}
		else{
			break;
		}
	}
	cout << "hago stp 2" << endl;
	if(he.getOffset() != -1){
		al_edit.push_back(he.getOffset());
	}
	cout << "hago stp 3" << endl;
	while(he.getOffset() != -1){
		Editorial temp_edito;
		archivo_edito.seekg(al_edit.back(), ios::beg);
		archivo_edito.read(reinterpret_cast<char*>(&temp_edito),sizeof(Editorial));
		if(temp_edito.getMark() != 1){
			al_edit.push_back(temp_edito.getMark());
		}
		else{
			break;
		}
	}
	cout << "hago stp 4" << endl;
	archivo_edito.close();
	archivo_libro.close();
}