#include <wx/wx.h>
#include <wx/treectrl.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "TreeCtrl example", wxDefaultPosition, {300, 300}) {
      auto rootId = treeCtrl->AddRoot("Root");
      auto firstId = treeCtrl->AppendItem(rootId, "First");
      treeCtrl->AppendItem(firstId, "Second");
      treeCtrl->AppendItem(firstId, "Third");
      auto fourthId = treeCtrl->AppendItem(rootId, "Fourth");
      treeCtrl->AppendItem(fourthId, "Fifth");
      treeCtrl->AppendItem(fourthId, "Sixth");
      treeCtrl->AppendItem(fourthId, "Seventh");
      treeCtrl->ExpandAll();
      treeCtrl->SelectItem(rootId);
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxTreeCtrl* treeCtrl = new wxTreeCtrl(panel, wxID_ANY, {10, 10}, {150, 200});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
