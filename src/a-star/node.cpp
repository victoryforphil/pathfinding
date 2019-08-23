#include "node.hpp"

using namespace AStar;

Node::Node(uint64_t id, Math::Vector2 pos, std::shared_ptr<Node> parent, std::shared_ptr<Node> goal){
    m_id = id;
    m_pos = pos;
    m_parent = parent;
    m_goal = goal;
}

void Node::UpdateParent(std::shared_ptr<Node> parent){
    m_parent = parent;
}

int Node::UpdateCosts(){
    // Set this nodes cost to the parents cost + 1, 
    // as this represents one more node along the path
    // START + 1 + 2 + 3 + 4 + 5 
    m_gCost = m_parent->GetGCost() + 1; 
    // Calculate the distance from target as a simple huristic (rip spelling)
    m_hCost = m_pos.GetDistanceInt(m_goal->GetPos());

    // Calulcate the final cost
    m_fCost = m_gCost + m_hCost;
    
    return m_fCost;
}

uint16_t Node::GetGCost(){
    return m_gCost;
}

uint16_t Node::GetHCost(){
    return m_hCost;
}

uint16_t Node::GetFCost(){
    return m_fCost;
}

Math::Vector2 Node::GetPos(){
    return m_pos;
}


uint64_t Node::GetID(){
    return m_id;
}

std::shared_ptr<Node> Node::GetParent(){
    return m_parent;
}

bool Node::IsEqual(std::shared_ptr<Node> other){
    return m_pos.GetX() == other->GetPos().GetX() && m_pos.GetY() == other->GetPos().GetY();
}