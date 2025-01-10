/**
  *
  * Jumping Frogs
  *
  * This is a nice challenge from a code challenge website.
  *
  *
  * The idea is that you have a sequence of towers of different heights.
  * Two frogs can be located on the top of any of the towers.
  * One frog go backwards and the other go forward.
  * Frogs can jump only up, so for a frog is possible to move from one tower to the other as long as the next tower is higher or equal
  * to the tower where the frog is located.
  * The distance between two towers is defined as J-K+1, given J<=K.
  * Hence, the distance between one tower and itself is 1, not zero.
  *
  * Goal: Given a sequence of heights, find the LARGEST separation that two frogs can achieve, for any given sequence, assumming that the frogs
  * can start anywhere on the sequence.
  *
  *
  * More formally this is given a sequence find the longest path where the sequence starts being monotonically decreasing and monotonically increasing.
  *
  **/
#include <algorithm>
#include <iostream>
#include <vector>

/**
 * Counts how many steps the frog can jump forward
 *
 **/
int monotonic(std::vector<int> &block)
{
    int counter = 0;
    int last=block[0];
    for(unsigned int i=1;i<block.size();i++)
    {
        if (block[i]>=last)
        {
            counter++;
            last = block[i];
        }
        else {
            break;
        }
    }
    return counter;
}

/**
 * The idea is to go through all the elements.
 * For each element check forward and backward how many steps the two frogs can take.
 *
 * To do this, the original block is sliced based on the current position.
 * The forward vector are the steps ahead, and the backward the steps behind.
 * The backward vector is reversed and the same function is used to check how many steps the frog can jump.
 * Memory: two additional vectors.
 * O()= N*N*N worst case.
 *
 **/
int solution(std::vector<int> &blocks) {
    // write your code in C++14 (g++ 6.2.0)

    std::vector<int> backwards,forward;
    backwards.reserve(blocks.size());
    forward.reserve(blocks.size());

    int max_stride=1;

    for (unsigned int starting_pos=0;starting_pos<blocks.size();starting_pos++)
    {

        backwards.clear();
        forward.clear();

        //std::cout << "Starting:" << starting_pos << std::endl;
        std::copy(blocks.begin()+starting_pos,blocks.end(),std::back_inserter(forward));
        int forward_stride = monotonic(forward);
        //std::cout << "Fw Counter:" << forward_stride << std::endl;

        std::copy(blocks.begin(),blocks.begin()+starting_pos+1,std::back_inserter(backwards));

        std::reverse(backwards.begin(),backwards.end());
        int backwrd_stride = monotonic(backwards);

        int stride = forward_stride+backwrd_stride+1;

        if (stride>max_stride)
        {
            max_stride = stride;
        }
    }


    return max_stride;

}

int main(int argc, char *argv[])
{
    std::vector<int> a;
    a.push_back(2);   //
    a.push_back(5);   /////
    a.push_back(8);   ////////
    a.push_back(3);   ///

    std::cout << solution(a) << std::endl;

    return 0;
}



