#include "keynode.hpp"
#include "index_file.hpp"
#include "header_editorial.hpp"
#include "header_book.hpp"
#include "book.hpp"
#include "editorial.hpp"
#include <vector>
#include <cstring>
#include <string>
#include <fstream>


using namespace std;

Index_file::Index_file(const char* file_name){
	string name(file_name);
	lista = new vector<Keynode>;

	ifstream file(file_name,ios::in|ios::binary);
	if(file.fail()){
		file.close();
		if(name.compare("bindex.dat")){
			Reindex_Book("book.dat",file_name);
		}
		if(name.compare("eindex.dat")){
			Reindex_Editorial("editorial.dat",file_name);
		}
	}
	if(file.good()){
		while(!file.eof()){
			Keynode keynode;
			file.read(reinterpret_cast<char*>(&keynode),sizeof(Keynode));
			lista->push_back(keynode);
		}
	}
}
void Index_file::Reindex_Book(const char* file_name, const char* index_name){
	lista = new vector<Keynode>;

	ifstream data_file(file_name,ios::in|ios::binary);
	if(data_file.good()){
		data_file.seekg(sizeof(HeaderBook));

		while(!data_file.eof()){
			Book book;
			data_file.read(reinterpret_cast<char*>(&book),sizeof(Book));
			if(!book.isMarked()){
				Keynode keynode(const_cast<char *>(book.getIsbn().c_str()),data_file.tellg());
				lista->push_back(keynode);
			}
		}
		sort();
	}
	data_file.close();

	ofstream index_file(index_name,ios::out|ios::binary);
	for (int i = 0; i < lista->size(); ++i)	{
		Keynode to_add = lista->at(i);
		index_file.write((char*)&to_add,sizeof(Keynode));
	}
	index_file.flush();
	index_file.close();
}
void Index_file::Reindex_Editorial(const char* file_name, const char* index_name){
	lista = new vector<Keynode>;

	ifstream data_file(file_name,ios::in|ios::binary);
	if(data_file.good()){
		data_file.seekg(sizeof(HeaderEditorial));

		while(!data_file.eof()){
			Editorial editorial;
			data_file.read(reinterpret_cast<char*>(&editorial),sizeof(Editorial));
			if(!editorial.isMarked()){
				Keynode keynode(const_cast<char *>(editorial.getId().c_str()),data_file.tellg());
				lista->push_back(keynode);
			}
		}
		sort();
	}
	data_file.close();

	ofstream index_file(index_name,ios::out|ios::binary);
	for (int i = 0; i < lista->size(); ++i)	{
		Keynode to_add = lista->at(i);
		index_file.write((char*)&to_add,sizeof(Keynode));
	}
	index_file.flush();
	index_file.close();
}
Index_file::~Index_file(){
	delete lista;
}
void Index_file::add(Keynode keynode){
	lista->push_back(keynode);
	sort();
}
Keynode Index_file::find(char* key){
	/////////////////////////////////////FALTA//////////////////////////////////////////////////////////
	unsigned long long int temporal[lista->size()];

	for (int i = 0; i < lista->size(); ++i){
		temporal[i] = 0;
	}

	for (int i = 0; i < lista->size(); ++i){
		char temp[14];
		temp[0] = const_cast<char*>(lista->at(i).getKey().c_str())[0];
		temp[1] = const_cast<char*>(lista->at(i).getKey().c_str())[1];
		temp[2] = const_cast<char*>(lista->at(i).getKey().c_str())[2];
		temp[3] = const_cast<char*>(lista->at(i).getKey().c_str())[4];
		temp[4] = const_cast<char*>(lista->at(i).getKey().c_str())[6];
		temp[5] = const_cast<char*>(lista->at(i).getKey().c_str())[7];
		temp[6] = const_cast<char*>(lista->at(i).getKey().c_str())[9];
		temp[7] = const_cast<char*>(lista->at(i).getKey().c_str())[10];
		temp[8] = const_cast<char*>(lista->at(i).getKey().c_str())[11];
		temp[9] = const_cast<char*>(lista->at(i).getKey().c_str())[12];
		temp[10] = const_cast<char*>(lista->at(i).getKey().c_str())[13];
		temp[11] = const_cast<char*>(lista->at(i).getKey().c_str())[14];
		temp[12] = const_cast<char*>(lista->at(i).getKey().c_str())[16];
		temp[13] = const_cast<char*>(lista->at(i).getKey().c_str())[17];

		string next_temp(temp);

		temporal[i] = stoull(next_temp);
	}
	/////////////////////////////////////NO TERMINADO///////////////////////////////////////////////////7

}
void Index_file::sort(){
	unsigned long long int temporal[lista->size()];

	for (int i = 0; i < lista->size(); ++i){
		temporal[i] = 0;
	}

	for (int i = 0; i < lista->size(); ++i){
		char temp[14];
		temp[0] = const_cast<char*>(lista->at(i).getKey().c_str())[0];
		temp[1] = const_cast<char*>(lista->at(i).getKey().c_str())[1];
		temp[2] = const_cast<char*>(lista->at(i).getKey().c_str())[2];
		temp[3] = const_cast<char*>(lista->at(i).getKey().c_str())[4];
		temp[4] = const_cast<char*>(lista->at(i).getKey().c_str())[6];
		temp[5] = const_cast<char*>(lista->at(i).getKey().c_str())[7];
		temp[6] = const_cast<char*>(lista->at(i).getKey().c_str())[9];
		temp[7] = const_cast<char*>(lista->at(i).getKey().c_str())[10];
		temp[8] = const_cast<char*>(lista->at(i).getKey().c_str())[11];
		temp[9] = const_cast<char*>(lista->at(i).getKey().c_str())[12];
		temp[10] = const_cast<char*>(lista->at(i).getKey().c_str())[13];
		temp[11] = const_cast<char*>(lista->at(i).getKey().c_str())[14];
		temp[12] = const_cast<char*>(lista->at(i).getKey().c_str())[16];
		temp[13] = const_cast<char*>(lista->at(i).getKey().c_str())[17];

		string next_temp(temp);

		temporal[i] = stoull(next_temp);
	}

	int pos_min;

	unsigned long long int temporary;
	Keynode temporary2;

	for (int i=0; i < lista->size()-1; i++){
	    pos_min = i;
		
		for (int j=i+1; j < lista->size(); j++){

			if (temporal[j] < temporal[pos_min])
               pos_min=j;
		}
		
        if (pos_min != i){
            temporary = temporal[i];
            temporary2 = lista->at(i);
            temporal[i] = temporal[pos_min];
            lista->at(i) = lista->at(pos_min);
            temporal[pos_min] = temporary;
            lista->at(pos_min) = temporary2;
        }
	}
}