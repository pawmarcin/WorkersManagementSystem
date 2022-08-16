#include "Logowanie1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WorkersManagementSystem::Logowanie1 form;
	Application::Run(%form);
	return 0;
}
