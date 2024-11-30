#pragma once

#include <string>

using namespace std;

namespace chants
{
    class Asset
    {
    private:
        std::string _name;
        std::string _description;
        int _value;
        bool _isOffensive;

    public:
        bool hasBeenUsed;
        Asset(std::string name, std::string description, int value, bool isOffensive);
        std::string GetName() const;
        string GetMessage();
        int GetValue();
        bool isOffensive();
    };
}