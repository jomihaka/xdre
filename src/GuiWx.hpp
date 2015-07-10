/*
 * Something I supposedly need
 */

#ifndef __GUIWX_HPP
#define __GUIWX_HPP


#include <wx/app.h>

class MainWindow;

class GuiWx : public wxApp {
public:
    virtual bool OnInit();
protected:
private:
    MainWindow* mainWindow;
};



#endif // __GUIWX_HPP
