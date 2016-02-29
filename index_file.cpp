#include "keynode.hpp"
#include "index_file.hpp"
#include "header_editorial.hpp"
#include "header_Editorial.hpp"
#include "Editorial.hpp"
#include "editorial.hpp"
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

Index_file::Index_file(char* file_name){
	lista = new vector<Keynode>;

	ifstream file(file_name,ios::in|ios::binary);
	if(file.good()){
		while(!file.eof()){
			Keynode keynode;
			file.read(reinterpret_cast<char*>(&keynode),sizeof(Keynode));
			lista->push_back(keynode);
		}
	}
}
void Index_file::Reindex_Book(char* file_name, char* index_name){
	lista = new vector<Keynode>;

	ifstream data_file(file_name,ios::in|ios::binary);
	if(data_file.good()){
		data_file.seekg(sizeof(Header_book));

		while(!data_file.eof()){
			Book book;
			file.read(reinterpret_cast<char*>(&book),sizeof(Book));
			if(!book.isMarked()){
				Keynode keynode(book.getIsbn(),file.tellg());
				lista->push_back(keynode);
			}
		}
		sort();
	}
	data_file.close();

	ofstream index_file(index_name,ios::out|ios::binary);
	for (int i = 0; i < lista->size(); ++i)	{
		Keynode* to_add = &lista->at(i);
		index_file.write((char*)&to_add,sizeof(Keynode));
	}
	index_file.flush();
	index_file.close();
}
void Index_file::Reindex_editorial(char* file_name, char* index_name){
	ista = new vector<Keynode>;

	ifstream data_file(file_name,ios::in|ios::binary);
	if(data_file.good()){
		data_file.seekg(sizeof(Header_editorial));

		while(!data_file.eof()){
			Editorial editorial;
			file.read(reinterpret_cast<char*>(&editorial),sizeof(Editorial));
			if(!editorial.isMarked()){
				Keynode keynode(editorial.getId(),file.tellg());
				lista->push_back(keynode);
			}
		}
		sort();
	}
	data_file.close();

	ofstream index_file(index_name,ios::out|ios::binary);
	for (int i = 0; i < lista->size(); ++i)	{
		Keynode* to_add = &lista->at(i);
		index_file.write((char*)&to_add,sizeof(Keynode));
	}
	index_file.flush();
	index_file.close();
}
Index_file::~Index_file(){
	delete lista;
}
void Index_file::add(Keynode){
	lista->push_back(Keynode);
	sort();
}
Keynode Index_file::find(char* key){

}
void Index_file::sort(){
	unsigned long long int temporal[lista.size()];

	for (int i = 0; i < lista->size(); ++i){
		temporal[i] = 0;
	}

	for (int i = 0; i < lista->size(); ++i){
		char* temp[14];
		temp[0] = lista->at(i).getKey()[0];
		temp[1] = lista->at(i).getKey()[1];
		temp[2] = lista->at(i).getKey()[2];
		temp[3] = lista->at(i).getKey()[4];
		temp[4] = lista->at(i).getKey()[6];
		temp[5] = lista->at(i).getKey()[7];
		temp[6] = lista->at(i).getKey()[9];
		temp[7] = lista->at(i).getKey()[10];
		temp[8] = lista->at(i).getKey()[11];
		temp[9] = lista->at(i).getKey()[12];
		temp[10] = lista->at(i).getKey()[13];
		temp[11] = lista->at(i).getKey()[14];
		temp[12] = lista->at(i).getKey()[16];
		temp[13] = lista->at(i).getKey()[17];

		string next_temp(temp);

		temporal[i] = stoull(next_temp);
	}

	int pos_min;

	unsigned long long int temporary;

	for (int i=0; i < lista->size()-1; i++){
	    pos_min = i;
		
		for (int j=i+1; j < lista->size(); j++){

			if (temporal[j] < temporal[pos_min])
               pos_min=j;
		}
		
        if (pos_min != i){
            temporary = temporal[i];
            char* temporary2;
            strcpy(temporary2,lista->at(i));
            temporal[i] = temporal[pos_min];
            strcpy(lista->at(i),lista->at(pos_min));
            temporal[pos_min] = temporary;
            strcpy(lista->at(pos_min),temporary2);
        }
	}
}