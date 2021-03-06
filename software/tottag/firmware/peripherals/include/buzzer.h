#ifndef __BUZZER_HEADER_H
#define __BUZZER_HEADER_H

// Header inclusions ---------------------------------------------------------------------------------------------------

#include <stdbool.h>


// Public buzzer functionality -----------------------------------------------------------------------------------------

void buzzer_init(void);
void buzzer_indicate_plugged_status(bool plugged_in);
void buzzer_indicate_invalid_rtc_time(void);
void buzzer_indicate_error(void);

#endif // #ifndef __BUZZER_HEADER_H
