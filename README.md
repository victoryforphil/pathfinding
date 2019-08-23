# pathfinding
Learning path finding

## How to build
Bazel is all that is required to build this project, along with approiate CPP build tools for your given platform.   
`bazel build ...`

## Notes  
Although many of the base algorithms may be the same, their implementations may differ as I practice diffrent techniques and styles.

## Modules  

### Grid A* (Done)   
A simple grid-based A* example.

### Area A* (Future)   
A* algorithm that works in a world of decimal defined objects not aligned to a grid. 
A* Nodes are on a grid however, but check for collision (2d collison detection) in its managed area

### Hybrid A*   
Car steering A* pathfinder to test our autonomous cars