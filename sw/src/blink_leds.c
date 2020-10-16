#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"
#include "xil_printf.h"

int main()
{
    init_platform();

    print("Hello World!\n\r");

    XGpio gpio;
	int xStatus = XGpio_Initialize(&gpio,XPAR_AXI_GPIO_0_DEVICE_ID);
	if(XST_SUCCESS != xStatus) {
		print("Failed to initialize GPIO");
	}

	unsigned char leds = 0x1;
	for(;;) {
		XGpio_DiscreteWrite(&gpio,1,leds);
		leds = leds << 1;
		if (leds == 0)
			leds = 0x1;
		usleep(50000);
	}

    cleanup_platform();
    return 0;
}
