//#include "carManager.h"
//
////
////using namespace System;
////using namespace System::Collections::Generic;
////using namespace System::Windows::Forms::ColumnHeader;
//
//void FillCarListView(ListView^ listView, List<Car^>^ cars)
//{
//    listView->Items->Clear(); // Очищаем ListView перед добавлением новых элементов
//    listView->Columns->Clear(); // Очищаем столбцы ListView
//
//    // Добавляем столбцы с заголовками
//    listView->Columns->Add("ID");
//    listView->Columns->Add("Brand");
//    listView->Columns->Add("Length");
//    listView->Columns->Add("Clearance");
//    listView->Columns->Add("Engine Capacity");
//    listView->Columns->Add("Engine Power");
//    listView->Columns->Add("Wheel Diameter");
//    listView->Columns->Add("Number");
//    listView->Columns->Add("Region");
//    listView->Columns->Add("Car Color");
//
//    // Добавляем каждый автомобиль в ListView
//    for each (Car ^ car in cars)
//    {
//        ListViewItem^ item = gcnew ListViewItem(Convert::ToString(car->id));
//        item->SubItems->Add(car->brand);
//        item->SubItems->Add(Convert::ToString(car->length));
//        item->SubItems->Add(Convert::ToString(car->clearance));
//        item->SubItems->Add(Convert::ToString(car->engineCapacity));
//        item->SubItems->Add(Convert::ToString(car->enginePower));
//        item->SubItems->Add(Convert::ToString(car->wheelDiameter));
//        item->SubItems->Add(car->number);
//        item->SubItems->Add(Convert::ToString(car->region));
//        item->SubItems->Add(car->carColor);
//        listView->Items->Add(item);
//    }
//}
