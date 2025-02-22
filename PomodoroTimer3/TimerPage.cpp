#include "TimerPage.h"
wxBEGIN_EVENT_TABLE(TimerPage, wxWindow)
    EVT_BUTTON(ID_StartWork, TimerPage::OnStartWork)
    EVT_BUTTON(ID_StartBreak, TimerPage::OnStartBreak)
    EVT_BUTTON(ID_StopTimer, TimerPage::OnStopTimer)
    EVT_TIMER(ID_TimerWidget, TimerPage::OnProgressTimer)
wxEND_EVENT_TABLE()
TimerPage::TimerPage(wxWindow* parent) :
    wxWindow(parent, wxID_ANY)
{
    timer = new wxTimer(this, ID_TimerWidget);

    auto sizer = new wxBoxSizer(wxVERTICAL);

    wxFont statusFont(57, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont timerFont(57, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont buttonsFont(37, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    statusLabel = new wxStaticText(this, wxID_ANY, "Status: " + state);
    statusLabel->SetFont(statusFont);
    timerLabel = new wxStaticText(this, wxID_ANY, "00:00");
    timerLabel->SetFont(timerFont);

    startWorkBtn = new wxButton(this, ID_StartWork, "Start Work");
    startBreakBtn = new wxButton(this, ID_StartBreak, "Start Break");
    stopTimerBtn = new wxButton(this, ID_StopTimer, "Stop Timer");
    startWorkBtn->SetFont(buttonsFont);
    startBreakBtn->SetFont(buttonsFont);
    stopTimerBtn->SetFont(buttonsFont);

    sizer->Add(statusLabel, 2, wxALIGN_CENTER_HORIZONTAL | wxALL, FromDIP(10));
    sizer->Add(timerLabel, 2, wxALIGN_CENTER_HORIZONTAL | wxALL, FromDIP(10));
    sizer->Add(startWorkBtn, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, FromDIP(10));
    sizer->Add(startBreakBtn, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, FromDIP(10));
    sizer->Add(stopTimerBtn, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, FromDIP(10));

    this->SetSizer(sizer);
    notification = new wxNotificationMessage();
    notification->SetParent(this);
    notification->SetTitle("Pomodoro Timer");
}
void TimerPage::OnStartWork(wxCommandEvent& event)
{
    state = "Work";
    endDateTime = wxDateTime::Now();
    std::cout << "Test" << std::endl;
    endDateTime.Add(wxTimeSpan::Minute()*30);
    timer->Start(TIMER_INTERVAL);
    notification->SetMessage(state+" Started");
    notification->Show();
}

void TimerPage::OnStartBreak(wxCommandEvent& event)
{
    OnStartBreak();
}

void TimerPage::OnStartBreak()
{
    state = "Break";
    endDateTime = wxDateTime::Now();
    endDateTime.Add(wxTimeSpan::Minute() * 10);
    timer->Start(TIMER_INTERVAL);
    notification->SetMessage(state + " Started");
    notification->Show();
}

void TimerPage::OnStopTimer(wxCommandEvent& event)
{
    OnStopTimer();
}
void TimerPage::OnStopTimer()
{
    state = "Idle";
    timer->Stop();
    statusLabel->SetLabelText("Status: " + state);
    timerLabel->SetLabelText("00:00");
    notification->SetMessage("Timer Stopped");
    notification->Show();
}

void TimerPage::OnProgressTimer(wxTimerEvent& event)
{
    auto currentDateTime = wxDateTime::Now();
    auto difference = endDateTime.Subtract(currentDateTime);
    if (difference >= 0) {
        timerLabel->SetLabelText(difference.Format("%M:%S"));
    }
    else {
        if (state == "Work") {
            OnStartBreak();
        }
        else {
            OnStopTimer();
        }
    }
    statusLabel->SetLabelText("Status: " + state);
}
