#include <wx/wx.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame(): wxFrame(nullptr, wxID_ANY, "Hello World") {
      auto menuFile = new wxMenu();
      auto menuFileHello = menuFile->Append(wxID_ANY, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
      menuFile->AppendSeparator();
      menuFile->Append(wxID_EXIT);
      auto menuHelp = new wxMenu();
      menuHelp->Append(wxID_ABOUT);
      auto menuBar = new wxMenuBar();
      menuBar->Append(menuFile, "&File");
      menuBar->Append(menuHelp, "&Help");
      SetMenuBar(menuBar);
      CreateStatusBar();
      SetStatusText("Welcome to wxWidgets!");
      menuBar->Bind(wxEVT_MENU, [menuFileHello, this](wxCommandEvent& event) {
        if (event.GetId() == menuFileHello->GetId()) wxLogMessage("Hello world from wxWidgets!");
        else if (event.GetId() == wxID_ABOUT) wxMessageBox("This is a wxWidgets Hello World example", "About Hello World", wxOK|wxICON_INFORMATION);
        else if (event.GetId() == wxID_EXIT) Close(true);
        else event.Skip();
      });
    }
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
