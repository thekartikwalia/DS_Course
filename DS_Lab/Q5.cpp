#include <iostream>
using namespace std;
struct Element{
    int i, j, x;
};
struct Sparse{
    int n, m, num;
    Element *e;
};
void create(Sparse &s){
    cout << "Enter dimensions (row x column): ";
    cin >> s.m >> s.n;
    cout << "Enter no. of non-zero elements: ";
    cin >> s.num;
    s.e = new Element[s.num];
    cout << "Enter all non-zero elements: ";
    for (int i = 0; i < s.num; i++){
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
}
void display(const Sparse &s){
    int k = 0;
    for (int i = 0; i < s.m; i++){
        for (int j = 0; j < s.n; j++){
            if (i == s.e[k].i && j == s.e[k].j){
                cout << s.e[k++].x << " ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
Sparse *add(const Sparse &s1, const Sparse &s2){
    Sparse *sum = new Sparse;
    sum->e = new Element[s1.num + s2.num];
    int i = 0, j = 0, k = 0;
    while (i < s1.num && j < s2.num){
        if (s1.e[i].i < s2.e[j].i){
            sum->e[k++] = s1.e[i++];
        }else if (s1.e[i].i > s2.e[j].i){
            sum->e[k++] = s2.e[j++];
        }else{
            if (s1.e[i].j < s2.e[j].j){
                sum->e[k++] = s1.e[i++];
            }else if (s1.e[i].j > s2.e[j].j){
                sum->e[k++] = s2.e[j++];
            }else{
                sum->e[k] = s1.e[i];
                sum->e[k].x = s1.e[i++].x + s2.e[j++].x;
                k++;
            }
        }
    }
    while (i < s1.num){
        sum->e[k++] = s1.e[i++];
    }
    while (j < s2.num){
        sum->e[k++] = s2.e[j++];
    }
    sum->m = s1.m;
    sum->n = s1.n;
    sum->num = k;
    return sum;
}
Sparse *transpose(const Sparse &s){
    Sparse *result = new Sparse;
    result->m = s.n;
    result->n = s.m;
    result->num = s.num;
    result->e = new Element[result->num];
    int *colCount = new int[s.n]();
    int *colPosition = new int[s.n]();
    for (int i = 0; i < s.num; i++){
        colCount[s.e[i].j]++;
    }
    colPosition[0] = 0;
    for (int i = 1; i < s.n; i++){
        colPosition[i] = colPosition[i - 1] + colCount[i - 1];
    }
    for (int i = 0; i < s.num; i++){
        int j = s.e[i].j;
        result->e[colPosition[j]].i = s.e[i].j;
        result->e[colPosition[j]].j = s.e[i].i;
        result->e[colPosition[j]].x = s.e[i].x;
        colPosition[j]++;
    }
    delete[] colCount;
    delete[] colPosition;
    return result;
}
Sparse *multiply(const Sparse &s1, const Sparse &s2){
    if (s1.n != s2.m){
        cout << "Matrix Multiplication not possible!" << endl;
        return nullptr;
    }
    Sparse *result = new Sparse;
    result->m = s1.m;
    result->n = s2.n;
    result->num = 0;
    result->e = new Element[result->num];
    int sum, k = 0;
    for (int i = 0; i < s1.m; i++){
        for (int j = 0; j < s2.n; j++){
            sum = 0;
            for (int l = 0; l < s1.num; l++){
                for (int m = 0; m < s2.num; m++){
                    if (s1.e[l].j == s2.e[m].i && s1.e[l].i == i && s2.e[m].j == j){
                        sum += s1.e[l].x * s2.e[m].x;
                    }
                }
            }
            if (sum != 0){
                result->num++;
                result->e = new Element[result->num];
                result->e[k].i = i;
                result->e[k].j = j;
                result->e[k].x = sum;
                k++;
            }
        }
    }
    return result;
}
int main(){
    Sparse s1, s2, *s3, *transposedMatrix, *s4;
    create(s1);
    create(s2);
    s3 = add(s1, s2);
    transposedMatrix = transpose(s1);
    cout << "First Matrix:" << endl;
    display(s1);
    cout << "Second Matrix:" << endl;
    display(s2);
    cout << "Sum Matrix:" << endl;
    display(*s3);
    cout << "Transpose Matrix:" << endl;
    display(*transposedMatrix);
    s4 = multiply(s1, s2);
    cout << "Product Matrix" << endl;
    display(*s4);
    delete[] s1.e;
    delete[] s2.e;
    delete[] s3->e;
    delete[] transposedMatrix->e;
    delete s3;
    delete transposedMatrix;
    return 0;
}

