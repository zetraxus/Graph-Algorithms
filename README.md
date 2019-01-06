**Author: Adam Kapica**
### Task: "AAL.14"
  - Find all connected components in graph
  - Find graph diameter
  - Find diameters in every connected component if a graph is disconnected
  - Find MST in a graph if it is connected
  - Find MST in every connected component if a graph is disconnected
  - If a graph is disconnected, find a proposal to make it connected
  - Find all cliques in a graph


### Command line arguments

| Arguments | Meaning |
| ------ | ------ |
| -a file_name| Execute with input from a file which name is file_name |
| -b | Execute with input from standard input|
| -c | Execute with generated data |
| -d | Execute with generated data + measure time|

### Input format

n m  
Vi Vj IJvalue  
...  
Vx Vy XYvalue  

where:  
n = Vertices count  
m = Edges count  
Vi, Vj = Vertices indexes  
IJvalue = Value of edge between i-vertex and j-vertex

### Algorithms
  - DFS to find connected components in a graph
  - BFS to find the diameter in a graph/connected components
  - Kruskal's algorithm to find MST
  - Brute-force to find all cliques
  - Heuristic algorithm to find all cliques effectively
