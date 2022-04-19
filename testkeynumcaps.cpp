#include <testkeynumcaps.h>
#include <X11/XKBlib.h>
#undef KeyPress
#undef KeyRelease
#undef FocusIn
#undef FocusOut

bool getCapsLockOn()
{
    Display* d = XOpenDisplay((char*)0);
    bool caps_state = false;
    if(d){
        unsigned n;
        XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
        caps_state = (n & 0x01) == 1;
    }
    return caps_state;
}

bool getNumLockOn()
{
    bool num_state = false;
    Display* d = XOpenDisplay(":0");
    XKeyboardState x;
    XGetKeyboardControl(d, &x);
    XCloseDisplay(d);

    num_state = ((x.led_mask & 2) ? true : false);
    return num_state;
}
