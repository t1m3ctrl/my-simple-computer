#include <string>
#include <unordered_map>

using namespace std;

class VariableTable
{
private:
  unordered_map<string, int> vars;

public:
  void define (string name, int address);
  int get_addr (string name);
  bool has (string name);
};
