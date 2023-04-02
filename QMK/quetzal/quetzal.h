#pragma once

#include "quantum.h"

#define XXX KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 *
 * The letter refers to which direction the diode is pointing for that key.
 * 'c' means from column pin to row pin.  'r' means from row pin to column pin.
 *
 * e.g. 'r14' means that key is connected to row pin 1 and column pin 4,
 *       with the diode pointing to the column pin.
 */
#define LAYOUT( \
	r00, c00, r01, c10, r02, c20, r03, c30, r04, c40, r05, c50, r06, c60, r07, c70, r08, c80, \
	r10, c01, r11, c11, r12, c21, r13, c31, r14, c41, r15, c51, r16, c61, r17, c71, r18, c81, \
	r20, c02, r21, c12, r22, c22, r23, c32, r24, c42, r25, c52, r26, c62, r27, c72, r28, c82, \
	r30, c03, r31, c13, r32, c23, r33, c33, r34, c43, r35, c53, r36, c63, r37, c73, r38, c83, \
	r40, c04, r41, c14, r42, c24, r43, c34, r44, c44, r45, c54, r46, c64, r47, c74, r48, c84, \
	                    r52, c25, r53, c35, r54, c45, r55, c55, r56, c65, r57, c75, r58, c85  \
) \
{ \
/*    Kicad PCB switch indexes */ \
/*    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   93   94  */ \
	{ r00, c00, r01, c10, r02, c20, r03, c30, r04, c40, r05, c50, r06, c60, r07, c70, r08, c80 }, \
/*    17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   95   96  */ \
	{ r10, c01, r11, c11, r12, c21, r13, c31, r14, c41, r15, c51, r16, c61, r17, c71, r18, c81 }, \
/*    45   46   47   48   33   34   35   36   37   38   39   40   41   42   43   44   97   98  */ \
	{ r20, c02, r21, c12, r22, c22, r23, c32, r24, c42, r25, c52, r26, c62, r27, c72, r28, c82 }, \
/*    61   62   63   64   49   50   51   52   53   54   55   56   57   58   59   60   99   100 */ \
	{ r30, c03, r31, c13, r32, c23, r33, c33, r34, c43, r35, c53, r36, c63, r37, c73, r38, c83 }, \
/*    65   66   67   68   69   70   71   72   73   74   75   76   77   78   79   80   101  102 */ \
	{ r40, c04, r41, c14, r42, c24, r43, c34, r44, c44, r45, c54, r46, c64, r47, c74, r48, c84 }, \
/*  					  81   82   83   84   85   86   87   88   89   90   91   92   103  104 */ \
	{ XXX, XXX, XXX, XXX, r52, c25, r53, c35, r54, c45, r55, c55, r56, c65, r57, c75, r58, c85 }  \
}





