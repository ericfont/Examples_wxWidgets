#include <wx/version.h>
#include <stdio.h>

int main()
{
    printf("%d.%d.%d\n", wxMAJOR_VERSION, wxMINOR_VERSION, wxRELEASE_NUMBER);
    return 0;
}
