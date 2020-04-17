# Olmech is my keyboard. This is the code which runs it.

It is made of a few parts:

* **Devices**, which manages the input electronics and maintains their known states.
* **The ino file**, which acts as an infrastructure/Business Logic to pass new device events to various event-handlers.
* The various **event handler modules**

Eventually it would be nice to have a true subscription model, but for now the event-handlers are only:
* The debug handler, which would print out coordinates of the key you hit, optionally consuming the input
* The layer handlers, only two of which are in use presently. They have the generic functionality I use in my keyboard today.
* **Future Work**, implement a history handler, and a command-prompt style function input UI. Other fun things.


## Is this software useful beyond one keyboard?
This code is written for my keyboard, as it physically is. Unless you've got an 8x16 ortholinear grid running on a Teensy 3.6, it would take some effort to apply to another keyboard. However, the device setup and the keyboard logic are fairly compartmentalized. If you can change the Device Manager behavior to suit your input device, then the rest might work ok. 

Oh, and there's some weird half-implementations throughout. Just FYI.
