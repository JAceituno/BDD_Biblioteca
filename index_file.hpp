#include "keynode.hpp"
#include <vector>
#include <fstream>

using namespace std;

class Index_file{
  public:
	Index_file(char*);
	~Index_file();
	void add(Keynode);
	Keynode find(char* key);
	void Reindex_Book(char* file_name, char* index_name);
	void Reindex_editorial(char* file_name, char* index_name);
  private:
  	vector<Keynode>* lista;	
  	void sort();
};