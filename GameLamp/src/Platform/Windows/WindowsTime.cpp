#include "Util/Time.h"

#include <windows.h>

static double g_DeltaTime = 0.0;

static LARGE_INTEGER Frequency;

double GetDeltaTime()
{
	return g_DeltaTime;
}

void UpdateDeltaTime()
{
	static LARGE_INTEGER PreviousTime, CurrentTime, Elapsed;

	PreviousTime = CurrentTime;

	QueryPerformanceCounter(&CurrentTime);

	Elapsed.QuadPart = CurrentTime.QuadPart - PreviousTime.QuadPart;

	g_DeltaTime = Elapsed.QuadPart * 1000.0 / (double)Frequency.QuadPart;

}

bool SetupTimeMeasurement()
{
	QueryPerformanceFrequency(&Frequency);

	return Frequency.QuadPart != (LONGLONG)0;
}

