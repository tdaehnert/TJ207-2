include_directories(${PROJECT_SOURCE_DIR}/inc)

add_executable(
    game_tests
    game_tests.cpp
    /home/tdaehnert/dev/AdventureGame/ChantsAdventure-main/src/Node.cpp
    /home/tdaehnert/dev/AdventureGame/ChantsAdventure-main/src/AdventureGameMap.cpp
)

target_link_libraries(
    game_tests
    gtest
    gtest_main
)



add_test(NAME GameTests COMMAND game_tests)
