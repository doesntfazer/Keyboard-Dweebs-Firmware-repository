kbd = Keyboard.new

row0 = 13
row1 = 12
row2 = 11
row3 = 10
row4 = 9
row5 = 8
col0 = 3
col1 = 28
col2 = 27
col3 = 26
col4 = 14
col5 = 4
col6 = 5
col7 = 6
col8 = 7

# Init duplex matrix
kbd.init_matrix_pins(
  [
    [ [row0, col0], [col0, row0], [row0, col1], [col1, row0],
		[row0, col2], [col2, row0], [row0, col3], [col3, row0],
		[row0, col4], [col4, row0], [row0, col5], [col5, row0],
		[row0, col6], [col6, row0], [row0, col7], [col7, row0],
		[row0, col8], [col8, row0] ],
    [ [row1, col0], [col0, row1], [row1, col1], [col1, row1],
		[row1, col2], [col2, row1], [row1, col3], [col3, row1],
		[row1, col4], [col4, row1], [row1, col5], [col5, row1],
		[row1, col6], [col6, row1], [row1, col7], [col7, row1],
		[row1, col8], [col8, row1] ],
    [ [row2, col0], [col0, row2], [row2, col1], [col1, row2],
		[row2, col2], [col2, row2], [row2, col3], [col3, row2],
		[row2, col4], [col4, row2], [row2, col5], [col5, row2],
		[row2, col6], [col6, row2], [row2, col7], [col7, row2],
		[row2, col8], [col8, row2] ],
    [ [row3, col0], [col0, row3], [row3, col1], [col1, row3],
		[row3, col2], [col2, row3], [row3, col3], [col3, row3],
		[row3, col4], [col4, row3], [row3, col5], [col5, row3],
		[row3, col6], [col6, row3], [row3, col7], [col7, row3],
		[row3, col8], [col8, row3] ],
    [ [row4, col0], [col0, row4], [row4, col1], [col1, row4],
		[row4, col2], [col2, row4], [row4, col3], [col3, row4],
		[row4, col4], [col4, row4], [row4, col5], [col5, row4],
		[row4, col6], [col6, row4], [row4, col7], [col7, row4],
		[row4, col8], [col8, row4] ],
    [ nil, nil, nil, nil,
		[row5, col2], [col2, row5], [row5, col3], [col3, row5],
		[row5, col4], [col4, row5], [row5, col5], [col5, row5],
		[row5, col6], [col6, row5], [row5, col7], [col7, row5],
		[row5, col8], [col8, row5] ]
  ]
)

kbd.add_layer :default, %i(
KC_1 KC_2 KC_3 KC_4 KC_5 KC_6
KC_7 KC_8 KC_9 KC_0 KC_1 KC_2
KC_3 KC_4 KC_5 KC_6 KC_7 KC_8
KC_1 KC_2 KC_3 KC_4 KC_5 KC_6
KC_7 KC_8 KC_9 KC_0 KC_1 KC_2
KC_3 KC_4 KC_5 KC_6 KC_7 KC_8
KC_1 KC_2 KC_3 KC_4 KC_5 KC_6
KC_7 KC_8 KC_9 KC_0 KC_1 KC_2
KC_3 KC_4 KC_5 KC_6 KC_7 KC_8
KC_1 KC_2 KC_3 KC_4 KC_5 KC_6
KC_7 KC_8 KC_9 KC_0 KC_1 KC_2
KC_3 KC_4 KC_5 KC_6 KC_7 KC_8
KC_1 KC_2 KC_3 KC_4 KC_5 KC_6
KC_7 KC_8 KC_9 KC_0 KC_1 KC_2
KC_3 KC_4 KC_5 KC_6 KC_7 KC_8
KC_5 KC_6
KC_7 KC_8 KC_9 KC_0 KC_1 KC_2
KC_3 KC_4 KC_5 KC_6 KC_7 KC_8
)

# debug LED on XIAO RP2040
gpio_init 2
gpio_set_dir 2, Keyboard::GPIO_OUT_HI


kbd.start!