#include "AdventureGameMap.hpp"
#include "Node.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace chants
{
    AdventureGameMap::AdventureGameMap() 
    {
    _nodes = {};
    }

    void AdventureGameMap::AddNode(Node* node) 
    {
    _nodes.push_back(node);
    }
    
    Node* AdventureGameMap::FindNode(int nodeId) const
    {
        
        for (Node* node : _nodes)
        {
            if (node->GetId() == nodeId)
            {
                return node; // Return the matching node
            }
        }

        return nullptr; // Return null if no matching node is found

    }


    const std::vector<Node*>& AdventureGameMap::GetNodes() const   

    {

    return _nodes;

    }

}



