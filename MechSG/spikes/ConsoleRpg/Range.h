#pragma once
namespace CRPG
{
    class Range
    {
    public:
        Range(int low, int high);
        Range (void);
        ~Range(void);
        int HighRange () const { return _HighRange; }
        int LowRange () const { return _LowRange; }

    private:
        int _LowRange;
        int _HighRange;
    };
}
