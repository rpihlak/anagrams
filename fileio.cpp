#include <fstream>

#include "fileio.h"

using namespace std;

string anagrams::read_file(const string &path)
{
  ifstream file(path);
  file.seekg(0, ios::end);

  string buffer;
  buffer.resize(static_cast<string::size_type>(file.tellg()));

  file.seekg(0, ios::beg);
  file.read(&buffer[0], static_cast<string::difference_type>(buffer.size()));

  return buffer;
}
