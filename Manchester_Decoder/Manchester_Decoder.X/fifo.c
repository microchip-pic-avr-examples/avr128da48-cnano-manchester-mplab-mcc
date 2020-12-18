#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "fifo.h"

uint8_t fifo_buffer[FIFO_BUFFER_SIZE];
bool    fifo_full;
bool    fifo_empty;
uint8_t fifo_put_index;
uint8_t fifo_get_index;

/* Initialize the fifo buffer */
void FIFO_Init(void)
{
    fifo_put_index = 0;
    fifo_get_index = 0;
    fifo_full = false;
    fifo_empty = true;
}

/* Returns false if OK, or true if FIFO empty */
bool FIFO_Get(uint8_t *pData)
{
    if(fifo_empty == true)
    {
        return true;
    }
    fifo_full = false;
    *pData = fifo_buffer[fifo_get_index++];
    if (fifo_get_index == FIFO_BUFFER_SIZE)
    {
        fifo_get_index = 0;
    }
    if(fifo_get_index == fifo_put_index)
    {
        fifo_empty = true;
    }
    return false;
}

/* Returns false if OK, or true if FIFO full */
bool FIFO_Put(uint8_t data)
{
    if(fifo_full == true)
    {
        return true;
    }
    fifo_empty = false;
    fifo_buffer[fifo_put_index++] = data;
    if(fifo_put_index == FIFO_BUFFER_SIZE)
    {
        fifo_put_index = 0;
    }
    if(fifo_put_index == fifo_get_index)
    {
        fifo_full = true;
    }
    return false;
}


