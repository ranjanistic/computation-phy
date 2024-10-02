#include <stdio.h>
#include <math.h>

float manual()
{
    float x, t, s, f;
    int n;
    for (x = 0.2; x <= 2.1; x += 0.1)
    {
        t = 1.0 / (x * x);
        s = t;
        n = 1;
        do
        {
            t *= 1 / x;
            s += t;
            n += 1;
        } while (n <= 18);
        s = 1 + s;
        printf("manual: x=%f sum=%f\n", n + 1, x, s);
    };
}

int main()
{
    float terms = 40;
    for (float x = 0.2; x <= 2.1; x += 0.1)
    {
        float sum = 0;
        float t = 1 / (x * x);
        for (int term = 1; term <= terms; term++)
        {
            if (term == 1)
            {
                sum += 1;
            }
            else
            {
                t *= 1 / pow(x, 1);
                sum += t;
            }
        }
        printf("x=%f,Sum=%f\n", x, sum);
    }
}
