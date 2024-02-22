[![MCHP](images/microchip.png)](https://www.microchip.com)

## Manchester Decoder - Use Case for CIPs Using the AVR128DA48 Microcontroller with MCC Melody

The Manchester code is a line code in which the encoding of each data bit is either a transition from LOW to HIGH or a transition from HIGH to LOW. It is a self-clocking signal with no DC component.

This project focuses on the Manchester coding as per IEEE 802.3. 
The Manchester code combines data and clock into a single signal, where one clock cycle is a Manchester-bit period with a transition occurring in the middle of it. Logic `'0'` is represented by a falling edge (HIGH to LOW transition) in the middle of the bit period, and logic `'1'` is represented by a rising edge (LOW to HIGH transition) in the middle of the bit period. 

In this application, the Manchester communication parameters are: 
- Baud rate: 16000 bits/s
- 8-bit transfer
- MSb (Most Significant bit) is sent first
- IEEE 802.3
- Manchester version (negative edge is binary zero).

An example is presented in the figure below:

<br><img src="images/manchester_waveform.png" width="600">

## Related Documentation

More details and code examples on the AVR128DA48 can be found at the following links:
- [AVR128DA48 Product Page](https://www.microchip.com/wwwproducts/en/AVR128DA48)
- [AVR128DA48 Code Examples on Discover](https://mplab-discover.microchip.com/v2?dsl=avr128da48)
- [AVR128DA48 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=avr128da48)

## Software Used
- [MPLAB X IDE v6.20 or newer](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
- [MPLAB XC8 v2.46 or newer](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/xc8)
- [AVR®-Dx_DFP v2.4.286 or newer](https://packs.download.microchip.com/)

## Hardware Used
- The [AVR128DA48 Curiosity Nano Development board (DM164151)](https://www.microchip.com/Developmenttools/ProductDetails/DM164151) is used as a test platform:
<br><img src="images/avr128da48_cnano.png" width="600">
- 4x Jumper wires

## Operation

To program the Curiosity Nano board with this MPLAB X project, follow the steps provided in the [How to Program the Curiosity Nano Board](#how-to-program-the-curiosity-nano-board) chapter.<br><br>

## Concept

This project is an implementation of a Manchester Decoder using Core Independent Peripherals (CIPs) by following the interaction between the Timer/Counter type B (TCB), Event System (EVSYS), Configurable Custom Logic (CCL) and Serial Peripheral Interface (SPI) peripherals. The encoded data are received through a single data wire. The Non-Return-to-Zero (NRZ) signal and clock signal are recovered using the circuit composed of the CIP mentioned above. The resulting signals are routed to the SPI peripheral which reads the data. The decoded data are transmitted further via serial communication.

The block diagram of this application is presented in the figure below: 

<br><img src="images/decoder-block-diagram.png" width="800">

The Manchester encoded signal is received through a single wire. A decoding circuit is implemented using a combination of CCL blocks and timers. The decoding circuit outputs the recovered NRZ data and a synchronized clock signal that are routed with jumper wires to the SPI1 peripheral configured in Client mode. The SPI1 peripheral will generate interrupts whenever a new byte is received and the current byte will be stored in a buffer. The data are further transmitted via serial communication (USART1). A time-out mechanism is implement using TCB2 configured in periodic Time-Out mode—an interrupt will be generated when no activity occurs on the Manchester data line for the duration of three bytes. A First-In First-Out (FIFO) buffer mechanism is used to facilitate the data storage and minimize data loss.

<br><img src="images/decoder-flow.png" width="800">


## Setup
The following peripheral and clock configurations are set up using the MPLAB Code Configurator (MCC) Melody for the AVR128DA48:

1. Clock Control:
  - Oscillator Frequency Selection: 24 MHz system clock
  
  <br><img src="images/decoder-mcc-clkctrl.png" width="400">

2. USART1:
  - UART PLIB Selector: USART1
  - Enable USART Transmitter: Enabled
  - Requested Baud Rate: 38400
  - Data Size: 8
  - Stop Bits: 1
  
  <br><img src="images/decoder-mcc-usart1-part1.png" width="400">
  <br><img src="images/decoder-mcc-usart1-part2.png" width="400">

3. SPI1:
  - SPI Client PLIB Selector: SPI1
  - SPI1 Type: Client
  - SPI1 Mode: Mode 0
  - Config Name: CLIENT_CONFIG
  - Interrupt Driven: Enabled
  
  <br><img src="images/decoder-mcc-spi1.png" width="400">

4. EVSYS:
  - Event Generators:
    - CCL_LUT0:  CHANNEL0
    - CCL_LUT2:  CHANNEL1
    - CCL_LUT4: CHANNEL2
    - CCL_LUT3: CHANNEL5
  - Event Users:
    - CHANNEL0: CCLLUT2B
    - CHANNEL1: TCB0CAPT
    - CHANNEL2: CCLLUT0A, CCLLUT2A
    - CHANNEL5: TCB1CAPT, TCB2CAPT  
  
5. CCL:
  - Enable CCL: Enabled
  - LUT0:
    - Enable LUT: Enabled
    - Enable LUT output: Enabled
    - Filter Options: DISABLE
    - Clock Selection: CLKPER
    - Sequential Logic: DFF
    - IN0: EVENTA
    - IN1: MASK
    - IN2: MASK
    - Gate Type: Custom
    - OUT result: 0x2
  
   <br><img src="images/decoder-mcc-lut0.png" width="400">
  
  - LUT1:
    - Enable LUT: Enabled
    - Enable LUT output: Enabled
    - Filter Options: DISABLE
    - Clock Selection: CLKPER
    - Sequential Logic: DFF
    - IN0: MASK
    - IN1: TCB1
    - IN2: MASK
    - Gate Type: Custom
    - OUT result: 0x4
  
   <br><img src="images/decoder-mcc-lut1.png" width="400">

  - LUT2:
    - Enable LUT: Enabled
    - Enable LUT output: Enabled
    - Filter Options: DISABLE
    - Clock Selection: CLKPER
    - Sequential Logic: DISABLE
    - IN0: EVENTA
    - IN1: EVENTB
    - IN2: MASK
    - Gate Type: Custom
    - OUT result: 0x6
  
   <br><img src="images/decoder-mcc-lut2.png" width="400">
  
  - LUT3:
    - Enable LUT: Enabled
    - Enable LUT output: Enabled
    - Filter Options: DISABLE
    - Clock Selection: CLKPER
    - Sequential Logic: DISABLE
    - IN0: TCB0
    - IN1: MASK
    - IN2: MASK
    - Gate Type: Custom
    - OUT result: 0x1
  
   <br><img src="images/decoder-mcc-lut3.png" width="400">

  - LUT4:
    - Enable LUT: Enabled
    - Enable LUT output: Enabled
    - Filter Options: DISABLE
    - Clock Selection: CLKPER
    - Sequential Logic: DISABLE
    - IN0: MASK
    - IN1: MASK
    - IN2: IN2
    - Gate Type: Custom
    - OUT result: 0x1
  
   <br><img src="images/decoder-mcc-lut4.png" width="400">
    
6. TCB0:
  - Enable Timer: Enabled
  - Clock Selection: DIV1
  - Timer Mode: Single
  - Requested Time-Out (s): 0.00004696 (46.9583 μs)
  - Enable Asynchronous: Enabled
  - Enable Event Input Capture: Enabled
  - Enable Pin Output: Enabled
  
  <br><img src="images/decoder-mcc-tcb0.png" width="400"> 

7. TCB1:
  - Enable Timer: Enabled
  - Clock Selection: DIV1
  - Timer Mode: Single
  - Requested Time-Out (s): 0.00000296 (2.9583 μs)
  - Enable Asynchronous: Enabled
  - Enable Event Input Capture: Enabled
  - Enable Pin Output: Enabled
  
  <br><img src="images/decoder-mcc-tcb1.png" width="400">

8. TCB2:
  - Enable Timer: Enabled
  - Clock Selection: DIV1
  - Timer Mode: Time-Out
  - Requested Time-Out (s): 0.000374917 (374.9167 μs)
  - Enable Event Input Capture: Enabled
  - Enable Noise Cancellation Filter: Enabled
  - Generate ISR: Enabled
  - Enable Capture/Time-Out Interrupt: Enabled
  
  <br><img src="images/decoder-mcc-tcb2.png" width="400">  

9. Interrupt Manager:
  - Global Interrupt Enable: Enabled
  - SPI1 RXC: Enabled
  - SPI1 IE: Enabled


 |                        Pin                       |    Configuration   |
 | :----------------------------------------------: | :----------------: |
 |     PC4 (SPI1 - MOSI)                            |   Digital input    |
 |     PC5 (SPI1 - MISO)                            |   Digital output   |
 |     PC6 (SPI1 - SCK)                             |   Digital input    |
 |     PC7 (SPI1 - SS)                              |   Digital input    | 
 |     PC0 (USART1 - TX)                            |   Digital output   |
 |     PC1 (USART1 - RX)                            |   Digital input    |
 |     PA3 (TCB1_OUT)                               |   Digital output   |
 |     PA2 (TCB0_OUT)                               |   Digital output   |
 |     PA6 (LUT0_OUT)  - NRZ Data Signal            |   Digital output   |
 |     PC3 (LUT1_OUT)                               |   Digital output   |
 |     PD3 (LUT2_OUT)  - Recovered Clock Signal     |   Digital output   |
 |     PF3 (LUT3_OUT)                               |   Digital output   |
 |     PB2 (LUT4_INSEL2) - Encoded Data Signal      |   Digital input    |
 |     PB3 (LUT4_OUT)                               |   Digital output   |



 Additional connections needed (with jumper wires):

 |               Pin 1                 |        Pin 2       |
 | :---------------------------------: | :----------------: |
 |     PA6 - NRZ Data signal           |   PC4 - SPI1 MOSI  |
 |     PD3 - Recovered Clock signal    |   PC6 - SPI1 SCK   |
 |     PC7 - Client select for SPI1    |   GND              |


 **Important:** The PD3 pin of the encoder board must be connected with the PB2 pin of the decoder board (Manchester data bus).

## Demo

In the demo, the ```Microchip!``` message is received in the serial terminal connected to the decoder board. Also, the recovered NRZ and Clock signal can be visualized with a logic analyzer.

<br><img src="images/decoder-demo-waveforms.png" width="800">

<br><img src="images/decoder-demo-terminal.png" width="800">

To use the embedded decoder from the Logic software, the next analyzer settings must be set: 
 - Manchester encoded signal on PD3:
  
  <br><img src="images/decoder-logic-settings1.png">

   - NRZ data on PC4:
  
  <br><img src="images/decoder-logic-settings2.png">
   
   - Manchester decoded signal on PC0:
  
  <br><img src="images/decoder-logic-settings3.png">



## Summary

This demo shows how to implement a CIP solution for a Manchester decoder using a circuit composed of SPI, USART, CCL, Timers and Event System peripherals.
This CIP solution can be used at high baud rates, the decoding process being implemented in the CIP circuit, and the CPU is used only at storing the received data in a buffer.

## How to Program the Curiosity Nano Board

This chapter demonstrates how to use the MPLAB X IDE to program an AVR® device with an ```Example_Project.X```. This is applicable to other projects.

1.  Connect the board to the PC.

2.  Open the ```Example_Project.X``` project in MPLAB X IDE.

3.  Set the ```Example_Project.X``` project as main project.
    <br>Right click the project in the Projects tab and click Set as Main Project.
    <br><img src="images/Program_Set_as_Main_Project.png" width="600">

4.  Clean and build the ```Example_Project.X``` project.
    <br>Right click the ```Example_Project.X``` project and select Clean and Build.
    <br><img src="images/Program_Clean_and_Build.png" width="600">

5.  Select AVRxxxxx Curiosity Nano in the Connected Hardware Tool section of the project settings:
    <br>Right click the project and click **Properties**.
    <br>Click the arrow under the Connected Hardware Tool.
    <br>Select AVRxxxxx Curiosity Nano (click the **SN**), click **Apply** and then click **OK**:
    <br><img src="images/Program_Tool_Selection.png" width="600">

6.  Program the project to the board.
    <br>Right click the project and click **Make and Program Device**.
    <br><img src="images/Program_Make_and_Program_Device.png" width="600">

<br>

## Menu 
<!-- no toc -->
- [Back to Top](#manchester-decoder---use-case-for-cips-using-the-avr128da48-microcontroller-with-mcc-melody)
- [Back to Related Documentation](#related-documentation)
- [Back to Software Used](#software-used)
- [Back to Hardware Used](#hardware-used)
- [Back to Operation](#operation)
- [Back to Concept](#concept)
- [Back to Setup](#setup)
- [Back to Demo](#demo)
- [Back to Summary](#summary)
- [Back to How to Program the Curiosity Nano Board](#how-to-program-the-curiosity-nano-board)