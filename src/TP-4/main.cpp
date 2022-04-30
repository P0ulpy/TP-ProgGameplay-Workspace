#include "includes/LinkedList.hpp"

namespace TP4
{
    int main()
    {
        LinkedList<int> list {};

        list.push_back(100);
        list.push_back(54);
        auto a = list.push_back(164);
        list.push_back(84);

        list.insert(a, 9647);

        return 0;
    }
}
