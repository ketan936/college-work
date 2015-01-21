active proctype main()
{   int step;
    int lower;
    int upper;
    int celsius;
    int fahr;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    do
    :: (fahr<=upper);
        celsius = ((fahr-32)*5)/9;
        printf("%d  %d\n", fahr, celsius);
        fahr=(fahr+step)
    :: else -> break
    od
}
