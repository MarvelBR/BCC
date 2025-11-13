#include <iostream>
using namespace std;

template <typename T>
T soma_array(T* arr, int n){
	T sum = 0;
	for (int i = 0; i < n; i++){
		sum += arr[i];
    }
    return sum;
}

int main(){

    int v[] = {3, 4, 1, 6, 2, 0};
    float u[] = {1.5, 2.4, 1.3};
    double w[] = {3.1, 5.0, 2.3};
    unsigned char y[] = {0, 244, 152};
    unsigned long long z[] = {69, 69, 69};

    auto soma_v = soma_array(v, 6);
    float soma_u = soma_array(u, 3);
    double soma_w = soma_array<double>(w, 3);
    int soma_y = soma_array(y, 3);
    unsigned long long soma_z = soma_array(z, 3);

    cout << "soma_v:" << soma_v << "\n";
    cout << "soma_u:" << soma_u << "\n";
    cout << "soma_w:" << soma_w << "\n";
    cout << "soma_y:" << soma_y << "\n";
    cout << "soma_z:" << soma_z << "\n";


    return 0;
}