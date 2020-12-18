/* This is a guard condition so that contents of this file are not included more than once */
#ifndef FIFO_H
#define	FIFO_H

#include <xc.h> 
#include <stdint.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#define  FIFO_BUFFER_SIZE   32      /* Maximum possible size is 256 */
    
void     FIFO_Init(void);           /* Initialize the FIFO buffer */
bool     FIFO_Get(uint8_t *pData);  /* Returns false if OK, or true if FIFO empty */
bool     FIFO_Put(uint8_t data);    /* Returns false if OK, or true if FIFO full */
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* FIFO_H */

