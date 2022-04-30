//
// Created by Flo on 01/04/2022.
//

#ifndef TP_PROGGAMEPLAY_WORKSPACE_TPLOADER_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_TPLOADER_HPP

#include <map>
#include <string>
#include <functional>
#include <iostream>

typedef int (*TPMain)(void);

class TPLoader
{
private:
    static std::map<std::string, TPMain> sm_mains;

public:
    static void load(const std::string& name, TPMain tpMain)
    {
        sm_mains.emplace(name, tpMain);
    }

    static void launch(const std::basic_string<char>& name)
    {
        std::cout << "Launching " << name << " ======================================" << std::endl;
        sm_mains[name]();
    }

    static void launchAll()
    {
        for(auto& tpMain : sm_mains)
        {
            std::cout << "Launching " << tpMain.first << " ======================================" << std::endl;
            tpMain.second();
        }
    }
};

std::map<std::string, TPMain> TPLoader::sm_mains;

#endif //TP_PROGGAMEPLAY_WORKSPACE_TPLOADER_HPP
