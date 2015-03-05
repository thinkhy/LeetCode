#include <stdio.h>

typedef struct {
    long type;
    long mrows;
    long ncols;
    long imagf;
    long namelen;
} Fmatrix;

int main() {
    char *pname;
    double *pr;
    double *pi;
    Fmatrix x;

    int mn;
    FILE *fp;

    double real_data = 1.0;
    double imag_data = 2.0;

    fp = fopen("mymatfile.mat", "wb");
    if (fp != NULL) {
        pname = "x";
        x.type = 1000;
        x.mrows = 1;
        x.ncols = 1;
        x.imagf = 1;
        x.namelen = 2;
        pr = &real_data;
        pi = &imag_data;
        fwrite(&x, sizeof(Fmatrix), 1, fp);
        fwrite(pname, sizeof(char), x.namelen, fp);
        
        mn = x.mrows *x.ncols;
        fwrite(pr, sizeof(double), mn, fp);

        if(x.imagf)
            fwrite(pi, sizeof(double), mn, fp);
    }
    else
        printf("File could not be opened.\n");

    fclose(fp);

    return 0;
}
