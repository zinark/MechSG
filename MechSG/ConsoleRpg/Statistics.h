#pragma once
namespace CRPG
{
    class Statistics
    {
    private:
        int _HitPoint;
        int _MaxHitPoint;
        int _Accuracy;
        int _Armor;
        int _Level;
    
    public:
        Statistics(void);
        ~Statistics(void);
        
        Statistics& SetHitPoint (int value);
        Statistics& SetMaxHitPoint (int value);
        Statistics& SetAccuracy (int value);
        Statistics& SetArmor (int value);
        Statistics& SetLevel (int value);

        int Level () const { return _Level;}
        int HitPoint () const { return _HitPoint; }
        int MaxHitPoint () const { return _MaxHitPoint;}
        int Accuracy() const { return _Accuracy; }
        int Armor () const { return _Armor; }
    };
}
