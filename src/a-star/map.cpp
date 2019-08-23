#include "map.hpp"

using namespace AStar;

void Map::Create(Math::Vector2 size){
    m_size = size;
    m_data.resize(size.GetY());
    for (int y=0;y<size.GetY();y++){
        std::vector<int> _row;

        for(int x=0;x<size.GetX();x++){
            _row.push_back(0);
        }
        m_data[y] = _row;
    }
}

void Map::AddObject(Math::Vector2 position, Math::Vector2 scale){
    for(int y=0;y<scale.GetY();y++){
        for(int x=0; x<scale.GetX();x++){
            m_data[position.GetY() + y][position.GetX() + x] = 1;
        }
    }
}

void Map::DrawPoint(Math::Vector2 pos, int index){
    m_data[pos.GetY()][pos.GetX()] = index;
}

void Map::Draw(){
    for (int row=0;row<m_data.size();row++){
       
        for (int col=0;col<m_data[row].size();col++){
            
            int cell = m_data[row][col];
            switch(cell){
                case 1:
                    std::cout << "#";
                    break;

                case 2:
                    std::cout << "*";
                    break;
                case 3:
                    std::cout << "+";
                    break;
                 case 4:
                    std::cout << "'";
                    break;
                case 0:
                    if(row == 0 || row == m_data.size() -1){
                        std::cout << "_";
                    }else{
                        std::cout << " ";
                    }
                    
                    break;

                default:
                    //std::cout << cell << "";
                    
                    break;
            }

            if(col == 0 || col == m_data[row].size() -1){
                std::cout << "|";
            }
             
        }
        std::cout << std::endl;
    }
}

int Map::Get(Math::Vector2 pos){
    return m_data[pos.GetY()][pos.GetX()];
}

Math::Vector2 Map::GetSize(){
    return m_size;
}