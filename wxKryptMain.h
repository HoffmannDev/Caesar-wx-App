/***************************************************************
 * Name:      wxKryptMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2020-09-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WXKRYPTMAIN_H
#define WXKRYPTMAIN_H



#include "wxKryptApp.h"

#include <iostream>

#include "GUIFrame.h"

class wxKryptFrame: public GUIFrame
{
    public:
        wxKryptFrame(wxFrame *frame);
        ~wxKryptFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void OnKrypter(wxCommandEvent& event);
        virtual void OnDekrypter(wxCommandEvent& event);
        virtual void OnValg(wxCommandEvent& event);

        int rot;
};

#endif // WXKRYPTMAIN_H
