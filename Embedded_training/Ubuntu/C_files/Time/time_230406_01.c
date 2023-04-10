#include <stdio.h>
#include <time.h>

int main()
{
    time_t current_time = time(NULL);

    struct tm *tmm = localtime(&current_time);

    char wdays[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    printf("%d/%d/%d %s\n", 1900 + tmm->tm_year, tmm->tm_mon + 1, tmm->tm_mday, wdays[tmm->tm_wday - 1]);
    printf("%2d : %2d : %2d\n", tmm->tm_hour, tmm->tm_min, tmm->tm_sec);

    return 0;
}