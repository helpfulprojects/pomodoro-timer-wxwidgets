#pragma once
#include <wx/wx.h>
#include "MyFrame.h"
class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

// This defines the equivalent of main() for the current platform.
wxIMPLEMENT_APP(MyApp);