#include <iostream>
#include "src/a-star/astar.hpp"
#include "src/math/vector2.hpp"
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


    for (int (&row)[10] : map){
        for (int & cell : row){
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    AStar::AStarCompute compute;

    std::vector<Math::Vector2> path = compute.Compute(map, Math::Vector2(1,1), Math::Vector2(8,8));

    for(int i=0;i<path.size();i++){
        map[path[i].GetY()][path[i].GetX()] = 9;
    }
    for (int (&row)[10] : map){
        for (int & cell : row){
            
            switch(cell){
                case 1:
                    std::cout << "#" << " ";
                    break;

                case 9:
                    std::cout << "*" << " ";
                    break;
                default:
                    std::cout << " " << " ";
                    break;
            }
        }
        std::cout << std::endl;
    }
    std::cin.get();

    return 0;
}