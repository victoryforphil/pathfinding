#ifndef _ASTAR_ASTAR_H_
#define _ASTAR_ASTAR_H_

#include <vector>
#include <iostream>
#include <memory>

#include "node.hpp"

#include "src/math/vector2.hpp"
#include "map.hpp"
namespace AStar{
    class AStarCompute
    {
    private:
        Math::Vector2 m_gridSize;
        std::shared_ptr<Node> m_start;
        std::shared_ptr<Node> m_goal;


        std::vector<std::shared_ptr<Node>> m_closed;
        std::vector<std::shared_ptr<Node>> m_open;

        uint64_t m_node_count;


    public:
        
        std::vector<Math::Vector2> Compute(Map* map, Math::Vector2 start, Math::Vector2 goal);
        std::shared_ptr<Node> CreateNode(Math::Vector2 position,  std::shared_ptr<Node> parent);
        
    };
    
    
    
}

#endif