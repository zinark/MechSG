#include "PlayerPersister.h"
#include "Player.h"
#include <fstream>
using namespace std;
using namespace CRPG;

PlayerPersister::PlayerPersister( string fileName )
{
    _FileName = fileName;
}


PlayerPersister::~PlayerPersister(void)
{
}

void PlayerPersister::Add( const Player& player )
{
    _Players.push_back(player);
}

void WriteTotalPlayer (ofstream& file, int number)
{
    file.write ((char*) &number, sizeof(number));
}

void WritePlayer (ofstream& file, const Player& player)
{
    file.write((char*) &player, sizeof(player));
}

bool PlayerPersister::Export()
{
    ofstream file (_FileName, ios_base::binary);
    if (!file) return false;
    
    WriteTotalPlayer (file, _Players.size());

    for (int i=0; i<_Players.size(); ++i)
    {
        WritePlayer(file, _Players[i]);
    }

    file.close();
    return true;
}

int& ReadTotalPlayer (ifstream& file)
{
    int result = 0;
    file.read ((char*) &result, sizeof(result));
    return result;
}

vector<Player> ReadPlayers (ifstream& file, int& quantity)
{
    vector<Player> result (quantity);
    for (int i=0; i<quantity; ++i)
    {
        file.read((char*) &result[i], sizeof(Player));
    }
    return result;
}

bool PlayerPersister::Import()
{
    ifstream file (_FileName, ios_base::binary);
    if (!file) return false;

    int totalPlayer = ReadTotalPlayer (file);
    _Players = ReadPlayers (file, totalPlayer);
    
    file.close();
    return true;
}
