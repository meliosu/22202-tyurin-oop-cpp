project(google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(google_tests_run
        parser_test.cpp
        frequencylist_test.cpp
        filereader_test.cpp
        filewriter_test.cpp
        ../Parser.h
        ../Parser.cpp
        ../FrequencyList.h
        ../FrequencyList.cpp
        ../FileReader.h
        ../FileReader.cpp
        ../FileWriter.h
        ../FileWriter.cpp)

target_link_libraries(google_tests_run gtest gtest_main)