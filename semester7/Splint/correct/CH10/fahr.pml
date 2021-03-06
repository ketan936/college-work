c_state "float fahr" "Local main"
c_state "float celsius" "Local main"

active proctype main()
{   int lower;
    int upper;
    int step;

    c_code { Pmain->lower=0; };
    c_code { Pmain->upper=300; };
    c_code { Pmain->step=20; };
    c_code { Pmain->fahr=Pmain->lower; };

    do
    :: c_expr { (Pmain->fahr <= Pmain->upper) };
       c_code { Pmain->celsius =
                    ((5.0/9.0)*(Pmain->fahr-32.0)); };
       c_code { Printf("%4.0f %6.1f\n",
                    Pmain->fahr, Pmain->celsius); };
       c_code { Pmain->fahr = (Pmain->fahr+Pmain->step); };
    :: else -> break
    od
}
