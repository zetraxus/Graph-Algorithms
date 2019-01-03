//
// Created by adam on 19.12.18.
//

#include <iostream>
#include <algorithm>
#include <chrono>
#include "AlgorithmLogic.h"

void AlgorithmLogic::computeConnectedComponents(Graph* graph) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    DFS(graph);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    graph->getTimes().setCCTime(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
}

unsigned AlgorithmLogic::computeDiameterGraph(Graph* graph) {
    unsigned diameter = 0;
    unsigned time = 0;
    for (unsigned i = 0; i < graph->getConnectedComponentsCount(); ++i) {
//        unsigned diameter = 0;
        ConnectedComponent* analysed = graph->getConnectedComponentsVector(i);

        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        for (unsigned j = 0; j < graph->getConnectedComponentsSize(i); ++j) {
            unsigned candidate = BFS(analysed, analysed->getVertex(j));
            if (candidate > diameter)
                diameter = candidate;
        }
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        time += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    graph->getTimes().setDiameterTime(time);

    return diameter;
}

std::vector<std::vector<unsigned> > AlgorithmLogic::computeCliquesBruteForce(Graph* graph) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    const std::vector<std::vector<unsigned> > subsets = getAllSubsets(graph->getVerticesCount());
    std::vector<std::vector<unsigned> > cliques;

    bool isClique;
    for (int i = 0; i < subsets.size(); ++i) {
        isClique = true;
        for (int j = 0; j < subsets[i].size(); ++j) {
            for (int k = j + 1; k < subsets[i].size(); ++k) {
                if (!graph->getVertex(subsets[i][j])->isNeighbour(graph->getVertex(subsets[i][k]))) {
                    isClique = false;
                    break;
                }
            }
            if (!isClique)
                break;
        }

        if (isClique)
            cliques.push_back(subsets[i]);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    graph->getTimes().setCliqueBruteForceTime(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

    return cliques;
}

std::vector<Clique*> AlgorithmLogic::computeCliquesHeuristic(Graph* graph) {
    std::vector<Clique*> cliques;
    std::vector<Vertex*> vertices;
    unsigned newCliqueInLastLoop = 0;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    for (unsigned i = 0; i < graph->getConnectedComponentsCount(); ++i) {
        vertices = graph->getConnectedComponentsVector(i)->getVertices();
        std::sort(vertices.begin(), vertices.end(), [](Vertex* a, Vertex* b) {
            return a->getDegree() < b->getDegree();
        });

        for (unsigned i = 0; i < vertices.size(); ++i) {
            Clique* oneElementClique = new Clique(vertices[i]);
            cliques.push_back(oneElementClique);
            ++newCliqueInLastLoop;
        }

        while (!newCliqueInLastLoop) {
            newCliqueInLastLoop = computeNextCliques(cliques, vertices, vertices.size() - newCliqueInLastLoop);
        }
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    graph->getTimes().setCliqueHeuristicTime(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

    return cliques;
}

MSTgraph* AlgorithmLogic::MSTonConnectedComponents(Graph* graph) {
    MSTgraph* mstGraph = new MSTgraph();

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::vector<std::vector<edgeDef> > results;
    for (unsigned i = 0; i < graph->getConnectedComponentsCount(); ++i) {
        if (graph->getConnectedComponentsSize(i) == 1)
            mstGraph->addToIsolatedVertices(graph->getConnectedComponentsVector(i)->getVertex(0)->getId());
        else
            mstGraph->addVectorToMSTonCC(MST(graph->getConnectedComponentsVector(i), graph->getVerticesCount()));
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    graph->getTimes().setMSTCCTime(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

    return mstGraph;
}

MSTgraph* AlgorithmLogic::MSTonGraph(MSTgraph* mstGraph, Graph*& graph) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    mstGraph->computeMSTonGraph();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    graph->getTimes().setMSTGraphTime(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

    return mstGraph;
}