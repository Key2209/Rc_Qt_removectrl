#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include "joystick.h"


typedef struct UiDataStruct
{
    JoystickDataStruct joystick1;
    JoystickDataStruct joystick2;

    float scroller_horiz1;
    float scroller_vertical1;

    int button_group1[10];
    int button_group2[10];

}UiDataStruct;







#endif // DATASTRUCT_H
