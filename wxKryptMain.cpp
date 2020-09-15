/***************************************************************
 * Name:      wxKryptMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2020-09-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxKryptMain.h"

#include <iostream>
#include <stdlib.h>     /* atoi */
#include <bits/stdc++.h>
using namespace std;


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


wxKryptFrame::wxKryptFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
}

wxKryptFrame::~wxKryptFrame()
{
}

void wxKryptFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void wxKryptFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void wxKryptFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("WVelkommen til..."));
}

void wxKryptFrame::OnKrypter(wxCommandEvent &event)
{
    wxString txt = klarBoks->GetValue();
    string x = txt.ToStdString();
    char y;
    int real_rot = rot;

    for (int i = 0; i < x.size(); i++) {
        y = x[i];
        if (x[i] > 96 && x[i] < 123) {
            y = x[i] - 32;
        }
        //x[i] = ( ((y + atoi(real_rot)) > 90) ? (65) : (0)) + (y + atoi(real_rot)) % 91;
        x[i] = ( ((y + rot)) > 90) ? (65) : (0) + (y + rot) % 91;

    }
    cifferBoks->SetValue(x);
}

void wxKryptFrame::OnDekrypter(wxCommandEvent &event)
{
    wxString txt = cifferBoks->GetValue();
    string x = txt.ToStdString();
    char y;
    int real_rot = rot;

    for (int i = 0; i < x.size(); i++) {
        y = x[i];
        if (x[i] > 96 && x[i] < 123) {
            y = x[i] - 32;
        }
        x[i] = ( ((y - rot)) < 65) ? (65) : (0) + (y - rot) % 91;
    }
    klarBoks->SetValue(x);
}

void wxKryptFrame::OnValg(wxCommandEvent &event)
{
    rot = keyChoice->GetSelection();
    //rot = 1;

}
