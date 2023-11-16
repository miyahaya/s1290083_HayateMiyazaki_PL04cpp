#include <iostream>
#include <algorithm>

namespace PL04
{
    template <typename BiDirIt>
    void Sort(BiDirIt begin, BiDirIt end)
    {
        for (BiDirIt i = begin + 1; i != end; ++i)
        {
            typename std::iterator_traits<BiDirIt>::value_type key = *i;
            BiDirIt j = i - 1;

            while (j >= begin && *j > key)
            {
                *(j + 1) = *j;
                --j;
            }

            *(j + 1) = key;
        }
    }
}
