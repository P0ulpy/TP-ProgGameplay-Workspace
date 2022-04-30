//
// Created by Flo on 01/04/2022.
//

#ifdef INCLUDE_TP6


#ifndef TP_PROGGAMEPLAY_WORKSPACE_MOMENTO_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_MOMENTO_HPP

class Momento
{
private:
    std::string _state;

public:
    explicit Momento(const std::string& state)
            :_state(state)
    { }

    std::string getSaved() const
    {
        return _state;
    }
};

#endif //TP_PROGGAMEPLAY_WORKSPACE_MOMENTO_HPP

#endif // INCLUDE_TP6
