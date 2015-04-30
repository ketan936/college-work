struct input_calc{
float a;
float b;
int op;
};

program CALC_PROG {
    version CALC_VERS {
        float CALCULATOR(input_calc) = 1;    /* procedure number = 1 */
    } = 1;                          /* version number = 1 */
} = 0x31234568;                     /* program number = 0x31234567 */