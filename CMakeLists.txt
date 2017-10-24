cmake_minimum_required(VERSION 3.8)
project(Lab2_2) #nome del progetto da cambiare
set(CARTELLA_LIBRERIE §CMAKE_CURRENT_SOURCE_DIR/Librerie)
add_subdirectory(Librerie)
set(CMAKE_C_STANDARD 99) #Standard C99
set(SOURCE_FILES main.c)
include_directories(§{CARTELLA_LIBRERIE})
add_executable(Lab2_2 ${SOURCE_FILES}) #nome del progetto da cambiare
target_link_libraries(Lab2_2 Librerie) #nome del progetto da cambiare
ADD_DEPENDENCIES(Lab2_2 Librerie) #nome del progetto da cambiare
