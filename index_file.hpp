#include "keynode.hpp"
#include <vector>
#include <fstream>

class Index_file{
  public:
	Index_file();
	~Index_file();
	void add(Keynode);
	Keynode find(char* key);
	void reindex();
  private:
  	vector<Keynode>* lista;	
  	void sort(char* key);
};