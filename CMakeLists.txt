cmake_minimum_required(VERSION 2.8)
project(bssid)

set(main linux/src/cpp/Main.cpp)
set(bssid linux/src/cpp/BSSID.cpp)
set(history linux/src/cpp/History.cpp)
set(parser linux/src/cpp/Parser.cpp)
set(requests linux/src/cpp/Requests.cpp)
set(shared linux/src/cpp/Shared.cpp)
set(pugixml public/pugixml/pugixml.cpp)

add_library(bssid STATIC ${bssid})
add_library(history STATIC ${history})
add_library(parser STATIC ${parser})
add_library(requests STATIC ${requests})
add_library(shared STATIC ${shared})
add_library(pugixml STATIC ${pugixml})

add_executable(main linux/src/cpp/Main.cpp)

target_link_libraries(main bssid history parser requests shared pugixml curl)
