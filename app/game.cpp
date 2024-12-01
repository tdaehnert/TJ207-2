#include <iostream>
#include <algorithm>
#include <limits>
#include <Node.hpp>
#include <Asset.hpp>
#include <Player.hpp>
#include <AdventureGameMap.hpp>

using namespace std;
using namespace chants;

// Helper to clear input buffer
void ClearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Helper to validate choice
int GetValidatedChoice(const vector<Node *> &connections)
{
    string input;
    while (true)
    {
        getline(cin, input);

        if (input == "x")
        {
            cout << "Exiting the game. Goodbye!" << endl;
            exit(0);
        }

        if (!all_of(input.begin(), input.end(), ::isdigit))
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        int choice = stoi(input);
        if (choice < 1 || choice > connections.size())
        {
            cout << "Invalid choice. Please select a valid number from the list." << endl;
            continue;
        }

        return choice - 1; // Return 0-based index
    }
}

// Displays node info and handles movement
void AtNode(Node &currentNode, Player &player)
{
    while (true)
    {
        // Display node info
        cout << "\nYou are at: " << currentNode.GetName() << endl;
        cout << currentNode.Description << endl;

        // Show connections
        cout << "You can move to:" << endl;
        for (size_t i = 0; i < currentNode.GetConnections().size(); ++i)
        {
            cout << i + 1 << ". " << currentNode.GetConnections()[i]->GetName() << endl;
        }

        if (currentNode.GetId() == 6 && !player.HasAsset("Fishing Pole"))
        {
            cout << "You see a Fishing Pole here. Do you want to pick it up? (yes/no): ";
            string choice;
            cin >> choice;
            ClearInputBuffer();

            if (choice == "yes" || choice == "y")
            {
                Asset fishingPole("Fishing Pole", "A tool to fish with.", 10);
                player.AddAsset(fishingPole);
                cout << "You picked up the Fishing Pole!" << endl;
            }
        }
        else if (currentNode.GetId() == 9 && player.HasAsset("Fishing Pole") && !player.HasAsset("Party Hat"))
        {
            cout << "You see a chance to fish for something. Do you want to fish? (yes/no): ";
            string choice;
            cin >> choice;
            ClearInputBuffer();

            if (choice == "yes" || choice == "y")
            {
                Asset partyHat("Party Hat", "A fun party accessory.", 5);
                player.AddAsset(partyHat);
                cout << "You caught a Party Hat!" << endl;
            }
        }
        else if (currentNode.GetId() == 19 && player.HasAsset("Party Hat"))
        {
            cout << "You are ready for the party! Game over. You win!" << endl;
            exit(0);
        }

        // Movement prompt
        cout << "\nWhere do you want to go? e(x)it: ";
        int choice = GetValidatedChoice(currentNode.GetConnections());

        // Move to the selected connected node
        currentNode = *currentNode.GetConnections()[choice];
        return;
    }
}

int main()
{
    // Player setup
    cout << "Welcome to Tim and Josh's adventure game!" << endl;
    cout << "Please enter your name: ";
    string playerName;
    getline(cin, playerName);

    Player player(playerName);
    AdventureGameMap gameMap;

    // Nodes
    Node *home = new Node(0, "Home");
    home->Description = "You are standing in the front yard of a warm and comfortable home that exudes charm and tranquility, inviting visitors to feel welcome even before they step inside.\n";
    gameMap.AddNode(home);

    Node *island = new Node(1, "Island");
    island->Description = "A tropical island surrounded by clear waters and lush greenery.";
    gameMap.AddNode(island);

    Node *mountain = new Node(2, "Mountain");
    mountain->Description = "A majestic mountain rises grandly with a towering peak.";
    gameMap.AddNode(mountain);

    Node *hut = new Node(3, "Hut");
    hut->Description = "A weathered hut, a sturdy refuge against the backdrop of the sea.";
    gameMap.AddNode(hut);

    Node *quicksand = new Node(4, "Quicksand");
    quicksand->Description = "A deceptive patch of quicksand blending into the terrain.";
    gameMap.AddNode(quicksand);

    Node *cave = new Node(5, "Cave");
    cave->Description = "A mysterious cave nestled into rocky cliffs.";
    gameMap.AddNode(cave);

    Node *stream = new Node(6, "Stream");
    stream->Description = "A serene stream with clear water and the sound of nature. Perhaps I can use the fishing pole in the distance?";
    gameMap.AddNode(stream);

    Node *beach = new Node(7, "Beach");
    beach->Description = "A beautiful beach with soft sand kissed by the ocean waves.";
    gameMap.AddNode(beach);

    Node *ocean = new Node(8, "Ocean");
    ocean->Description = "The sea appears restless and chaotic, with surging swells.";
    gameMap.AddNode(ocean);

    Node *pier = new Node(9, "Pier");
    pier->Description = "A sturdy pier extending into the ocean. You see a party hat in the rocks below, you need a fishing pole found at the stream.";
    gameMap.AddNode(pier);

    Node *city = new Node(10, "City");
    city->Description = "A bustling city with diverse architecture, parks, and theaters.";
    gameMap.AddNode(city);

    Node *park = new Node(11, "Park");
    park->Description = "A peaceful park with lush greenery and serene ambiance.";
    gameMap.AddNode(park);

    Node *pond = new Node(12, "Pond");
    pond->Description = "A quiet pond with still waters, reflecting the surroundings.";
    gameMap.AddNode(pond);

    Node *gym = new Node(13, "Gym");
    gym->Description = "A vibrant gym filled with energy and fitness enthusiasts.";
    gameMap.AddNode(gym);

    Node *library = new Node(14, "Library");
    library->Description = "A quiet library filled with books and knowledge.";
    gameMap.AddNode(library);

    Node *theater = new Node(15, "Theater");
    theater->Description = "An elegant theater showcasing art and performances.";
    gameMap.AddNode(theater);

    Node *restaurant = new Node(16, "Restaurant");
    restaurant->Description = "A cozy restaurant with delicious aromas and happy chatter.";
    gameMap.AddNode(restaurant);

    Node *bathroom = new Node(17, "Bathroom");
    bathroom->Description = "A small, tucked-away bathroom providing necessary privacy in the restaurant.";
    gameMap.AddNode(bathroom);

    Node *alleyway = new Node(18, "Alleyway");
    alleyway->Description = "A shadowy alleyway with mystery and hidden corners.";
    gameMap.AddNode(alleyway);

    Node *party = new Node(19, "Party");
    party->Description = "A lively party with music and joy. Bring a party hat, I think there was one by the rocks below the pier, to win!";
    gameMap.AddNode(party);

    // Connections
    home->AddConnection(island);
    home->AddConnection(city);
    home->AddConnection(beach);

    mountain->AddConnection(stream);
    mountain->AddConnection(cave);
    mountain->AddConnection(hut);
    mountain->AddConnection(quicksand);
    mountain->AddConnection(island);

    stream->AddConnection(mountain);

    cave->AddConnection(mountain);

    hut->AddConnection(mountain);
    hut->AddConnection(quicksand);

    quicksand->AddConnection(mountain);
    quicksand->AddConnection(hut);

    ocean->AddConnection(home);
    ocean->AddConnection(beach);
    ocean->AddConnection(pier);

    pier->AddConnection(ocean);

    city->AddConnection(home);
    city->AddConnection(park);
    city->AddConnection(library);
    city->AddConnection(gym);
    city->AddConnection(restaurant);
    city->AddConnection(alleyway);
    city->AddConnection(bathroom);
    city->AddConnection(beach);

    park->AddConnection(city);
    park->AddConnection(pond);

    pond->AddConnection(park);

    gym->AddConnection(city);

    library->AddConnection(city);

    theater->AddConnection(city);

    restaurant->AddConnection(city);

    alleyway->AddConnection(city);
    alleyway->AddConnection(party);

    party->AddConnection(alleyway);

    bathroom->AddConnection(city);

    beach->AddConnection(home);
    beach->AddConnection(ocean);
    beach->AddConnection(island);
    beach->AddConnection(city);

    island->AddConnection(mountain);
    island->AddConnection(home);
    island->AddConnection(beach);

    // Start game
    Node *currentNode = home;
    while (true)
    {
        AtNode(*currentNode, player);
    }

    return 0;
}