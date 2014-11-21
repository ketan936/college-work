#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int prime(int n)
{
        int i, flag = 0;
        for (i = 2; i <= n / 2; ++i) {
                if (n % i == 0) {
                        flag = 1;
                        break;
                }
        }
        return flag;
}
int find_prime(int x)
{
        printf("inside prime: %d \n",x);
        int i;
        for (i = x+1; i; i++) {
                if (prime(i)==0)
                        return i;

        }
        return 0;
}
int positive_modulo(int i, int n)
{
        return (i % n + n) % n;
}
int mode(int n, int p, int r)
{
        int i;
        int a1 = positive_modulo(n, r);
        int q = 1;
        for (i = 1; i <= p; i++) {
                q *= a1;
                q = positive_modulo(q, r);
        }
        return q;
}
int gcd(int a, int b)
{
        if (b == 0)
                return a;
        else
                return gcd(b, positive_modulo(a, b));
}

int coprime(int e, int n)
{
        return (gcd(e, n) == 1);
}
struct p_text
{
        char char_s[20];
        int value;
};
int main()
{
        //encryption
        FILE *fp;
        time_t t;
        int k, b_size, i, j, pro = 0, max = 0, n1, n2, n, e, p, d, powe, m;
        char ch;
        struct p_text b_no[100], cip[100], dec[100];
        fp = fopen("plain.txt", "r");
        printf("Enter block size:");
        scanf("%d", &b_size);
        i = 0;
        j = 0;
        while ((ch = fgetc(fp)) != EOF) {
                b_no[j].char_s[i] = ch;
                pro = pro + pow(26, (b_size - i - 1)) * (ch - 65);
                i++;
                if (i == b_size) {
                        b_no[j].char_s[i] = '\0';
                        b_no[j].value = pro;
                        i = 0;
                        j++;
                        pro = 0;

                }

        }
        while (i < b_size) {
                b_no[j].char_s[i] = 'X';
                pro = pro + pow(26, (b_size - i - 1)) * ('X' - 65);
                i++;
        }
        b_no[j].value = pro;
        b_no[j].char_s[i] = '\0';
        for (i = 0; i <= j; i++)
                printf("%s ", b_no[i].char_s);
        printf("\n");
        for (i = 0; i <= j; i++)
                printf("%d ", b_no[i].value);
        printf("\n");
        fclose(fp);
        for (i = 0; i < b_size; i++)
                max = max + pow(26, i) * 25;
        printf("Maximum value can be: %d", max);
        //random number generation
        srand((unsigned) time(&t));
        printf("\n");

        n1 = find_prime(sqrt(max));
        n2 = find_prime(n1);

        printf("two prime numbers:%d %d\n", n1, n2);
        n = n1 * n2;
        printf("Value of n: %d\n", (n1 * n2));
        printf("Value of phi: %d\n", ((n1 - 1) * (n2 - 1)));
        p = ((n1 - 1) * (n2 - 1));
        e = find_prime(sqrt(p));
        d = find_prime(e);

        for (i = 0; i < p; i++) {
                if ((i * e) % p == 1) {
                        printf("Value of D: %d", i);
                        break;
                }
        }
        d = i;
        printf("\n");
        printf("Public key: {%d ,%d}\n", e, n);
        printf("Private key: {%d ,%d}\n", d, n);
        printf("ciphertext :");
        for (i = 0; i <= j; i++) {
                cip[i].value = mode(b_no[i].value, e, n);
                printf("%d ", cip[i].value);
        }

        //Decryption
        printf("\n");
        printf("Decrypted: ");
        for (i = 0; i <= j; i++) {
                dec[i].value = mode(cip[i].value, d, n);
                printf("%d ", dec[i].value);
        }
        for (i = 0; i <= j; i++) {
                k = 0;
                while (k < b_size) {
                        m = 0;
                        powe = pow(26, (b_size - 1 - k));
                        if (powe > dec[i].value)
                                dec[i].char_s[k] = 'A';
                        else {
                                while (powe * m < dec[i].value) {
                                        m++;
                                }
                                if (powe == 1)
                                        dec[i].char_s[k] = 65 + m;
                                else
                                        dec[i].char_s[k] = 65 + m - 1;
                                dec[i].value = dec[i].value - ((m - 1) * powe);
                        }
                        k++;
                }
                dec[i].char_s[k] = '\0';
        }
        printf("\n");
        for (i = 0; i <= j; i++) {
                dec[i].value = mode(cip[i].value, d, n);
                printf("%s ", dec[i].char_s);
        }
        return 0;

}
