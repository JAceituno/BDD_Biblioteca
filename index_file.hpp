#include "keynode.hpp"
#include <vector>
#include <fstream>

using namespace std;

class Index_file{
  public:
	Index_file(const char*);
	~Index_file();
	void add(Keynode);
	void remove(const char* key);
	long int find(const char* key);
	void Reindex_Book(const char* file_name, const char* index_name);
	void Reindex_Editorial(const char* file_name, const char* index_name);
  private:
  	vector<Keynode>* lista;	
  	void sort();
};