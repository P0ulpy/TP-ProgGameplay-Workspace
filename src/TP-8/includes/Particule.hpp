//
// Created by Flo on 22/04/2022.
//

#ifndef TP_PROGGAMEPLAY_WORKSPACE_PARTICULE_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_PARTICULE_HPP

#include "Point.hpp"

namespace TP8
{
    template<typename Type>
    struct Particle
    {
        Maths::Point2D<Type> position;
        Maths::Vector2D<Type> velocity;
        Type mass;
    };
}

#endif //TP_PROGGAMEPLAY_WORKSPACE_PARTICULE_HPP
