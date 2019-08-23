#include <iostream>
#include "src/a-star/astar.hpp"
#include "src/math/vector2.hpp"
#include "src/a-star/map.hpp"
int map[10][10] = 
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,0,0,1,1,1,0,1,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
}; // 0 = nothing, 1 = block, 2 = start, 3 = goal

int main(){

    // Print Grid

    AStar::AStarCompute compute;

    AStar::Map map;

    map.Create(Math::Vector2(80,40));
    map.AddObject(Math::Vector2(0,2), Math::Vector2(76,1));
    map.AddObject(Math::Vector2(4,4), Math::Vector2(76,1));
    map.AddObject(Math::Vector2(0,6), Math::Vector2(76,1));
    map.AddObject(Math::Vector2(4,8), Math::Vector2(76,1));
    map.AddObject(Math::Vector2(0,10), Math::Vector2(76,1));
    map.AddObject(Math::Vector2(4,12), Math::Vector2(76,1));

    std::vector<Math::Vector2> path = compute.Compute(&map, Math::Vector2(1,1),Math::Vector2(70,35));
    for(int i=0;i<path.size();i++){
        map.DrawPoint(path[i], 2);
        
    }
    map.Draw();
    
    std::cin.get();

    return 0;
}