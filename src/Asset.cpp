#include <Asset.hpp>

namespace chants
{
    Asset::Asset(string name, string description, int value)
    {
        _name = name;
        _description = description;
        _value = value;
    }

    std::string Asset::GetName() const
    {
        return _name;
    }

    string Asset::GetMessage()
    {
        return _description;
    }

    int Asset::GetValue()
    {
        return _value;
    }

}