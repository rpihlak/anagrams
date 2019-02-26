#include <limits>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/utility/string_view.hpp>

#include "anagrams.h"
#include "primes.h"

using namespace std;
using namespace boost;
using namespace boost::multiprecision;
using namespace anagrams;

uint128_t calculate_product_safe(const string_view &str);
uint128_t calculate_product(const string_view &str);

vector<string> anagrams::find_anagrams(const string &dictionary, const string &word)
{
  const auto product = calculate_product_safe(word);

  string::size_type begin = 0;
  string::size_type end = 0;

  vector<string> anagrams;

  while (true)
  {
    end = dictionary.find('\n', begin);
    if (end == string::npos)
      break;

    string_view candidate(&dictionary[begin], end - begin - 1); // exclude '\r'
    if (candidate.length() == word.length() && calculate_product(candidate) == product)
      anagrams.push_back(candidate.to_string());

    begin = end + 1;
  }

  return anagrams;
}

uint128_t calculate_product_safe(const string_view &str)
{
  uint128_t product = 1;

  for (const auto character : str)
  {
    // Prevent overflow
    const auto prime = primes[static_cast<unsigned char>(character)];
    if (numeric_limits<uint128_t>::max() / product < prime)
      return 0;

    product *= prime;
  }

  return product;
}

uint128_t calculate_product(const string_view &str)
{
  uint128_t product = 1;

  for (const auto character : str)
  {
    const auto prime = primes[static_cast<unsigned char>(character)];
    product *= prime;
  }

  return product;
}
