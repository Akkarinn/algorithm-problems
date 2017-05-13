/**
 * Source: https://leetcode.com/problems/minimum-height-trees/
 * 
 * For a undirected graph with tree characteristics, we can choose any node as the root.
 * The result graph is then a rooted tree. Among all possible rooted trees, those with
 * minimum height are called minimum height trees (MHTs). Given such a graph, write a
 * function to find all the MHTs and return a list of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1.
 * You will be given the number n and a list of undirected edges (each edge is a pair of labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges are
 * undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <vector>
#include <set>
#include <unordered_map>

namespace {

   class Solution {
      typedef int T_Node;
      typedef std::set<T_Node> T_Nodes;

      struct Graph {
         void addEdge(T_Node a, T_Node b) {
            nodes[a].insert(b);
            nodes[b].insert(a);
         }
         void addNode(T_Node a) {
            nodes.insert(std::make_pair(a, T_Nodes()));
         }
         void remove(T_Node a) {
            for (auto parent : nodes[a])
               nodes[parent].erase(a);
            nodes.erase(a);
         }
         std::size_t degree(T_Node n) const {
            return nodes.find(n)->second.size();
         }
         std::unordered_map<T_Node, T_Nodes> nodes;
      };

   public:
      std::vector<int> findMinHeightTrees(int n, std::vector<std::pair<T_Node, int>>& edges) {
         // Build the graph
         Graph g;
         for (auto i = 0; i < n; ++i)
            g.addNode(i);
         for (auto e : edges)
            g.addEdge(e.first, e.second);

         // Find the leaves
         std::set<T_Node> leaves(findLeaves(g));
         while (leaves.size() != n) {
            std::set<T_Node> nextLeaves;
            for (auto& leaf : leaves) {
               for (auto& parent : g.nodes[leaf]) {
                  if (g.degree(parent) == 2)
                     nextLeaves.insert(parent);
               }
               g.remove(leaf);
               --n;
            }
            leaves.swap(nextLeaves);
         }

         return std::vector<int>(leaves.begin(), leaves.end());
      }
   private:
      std::set<T_Node> findLeaves(const Graph& g) const {
         std::set<T_Node> leaves;
         for (const auto& n : g.nodes) {
            if (g.degree(n.first) <= 1)
               leaves.insert(n.first);
         }
         return leaves;
      }
   };
}

#define COMA ,

TEST_CASE( "Minimum Height Trees", "[test]" ) {
   typedef std::vector<std::pair<int, int> > T_Edges;

   Solution solver;

   CHECK(std::vector<int>{ 0 } == solver.findMinHeightTrees(1, T_Edges{}));
   CHECK(std::vector<int>{ 0 COMA 1 } == solver.findMinHeightTrees(2 COMA T_Edges{ { 0, 1 } }));
   CHECK(std::vector<int>{ 1 } == solver.findMinHeightTrees(4 COMA T_Edges{ { 0, 1 },{ 2, 1 },{ 3, 1 } }));
   CHECK(std::vector<int>{ 3 COMA 4 } == solver.findMinHeightTrees(6 COMA T_Edges{ { 0, 3 }, { 3, 1 }, { 3, 2 }, { 4, 4 }, { 5, 4} }));
}
