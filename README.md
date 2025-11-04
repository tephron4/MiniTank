# MiniTank
Project for the functionality of a "MiniTank" bot built from the [MakeBlock Ultimate 2.0 kit](https://www.makeblock.com/collections/all/products/buy-mbot-ultimate-for-classroom)

## The Tank

The MiniTank is from the [MakeBlock Ultimate 2.0 kit](https://www.makeblock.com/collections/all/products/buy-mbot-ultimate-for-classroom). The build is specifically the [Detecting robot](https://drive.google.com/file/d/1Eb0_lIxCSKgGLyFQi_2d9IOy6RE2bIQ7/view) with the line follower removed.

## Setup

The setup for the MiniTank follows the information from the [previous section](#the-tank). For controlling the tank, the project uses the [MakeBlock Bluetooth Remote Controller Joystick](https://www.makeblock.com/collections/all/products/bluetooth-remote-controller), which connects to the tank through bluetooth.

## Functionality

Movement for the MiniTank is controlled with the joysticks on the bluetooth controller:
* the vertical (up/down) movement of the left stick (LY) determines the forward/backward speed of the tank;
* the horizontal (right/left) movement of the right stick (RX) determines the left/right turning speed of the tank.

Also, the tank will move backward whenever it detects an object within 7.5cm infront of it.

> **_NOTE:_** There are a couple issues that have yet to be handled for the sensor-based movement:
> * it can be driven through, so the tank continues forward and doesn't move backward from the object,
> * it is sometimes for an extended distance, seemingly based on how the tank is driven into the 7.5cm threshold.
