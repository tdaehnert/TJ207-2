#include <Player.hpp>
#include <algorithm>

namespace chants
{
    Player::Player(std::string name) { /* Constructor implementation */ }

    void Player::AddAsset(const Asset &asset)
    {
        _assets.push_back(asset);
    }

    bool Player::HasAsset(const std::string &assetName) const
    {
        // Check if any asset in the player's inventory matches the given name
        return std::any_of(_assets.begin(), _assets.end(), [&assetName](const Asset &asset) {
            return asset.GetName() == assetName;
        });
    }
}