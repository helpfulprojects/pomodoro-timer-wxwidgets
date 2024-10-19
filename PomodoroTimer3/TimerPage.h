#pragma once
#include <wx/wx.h>
#include <wx/notifmsg.h>
#include "MainWindow.h"
class TimerPage : public wxWindow
{
public:
    TimerPage(wxWindow* parent);
    void OnStartWork(wxCommandEvent& event);
    void OnStartBreak(wxCommandEvent& event);
    void OnStartBreak();
    void OnStopTimer(wxCommandEvent& event);
    void OnStopTimer();
    void OnProgressTimer(wxTimerEvent& event);
private:
    static const int TIMER_INTERVAL = 300;
    wxStaticText* statusLabel = nullptr;
    wxStaticText* timerLabel = nullptr;
    wxButton* startWorkBtn = nullptr;
    wxButton* startBreakBtn = nullptr;
    wxButton* stopTimerBtn = nullptr;
    wxTimer* timer = nullptr;
    wxString state = "Idle";
    wxDateTime endDateTime = wxDateTime::Now();
    wxNotificationMessage* notification = nullptr;
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_StartWork = 1,
    ID_StartBreak = 2,
    ID_StopTimer = 3,
    ID_TimerWidget = 4,
};
