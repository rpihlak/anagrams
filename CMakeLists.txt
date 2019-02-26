cmake_minimum_required(VERSION 3.10)

project(anagrams)
add_executable(
  ${PROJECT_NAME}
  "anagrams.cpp"
  "encoding.cpp"
  "fileio.cpp"
  "main.cpp"
  "anagrams.h"
  "encoding.h"
  "fileio.h"
  "primes.h"
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.65 REQUIRED COMPONENTS locale)
find_library(ICU_UC_LIBRARY libicuuc.a)
find_library(ICU_DATA_LIBRARY libicudata.a)
find_library(DL_LIBRARY dl)

target_link_libraries(${PROJECT_NAME} LINK_PRIVATE ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} LINK_PRIVATE ${ICU_UC_LIBRARY})
target_link_libraries(${PROJECT_NAME} LINK_PRIVATE ${ICU_DATA_LIBRARY})
target_link_libraries(${PROJECT_NAME} LINK_PRIVATE ${DL_LIBRARY})
