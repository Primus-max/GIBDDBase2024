#include "MainForm.h"
#include <vector>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	GIBDDBase2024::MainForm mainForm;
	Application::Run(% mainForm);		

	return 0;
}