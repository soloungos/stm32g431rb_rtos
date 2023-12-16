/*
 * tick.c
 *
 *  Created on: Dec 15, 2022
 *      Author: soloungos
 */
#include "os.h"

volatile unsigned int os_tick_counter = 0;

/**
* @brief
* @retval
*/
void tick_increase(void)
{
  if ((++os_tick_counter % TIMESLICE) == 0)
  {
    schedule();
  }
}


/**
* @brief
* @retval
*/
void sleep_ms(int ms)
{
  if (ms < 2)
    return;

  task_get_current()->wakeup_time = os_tick_counter + ms;
  task_waiting(task_get_current());
  schedule();
}
