#include "InfoMessageService.h"

using namespace System::Windows::Forms;

void SuccessMessage(String^ message)
{
	MessageBox::Show(message, "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

void ErrorMessage(String^ message)
{
	MessageBox::Show(message, "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
