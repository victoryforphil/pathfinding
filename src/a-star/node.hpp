#ifndef _ASTAR_NODE_H_
#define _ASTAR_NODE_H_


#include <vector>
#include <memory>

#include "src/math/vector2.hpp"

namespace AStar{
    class Node
    {
    private:
        uint64_t m_id;

        uint16_t m_gCost;
        uint16_t m_hCost;
        uint16_t m_fCost;

        bool m_occupied;

        Math::Vector2 m_pos;

        std::shared_ptr<Node> m_parent;        
        std::shared_ptr<Node> m_goal;

    public:
        Node(uint64_t id, Math::Vector2 m_pos, std::shared_ptr<Node> parent, std::shared_ptr<Node> goal);
        int UpdateCosts();
        void UpdateParent(std::shared_ptr<Node> parent);
        uint16_t GetGCost();
        uint16_t GetHCost();
        uint16_t GetFCost();
        Math::Vector2 GetPos();
        uint64_t GetID();
        std::shared_ptr<Node> GetParent();
        bool IsEqual(std::shared_ptr<Node> other);


    };

    
}

#endif