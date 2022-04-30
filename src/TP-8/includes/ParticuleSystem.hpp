//
// Created by Flo on 22/04/2022.
//

#ifndef TP_PROGGAMEPLAY_WORKSPACE_PARTICULESYSTEM_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_PARTICULESYSTEM_HPP

#include <vector>
#include "Point.hpp"
#include "Particule.hpp"

namespace TP8
{
    using Point2d = Maths::Point2D<double>;
    using Vector2d = Maths::Vector2D<double>;
    using ParticleD = Particle<double>;

    constexpr double g_gravity = 9.81;

    class ParticleSystem;
    std::ostream& operator<<(std::ostream& os, const ParticleSystem& particleSystem);

    class ParticleSystem
    {
        friend std::ostream& operator<<(std::ostream& os, const ParticleSystem& particleSystem);

    public:
        ParticleSystem(const size_t& numberOfParticle);
        void simulate(const double& elapsedTimeMs, const double& stepMs = 1.0);

    private:
        Vector2d computeGravityForce(ParticleD& particle);
        std::vector<ParticleD> m_particles;
    };

    std::ostream& operator<<(std::ostream& os, const ParticleSystem& particleSystem)
    {
        for (size_t i = 0; i < particleSystem.m_particles.size(); ++i)
            os << "[" << i << "] p" << particleSystem.m_particles[i].position
               << " v" << particleSystem.m_particles[i].velocity
               << " m=" << particleSystem.m_particles[i].mass << std::endl;

        return os;
    }
}

#endif //TP_PROGGAMEPLAY_WORKSPACE_PARTICULESYSTEM_HPP
