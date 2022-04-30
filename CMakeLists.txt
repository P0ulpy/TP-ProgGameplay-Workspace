cmake_minimum_required(VERSION 3.21)
project(TP-ProgGameplay-Workspace VERSION 0.1.0 DESCRIPTION "Gameplay programmation workspace")

set(CMAKE_CXX_STANDARD 14)

# A changer pour un fichier CMake par module de TP
file(GLOB_RECURSE SOURCE_FILES
    "src/Exercice-Rattrapage/*.hpp"
    "src/Exercice-Rattrapage/*.cpp"
)

add_executable(TP-ProgGameplay-Workspace ${SOURCE_FILES})