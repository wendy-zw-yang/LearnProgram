/*
Author: 申佳依
*/
#ifndef TIMESETTING_HEADER_FILE
#define TIMESETTING_HEADER_FILE

void set_time(struct tm *time_a);
void read_current_time(struct tm *current_time);
int time_difference(struct tm *time_a, struct tm *current_time);

#endif