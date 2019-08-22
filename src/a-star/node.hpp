#ifndef _ASTAR_NODE_H_
#define _ASTAR_NODE_H_


#include <vector>
#include <memory>

#include "math/vector2.hpp"

namespace AStar{
    class Node
    {
    private:
        uint16_t m_gCost;
        uint16_t m_hCost;
        uint16_t m_fCost;

        bool m_occupied;

        std::unique_ptr<Node> m_parent;

        
        std::unique_ptr<Math::Vector2> m_target;

    public:
        Node();

        int UpdateCosts();

        ~Node();
    };

    
}

#endif