#include "astar.hpp"

using namespace AStar;

std::shared_ptr<Node> AStarCompute::CreateNode(Math::Vector2 pos, std::shared_ptr<Node> parent){
    std::shared_ptr<Node> _created;
    _created.reset(new Node(m_node_count, pos, parent, m_goal ));
    m_node_count++;
    return _created;
}

 std::vector<Math::Vector2> AStarCompute::Compute(Map* map, Math::Vector2 start, Math::Vector2 goal){

    //Created end and start node
 std::vector<Math::Vector2> _path;
    m_start = CreateNode(start,nullptr);
    m_goal  = CreateNode(goal, nullptr);

    m_open.push_back(m_start);

    uint64_t _iterations = 0;
    while(m_open.size() > 0 ){
       // std::cout << " - m_open=" << m_open.size() << std::endl;
        std::shared_ptr<Node> _currentNode = m_open[0];
        int _currentIndex = 0;

        for(int i=0;i<m_open.size();i++){
            std::shared_ptr<Node> _item = m_open[i];
            map->DrawPoint(_item->GetPos(), 3);
            if(_item->GetFCost() < _currentNode->GetFCost()){
                _currentNode = _item;
                _currentIndex = i;
            }
        }

        m_open.erase(m_open.begin() + _currentIndex);
        m_closed.push_back(_currentNode);

        if(_currentNode->IsEqual(m_goal)){
           
            std::shared_ptr<Node> _current = _currentNode;
            while(_current != nullptr){
                _path.push_back(_current->GetPos());
                _current = _current->GetParent();
            }
            std::cout << "Took: " << _iterations << " steps" << std::endl;
            return _path;
        }

        std::vector<std::shared_ptr<Node>> _children;
        std::vector<Math::Vector2> _checkPositions;
        _checkPositions.push_back(Math::Vector2(-1,-1));
        _checkPositions.push_back(Math::Vector2(-1, 0));
        _checkPositions.push_back(Math::Vector2(-1, 1));

        _checkPositions.push_back(Math::Vector2(0,-1));
        _checkPositions.push_back(Math::Vector2(0, 1));

        _checkPositions.push_back(Math::Vector2(1,-1));
        _checkPositions.push_back(Math::Vector2(1, 0));
        _checkPositions.push_back(Math::Vector2(1, 1));
       
        for(int i=0;i<_checkPositions.size();i++){
            Math::Vector2 _check = _checkPositions[i];
            Math::Vector2 _nodePosition = _currentNode->GetPos() + _check;

            if(_nodePosition.GetX() >= map->GetSize().GetX() || _nodePosition.GetX() < 0 ||
                _nodePosition.GetY() >= map->GetSize().GetY() || _nodePosition.GetY() < 0 ){
                    continue;
            }

            if(map->Get(_nodePosition) == 0){
                std::shared_ptr<Node> _newNode = CreateNode(_nodePosition, _currentNode);
                _children.push_back(_newNode);
               
            }

            
        }


        
        for(int i=0;i<_children.size(); i++){
            bool dontAdd = false;
            std::shared_ptr<Node> _child = _children[i];
            for(int j=0;j<m_closed.size();j++){
                 std::shared_ptr<Node> _closedChild = m_closed[j];
                 if(_child->IsEqual(_closedChild)){ dontAdd = true;continue;}
            }
            _child->UpdateParent(_currentNode);
            _child->UpdateCosts();

           
            for(int j=0;j<m_open.size();j++){
                std::shared_ptr<Node> _openNode = m_open[j];
                if(_child->IsEqual(_openNode)){
                     //_child->UpdateParent(_openNode);
                     dontAdd = true;
                     continue;
                }
            }
            if(!dontAdd){
                m_open.push_back(_child);
            }
                
        }

        _iterations++;

    }
  
    std::cout << "Took: " << _iterations << " steps" << std::endl;
      return _path;
}