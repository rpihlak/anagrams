#include <chrono>
#include <iostream>

#include "anagrams.h"
#include "encoding.h"
#include "fileio.h"
#include "primes.h"

using namespace std;
using namespace std::chrono;
using namespace anagrams;

int main(int argc, char *argv[])
{
  const auto start = system_clock::now();

  if (argc < 3)
    return 1;

  const auto dictionary = read_file(argv[1]);
  const auto word = from_utf(argv[2]);
  const auto anagrams = find_anagrams(dictionary, word);

  const auto finish = system_clock::now();
  const auto duration_us = duration<double, micro>(finish - start).count();

  cout << duration_us;

  for (const auto &anagram : anagrams)
    cout << ',' << to_utf(anagram);

  cout << endl;

  return 0;
}
