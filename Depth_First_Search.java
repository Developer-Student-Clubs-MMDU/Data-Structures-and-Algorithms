//Adjacency Matrix Representation of Graphs using Depth First Search

//What is DFS?
// Depth First Traversal (or Search) for a graph is similar to 
// Depth First Traversal of a tree. The only catch here is, that, 
// unlike trees, graphs may contain cycles (a node may be visited twice).
// To avoid processing a node more than once, use a boolean visited array. 
// A graph can have more than one DFS traversal.

//Example of input:
//4
// 6
// 1 2
// 1 3
// 2 3
// 3 1
// 3 4
// 4 4

//Example of output:
// 0->1->2->3

//importing the required packages
import java.util.*;
import java.io.*;

//Class to represent every node of a graph
class Node {
    int val;
    boolean visited;

    Node(int val) {
        this.val = val;
        this.visited = false;
    }
}

// Class to represent a graph with Node objects
class Graph {
    int numNodes;
    int[][] adjMat;
    Node[] nodeL;

    // Constructor to initialize the graph
    Graph(int size) {
        numNodes = 0;
        adjMat = new int[size][size];
        nodeL = new Node[size];
    }

    // Method to add a node to the graph
    void addNode(int el) {
        nodeL[this.numNodes++] = new Node(el);
    }

    // Method to add an edge to the graph
    void addEdge(int s, int e) {
        adjMat[s][e] = 1;
        adjMat[e][s] = 1;
    }

    // Method to get the adjacent Nodes to a particular Node
    int getAdjUnN(int node) {
        for (int i = 0; i < this.numNodes; i++) {
            if (adjMat[node][i] == 1 && !nodeL[i].visited)
                return i;
        }
        return -1;
    }

    // Recursive function to perform DFS
    void dfs(int n) {
        nodeL[n].visited = true;
        int n1;
        System.out.print(n + "->");
        while ((n1 = getAdjUnN(n)) != -1) {
            dfs(n1);
        }
    }

    // Recursive function to perform DFS and handling disconnected graphs
    void dft() {
        for (int i = 0; i < numNodes; i++) {
            if (!nodeL[i].visited) {
                dfs(i);
            }
        }
    }
}

public class Depth_First_Search {

    public static void main(String args[]) throws IOException {

        Scanner sc = new Scanner(System.in);
        // Number of vertices
        int v = sc.nextInt();

        // Number of edges
        int e = sc.nextInt();

        // Initializing the graph
        Graph g = new Graph(v);
        for (int i = 0; i < v; i++)
            g.addNode(i);

        for (int i = 0; i < e; i++) {
            int u1 = sc.nextInt() - 1;
            int v1 = sc.nextInt() - 1;

            g.addEdge(u1, v1);
        }

        // Performing DFS
        g.dft();

    }
}