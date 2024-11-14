# Exact and Rapid Linear Clustering of Networks with Dynamic Programming

**Course:** Advanced Algorithms (CS354)  
**Project Team:**  
- Naveen (21CSB0B69)  
- Junaid (21CSB0B36)  
- Vishal (21CSB0B11)  

**Presented to:**  
Dr. Manish Kumar Bajpai

---

## Introduction
This project addresses clustering within ultra low-dimensional networks, focusing on one-dimensional spatial networks. Many such networks represent physical or spatial data, such as geographic locations or other one-dimensional metrics. Here, we develop and implement an efficient clustering algorithm for partitioning nodes into contiguous communities using Dynamic Programming (DP).

---

## Problem Statement
- **Input**: Given \( N \) points in a one-dimensional plane, each node has a score \( x \).
- **Objective**: Partition the nodes into \( q \) contiguous communities, or layers, \( L = \{L_1, L_2, \ldots, L_q\} \), such that for any three nodes \( i, j, k \) with scores \( x_i > x_j > x_k \), nodes \( i \) and \( k \) belong to the same community if and only if node \( j \) is also in that community.
  
---

## Key Points
- **Input**: A one-dimensional network of nodes based on observed covariates.
- **Optimization Goal**: To find an optimal partition of nodes into communities that maximizes a quality function, \( Q(L) = \sum_{p=1}^{q} f(L_p) \).
- **Community Representation**: Layers are represented as contiguous groups of nodes.
- **Optimality**: The algorithm ensures an optimal partition based on the given objective function.
- **Partitioning Rule**: Nodes are grouped based on their scores and relative positions, ensuring consistency in clustering.

---

## Main Contribution
This project introduces a rapid clustering method for contiguous communities in one-dimensional space using dynamic programming. Our approach achieves an optimal solution in \( O(n^2) \) time complexity, where \( n \) is the number of nodes, independent of the number of clusters, \( q \).

---

## Class of Hardness
The linear clustering problem is NP-hard, as verifying an optimal solution in polynomial time is infeasible. We demonstrate that the problem can be reduced from the graph partition problem, which is a known NP-hard problem.

---

## Terminology and Objective Functions
- **Layer Notation**: \( L_{i,j} \) denotes a layer containing nodes from \( i \) through \( j \).
- **Quality Function**: \( f(L_{i,j}) \) denotes the quality of layer \( L_{i,j} \).
- **Objective Functions**:
  - **Objective Function 1** maximizes internal edges but often leads to trivial solutions.
  - **Objective Function 2** incorporates penalties to avoid uninteresting solutions by factoring in the number of nodes and edges in each layer.

---

## Existing Solutions and Proposed Solution
- **Existing Solutions**: Algorithms like the critical gap method or greedy strategies provide approximate solutions but are computationally intensive for large networks.
- **Proposed Solution**:
  - **Preprocessing**: Nodes are ordered by non-increasing scores, and nodes with identical scores are grouped into super-nodes.
  - **Dynamic Programming (DP) Approach**: Our DP algorithm recursively calculates the optimal partitions by maximizing quality functions over possible separations. The optimal partition is backtracked from stored indices.

---

## Implementation
The algorithm is implemented in C++ (refer to CPP documentation [here](https://en.cppreference.com/w/)).

---

## Limitations and Future Improvements
- **Limitations**:
  - The algorithm is designed for one-dimensional clustering and may not scale well for very large networks due to its \( O(n^2) \) complexity.
  - The DP approach is limited to linear clustering; extensions to higher dimensions would require significant changes.

- **Future Improvements**:
  - Extend the algorithm to two-dimensional hyperbolic space by incorporating radial and angular dimensions.
  - Develop a divide-and-conquer strategy to improve scalability by processing smaller network chunks.

---

## Conclusion
This project successfully implements a rapid linear clustering algorithm for one-dimensional networks using dynamic programming. The algorithm achieves optimal clustering with proven accuracy, marking a significant step in efficiently partitioning spatial networks.

---

## References
- [Exact and Rapid Linear Clustering of Networks with Dynamic Programming](https://arxiv.org/abs/2301.10403)
- [C++ Documentation](https://en.cppreference.com/w/)
- [Spatial Networks](https://www.sciencedirect.com/science/article/abs/pii/S037015731000308X?via%3Dihub)
- [A Survey of Graph Layout Problems](https://dl.acm.org/doi/10.1145/568522.568523)

### Citation
Patania, Alice, Allard, Antoine, and Young, Jean-Gabriel. "Exact and rapid linear clustering of networks with dynamic programming." *Proceedings of the Royal Society A*, vol. 479, no. 2275, 2023, pp. 20230159. The Royal Society.
