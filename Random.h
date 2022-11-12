#include <ctime>
#include <cstdlib>
int getRandomNumber()
{
srand(time(0));
return rand() % 100+1;
}
