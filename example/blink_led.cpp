#include <cstdio>
#include <cstdlib>

#include <unistd.h>

#include <phantompi/sysfs/phantompi.hpp>

int main(int argc, char ** argv)
{
    if(argc != 3)
    {
        std::printf("Usage: %s <gpio> <count>\n", argv[0]);
        return (argc == 1);
    }

    auto gpio = std::atoi(argv[1]);
    auto count = std::atoi(argv[2]);

    auto ledGpio = phantompi::sysfs::accessOutputGpio(gpio);

    while(count > 0)
    {
        ledGpio->setState(phantompi::GpioState::high);
        usleep(500000);
        ledGpio->setState(phantompi::GpioState::low);
        usleep(500000);
        --count;
    }
    return 0;
}
