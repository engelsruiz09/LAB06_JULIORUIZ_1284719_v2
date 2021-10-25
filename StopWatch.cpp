#include "StopWatch.h"

void StopWatch::Start()
{
	start = clock();
}
int StopWatch::End()
{
	return clock() - start;
}