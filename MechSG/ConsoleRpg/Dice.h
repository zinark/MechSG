#pragma once
#include "Range.h"

namespace CRPG
{
    class Dice
    {
    private:
        Range _Range;
    
    public:
        Dice(Range& range);
        ~Dice(void);
        int Roll ();
    };


}
