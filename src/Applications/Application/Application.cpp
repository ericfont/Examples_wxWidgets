#include <wx/wx.h>

namespace Examples {
  class Application : public wxApp {
    bool OnInit() override {
      wxFrame *_frame = new wxFrame(nullptr, wxID_ANY, wxEmptyString);
      _frame->SetMinSize( wxSize(100, 100) );
      _frame->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
