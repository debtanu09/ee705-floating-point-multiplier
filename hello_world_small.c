/* 
 /*
 * "Small Hello World" example. 
 * 
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example 
 * designs. It requires a STDOUT  device in your system's hardware. 
 *
 * The purpose of this example is to demonstrate the smallest possible Hello 
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard 
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete 
 * description.
 * 
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION 
 *      This removes software exception handling, which means that you cannot 
 *      run code compiled for Nios II cpu with a hardware multiplier on a core 
 *      without a the multiply unit. Check the Nios II Software Developers 
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks  
 *      support for buffering, file IO, floating point and getch(), etc. 
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program 
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

#include "sys/alt_stdio.h"
#include "sys/alt_stdio.h"
#include "system.h"
#include "io.h"
#include <stdio.h>

int main()
{ 
  alt_putstr("Hello from Nios II!\n \n");

  /* Event loop never exits. */
  int input_vector0, input_vector1, output,extra_inputs;

  /////// Test case 1 ////////////////////

  printf ("Test case 1 \n");

  input_vector0 = 0x42480000;
  input_vector1 = 0x42480000;// 4 bytes from LSB side is input 1 and from MSB side is input2
  //extra_inputs = 0x0;  // specifying opcode

  IOWR(USER_INPUT_0_BASE, 0, input_vector0);
  printf ("Input1 is [0x%x].\n", input_vector0);
  //printf ("Input2 is [0x%x].\n", input_vector >> 16);
  IOWR(USER_INPUT_1_BASE, 0, input_vector1);
    printf ("Input2 is [0x%x].\n", input_vector1);
  //IOWR(USER_EXTRA_INPUTS_BASE, 0, extra_inputs);
  //printf ("Opcode is %d.\n", extra_inputs & 0x1);

  output = IORD(USER_OUTPUT_BASE, 0);
  //extra_outputs = IORD(USER_EXTRA_OUTPUTS_BASE, 0);  // Carry and Zero flags

  printf ("Output = [0x%x] \n", output);
  //printf ("Carry = %d \n", (extra_outputs >> 1) & 0x1);
  //printf ("Zero = %d \n \n", (extra_outputs) & 0x1);

  /////// Test case 2 ////////////////////

  printf ("Test case 2 \n");

  input_vector0 = 0x424c0000; // 4 bytes from LSB side is input 1 and from MSB side is input2
  input_vector1 = 0x424c0000;  // specifying opcode

  IOWR(USER_INPUT_0_BASE, 0, input_vector0);
    printf ("Input1 is [0x%x].\n", input_vector0);
    //printf ("Input2 is [0x%x].\n", input_vector >> 16);

    IOWR(USER_INPUT_1_BASE, 0, input_vector1);
      printf ("Input2 is [0x%x].\n", input_vector1);

    //IOWR(USER_EXTRA_INPUTS_BASE, 0, extra_inputs);
    //printf ("Opcode is %d.\n", extra_inputs & 0x1);

    output = IORD(USER_OUTPUT_BASE, 0);
    //extra_outputs = IORD(USER_EXTRA_OUTPUTS_BASE, 0);  // Carry and Zero flags

    printf ("Output = [0x%x] \n", output);
   //printf ("Carry = %d \n", (extra_outputs >> 1) & 0x1);
    //printf ("Zero = %d \n \n", (extra_outputs) & 0x1);

    /////// Test case 3 ////////////////////

    printf ("Test case 3 \n");

    input_vector0 = 0x42500000; // 4 bytes from LSB side is input 1 and from MSB side is input2
    input_vector1 = 0x42500000;  // specifying opcode

  IOWR(USER_INPUT_0_BASE, 0, input_vector0);
    printf ("Input1 is [0x%x].\n", input_vector0);


    IOWR(USER_INPUT_1_BASE, 0, input_vector1);
      printf ("Input2 is [0x%x].\n", input_vector1);
    //printf ("Input2 is [0x%x].\n", input_vector >> 16);

   // IOWR(USER_EXTRA_INPUTS_BASE, 0, extra_inputs);
   // printf ("Opcode is %d.\n", extra_inputs & 0x1);

    output = IORD(USER_OUTPUT_BASE, 0);
    //extra_outputs = IORD(USER_EXTRA_OUTPUTS_BASE, 0);  // Carry and Zero flags

    printf ("Output = [0x%x] \n", output);
    //printf ("Carry = %d \n", (extra_outputs >> 1) & 0x1);
    //printf ("Zero = %d \n \n", (extra_outputs) & 0x1);

    /////// Test case 4 ////////////////////

    printf ("Test case 4 \n");

    input_vector0 = 0x42540000; // 4 bytes from LSB side is input 1 and from MSB side is input2
    input_vector1 = 0x42540000;  // specifying opcode;

  IOWR(USER_INPUT_0_BASE, 0, input_vector0);
    printf ("Input1 is [0x%x].\n", input_vector0);
    //printf ("Input2 is [0x%x].\n", input_vector >> 16);

    IOWR(USER_INPUT_1_BASE, 0, input_vector1);
      printf ("Input2 is [0x%x].\n", input_vector1);

    //IOWR(USER_EXTRA_INPUTS_BASE, 0, extra_inputs);
    //printf ("Opcode is %d.\n", extra_inputs & 0x1);

    output = IORD(USER_OUTPUT_BASE, 0);
    //extra_outputs = IORD(USER_EXTRA_OUTPUTS_BASE, 0);  // Carry and Zero flags

    printf ("Output = [0x%x] \n", output);
    //printf ("Carry = %d \n", (extra_outputs >> 1) & 0x1);
    //printf ("Zero = %d \n \n", (extra_outputs) & 0x1);


  return 0;
}
