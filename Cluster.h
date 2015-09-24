//
// Created by dragon5hoarder on 9/19/2015.
//

#ifndef INT_PA2_CLUSTER_H
#define INT_PA2_CLUSTER_H

#include "Point.h"

namespace Clustering {
    typedef Point *PointPtr;
    typedef struct Node *NodePtr;

    struct Node{
        PointPtr point;
        Node *next;
    };

    class Cluster{

    private:
        NodePtr points;
        int size;
        bool isPresent(PointPtr& point, NodePtr& head);

    public:
        Cluster();
        Cluster(const Cluster &copyCluster);
        void operator=(const Cluster &copyCluster);
        ~Cluster();

        // Set functions
        const PointPtr& add(const PointPtr &addedPt);
        const PointPtr& remove(const PointPtr &deletedPt);

        // overloaded operators
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        Cluster &operator+=(Point &rhs); // add point
        Cluster &operator-=(Point &rhs); // remove point

        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator-=(const Cluster &rhs); // difference

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);

        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);




        friend std::ostream &operator<<(std::ostream &os, const Cluster &output);
        friend std::istream &operator>>(std::istream &os, const Cluster &input);
    };

}

#endif //INT_PA2_CLUSTER_H
