//
// Created by Flo on 01/04/2022.
//

#ifdef INCLUDE_TP6

#include <memory>
#include "includes/SpinOriginator.hpp"
#include "includes/SpinCaretaker.hpp"

#include "includes/Momento.hpp"

namespace TP6
{
    int main()
    {
        auto pSpinbox = std::make_shared<SpinOriginator>(5);
        auto pCaretaker = std::make_unique<SpinCaretaker>(pSpinbox);

        pCaretaker->createMomento();
        std::cout << pSpinbox->getValue() << std::endl;

        pSpinbox->setValue(15);
        pCaretaker->createMomento();

        //pSpinbox->setvalue(24);
        pCaretaker->restoreLastMomento();

        std::cout << pSpinbox->getValue() << std::endl;

        return 0;
    }
};

#endif // INCLUDE_TP6