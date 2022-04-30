//
// Created by Flo on 22/04/2022.
//

#include <iostream>
#include "includes/ParticuleSystem.hpp"

namespace TP8
{
    int main()
    {
        ParticleSystem particleSystem(3);
        std::cout << particleSystem << std::endl;
        particleSystem.simulate(10);

        return 0;
    }
}