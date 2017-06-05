#include <cstdio>

#include <unistd.h>

#include <phantompi/sysfs/phantompi.hpp>
#include <phantompi/button.hpp>

#include "button_example.hpp"

int main(int argc,
         char ** argv)
{
    if(argc != 3)
    {
        std::printf("Usage: %s <gpio> <count>\n", argv[0]);
        return (argc == 1);
    }

    auto gpio = std::atoi(argv[1]);
    auto count = std::atoi(argv[2]);

    auto buttonGpio = phantompi::sysfs::accessInputGpio(gpio);
    auto button = makePullUpButton(buttonGpio);

    while(count > 0)
    {
        usleep(500000);
        checkButton(button);
        --count;
    }
    return 0;
}
