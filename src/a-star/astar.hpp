#ifndef _ASTAR_ASTAR_H_
#define _ASTAR_ASTAR_H_

#include <vector>
#include <iostream>
#include <memory>

#include "node.hpp"

#include "math/vector2.hpp"

namespace AStar{
    class AStar
    {
    private:
        Math::Vector2 m_gridSize;
        Math::Vector2 m_start;
        Math::Vector2 m_goal;

        std::vector<


    public:
        AStar(/* args */);
        ~AStar();
    };
    
    
    
}

#endif