#include <sys/time.h> // for gettimeofday()
int main()
{
 struct timeval t1, t2;
 double elapsedTime;
 // start timer
 gettimeofday(&t1, NULL);
 // do something or call a function
 // ...
 // stop timer
 gettimeofday(&t2, NULL);
 // compute and print the elapsed time in millisec
 elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
 elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
 printf("Total time is" + elapsedTime + "ms.\n";
 return 0;
}
