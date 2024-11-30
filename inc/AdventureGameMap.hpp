#pragma once
#include "Node.hpp"
#include <string>
#include <Node.hpp>

namespace chants
{
    class AdventureGameMap
    {
    private:
        std::vector<Node*> _nodes;

    public:
        AdventureGameMap();
        void AddNode(Node* node);
        const std::vector<Node*>& GetNodes() const;
        Node* FindNode(int nodeId) const;  
        vector<Node> GetLocations();
    };
}