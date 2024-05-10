#include "InfoMessageService.h"

using namespace System::Windows::Forms;

void SuccessMessage(String^ message)
{
	MessageBox::Show(message, "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

void ErrorMessage(String^ message)
{
	MessageBox::Show(message, "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
