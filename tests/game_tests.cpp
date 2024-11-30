#include <gtest/gtest.h>
#include "Node.hpp"
#include <AdventureGameMap.hpp>

namespace chants 
{

TEST(AdventureGameMapTests, AddNodeAndFindNode) 
{
    // Create the game map
    AdventureGameMap gameMap;

    // Create nodes
    Node* home = new Node(0, "Home");
    Node* island = new Node(1, "Island");
    Node* mountain = new Node(2, "Mountain");

    // Add nodes to the game map
    gameMap.AddNode(home);
    gameMap.AddNode(island);
    gameMap.AddNode(mountain);

    // Verify that nodes are added
    EXPECT_EQ(gameMap.GetNodes().size(), 3);

    // Test FindNode
    Node* foundNode = gameMap.FindNode(1); // Search for the "Island" node
    ASSERT_NE(foundNode, nullptr);         // Ensure the node is found
    EXPECT_EQ(foundNode->GetName(), "Island");

    // Test invalid node ID
    EXPECT_EQ(gameMap.FindNode(99), nullptr);
}

TEST(NodeTests, AddAndGetConnections) 
{
    // Create nodes
    Node* home = new Node(0, "Home");
    Node* island = new Node(1, "Island");
    Node* mountain = new Node(2, "Mountain");

    // Add connections
    home->AddConnection(island);
    home->AddConnection(mountain);

    // Verify connections
    const auto& connections = home->GetConnections();
    EXPECT_EQ(connections.size(), 2);
    EXPECT_EQ(connections[0]->GetName(), "Island");
    EXPECT_EQ(connections[1]->GetName(), "Mountain");
}

}  