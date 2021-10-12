#include <wx/wx.h>

namespace Examples {
enum wxOwnedID {
  ID_OPENRECENTFILE1 = 2,
  ID_OPENRECENTFILE2,
  ID_OPENRECENTFILE3,
  ID_OPENRECENTFILE4,
  ID_OPENRECENTFILE5,
  ID_SHOW,
  ID_HIDE,
  ID_OPTIONA,
  ID_OPTIONB,
  ID_OPTIONC,
  ID_OPTIOND,
  ID_OPTIONE,
  ID_OPTIONF,
  ID_OPTIONG,
  ID_OPTIONH,
  ID_OPTIONI,
};
  class Window : public wxFrame {
  public:
    Window() : wxFrame(nullptr, wxID_ANY, "AutoScroll example", wxDefaultPosition, {400, 250}) {
        auto menuHelp = new wxMenu();
        mainMenu->Append(menuHelp, "&Help");

        SetMenuBar(mainMenu);

      panel1->SetBackgroundColour({0x90, 0xEE, 0x90, 0xFF});
      panel2->SetBackgroundColour({0xFF, 0xB6, 0xC1, 0xFF});

      wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
      sizer->Add(new wxButton(panel1, -1, "first row of controls"), 0, 0, 0);
      sizer->Add(new wxButton(panel1, -1, "second row of controls"), 0, 0, 0);
      wxSize minsize = sizer->GetMinSize();
    //  printf( "\n%dx%d\n\n", minsize.GetHeight(), minsize.GetWidth());
     // sizer->SetMinSize( minsize );   // set size hints to honour mininum size
      //sizer->SetSizeHints(panel1);
      panel1->SetSizerAndFit(sizer);

      boxSizerMain->Add(panel1, 0, wxGROW);
      boxSizerMain->Add(panel2, 0, wxGROW);

      panelMain->SetScrollRate(10, 10);
      panelMain->SetSizerAndFit(boxSizerMain);
      panelMain->SetVirtualSize(boxSizerMain->GetSize());

      SetMinSize(minsize);
    }
    
  private:
    wxListBox* listBox1 = new wxListBox(this, wxID_ANY);
    wxMenuBar* mainMenu = new wxMenuBar();
    wxScrolled<wxPanel>* panelMain = new wxScrolled<wxPanel>(this);
    wxBoxSizer* boxSizerMain = new wxBoxSizer(wxVERTICAL);
    wxPanel* panel1 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE);
    wxPanel* panel2 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Window())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
