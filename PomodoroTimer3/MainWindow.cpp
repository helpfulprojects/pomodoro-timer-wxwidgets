#include "MainWindow.h"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Pomodoro Timer", wxPoint(1920 / 2 - 400, 1080 / 2 - 300), wxSize(800, 600))
{
	auto sizer = new wxBoxSizer(wxVERTICAL);
	wxNotebook* notebook = new wxNotebook(this, wxID_ANY);
	notebook->AddPage(new TimerPage(notebook), L"Timer");
	notebook->AddPage(new wxNotebookPage(notebook, -1), L"Settings");
	sizer->Add(notebook, 1, wxEXPAND | wxALL, FromDIP(10));
}
