//Reading
#define MXBC 200000

char buffer_to[MXBC];
char *buffer_ptr = buffer_to;

int scan_integer() {
    int k = 0;
    while (*buffer_ptr < 33) {
        buffer_ptr++;
    }
    do {
        k = k*10 + *buffer_ptr++ - '0';
    } while(*buffer_ptr > 32);
    return k;
}

fread(buffer_to, 1, MXBC, stdin);

//Writing
#define MAXOUT 500005
char buffer_out[MAXOUT];
char *buffer_ptr2 = buffer_out;

void write(long long n) {
    buffer_ptr2 += sprintf(buffer_ptr2, "%lld\n", n);
}

void to_stdout() {
    printf("%s", buffer_out);
}
