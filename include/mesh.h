#include <iostream>
#include "element.h"
#include "node.h"


class mesh
{
    public:
        mesh(int ne, int nh, element *e);
        int nh;
        int ne;
        double **HG;
        double *PG;
        double *T;

        void showME();
        void gaussJordan();
        void showResults();
};
