//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
#include "Mainn.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFLogin *FLogin;
//---------------------------------------------------------------------------
__fastcall TFLogin::TFLogin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFLogin::LoginBClick(TObject *Sender)
{
	if ( (Login->Text!="") && (Pass->Text!="") )
	{
		DM->QLiber->Close();
		DM->QLiber->SQL->Clear();
		DM->QLiber->SQL->Add(" SELECT * FROM EXPERT WHERE USERNAME=:USERNAME AND PAROLA=:PAROLA ");
		DM->QLiber->ParamByName("USERNAME")->AsString = Login->Text;
		DM->QLiber->ParamByName("PAROLA")->AsString = Pass->Text;
		DM->QLiber->Open();

		if (!DM->QLiber->IsEmpty())
		{
			FMain->FMainStatusBar->Panels->Items[0]->Text = DM->QLiber->FieldByName("NUME")->AsString + " " + DM->QLiber->FieldByName("PRENUME")->AsString;
			FMain->FMainStatusBar->Panels->Items[1]->Text = DM->QLiber->FieldByName("FUNCTIA")->AsString;

			FMain->SetUserType(DM->QLiber->FieldByName("TIP_ACCES")->AsInteger);

			switch (FMain->GetUserType())
			{
				case 2:
					FMain->Image6->Visible = false;
					FMain->Visible = true;
					break;

				case 3:
					FMain->InregDosar->Enabled = false;
					FMain->Image6->BringToFront();
					FMain->Image1->Visible = false;
					FMain->InregDosar->Flat = false;
					FMain->Label1->BringToFront();

					FMain->InregExam->Enabled = false;
					FMain->Image2->BringToFront();
					FMain->InregExam->Flat = false;
					FMain->Label2->BringToFront();

					FMain->Visible = true;

					break;

				case 4:  break;

				case 5:  break;

				default: break;
			}
			FLogin->Close();
		}
		else
		{
			ShowMessage("Autentificare Esuata!");
			Login->Clear();
			Pass->Clear();
		}
	}
	else
	{
		ShowMessage("Nu sunt completate cimpurile de logare");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFLogin::ExitBClick(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TFLogin::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (FMain->GetUserType() == NULL) { Application->Terminate(); }

}
//---------------------------------------------------------------------------

void __fastcall TFLogin::FormShow(TObject *Sender)
{
	switch (FMain->GetUserType())
	{
		case 2:
			FMain->Image6->Visible = true;
			break;

		case 3:
			FMain->InregDosar->Enabled = true;
			FMain->Image6->SendToBack();
			FMain->Image1->Visible = true;
			FMain->InregDosar->Flat = true;
			FMain->Label1->SendToBack();

			FMain->InregExam->Enabled = true;
			FMain->Image2->SendToBack();
			FMain->InregExam->Flat = true;
			FMain->Label2->SendToBack();

			break;

		case 4:  break;

		case 5:  break;

		default: break;
	}

	FMain->SetUserType(NULL);
	Login->Clear();
	Pass->Clear();
	// de setat focusul pe login tab;
}
//---------------------------------------------------------------------------



void __fastcall TFLogin::PassKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == 13)
	{
		LoginB->Click();
	}
}
//---------------------------------------------------------------------------

