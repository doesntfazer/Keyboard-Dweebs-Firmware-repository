# Ostrich

![Ostrich](https://i.imgur.com/kaxrSqM.jpg)

The Ostrich is a 34 key keyboard with splayed pinky columns. the rp2040 Pico MCU is canted like the Reviung34. It has the option for a single OLED in the middle of the keyboard, and supports EC12 encoders. (Low profile is recommended.) 

revision 0.9 uses an MCP23017 to avoid having to solder diodes.


Add this folder to the "keyboards" folder of qmk.

See [qmk's firmware setup guide](https://docs.qmk.fm/#/newbs_getting_started) for more information on how to set up qmk.

Use this to flash the keyboard.

```bash
qmk flash -kb ostrich -km default 
```

This keyboard only works if you either have pull ups on the gp0 and gp1 pins. Or if you have an OLED connected. (Because it will use the pull ups from the OLED screen) 
