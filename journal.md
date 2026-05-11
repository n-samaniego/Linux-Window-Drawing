# Journal for my project

## Notes on XLIB functions
### XOpenDisplay
- Used to connect or disconnect to X server
- XOpenDisplay syntax: Display *XOpenDisplay(_Xconst char *display_name);
- from the manpage, display_name "Specifies  the hardware display name, which determines the display and communications domain to be used.  On a POSIX-conformant system, if the display_name  is  NULL,  it  defaults to the value of the DISPLAY environment variable."
- XOpenDisplay returns a Display structure that serves as the connection the X server and contains all information about the X server. Can use TCP, DECnet, or some local protocol. Some syntax to specify whether or not to open using TCP or DECnet, but not relevant since i'm going local
- If successful, XOpenDisplay returns a pointer to the Display structure, defined in X11/Xlib.h. If it fails, it returns NULL.

### The Display Structure
- looks to be a union of a few things
- has components like Visual and Screen, ScreenFormat, etc

### XCreateSimpleWindow
- Syntax: Window XCreateSimpleWindow(Display *display, Window parent,  int  x, int  y, unsigned int width, unsigned int height, unsigned int border_width, unsigned  long  border,  unsigned  long  back-ground);
- The  XCreateSimpleWindow  function  creates  an unmapped InputOutput subwindow for a specified parent window, returns the  window  ID  of the  created window, and causes the X server to generate a CreateNotify event.  The created window is placed on top in the stacking order with respect to siblings.  Any part of the window  that  extends outside its parent window is clipped.  The border_width for an InputOnly window must be zero, or a BadMatch error results.  XCreateSimpleWindow  inherits  its  depth,  class, and visual from its parent. All other window attributes,  except  background  and  border,  have their default values.
- XCreateSimpleWindow  can  generate BadAlloc, BadMatch, BadValue, and BadWindow errors.
- BadAlloc  The  server  failed  to allocate the requested resource or server memory.
- BadMatch  The values do not exist for an InputOnly window. OR Some  argument  or  pair of arguments has the correct type and range but fails to match in some other way required by the request.
- BadValue  Some  numeric  value falls outside the range of values accepted by the request.  Unless a specific range is  specified  for an argument, the full range defined by the argument's type is accepted.  Any argument defined as a set of alternatives can generate this error.
- BadWindow A value for a Window argument does not name a defined Window.

### XMapWindow
- Syntax: int XMapWindow(Display *display, Window w);
- Maps the window and all subwindows that requested to be mapped
- If the window becomes viewable and no eariler contents are remembered, it tiles the window with it's background. 
- Can create the BadWindow error. 

### XFlush
- Pushes the queued up functions from the output buffer to the display

### XNextEvent
