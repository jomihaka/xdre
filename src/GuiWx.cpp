#include "GuiWx.hpp"
#include "MainWindow.hpp"

bool GuiWx::OnInit() {
    mainWindow = new MainWindow();
    mainWindow->Show(true);

    return true;
}
