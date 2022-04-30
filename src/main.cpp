#include "TPLoader.hpp"

#include "Exercice-Ratrapage/main.cpp"

int main()
{
    //TPLoader::load("TP1", TP1::main);
    //TPLoader::load("TP4", TP4::main);
    //TPLoader::load("TP6", TP6::main);
    TPLoader::load("ExplorableTree", ExplorableTree::main);

    TPLoader::launch("ExplorableTree");
    //TPLoader::launchAll();
}