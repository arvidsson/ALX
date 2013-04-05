#ifndef ALX_EVENT_HPP
#define ALX_EVENT_HPP


#include <cassert>
#include "Joystick.hpp"
#include "Display.hpp"
#include "Timer.hpp"
#include "Value.hpp"


namespace alx {


/**
    Value-based wrapper around ALLEGRO_EVENT.
 */
class Event : public Value<ALLEGRO_EVENT> {
public:
    /**
        default constructor.
     */
    Event() {
    }

    /**
        constructor from event struct.
     */
    Event(const ALLEGRO_EVENT &event) :Value(event) {
    }

    /**
        If the event is a user event, then it is automatically unrefd.
     */
    ~Event() {
        if (_isUserEvent(get().type)) al_unref_user_event(&get().user);
    }

    /**
        Returns true if the event is a user one.
        @return true if user event, false otherwise.
     */
    bool isUserEvent() const {
        return _isUserEvent(get().type);
    }

    /**
        Returns the type of the event.
        @return the type of the event.
     */
    int getType() const {
        return get().type;
    }

    /**
        Returns the event source.
        @return the event source.
     */
    EventSource getEventSource() const {
        return EventSource(get().any.source, false);
    }

    /**
        Returns the timestamp.
        @return the timestamp.
     */
    double getTimestamp() const {
        return get().any.timestamp;
    }

    /**
        Returns the display.
        @return the display.
     */
    Display getDisplay() const {
        return Display(get().display.source, false);
    }

    /**
        Returns the display x.
        @return the display x.
     */
    int getDisplayX() const {
        return get().display.x;
    }

    /**
        Returns the display y.
        @return the display y.
     */
    int getDisplayY() const {
        return get().display.y;
    }

    /**
        Returns the display width.
        @return the display width.
     */
    int getDisplayWidth() const {
        return get().display.width;
    }

    /**
        Returns the display height.
        @return the display height.
     */
    int getDisplayHeight() const {
        return get().display.height;
    }

    /**
        Returns the display orientation.
        @return the display orientation.
     */
    int getDisplayOrientation() const {
        return get().display.orientation;
    }

    /**
        Returns the joystick.
        @return the joystick.
     */
    Joystick getJoystick() const {
        return Joystick(get().joystick.source, false);
    }

    /**
        Returns the joystick id.
        @return the joystick id.
     */
    Joystick getJoystickId() const {
        return Joystick(get().joystick.id, false);
    }

    /**
        Returns the joystick stick.
        @return the joystick stick.
     */
    int getJoystickStick() const {
        return get().joystick.stick;
    }

    /**
        Returns the joystick axis.
        @return the joystick axis.
     */
    int getJoystickAxis() const {
        return get().joystick.axis;
    }

    /**
        Returns the joystick position.
        @return the joystick position.
     */
    float getJoystickPos() const {
        return get().joystick.pos;
    }

    /**
        Returns the joystick button.
        @return the joystick button.
     */
    int getJoystickButton() const {
        return get().joystick.button;
    }

    /**
        Returns the keyboard display.
        @return the keyboard display.
     */
    Display getKeyboardDisplay() const {
        return Display(get().keyboard.display, false);
    }

    /**
        Returns the keyboard keycode.
        @return the keyboard keycode.
     */
    int getKeyboardKeycode() const {
        return get().keyboard.keycode;
    }

    /**
        Returns the keyboard unicode character.
        @return the keyboard unicode character.
     */
    int getKeyboardCharacter() const {
        return get().keyboard.unichar;
    }

    /**
        Returns the keyboard modifiers.
        @return the keyboard modifiers.
     */
    int getKeyboardModifiers() const {
        return get().keyboard.modifiers;
    }

    /**
        Returns the keyboard repeat flag.
        @return the keyboard repeat flag.
     */
    bool getKeyboardRepeat() const {
        return get().keyboard.repeat;
    }

    /**
        Returns the mouse display.
        @return the mouse display.
     */
    Display getMouseDisplay() const {
        return Display(get().mouse.display, false);
    }

    /**
        Returns the mouse x.
        @return the mouse x.
     */
    int getMouseX() const {
        return get().mouse.x;
    }

    /**
        Returns the mouse y.
        @return the mouse y.
     */
    int getMouseY() const {
        return get().mouse.y;
    }

    /**
        Returns the mouse z.
        @return the mouse z. 
     */
    int getMouseZ() const {
        return get().mouse.z;
    }

    /**
        Returns the mouse w.
        @return the mouse w. 
     */
    int getMouseW() const {
        return get().mouse.w;
    }

    /**
        Returns the mouse dx.
        @return the mouse dx. 
     */
    int getMouseDX() const {
        return get().mouse.dx;
    }

    /**
        Returns the mouse dy.
        @return the mouse dy. 
     */
    int getMouseDY() const {
        return get().mouse.dy;
    }

    /**
        Returns the mouse dz.
        @return the mouse dz. 
     */
    int getMouseDZ() const {
        return get().mouse.dz;
    }

    /**
        Returns the mouse dw.
        @return the mouse dw. 
     */
    int getMouseDW() const {
        return get().mouse.dw;
    }

    /**
        Returns the mouse pressure.
        @return the mouse pressure. 
     */
    float getMousePressure() const {
        return get().mouse.pressure;
    }

    /**
        Returns the timer.
        @return the timer.
     */
    Timer getTimer() const {
        return Timer(get().timer.source, false);
    }

    /**
        Returns the timer count.
        @return the timer count.
     */
    int64_t getTimerCount() const {
        return get().timer.count;
    }

    /**
        Returns the timer error.
        @return the timer error.
     */
    double getTimerError() const {
        return get().timer.error;
    }

    /**
        Returns the user data field 1.
        @return the user data field 1.
     */
    intptr_t getUserData1() const {
        return get().user.data1;
    }

    /**
        Returns the user data field 2.
        @return the user data field 2. 
     */
    intptr_t getUserData2() const {
        return get().user.data2;
    }

    /**
        Returns the user data field 3.
        @return the user data field 3. 
     */
    intptr_t getUserData3() const {
        return get().user.data3;
    }

    /**
        Returns the user data field 4.
        @return the user data field 4. 
     */
    intptr_t getUserData4() const {
        return get().user.data4;
    }

private:
    friend class UserEventSource;
    
    //check if the type represents an Allegro event or a user type event.
    static bool _isUserEvent(int type);
};


} //namespace alx


#endif //ALX_EVENT_HPP
