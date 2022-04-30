//
// Created by Flo on 01/04/2022.
//

#ifdef INCLUDE_TP6

#ifndef TP_PROGGAMEPLAY_WORKSPACE_SPINORIGINATOR_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_SPINORIGINATOR_HPP

#include <string>
#include "Momento.hpp"

class SpinOriginator
{
public:
    explicit SpinOriginator(const int& value = 0)
            : _value(value)
    { }

    void setValue(const int& value)
    {
        _value = value;
    }

    int getValue() const
    {
        return _value;
    }

    Momento* save() const
    {
        _state = std::to_string(_value);
        return new Momento(_state);
    }

    void restore (const Momento& momento)
    {
        _state = momento.getSaved();
        _value = std::stoi(_state);
    }

private:
    int _value;
    mutable std::string _state;//Modifiable dans une fonction const
};

#endif //TP_PROGGAMEPLAY_WORKSPACE_SPINORIGINATOR_HPP

#endif // INCLUDE_TP6