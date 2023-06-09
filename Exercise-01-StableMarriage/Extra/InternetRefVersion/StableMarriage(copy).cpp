/* 
 * C++ Program to Implement Stable Marriage Problem
 * Ref.: https://www.sanfoundry.com/cpp-program-implement-stable-marriage-problem/
 * Edited by Junio Cesar Ferreira: I just made some corrections to compile and change input data.
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
 
// Number of Men or Women
#define N  7
 
// This function returns true if woman 'w' prefers man 'm1' over man 'm'
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1)
{
    // Check if w prefers m over her current engagment m1
    for (int i = 0; i < N; i++)
    { 
        // If m1 comes before m in the list of w, 
        // then w prefers her current engagement, don't do anything 
 
        if (prefer[w][i] == m1) return true;
 
        // If m cmes before m1 in w's list, then free her current
        // engagement and engage her with m
        if (prefer[w][i] == m) return false;
    }
	return false;
}
 
// Prints stable matching for N boys and N girls. Boys are numbered as 0 to N-1.
// Girls are numbered as N to 2N-1.
void stableMarriage(int prefer[2*N][N])
{
    /*
     Stores partner of women. This is our output array that stores information.
     The value of wPartner[I] indicates the partner assigned to woman N+i.
     Note that the woman numbers between N and 2*N-1. 
     The value -1 indicates that (N+i)'th woman is free
    */
    int wPartner[N];
 
    // An array to store availability of men. If mFree[i] is false, 
    // then man 'i' is free, otherwise engaged.
    bool mFree[N];
 
    // Initialize all men and women as free
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;
 
    // While there are free men
    while (freeCount > 0)
    {
        // Pick the first free man (we could pick any)
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;
 
        printf("suitor: %d\n", m);
        // One by one go to all women according to m's preferences.
        // Here m is the picked free man
        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];
 
            // The woman of preference is free, w and m become partners.
            // So we can say they are engaged not married
            if (wPartner[w] == -1)
            {
                wPartner[w] = m;
                mFree[m] = true;
				printf("engagement (%d, %d)\n", m, w);
                freeCount--;
            } 
            else  // If w is not free
            {
                // Find current engagement of w
                int m1 = wPartner[w];
 
                // If w prefers m over her current engagement m1,
                // then break the engagement between w and m1 and engage m with w.
                if (wPrefersM1OverM(prefer, w, m, m1) == false)
                {
                    wPartner[w] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
					printf("engagement (%d, %d)\n", m, w);
                }
            }
        } // End of the for loop that goes to all women in m's list
    } // End of the main while loop
 
 
    // Print the solution
    cout << "Woman   Man" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << i+1 << "\t" << wPartner[i]+1 << endl;
}
 
// Driver program to test above functions
int main()
{
    int prefer[2*N][N] = { 
		{2, 3, 1, 0, 5, 6, 4},
		{5, 3, 1, 2, 4, 0, 6},
		{5, 2, 4, 6, 1, 3, 0},
		{0, 5, 2, 1, 3, 6, 4},
		{0, 5, 4, 2, 3, 6, 1},
		{0, 6, 2, 3, 4, 5, 1},
		{4, 5, 1, 3, 2, 6, 0},
		{3, 4, 2, 6, 1, 5, 0},
		{4, 5, 3, 6, 2, 1, 0},
		{0, 5, 4, 3, 2, 6, 1},
		{2, 4, 5, 6, 1, 3, 0},
		{0, 6, 5, 3, 2, 4, 1},
		{5, 2, 6, 4, 1, 3, 0},
		{0, 6, 3, 1, 5, 4, 2}
    };
    stableMarriage(prefer);
	getch();
    return 0;
}