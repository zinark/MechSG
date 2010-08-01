#pragma once
namespace CRPG
{
    class Statistics
    {
    private:
        int _HitPoint;
        int _Accuracy;
        int _Armor;
    
    public:
        Statistics(void);
        ~Statistics(void);
        Statistics& SetHitPoint (int value);
        Statistics& SetAccuracy (int value);
        Statistics& SetArmor (int value);

        int HitPoint () const { return _HitPoint; }
        int Accuracy() const { return _Accuracy; }
        int Armor () const { return _Armor; }
    };
}
