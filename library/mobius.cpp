
#define MAXN 1000000
int mu[MAXN];

void mobius() {
    for (int i = 1; i < MAXN; i++)
        mu[i] = 1;

    int rt = (int)sqrt(MAXN + 0.5);
    for (int i = 2; i <= rt; i++) {
        if (mu[i] == 1) {
            for (int j = i;j < MAXN; j += i)
                mu[j] *= -i;
            for (int j = i*i;j < MAXN; j += i*i)
                mu[j] = 0;
        }
    }

    for (int i = 2; i < MAXN; i++) {
        if (mu[i] == i) mu[i] = 1;
        else if (mu[i] == -i) mu[i] = -1;
        else if (mu[i] < 0) mu[i] = 1;
        else if (mu[i] > 0) mu[i] = -1;
    }
}

//By marioyc
int N = 15;
int mu[N+1];

void mobius2() {
    memset(mu, 0, sizeof(mu));
    mu[1] = 1;

    for(int i = 1;i <= N;++i)
        for(int j = 2*i;j <= N;j += i)
            mu[j] -= mu[i];
}
