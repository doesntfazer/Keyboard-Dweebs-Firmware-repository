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
	c00, r00, c10, r01, c20, r02, c30, r03, c40, r04, c50, r05, c60, r06, c70, r07, c80, r08, \
	c01, r10, c11, r11, c21, r12, c31, r13, c41, r14, c51, r15, c61, r16, c71, r17, c81, r18, \
	c02, r20, c12, r21, c22, r22, c32, r23, c42, r24, c52, r25, c62, r26, c72, r27, c82, r28, \
	c03, r30, c13, r31, c23, r32, c33, r33, c43, r34, c53, r35, c63, r36, c73, r37, c83, r38, \
	c04, r40, c14, r41, c24, r42, c34, r43, c44, r44, c54, r45, c64, r46, c74, r47, c84, r48, \
	                    c25, r52, c35, r53, c45, r54, c55, r55, c65, r56, c75, r57, c85, r58  \
) \
{ \
/*    KiCad PCB switch indexes */ \
/*    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   93   94  */ \
	{ c00, r00, c10, r01, c20, r02, c30, r03, c40, r04, c50, r05, c60, r06, c70, r07, c80, r08 }, \
/*    17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   95   96  */ \
	{ c01, r10, c11, r11, c21, r12, c31, r13, c41, r14, c51, r15, c61, r16, c71, r17, c81, r18 }, \
/*    45   46   47   48   33   34   35   36   37   38   39   40   41   42   43   44   97   98  */ \
	{ c02, r20, c12, r21, c22, r22, c32, r23, c42, r24, c52, r25, c62, r26, c72, r27, c82, r28 }, \
/*    61   62   63   64   49   50   51   52   53   54   55   56   57   58   59   60   99   100 */ \
	{ c03, r30, c13, r31, c23, r32, c33, r33, c43, r34, c53, r35, c63, r36, c73, r37, c83, r38 }, \
/*    65   66   67   68   69   70   71   72   73   74   75   76   77   78   79   80   101  102 */ \
	{ c04, r40, c14, r41, c24, r42, c34, r43, c44, r44, c54, r45, c64, r46, c74, r47, c84, r48 }, \
/*  					  81   82   83   84   85   86   87   88   89   90   91   92   103  104 */ \
	{ XXX, XXX, XXX, XXX, c25, r52, c35, r53, c45, r54, c55, r55, c65, r56, c75, r57, c85, r58 }  \
}





