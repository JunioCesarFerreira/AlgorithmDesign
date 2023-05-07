#include <iostream>
#include <ctime>


// Time complexity O(phi^N) where phi = 1.618033...
uint64_t fibonacci_recursive(int n)
{
    if (n==0 || n==1) 
        return 1;
    
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}


// Time and Space complexity O(N)
uint64_t fibonacci_dp_top_down_rec(int n, uint64_t* array);
uint64_t fibonacci_dp_top_down(int n)
{
    if (n==0 || n==1) 
        return 1;

    uint64_t* array = new uint64_t[n];
    for (int i=0; i<n; i++) array[i]=0;

    uint64_t fn = fibonacci_dp_top_down_rec(n-1, array) + fibonacci_dp_top_down_rec(n-2, array);

    delete[] array; 

    return fn;
}
// use in fibonacci_dp_top_down
uint64_t fibonacci_dp_top_down_rec(int n, uint64_t* array)
{
    if (n==0 || n==1) 
        return 1;

    if (array[n]==0)
        array[n] = fibonacci_dp_top_down_rec(n-1, array) + fibonacci_dp_top_down_rec(n-2, array);
    
    return array[n];
}


// Time complexity O(N) and Space complexity O(1)
uint64_t fibonacci_dp_bottom_up(int n)
{
    if (n==0 || n==1) 
        return 1;

    uint64_t f1 = 1, f2 = 1, f3;
    for (int i=2; i <= n; i++)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}


// integer bidimensional vector
typedef struct
{
    uint64_t x, y;
} vector_2x2;

// matrix 2x2 integers
class Matrix_2x2
{
    public:
        uint64_t a_11, a_12, a_21, a_22;
        
        Matrix_2x2(uint64_t a11, uint64_t a12, uint64_t a21, uint64_t a22)
        {
            a_11 = a11;
            a_12 = a12;
            a_21 = a21;
            a_22 = a22;
        }

        void operator *= (Matrix_2x2 M)
        {
            /*
                | a b | | m11 m12 | | a.m11+b.m21 a.m12+b.m22 | 
                |     |.|         |=| 
                | c d | | m21 m22 | | c.m11+d.m21 c.m12+d.m22 |
            */
            uint64_t a=a_11, b=a_12, c=a_21, d=a_22;
            a_11 = a * M.a_11 + b * M.a_21;
            a_12 = a * M.a_12 + b * M.a_22;
            a_21 = c * M.a_11 + d * M.a_21;
            a_22 = c * M.a_12 + d * M.a_22;
        }
        
        Matrix_2x2 pow(int n)
        {
            Matrix_2x2 matrix = Matrix_2x2(a_11, a_12, a_21, a_22); // auxiliar matrix
            Matrix_2x2 result = Matrix_2x2(1,0,0,1);                // init identity matrix
            
            while (n != 0) // Exponentiation by squaring algorithm
            {
                if (n % 2 != 0) result *= matrix;
                n /= 2;
                matrix *= matrix;
            }

            return result;
        }

        vector_2x2 apply(vector_2x2 v)
        {
            vector_2x2 result;
            result.x = a_11*v.x + a_12*v.y;
            result.y = a_21*v.x + a_22*v.y;
            return result;
        }
};

// Time complexity O(Log(N)) and Space complexity O(1)
uint64_t fibonacci_matrix(int n)
{
    Matrix_2x2 Tn = Matrix_2x2(0,1,1,1).pow(n);
    return Tn.apply({1,1}).x;
}

int main()
{
    // runtime benchmark
    clock_t start_time, end_time;
    double interval;

    int n=30;    // find n
    uint64_t fn; // nth Fibonacci sequence

    printf("Fibonacci: n=%d\n", n);
    
    printf("Fibonacci recursive\n");
    start_time = clock();

    fn = fibonacci_recursive(n);

    end_time = clock();
    interval = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\tresult: fn=%lu\n", fn);
    printf("\truntime: %.3lf s\n", interval);

    printf("Fibonacci DP Top-Down\n");
    start_time = clock();

    fn = fibonacci_dp_top_down(n);

    end_time = clock();
    interval = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\tresult: fn=%lu\n", fn);
    printf("\truntime: %.3lf s\n", interval);

    printf("Fibonacci DP Bottom-Up\n");
    start_time = clock();

    fn = fibonacci_dp_bottom_up(n);

    end_time = clock();
    interval = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\tresult: fn=%lu\n", fn);
    printf("\truntime: %.3lf s\n", interval);
    

    printf("Fibonacci matrix\n");
    start_time = clock();

    fn = fibonacci_matrix(n);

    end_time = clock();
    interval = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\tresult: fn=%lu\n", fn);
    printf("\truntime: %.3lf s\n", interval);

    return 0;
}

/* 
Results on Core i7 10th gen 8G:
----------------------------------------
Fibonacci: n=50
Fibonacci recursive
        result: fn=3185141890
        runtime: 92.096 s
Fibonacci DP Top-Down
        result: fn=3185141890
        runtime: 0.000 s
Fibonacci DP Bottom-Up
        result: fn=3185141890
        runtime: 0.000 s
Fibonacci matrix
        result: fn=3185141890
        runtime: 0.000 s
----------------------------------------
*/

/*
Fibonacci: n=1000000
Fibonacci DP Bottom-Up
        result: fn=48392605
        runtime: 0.003 s
Fibonacci matrix
        result: fn=48392605
        runtime: 0.000 s
*/