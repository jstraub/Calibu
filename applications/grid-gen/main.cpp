#include <Eigen/Eigen>
#include <sophus/se2.hpp>
#include <random>
#include <iostream>
#include <array>
#include <signal.h>
#include <fstream>
#include <deque>

#include <calibu/target/RandomGrid.h>

using namespace calibu;

bool should_run = true;

void UserQuit(int)
{
    should_run = false;
}

int main( int, char** )
{
    signal(SIGABRT,UserQuit);
    signal(SIGTERM,UserQuit);

    const int PR = 24;//35;//10;
    const int PC = 12;//35;//10;

    uint32_t seed = FindBestSeed(PR, PC, should_run); // 14
    //uint32_t seed = 62;
    const std::array<Eigen::MatrixXi,4> PG = MakePatternGroup(PR, PC, seed);

    std::cout << PG[0] << std::endl;
    std::cout << "Best seed: " << seed << std::endl;
    std::cout << "Min unique window size: " << AutoCorrelationMinArea(PG) << std::endl;

    const int auto_corr = AutoCorrelation(PG,5,5);
    std::cout << "Bad auto correlation matches: " << auto_corr << std::endl;

    //SaveEPS("target.eps", PG[0], Eigen::Vector2d(0,0), 20.0, 4.0, 6.0, 4.0, seed);
    SaveEPS("target.eps", PG[0], Eigen::Vector2d(0,0), 60.0, 12.0, 18.0, 4.0, seed);

    return 0;
}
