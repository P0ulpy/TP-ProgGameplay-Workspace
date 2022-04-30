//
// Created by Flo on 01/04/2022.
//

#ifdef INCLUDE_TP6

#ifndef TP_PROGGAMEPLAY_WORKSPACE_SPINCARETAKER_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_SPINCARETAKER_HPP

#include <vector>
#include <memory>

#include <vector>
#include "Momento.hpp"
#include "SpinOriginator.hpp"
#include <cassert>

class SpinCaretaker
{
public:
    SpinCaretaker(std::shared_ptr<SpinOriginator> pOriginator)
            :_pOriginator(pOriginator)
    { }

    ~SpinCaretaker()
    {
        for(auto& momento : _backups)
        {
            delete momento;
            momento = nullptr;
        }
    }

    void createMomento()
    {
        assert(!_backups.empty());
        _backups.push_back(_pOriginator->save());
    }

    void restoreLastMomento()
    {
        _pOriginator->restore(_backups.back());
    }

private:
    std::vector<Momento> _backups;
    std::shared_ptr<SpinOriginator> _pOriginator;
};

#endif //TP_PROGGAMEPLAY_WORKSPACE_SPINCARETAKER_HPP

#endif //INCLUDE_TP6
