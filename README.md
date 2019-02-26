# Anagrams

## Prerequisites

* [Boost](https://www.boost.org)
* [CMake](https://cmake.org)

## Getting Started

Build the project with the following command:

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=.. ..
make
make install
```

Run the project with the following command:

```bash
./anagrams <path-to-dictionary> <word>
```

where `<path-to-dictionary>` is a path to a Windows-1257 encoded dictionary and
`<word>` is an UTF-8 encoded word. The program is designed to find anagrams from
the dictionary found on http://www.eki.ee/tarkvara/wordlist/lemmad.zip.
