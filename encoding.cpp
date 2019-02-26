#include <boost/locale.hpp>

#include "encoding.h"

using namespace std;
using namespace boost::locale::conv;

const auto charset = "Windows-1257";

string anagrams::from_utf(const string &str)
{
  return ::from_utf(str, charset);
}

string anagrams::to_utf(const string &str) {
  return ::to_utf<char>(str, charset);
}
