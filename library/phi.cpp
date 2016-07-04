
#define N 501

int phi[N];
void phi() {
    for(int i = 1;i < N;i++) {
        phi[i] = i;
    }
    for(int i = 2;i < N;i++) {
        if(phi[i] == i){
            for(int j = i;j < N;j += i) {
                phi[j] /= i;
                phi[j] *= i-1;
            }
        }
    }
}
