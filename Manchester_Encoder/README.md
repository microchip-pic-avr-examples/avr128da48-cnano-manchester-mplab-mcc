[![MCHP](images/microchip.png)](https://www.microchip.com)

## Manchester Encoder - Use Case for CIPs Using the AVR128DA48 Microcontroller with MCC Melody

The Manchester code is a line code in which the encoding of each data bit is either a transition from LOW to HIGH or a transition from HIGH to LOW. It is a self-clocking signal with no DC component.

There are two versions of the Manchester code. This project focuses on the Manchester coding as per IEEE 802.3. The
Manchester code combines data and clock into a single signal, where one clock cycle is a Manchester-bit period. A transition always occurs in the middle of the bit period. Logic `0` is represented by a falling edge (HIGH to LOW transition) in the middle of the bit period, and logic `1` is represented by a rising edge (LOW to HIGH transition) in the middle of the bit period. 

In this application the Manchester communication parameters are: baud rate 16000 bits/s, 8 bit transfer, MSb (Most Signifacnt bit) is sent first, IEEE 802.3. Manchester version (negative edge is binary zero).

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
- [AVR-Dx_DFP v2.4.286 or newer](https://packs.download.microchip.com/)

## Hardware Used
- The [AVR128DA48 Curiosity Nano Development board (DM164151)](https://www.microchip.com/Developmenttools/ProductDetails/DM164151) is used as a test platform:
<br><img src="images/avr128da48_cnano.png" width="600">

## Operation

To program the Curiosity Nano board with this MPLAB X project, follow the steps provided in the [How to Program the Curiosity Nano Board](#how-to-program-the-curiosity-nano-board) chapter.<br><br>

## Concept

This project is an implementation of a Manchester Encoder using CIP (Core Independent Peripherals) by following the interaction between USART, SPI, Event System and CCL peripherals. The raw data are received via serial communication, encoded using a circuit composed of the CIP mentioned above and sent further through a single data wire.

The block diagram of this application is presented in the figure below: 

<br><img src="images/encoder-block-diagram.png" width="600">

The raw data are received via serial communication by the USART1 peripheral. These data are then stored in a buffer and used as input for the SPI0 peripheral (configured in Host mode 1) which generates NRZ (Non-return-to-zero) data signal and a clock signal. Those signals are selected as inputs for the CCL (Configurable Custom Logic) peripheral which outputs the exclusive or logic operation between the two selected inputs. The XOR operation between the raw data signal and clock represent the Manchester encoded data. The FIFO (First-In First-Out) buffer mechanism is used to facilitate the data storage and minimize data loss.

<br><img src="images/encoder-flow.png" width="600">

## Setup
The following peripheral and clock configurations are set up using the MPLAB Code Configurator (MCC) Melody for the AVR128DA48:

Global interrupts: Enabled

1. Clock Control:
  - Oscillator Frequency Selection: 2 MHz system clock
  
  <br><img src="images/encoder-mcc-clkctrl.png" width="400">

1. USART1:
  - UART PLIB Selector: USART1
  - Enable USART Receiver: Enabled
  - Enable USART Transmitter: Enabled
  - Receive Interrupt Enable: Enabled
  - Requested Baudrate: 19200
  - Data Size: 8
  - Stop Bits: 1
  - Interrupt Driven: Enabled
  - Software Receive Buffer Size: 128
  
  <br><img src="images/encoder-mcc-usart1-part1.png" width="400">
  <br><img src="images/encoder-mcc-usart1-part2.png" width="400">

1. SPI0:
  - SPI Host PLIB Selector: SPI0
  - SPI0 Type: Host
  - SPI0 Mode: Mode 1
  - Config Name: HOST_CONFIG
  - Requested Speed: 10 kHz
  
  <br><img src="images/encoder-mcc-spi0.png" width="400">

1. EVSYS:
  - Event Generators:
    - USART0_XCK: CHANNEL1
  - Event Users:
    - CHANNEL1: CCLLUT2A

2. CCL:
  - Enable CCL: Enabled
  - LUT2:
    - Enable LUT: Enabled
    - Enable LUT output: Enabled
    - Filter Options: SYNCH
    - Clock Selection: CLKPER
    - Sequential Logic: DISABLE
    - IN0: SPI0
    - IN1: EVENTA
    - IN2: MASK
    - Gate Type: Custom
    - OUT result: 0x6
  
   <br><img src="images/encoder-mcc-lut2.png" width="400">

 |                         Pin                          |    Configuration   |
 | :--------------------------------------------------: | :----------------: |
 |     PC0 (USART1 - TX)                                |   Digital Output   |
 |     PC1 (USART1 - RX)                                |   Digital Input    |
 |     PA5 (SPI0 - MISO)                                |   Digital  Input   |
 |     PA4 (SPI0 - MOSI)                                |   Digital Output   |
 |     PA6 (SPI0 - SCK)                                 |   Digital Output   |
 |     PD3 (LUT2_OUT) - Manchester Encoded Signal       |   Digital Output   |

 **Important:** The encoder's board PD3 pin must be connected with the decoder's board PB2 pin (Manchester data bus).

## Demo
In the demo, the ```Microchip!``` message was inserted by the user in the terminal. Pin PD3 (the output pin for the Manchester encoded signal) was visualized using a logic analyzer.

<br><img src="images/encoder-demo-waveform.png" width="800">

<br><img src="images/encoder-demo-waveform-zoom.png" width="800">

To use the embedded decoder from the Logic software, the next analyzers settings must be set: 
 - Manchester encoded signal on PD3:
  
  <br><img src="images/encoder-logic-settings1.png">

## Summary

This demo shows how to implement a CIP solution for a Manchester encoder using USART, CCL and Event System peripherals. This CIP solution can be used at high baud rates, the encoding process being implemented with minimum effort from the CPU.

## How to Program the Curiosity Nano Board

 1. Connect the board to the PC.

 2. Open the Manchester_Encoder.X project in MPLAB X.

 3. Set the Manchester_Encoder.X project as main project. Right click on the project in the **Projects** tab and click **Set as Main Project**.
 
 <br><img src="images/Program_Set_as_Main_Project.png">

 4. Clean and build the Manchester_Encoder.X project: right click on the **Manchester_Encoder.X** project and select **Clean and Build**.

 <br><img src="images/Program_Clean_and_Build.png">

 5. Select the **AVR128DA48 Curiosity Nano** in the Connected Hardware Tool section of the project settings:
   - Right click on the project and click **Properties**
   - Click on the arrow right next to Connected Hardware Tool
   - Select the AVR128DA48 Curiosity Nano (click on the **SN**), click **Apply** and then click **OK**:

   <br><img src="images/Program_Tool_Selection.png">

 6. Program the project to the board: Right click on the project and click **Make and Program Device**.

<br><img src="images/Program_Make_and_Program_Device.png">

## Menu 
<!-- no toc -->
- [Back to Top](#manchester-encoder---use-case-for-cips-using-the-avr128da48-microcontroller-with-mcc-melody)
- [Back to Related Documentation](#related-documentation)
- [Back to Software Used](#software-used)
- [Back to Hardware Used](#hardware-used)
- [Back to Operation](#operation)
- [Back to Concept](#concept)
- [Back to Setup](#setup)
- [Back to Demo](#demo)
- [Back to Summary](#summary)
- [Back to How to Program the Curiosity Nano Board](#how-to-program-the-curiosity-nano-board)