#include <reg51.h>
#include <stdlib.h> // for atoi()8

sbit TX = P3^1;  // UART TX to Bluetooth
sbit RX = P3^0;  // UART RX from Arduino

char buffer[30]; // buffer to store incoming data
unsigned char idx = 0; // index to store buffer position

// UART Initialization for 9600 baud rate
void UART_Init() {
    TMOD = 0x20; // Timer1, Mode2
    TH1 = 0xFD;  // 9600 baud
    SCON = 0x50; // Mode1, REN enabled
    TR1 = 1;     // Start timer
}

// Send string over UART (Bluetooth)
void UART_SendString(char *str) {
    while (*str) {
        SBUF = *str;
        while (!TI); // Wait for transmission to complete
        TI = 0;
        str++;
    }
}

// Parse and classify the flex sensor data
void parse_and_classify(char *csv) {
    int values[5] = {0};
    char temp[6];
    int i = 0, j = 0;
    int f0, f1, f2, f3, f4;

    // Parse incoming CSV data
    while (*csv && i < 5) {
        if (*csv != ',') {
            temp[j++] = *csv;
        } else {
            temp[j] = '\0';
            values[i++] = atoi(temp);
            j = 0;
        }
        csv++;
    }

    // Last value
    temp[j] = '\0';
    values[i] = atoi(temp);

    // Assign to variables
    f0 = values[0];
    f1 = values[1];
    f2 = values[2];
    f3 = values[3];
    f4 = values[4];

    // Gesture classification
    if (f0 < 1020 && f1 <1020 && f2 < 1020 && f3 < 1020 && f4 < 1020) {
        UART_SendString("Hello\n");
    } else if (f0 < 1020 && f1 > 1000 && f2 > 1000 && f3 > 1000 && f4 > 1000) {
        UART_SendString("Okay\n");
    }else if (f0 > 1010 && f1 < 1020 && f2 < 1020 && f3 > 1010 && f4 > 1010) {
        UART_SendString("Peace\n");
    } else {
        UART_SendString("Unknown\n");
    }
}

// UART interrupt handler
void serial_ISR(void) interrupt 4 {
    char ch;
    if (RI) {
        ch = SBUF;
        RI = 0;
        if (ch == '\n') {
            buffer[idx] = '\0';
            parse_and_classify(buffer);
            idx = 0;
        } else {
            if (idx < sizeof(buffer) - 1) {
                buffer[idx++] = ch;
            }
        }
    }
}

void main() {
    UART_Init();
    EA = 1;
    ES = 1;

    while (1);  // Wait for data
}
