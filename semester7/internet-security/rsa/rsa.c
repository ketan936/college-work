#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
long long prime(long long n)
{
        long long i, flag = 0;
        for (i = 2; i <= n / 2; ++i) {
                if (n % i == 0) {
                        flag = 1;
                        break;
                }
        }
        return flag;
}
long long find_prime(long long x)
{
        printf("inside prime: %lld \n",x);
        long long i;
        for (i = x+1; i; i++) {
                if (prime(i)==0)
                        return i;

        }
        return 0;
}
long long positive_modulo(long long i, long long n)
{
        return (i % n + n) % n;
}
long long mode(long long n, long long p, long long r)
{
        long long i;
        long long a1 = positive_modulo(n, r);
        long long q = 1;
        for (i = 1; i <= p; i++) {
                q *= a1;
                q = positive_modulo(q, r);
        }
        return q;
}
long long gcd(long long a, long long b)
{
        if (b == 0)
                return a;
        else
                return gcd(b, positive_modulo(a, b));
}

long long coprime(long long e, long long n)
{
        return (gcd(e, n) == 1);
}
struct p_text
{
        char char_s[20];
        long long value;
};
long long main()
{
        //encryption
        FILE *fp;
        time_t t;
        long long k, b_size, i, j, pro = 0, max = 0, n1, n2, n, e, p, d, powe, m;
        char ch;
        struct p_text b_no[100], cip[100], dec[100];
        fp = fopen("plain.txt", "r");
        printf("Enter block size:");
        scanf("%lld", &b_size);
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
                printf("%lld ", b_no[i].value);
        printf("\n");
        fclose(fp);
        for (i = 0; i < b_size; i++)
                max = max + pow(26, i) * 25;
        printf("Maximum value can be: %lld", max);
        //random number generation
        srand((unsigned) time(&t));
        printf("\n");

        n1 = find_prime(sqrt(max));
        n2 = find_prime(n1);

        printf("two prime numbers:%lld %lld\n", n1, n2);
        n = n1 * n2;
        printf("Value of n: %lld\n", (n1 * n2));
        printf("Value of phi: %lld\n", ((n1 - 1) * (n2 - 1)));
        p = ((n1 - 1) * (n2 - 1));
        e = find_prime(sqrt(p));
        d = find_prime(e);

        for (i = 0; i < p; i++) {
                if ((i * e) % p == 1) {
                        printf("Value of D: %lld", i);
                        break;
                }
        }
        d = i;
        printf("\n");
        printf("Public key: {%lld ,%lld}\n", e, n);
        printf("Private key: {%lld ,%lld}\n", d, n);
        printf("ciphertext :");
        for (i = 0; i <= j; i++) {
                cip[i].value = mode(b_no[i].value, e, n);
                printf("%lld ", cip[i].value);
        }

        //Decryption
        printf("\n");
        printf("Decrypted: ");
        for (i = 0; i <= j; i++) {
                dec[i].value = mode(cip[i].value, d, n);
                printf("%lld ", dec[i].value);
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
