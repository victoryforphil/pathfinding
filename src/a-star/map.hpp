#ifndef _ASTAR_MAP_H_
#define _ASTAR_MAP_H_

#include <vector>
#include <iostream>


#include "src/math/vector2.hpp"
namespace AStar{
    class Map
    {
    private:
        std::vector<std::vector<int>> m_data;
        Math::Vector2 m_size;
    public:
        void Create(Math::Vector2 size);
        void AddObject(Math::Vector2 position, Math::Vector2 scale);
        void DrawPoint(Math::Vector2 pos, int index );
        void Draw();
        Math::Vector2 GetSize();
        int Get(Math::Vector2 pos);
    };
    

    
}

#endif