#include<stdio.h>
#include<math.h>
#include<string.h>
float inverse[25][25];
void trim(char[]);
void cofactor(float[25][25], float);
void transpose(float[25][25], float[25][25], float);
float determinant(float a[25][25], float k)
{
        float s = 1, det = 0, b[25][25];
        int i, j, m, n, c;
        if (k == 1)
                return (a[0][0]);
        else {
                det = 0;
                for (c = 0; c < k; c++) {
                        m = 0;
                        n = 0;
                        for (i = 0; i < k; i++) {
                                for (j = 0; j < k; j++) {
                                        b[i][j] = 0;
                                        if (i != 0 && j != c) {
                                                b[m][n] = a[i][j];
                                                if (n < (k - 2))
                                                        n++;
                                                else {
                                                        n = 0;
                                                        m++;
                                                }
                                        }
                                }
                        }
                        det = det + s * (a[0][c] * determinant(b, k - 1));
                        s = -1 * s;
                }
        }
        return (det);
}
void strupr(char *string)
{
  for(; *string; string++)
    *string = toupper((unsigned char) *string);
}
void cofactor(float num[25][25], float f)
{
        float b[25][25], fac[25][25];
        int p, q, m, n, i, j;
        for (q = 0; q < f; q++) {
                for (p = 0; p < f; p++) {
                        m = 0;
                        n = 0;
                        for (i = 0; i < f; i++) {
                                for (j = 0; j < f; j++) {
                                        if (i != q && j != p) {
                                                b[m][n] = num[i][j];
                                                if (n < (f - 2))
                                                        n++;
                                                else {
                                                        n = 0;
                                                        m++;
                                                }
                                        }
                                }

                        }
                        fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
                }
        }
        transpose(num, fac, f);
}
/*transpose of matrix*/
void transpose(float num[25][25], float fac[25][25], float r)
{
        int i, j;
        float b[25][25], d;
        for (i = 0; i < r; i++)
                for (j = 0; j < r; j++)
                        b[i][j] = fac[j][i];
        d = determinant(num, r);
        for (i = 0; i < r; i++)
                for (j = 0; j < r; j++)
                        inverse[i][j] = b[i][j] / d;
        printf("\n\n\nThe inverse of matrix is : \n");
        for (i = 0; i < r; i++) {
                for (j = 0; j < r; j++)
                        printf("\t%f", inverse[i][j]);
                printf("\n");
        }
}

void encrypt(float a[25][25], char msg[], int k)
{
        FILE *fp;
        char msg1[1000], temp[3];
        int i, j, r, q = k, m = 0, n = 0, p = strlen(msg);
        int encr[1000];
        strcpy(msg1, msg);
        while ((p % q) != 0)
                msg1[p++] = 'X';
        for (i = 0; i < p; i++) {
                if (i < k)
                        temp[m++] = msg1[i];
                if (i == k || i == p - 1) {
                        r = 0;
                        while (r < q) {
                                encr[n] = 0;
                                for (j = 0; j < q; j++) {
                                        //printf("\n%d  %d",(int)a[r][j],(temp[j]-65));
                                        encr[n] =
                                                        (encr[n]
                                                                        + (temp[j]
                                                                                        - 65)
                                                                                        * (int) a[r][j]);
                                        while (encr[n] < 0)
                                                encr[n] = encr[n] + 26;
                                        encr[n] = encr[n] % 26;
                                }
                                r++;
                                n++;
                        }
                        if (i != p - 1) {
                                k = k + q;
                                m = 0;
                                temp[m++] = msg1[i];
                        }
                }
        }
        printf("\n Output : ");
        fp = fopen("cipher.txt", "w");
        for (i = 0; i < p; i++) {
                printf("%c", encr[i] + 65);
                fprintf(fp, "%c", encr[i] + 65);
        }
        fclose(fp);
}
int main()
{
        FILE *fp;
        float a[25][25], k, d;
        int i, j, ch, m, n, p;
        char msg[1000], dec[1000], msg2[1000];
        do {
                printf("\n\n1. To enter Key matrix\n");
                printf("2. For Input text\n");
                printf("3. For encryption\n");
                printf("4. For decryption\n");
                printf("5. For EXIT\n");
                printf("Your choice : ");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                        up: printf("Enter the order of the Matrix : ");
                        scanf("%f", &k);
                        printf("Enter the elements of %.0fX%.0f Matrix : \n", k,
                                        k);
                        for (i = 0; i < k; i++)
                                for (j = 0; j < k; j++)
                                        scanf("%f", &a[i][j]);
                        d = determinant(a, k);
                        printf("Determinant of the Matrix = %f", d);
                        if (d == 0) {
                                printf("\nNot Invertible! Enter Again...\n");
                                goto up;
                        } else
                                cofactor(a, k);
                        break;
                case 2:
                        fp = fopen("plain.txt", "r");
                        j = 0;
                        while ((ch = fgetc(fp)) != EOF)
                                msg[j++] = ch;
                        trim(msg);
                        printf("Input message : %s", msg);
                        fclose(fp);
                        break;
                case 3:
                        encrypt(a, msg, k);
                        break;
                case 4:
                        fp = fopen("cipher.txt", "r");
                        j = 0;
                        while ((ch = fgetc(fp)) != EOF)
                                msg2[j++] = ch;
                        trim(msg2);
                        printf("Input message : %s", msg2);
                        fclose(fp);
                        printf("\n\n\nThe inverse of matrix is : \n");
                        for (i = 0; i < k; i++) {
                                for (j = 0; j < k; j++)
                                        printf("\t%f", inverse[i][j]);
                                printf("\n");
                        }
                        encrypt(inverse, msg2, k);
                        break;
                }
        } while (ch != 5);

        return 0;
}
void trim(char msg[])
{
        int i, len, j, size;
        char msg1[1000];
        size = strlen(msg);
        strupr(msg);
        for (i = 0, j = 0; i < size; i++) {
                if ((msg[i] >= 65 && msg[i] <= 90)
                                || (msg[i] >= 97 && msg[i] <= 122))
                        msg1[j++] = msg[i];
        }
        msg1[j] = '\0';
        for (i = 0; i < strlen(msg1); i++) {
                msg[i] = msg1[i];
        }
        msg[i] = '\0';
}
/*For calculating Determinant of the Matrix */

