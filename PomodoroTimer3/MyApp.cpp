#include "MyApp.h"
bool MyApp::OnInit()
{
    MainWindow* mainWindow = new MainWindow();
    mainWindow->Show(true);
    return true;
}