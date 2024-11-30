#pragma once

#include <string>
#include <vector>
#include <Asset.hpp>

using namespace std;

namespace chants
{
    class Player
    {
    private:
        std::vector<Asset> _assets ;

    public:
        Player(std::string name);
        void AddAsset(const Asset &asset);
        bool HasAsset(const std::string &assetName) const;
    };
}
