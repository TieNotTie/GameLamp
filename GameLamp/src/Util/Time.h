#pragma once

/*
	!!! HAS TO BE DEFINED IN PLATFORM RELATED FILE

	Measures in milliseconds
*/
double GetDeltaTime();

/*
	!!! HAS TO BE DEFINED IN PLATFORM RELATED FILE
*/
void UpdateDeltaTime();

/*
	!!! HAS TO BE DEFINED IN PLATFORM RELATED FILE
*/
bool SetupTimeMeasurement();

/* TODO: Consider adding time management functions
 *	void SetTimer(milliseconds)  // Set non-blocking timer for some time in milliseconds 
 *	Time GetCurrentSystemTime() const // Get Current System time (Year, Month, Day, hour, minute, second)
 *	Time GetProgramTime() const // Get time passed from when program was started
 */ 
