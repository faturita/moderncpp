/**
  *
  * Missing Sequence
  *
  * This is a nice challenge from a code challenge website.
  *
  *
  * Given a known sequence of dice values (1-6), some of the values of the sequence are known but others are not known.
  * The idea is to calculate the missing values, given that it is known how many of them are there and also the average
  * of the whole sequence is known.
  *
  * Goal: Find the possible values of a sequence B of length F, given a known sequence A, and the average value of the whole sequence
  * which is M.
  **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>


std::vector<int> toBase(int number, int base, int length)
{
    std::vector<int> expansion;

    for(int exp=length-1;exp>=0;exp--)
    {

        int coeff = number / pow(base, exp);
        expansion.push_back(coeff);

        number = number % ((int)pow(base, exp));
    }

    return expansion;
}


double calculate_mean(std::vector<int> &D)
{
    double sum=0;
    for(unsigned int i=0;i<D.size();i++)
    {
        sum += (D[i]);
    }

    sum = sum / D.size();

    return (sum);
}

void show_vector(std::vector<int> &a)
{
    std::cout << "[";
    for(unsigned int pos=0;pos<a.size();pos++)
    {
        std::cout << a[pos] << ",";
    }
    std::cout << "]";
}

/**
 * @brief The values for the array that you don't know can be explored by brute force.  The point is that you can go through all the possible
 * values for the array and check for each one of them is the average value that they produce is exactly the value of the average.
 *
 * In reality this means, two conditions,
 *
 * First:   E (A) + E(B) = 0 (#A+F)
 *          The sum of all the values from A, plus all the values from B must be congruent with 0 modulus the length of both arrays.
 *          This is because the value of M is an integer, so the sum of all the numbers must be a multiple of the all the elements (to allow
 *          the average to be an integer number between 1 and 6).
 *
 *          (E(A)+E(B)) * 1/(#A+F) = M
 *
 * @param A
 * @param F
 * @param M
 * @return
 */
std::vector<int> solution(std::vector<int> &A, int F, int M) {
    // write your code in C++14 (g++ 6.2.0)

    std::vector<int> V(F);
    std::vector<int> full;
    full.reserve(F+A.size());

    for(unsigned int i=0;i<V.size();i++)
    {
        V[i]=1;
    }

    bool found=false;

    for(unsigned int i=0;i<pow(6,F);i++)
    {
        for(unsigned int pos=0;pos<V.size();pos++)
        {
            V[pos]= (rand() % 6) + 1;
        }


        V = toBase(i,6,F);


        full.clear();
        full.insert(full.end(),A.begin(),A.end());
        full.insert(full.end(),V.begin(),V.end());
        double M_hat = calculate_mean(full);

        if (M_hat == (double)M)
        {
            found=true;
            break;
        }
    }

    if (!found)
    {
        std::vector<int> V(1);V[0]=0;
        return V;
    }

    for(unsigned int i=0;i<V.size();i++)
    {
        //std::cout << V[i] << std::endl;
    }
    return V;

}


int main(int argc, char *argv[])
{
    srand (time(NULL));

    {
        std::vector<int> a;
        a.push_back(3);
        a.push_back(2);
        a.push_back(4);
        a.push_back(3);

        std::cout << "Input"; show_vector(a); std::cout << "2,4";

        std::vector<int> b = solution(a,2,4);

        std::cout << "Result:" ;
        show_vector(b);
        std::cout << std::endl;
    }

    {
        std::vector<int> a;
        a.push_back(5);
        a.push_back(3);
        a.push_back(2);
        a.push_back(1);

        std::cout << "Input"; show_vector(a); std::cout << "2,4";

        std::cout << "Result:" ;
        std::vector<int> b = solution(a,2,4);
        show_vector(b);
        std::cout << std::endl;
    }


    {
        std::vector<int> a;
        a.push_back(5);
        a.push_back(3);
        a.push_back(2);
        a.push_back(3);

        std::cout << "Input"; show_vector(a); std::cout << "4,4";
        std::cout << "Result:" ;
        std::vector<int> b = solution(a,4,4);
        show_vector(b);
        std::cout << std::endl;
    }

    return 0;
}
