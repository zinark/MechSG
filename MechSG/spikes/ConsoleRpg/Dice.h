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
        Dice (void);
        ~Dice(void);
        Dice& Ranged (Range& range);
        int Roll ();
    };


}
