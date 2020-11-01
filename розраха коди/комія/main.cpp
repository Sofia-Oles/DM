#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int formation(int vershunu, int **arr);
void print(int vershunu, int **arr);
bool check_node(int *V, int vershunu, int Node);
int build(int vershunu, int **arr, int *V, int *counter_of_nodes);
void del(int vershunu, int **arr);
int min_numb(int vershunu, int min, int **arr, int *V, int i);

int main() {
    int vershunu, counter_of_nodes = 1, min = 999, rez = 0;
    cout << "Input size: ";
    cin >> vershunu;
    int *V = new int[vershunu];
    int *Vcon = new int[vershunu];

    int **arr = new int *[vershunu];
    for (int i = 0; i < vershunu; i++)
        arr[i] = new int[vershunu];
    cout << "Input matrix=";
    if (formation(vershunu, arr) == -1) {
        cout << "Program error" << endl;
    } else {
        print(vershunu, arr);
        cout << endl;
        delete[] V;
        for (int i = 0; i < vershunu; i++) {
            int *V = new int[vershunu];
            V[0] = i;
            counter_of_nodes = 1;
            rez = build(vershunu, arr, V, &counter_of_nodes);
        }
        cout << endl << "The shortest way:" << rez << endl;
        for (int i = 0; i < vershunu; i++) {

            if (i == vershunu - 1)
                cout << V[i] + 1;
            else cout << V[i] + 1 << " -> ";
        }
    del(vershunu, arr);
    delete[] Vcon;
    return 0;
}
}
int formation(int vershunu, int **arr) {
    for (int i = 0; i < vershunu; i++) {
        for (int j = 0; j < vershunu; j++) {
            cin >> arr[i][j];
            if (cin.fail()) {
                cout << "Input error" << endl;
                return -1;
            }
        }
    }
    return 1;
}
void print(int vershunu, int **arr) {
    for (int i = 0; i < vershunu; i++) {
        for (int j = 0; j < vershunu; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
}
void del(int vershunu, int **arr) {
    for (int i = 0; i < vershunu; i++) {
        delete[] arr[i];
    }
    delete[] arr;

}
bool check_node(int *V, int vershunu, int Node) {
    for (int i = 0; i < vershunu; i++)
        if (V[i] == Node)return false;
    return true;
}

int build(int vershunu, int **arr, int *V, int *counter_of_nodes) {
    int sum = 0, min;
    for (int i = 0; i < *counter_of_nodes; i++) {
        min = min_numb(vershunu, 999, arr, V, i);
        for (int j = 0; j < vershunu; j++)
            if (arr[V[i]][j] == min && check_node(V, vershunu, j)) {
                V[*counter_of_nodes] = j;
                (*counter_of_nodes)++;
                sum += arr[V[i]][j];
                break;
            }
    }
    return sum;
}
int min_numb(int vershunu, int min, int **arr, int *V, int i) {
    for (int j = 0; j < vershunu; j++)
        if (min > arr[V[i]][j] && arr[V[i]][j] != 0 && check_node(V, vershunu, j)) min = arr[V[i]][j];
    return min;}
