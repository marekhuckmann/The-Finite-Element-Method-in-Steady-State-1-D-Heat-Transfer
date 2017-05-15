#include "mesh.h"

mesh::mesh(int ne, int nh, element *e) {

	this->nh = nh;
	this->HG = new double *[nh];
    for (int i = 0; i < nh; i++)
		HG[i] = new double[nh];

	this->T = new double[nh];
    this->PG = new double[nh];


	for (int i = 0; i <nh; i++) {
		for (int j = 0; j < nh; j++)
				HG[i][j] = 0;
	}

	for (int i = 0; i <nh; i++) {
			T[i] = 0;
	}

	for (int i = 0; i <nh; i++) {
			PG[i] = 0;
	}

	// Merging local matrixes into global ones

	for (int i = 0; i < ne; i++) {
		PG[(e[i].left.ID) - 1] += e[i].PL[0];
		PG[(e[i].right.ID) - 1] += e[i].PL[1];

		HG[(e[i].left.ID) - 1][(e[i].left.ID) - 1] += e[i].HL[0][0];
        HG[(e[i].left.ID) - 1][(e[i].right.ID) - 1] += e[i].HL[0][1];
		HG[(e[i].right.ID) - 1][(e[i].left.ID) - 1] += e[i].HL[1][0];
		HG[(e[i].right.ID) - 1][(e[i].right.ID) - 1] += e[i].HL[1][1];
	}
}
void mesh::showUR() {
	cout << "\nMatrix equation:\n";

	for(int i = 0; i < nh; i++) {
		cout << "|";
		for (int j = 0; j < nh; j++) {
			cout << HG[i][j]<<" ";
		}
		cout << "|\tt" << i+1 << " +  ";

		cout << "\t|" << PG[i] << "|\n";
	}
}

void mesh::gaussJordan() {
	double **a = new double*[nh];
	for (int i = 0; i < nh; i++) {
		int j = nh + 1;
			a[i] = new double[j];
		}

	for (int i = 0; i <nh; i++) {
		for (int j = 0; j <nh; j++) {
			a[i][j] = HG[i][j];
			a[i][nh] = PG[i] * (-1);
		}
	}

	for (int i=0;i<nh;i++)
        for (int k=i+1;k<nh;k++)
            if (a[i][i]<a[k][i])
                for (int j=0;j<=nh;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }

    for (int i=0;i<nh-1;i++)
        for (int k=i+1;k<nh;k++)
            {
                double t=a[k][i]/a[i][i];
                for (int j=0;j<=nh;j++)
                    a[k][j]=a[k][j]-t*a[i][j];
            }

    for (int i=nh-1;i>=0;i--)
    {
        T[i]=a[i][nh];
        for (int j=0;j<nh;j++)
            if (j!=i)
                T[i]=T[i]-a[i][j]*T[j];
        T[i]=T[i]/a[i][i];
    }
}

void mesh::showResults() {
    cout << "\nResults:\n";
	for (int i = 0; i < nh; i++) {
		cout << "t" << i+1 << " = " << T[i]<< "\n";
	}
}