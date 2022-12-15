Add this folder to the "keyboards" folder of qmk.
Use this to flash the keyboard.

```bash
qmk flash -kb ostrich -km default 
```

This keyboard only works if you either have pull ups on the gp0 and gp1 pins. Or if you have an OLED connected. (Because it will use the pull ups from the OLED screen) 
