#include <iostream>
#include <windows.h>
#include <chrono>
#include "include/Hx20Api.h"
#include "include/TypeDef.h"

#define IP1 192
#define IP2 168
#define IP3 150
#define IP4 15
#define PORT1 3001
#define PORT2 3002

//int ch = 1;

int main()
{
    // Initialize and connect
    HxInitialize(0);
    bool motor1 = HxConnect(1, IP1, IP2, IP3, IP4, PORT1);
    bool motor2 = HxConnect(2, IP1, IP2, IP3, IP4, PORT2);

    if (motor1 == false || motor2 == false) {
        printf("[Channel = %d] Connection Failed\n", 1);
        return -1;
    }
    printf("[Channel = %d] Connected\n", 1);


    for (int ch = 1; ch < 3; ch++)
    {
        HxSetRB(ch, 600, 1, true);
        Sleep(100);
        HxSetRB(ch, 600, 1, false);

        // Set ZRN Mode
        HxSetRB(ch, 601, 2, true);
        Sleep(100);
        HxSetRB(ch, 601, 2, false);
        Sleep(100);

        // Set ZRN Start
        HxSetRB(ch, 600, 2, true);
        Sleep(3000);
        HxSetRB(ch, 600, 2, false);
        Sleep(100);

        // Set Jog Mode
        HxSetRB(ch, 601, 1, true);
        Sleep(500);
        HxSetRB(ch, 601, 1, false);
        Sleep(500);

        HxSetRB(ch, 601, 6, true);
        Sleep(500);
        HxSetRB(ch, 601, 6, false);
        Sleep(100);
    }
   

    // Define Z-axis limits
    const float Z_MAX = -25.0;  // Replace with your Z+ maximum position
    const float Z_MIN = -120.0; // Replace with your Z- minimum position
    const int TIMEOUT_MS = 50000; //5Timeout for moving in one direction
    float current_z = 0.0;

    while (true) {

        for (int ch = 1; ch < 3; ch++) {

            HxSetRB(ch, 600, 1, true);
            Sleep(100);
            HxSetRB(ch, 600, 1, false);
            // Get the current Z position
            current_z = HxGetSNF(ch, 205); // Update to match correct Z-axis API parameter
            printf("Current Z Position: %.3f\n", current_z);

            // Move Z+ until max
            if (current_z < Z_MAX) {
                printf("Moving towards Z_MAX...\n");
                HxSetRB(ch, 601, 5, true); // Start moving Z+
                auto start_time = std::chrono::steady_clock::now();
                while (current_z < Z_MAX) {
                    Sleep(100); // Wait a bit
                    current_z = HxGetSNF(ch, 205);
                    printf("Z+: %.3f\n", current_z);

                    // Check for timeout
                    if (std::chrono::steady_clock::now() - start_time > std::chrono::milliseconds(TIMEOUT_MS)) {
                        printf("Timeout while moving Z+.\n");
                        break;
                    }
                }
                HxSetRB(ch, 601, 5, false); // Stop Z+ movement
                printf("Reached or Timeout at Z_MAX: %.3f\n", current_z);
            }

            // Move Z- until min
            if (current_z > Z_MIN) {
                printf("Moving towards Z_MIN...\n");
                HxSetRB(ch, 601, 6, true); // Start moving Z-
                auto start_time = std::chrono::steady_clock::now();
                while (current_z > Z_MIN) {
                    Sleep(100); // Wait a bit
                    current_z = HxGetSNF(ch, 205);
                    printf("Z-: %.3f\n", current_z);

                    // Check for timeout
                    if (std::chrono::steady_clock::now() - start_time > std::chrono::milliseconds(TIMEOUT_MS)) {
                        printf("Timeout while moving Z-.\n");
                        break;
                    }
                }
                HxSetRB(ch, 601, 6, false); // Stop Z- movement
                Sleep(5000);
                for (int sh = 0; sh < 10; sh++)
                {
                    HxSetRB(ch, 601, 5, true);
                    Sleep(200);
                    HxSetRB(ch, 601, 5, false);
                    Sleep(100);
                    HxSetRB(ch, 601, 6, true);
                    Sleep(200);
                    HxSetRB(ch, 601, 6, false);
                    Sleep(200);
                }

                
                
                printf("Reached or Timeout at Z_MIN: %.3f\n", current_z);

                HxSetRB(ch, 601, 5, true);
                Sleep(4000);
                HxSetRB(ch, 601, 5, false);
                Sleep(100);


            }

            // Add delay before switching directions
            Sleep(1000);

        }





    }

    // Disconnect and cleanup
    HxDisconnect(0);
    HxDisconnect(1);
    return 0;
}

