
'alex.h'
This is <keyboard>.h
It needs to be renamed to match the folder that your keyboard files are in.

'config.h'
I changed your matrix size to 4x9 to make the matrix scanning easier.
I don't know if defining MATRIX_x_PINS as an empty array like that is necessary.
I just remembering it being a huge pain and throwing some error if I did not do it on mine.

'matrix.c'
Under CONFIGURATION SETTINGS, you can define your direct pins, and the hardware address of MPC23017.
These are both already set to what you gave me, so you shouldn't need to touch this file.

'mcp23017.c' and 'mcp23017.h' were adapted from their mpc23018 counterparts in QMK.
They have functions available for interfacing with the MPC23017 chip.

'rules.mk'
Make sure that you copy the lines from this file into your 'rules.mk' file.
That will make sure the compiler knows to look for the MPC and matrix files.
CUSTOM_MATRIX = LITE tells QMK that you're replacing some functions for matrix scanning.

-------------------------------------------------------------------------------

I haven't tested if anything compiles successfully, and obviously have no way to test this code.
Let me know if there are any errors that you can't figure out.

-hakbraley
