//
// Created by Diana Grigore on 05-Apr-20.
//

#include "MatriceAdiacenta.h"


MatriceAdiacenta :: MatriceAdiacenta(int m, int n, int val) : m{m}, n{n} {
    matrice = new int* [m];
    for (int i = 0; i < m; i++)
        matrice[i] = new int [n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrice[i][j] = val;
}

MatriceAdiacenta ::~MatriceAdiacenta() {
    for (int i = 0; i < m; i++)
        delete [] matrice[i];
    delete [] matrice;
    m = 0;
    n = 0;
}

MatriceAdiacenta ::MatriceAdiacenta(const MatriceAdiacenta &matrix) {
    m = matrix.m;
    n = matrix.n;
    matrice = new int* [m];
    for (int i = 0; i < m; i++)
        matrice[i] = new int [n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrice[i][j] = matrix.matrice[i][j];

}

void swap(MatriceAdiacenta &first, MatriceAdiacenta &second){
    using std :: swap;
    swap(first.m, second.m);
    swap(first.n, second.n);
    swap(first.matrice,second.matrice);
}

std :: istream &operator >>(std :: istream &in, MatriceAdiacenta &matrix){
    for (int i = 0; i < matrix.m; i++)
        delete [] matrix.matrice[i];
    delete [] matrix.matrice;
    in >> matrix.m >> matrix.n;
    matrix.matrice = new int* [matrix.m];
    for (int i = 0; i < matrix.m; i++)
        matrix.matrice[i] = new int [matrix.n];
    for (int i = 0; i < matrix.m; i++)
        for (int j = 0; j < matrix.n; j++)
            in >> matrix.matrice[i][j];
    return in;
}

std :: ostream &operator <<(std :: ostream &out, const MatriceAdiacenta &matrix){
    for (int i = 0; i < matrix.m; i++){
        for (int j = 0; j < matrix.n; j++)
            out << matrix.matrice[i][j] << " ";
        out << '\n';
    }
    return out;
}

MatriceAdiacenta  &MatriceAdiacenta :: operator =(MatriceAdiacenta matrix){
    if(this != &matrix)
        swap(*this, matrix);
    return *this;

}

int MatriceAdiacenta :: getrows() const {
    return m;
}

int MatriceAdiacenta :: getcolumns() const {
    return n;
}

int * MatriceAdiacenta :: parcurgere_latime(int nod_start) {
    int* viz = new int [n];
    for (int i = 0; i < n; i++)
        viz[i] = 0;
    viz[nod_start - 1] = 1;
    int prim = 1;
    int ultim = 1;
    int *parcurgere = new int [n + 2];
    parcurgere[ultim] = nod_start - 1;
    while (prim <= ultim) {
        for(int i = 0; i < n; i++)
            if(matrice[parcurgere[prim]][i] == 1 && viz[i] == 0)
            {
                ultim++;
                parcurgere[ultim] = i;
                viz[i] = 1;
            }
        prim++;
    }
    delete [] parcurgere;
    return viz;

}