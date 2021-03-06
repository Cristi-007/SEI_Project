//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Add.h"
#include "Login.h"
#include "Mainn.h"
#include "Search.h"
#include "DataModule.h"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Notite"
#pragma resource "*.dfm"
TFAdd *FAdd;

int DosarID = NULL, OrdonatorID = NULL, RaportID = NULL;
bool Cell_Click = false;

//---------------------------------------------------------------------------
__fastcall TFAdd::TFAdd(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAdd::FormShow(TObject *Sender)
{
	FAddStatusBar->Panels->Items[2]->Text = System::TDateTime::CurrentDate();
	FAddStatusBar->Panels->Items[0]->Text = FMain->FMainStatusBar->Panels->Items[0]->Text;
	FAddStatusBar->Panels->Items[1]->Text = FMain->FMainStatusBar->Panels->Items[1]->Text;

	DataD->Date = System::TDateTime::CurrentDate();
	DataAct->Date = System::TDateTime::CurrentDate();

	InregDos->TabVisible = false;
	Ordonator->TabVisible = false;
	InregDos->TabVisible = true;

	DM->QInregistrare->Close();
	DM->QInregistrare->Open();

	DM->QTipActiuneCombo->Close();
	DM->QTipActiuneCombo->Open();

	DM->QPrimitDe->Close();
	DM->QPrimitDe->Open();

	DM->QExecutorCombo->Close();
	DM->QExecutorCombo->Open();

	DM->QClasificareCombo->Close();
	DM->QClasificareCombo->Open();

	DM->QTipRaportCombo->Close();
	DM->QTipRaportCombo->Open();

	DM->QSubdiviziuneCombo->Close();
	DM->QSubdiviziuneCombo->Open();

	NumarD->Clear();
	NrAct->Clear();
	TipActiune->KeyValue = NULL;
	NrActiune->Clear();
	NrPachete->Clear();
	NrObiecte->Clear();
	Locatia->Clear();
	Termen->ItemIndex = 0;
	Executor->KeyValue = NULL;
	Primit->KeyValue = NULL;
	StMaterial->ItemIndex = 0;
	EtapaDos->ItemIndex = 0;
	Clasificare->KeyValue = NULL;
	TipRaport->KeyValue = NULL;
	NumeO->Clear();
	PrenumeO->Clear();
	SubdivO->Clear();
	DirO->Clear();
	FNotite->Notite->Clear();

	CautSubdivO->KeyValue = 1;
}
//---------------------------------------------------------------------------


void __fastcall TFAdd::DBGrid1CellClick(TColumn *Column)
{
	Cell_Click = true;
	DosarID = DM->QInregistrare->FieldByName("DOSAR_ID")->AsInteger;
	FNotite->SpeedButton2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::FNotiteSpeedButton1Click(TObject *Sender)
{
	if( FNotite->Notite->Text != "" )
	{
		if (MessageDlg("Dvs intradevar doriti sa inchideti fereastra? (Toate datele introduse vor fi sterse)", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
			FNotite->Visible=false;
			NoteB->Enabled = true;
			FNotite->Notite->Clear();
		}
	}
	else
	{
		FNotite->Visible=false;
		NoteB->Enabled = true;
		FNotite->Notite->Clear();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFAdd::FNotiteSpeedButton2Click(TObject *Sender)
{
	if( (FNotite->Notite->Text != "") && DosarID != NULL)
	{
		DM->QLiber->Close();
		DM->QLiber->SQL->Clear();
		DM->QLiber->SQL->Add(" UPDATE DOSAR SET NOTE=:NOTE WHERE DOSAR_ID=:DOSAR_ID ");

		DM->QLiber->ParamByName("NOTE")->AsString = FNotite->Notite->Text.UpperCase();
		DM->QLiber->ParamByName("DOSAR_ID")->AsInteger = DosarID;
		DM->QLiber->ExecSQL();

		ShowMessage("Notite adaugate cu succes !");

		FNotite->Notite->Clear();
		DM->QLiber->Close();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFAdd::AnulareBClick(TObject *Sender)
{
	FAdd->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::NoteBClick(TObject *Sender)
{
	if (Cell_Click == true)
	{
		FNotite->Notite->Clear();
		FNotite->Notite->MaxLength = 300;
		FNotite->Visible = true;
		NoteB->Enabled = false;
		FNotite->SpeedButton2->Enabled = true;
	}
	else
	{
		FNotite->Notite->Clear();
		FNotite->Notite->MaxLength = 300;
		FNotite->Visible = true;
		NoteB->Enabled = false;
		FNotite->SpeedButton2->Enabled = false;
	}
}
//---------------------------------------------------------------------------


void __fastcall TFAdd::InregistrareBClick(TObject *Sender)
{
	AnsiString FreeQuery = NULL;

	if ( (NumarD->Text!="") && (NrAct->Text!="") && (TipActiune->KeyValue != NULL ) && (NrActiune->Text!="") && (Locatia->Text!="") && (Executor->KeyValue!= NULL) && (Primit->KeyValue!= NULL) && (Clasificare->KeyValue!= NULL) && (TipRaport->KeyValue!= NULL) && (OrdonatorID != NULL))
	 {
//////////// INSERT TIP RAPORT --> RAPORT_ID
		DM->ProcRaport_ID->Close();
		DM->ProcRaport_ID->Params->Items[1]->AsInteger = TipRaport->KeyValue;
		DM->ProcRaport_ID->ExecProc();
		RaportID = DM->ProcRaport_ID->Params->Items[0]->AsInteger;
		DM->ProcRaport_ID->Close();

//////////// INSERT DOSAR
		FreeQuery = " INSERT INTO DOSAR (NR_DOSAR, DATA_DOSAR, NR_ACT_DISPUNERE, DATA_ACT_DISPUNERE, TIP_ACTIUNE_ID, NR_ACTIUNE, NR_PACHETE, NR_OBIECTE, ";
		FreeQuery +="TERMEN, LOCATIA_CPD, EXECUTOR_ID, EXPERT_ID_PRIMIT_DOSAR, CLASIFICARE_ID, STARE_MATERIAL, ETAPE_INTERMEDIARE, RAPORT_ID, ORDONATOR_ID ) ";
		FreeQuery +="VALUES (:NR_DOSAR, :DATA_DOSAR, :NR_ACT_DISPUNERE, :DATA_ACT_DISPUNERE, :TIP_ACTIUNE_ID, :NR_ACTIUNE, :NR_PACHETE, :NR_OBIECTE, ";
		FreeQuery +=":TERMEN, :LOCATIA_CPD, :EXECUTOR_ID, :EXPERT_ID_PRIMIT_DOSAR, :CLASIFICARE_ID, :STARE_MATERIAL, :ETAPE_INTERMEDIARE, :RAPORT_ID, :ORDONATOR_ID)";
		DM->QLiber->Close();
		DM->QLiber->SQL->Clear();
		DM->QLiber->SQL->Add(FreeQuery);

		DM->QLiber->ParamByName("NR_DOSAR")->AsInteger = NumarD->Text.ToInt();
		DM->QLiber->ParamByName("DATA_DOSAR")->AsDate = DataD->Date;
		DM->QLiber->ParamByName("NR_ACT_DISPUNERE")->AsInteger = NrAct->Text.ToInt();
		DM->QLiber->ParamByName("DATA_ACT_DISPUNERE")->AsDate = DataAct->Date;
		DM->QLiber->ParamByName("NR_ACTIUNE")->AsString = NrActiune->Text.UpperCase();
		DM->QLiber->ParamByName("LOCATIA_CPD")->AsString = Locatia->Text.UpperCase();
		DM->QLiber->ParamByName("TERMEN")->AsInteger = Termen->ItemIndex;
		DM->QLiber->ParamByName("STARE_MATERIAL")->AsInteger = StMaterial->ItemIndex;
		DM->QLiber->ParamByName("CLASIFICARE_ID")->AsInteger = Clasificare->KeyValue;
		DM->QLiber->ParamByName("EXPERT_ID_PRIMIT_DOSAR")->AsInteger = Primit->KeyValue;
		DM->QLiber->ParamByName("EXECUTOR_ID")->AsInteger = Executor->KeyValue;
		DM->QLiber->ParamByName("ORDONATOR_ID")->AsInteger = OrdonatorID;
		DM->QLiber->ParamByName("TIP_ACTIUNE_ID")->AsInteger = TipActiune->KeyValue;
		DM->QLiber->ParamByName("RAPORT_ID")->AsInteger = RaportID;

		if ( EtapaDos->ItemIndex == 0 ) { DM->QLiber->ParamByName("ETAPE_INTERMEDIARE")->AsString = "C"; }
			else  { DM->QLiber->ParamByName("ETAPE_INTERMEDIARE")->AsString = "E"; }

		if (NrPachete->Text=="") { DM->QLiber->ParamByName("NR_PACHETE")->AsInteger = 0; }
			else { DM->QLiber->ParamByName("NR_PACHETE")->AsInteger = NrPachete->Text.ToInt(); }

		if (NrObiecte->Text=="") { DM->QLiber->ParamByName("NR_OBIECTE")->AsInteger = 0; }
			else { DM->QLiber->ParamByName("NR_OBIECTE")->AsInteger = NrObiecte->Text.ToInt(); }

		DM->QLiber->ExecSQL();
		FreeQuery = NULL;


		ShowMessage("Dosar Inregistrat cu Succes!");
		NumarD->Clear();
		NrAct->Clear();
		TipActiune->KeyValue = NULL;
		NrActiune->Clear();
		NrPachete->Clear();
		NrObiecte->Clear();
		Locatia->Clear();
		Termen->ItemIndex = 0;
		Executor->KeyValue = NULL;
		Primit->KeyValue = NULL;
		StMaterial->ItemIndex = 0;
		EtapaDos->ItemIndex = 0;
		Clasificare->KeyValue = NULL;
		TipRaport->KeyValue = NULL;
		NumeO->Clear();
		PrenumeO->Clear();
		SubdivO->Clear();
		DirO->Clear();
		FNotite->Notite->Clear();
		DataD->Date = System::TDateTime::CurrentDate();
		DataAct->Date = System::TDateTime::CurrentDate();

		DM->QInregistrare->Close();
		DM->QInregistrare->Open();
	 }
	 else
	 {
		ShowMessage("Nu sunt indeplinite toate cimpurile !!!");
	 }
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::CautNumeOChange(TObject *Sender)
{
	AnsiString FreeQuery = NULL;

	if (CautNumeO->Text!="")
	{
		if (CautSubdivO->KeyValue==1)
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->Open();
		}
		else if (CautDirO->KeyValue==1)
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->Open();
		}
		else
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
			FreeQuery += "AND OD.DIRECTIE_ID= :DIRECTIE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
			DM->QOrdonator->Open();
		}
	}
	else
	{
		if (CautSubdivO->KeyValue==1)
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE OD.ORDONATOR_ID!=1 ";
			FreeQuery += "ORDER BY SU.PRESCURTARE ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->Open();
		}
		else if (CautDirO->KeyValue==1)
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID AND OD.ORDONATOR_ID!=1 ORDER BY SU.PRESCURTARE ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->Open();
		}
		else
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID AND OD.DIRECTIE_ID= :DIRECTIE_ID AND OD.ORDONATOR_ID!=1 ORDER BY SU.PRESCURTARE ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
			DM->QOrdonator->Open();
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TFAdd::CautPrenumeOChange(TObject *Sender)
{
	AnsiString FreeQuery = NULL;

	if (CautNumeO->Text=="")
	{
		if (CautPrenumeO->Text!="")
		{
			if (CautSubdivO->KeyValue==1)
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->Open();
			}
			else if (CautDirO->KeyValue==1)
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
				DM->QOrdonator->Open();
			}
			else
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
				FreeQuery += "AND OD.DIRECTIE_ID= :DIRECTIE_ID ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
				DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
				DM->QOrdonator->Open();
			}
		}
		else
		{
			if (CautSubdivO->KeyValue==1)
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE OD.ORDONATOR_ID!=1 ";
				FreeQuery += "ORDER BY SU.PRESCURTARE ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->Open();
			}
			else if (CautDirO->KeyValue==1)
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ORDER BY SU.PRESCURTARE ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
				DM->QOrdonator->Open();
			}
			else
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID AND OD.DIRECTIE_ID= :DIRECTIE_ID ORDER BY SU.PRESCURTARE ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
				DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
				DM->QOrdonator->Open();
			}
		}
	}
	else
	{
		if (CautPrenumeO->Text!="")
		{
			if (CautSubdivO->KeyValue==1)
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND ";
				FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->Open();
			}
			else if (CautDirO->KeyValue==1)
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND ";
				FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
				DM->QOrdonator->Open();
			}
			else
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND ";
				FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
				FreeQuery += "AND OD.DIRECTIE_ID= :DIRECTIE_ID ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
				DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
				DM->QOrdonator->Open();
			}
		}
		else
		{
			if (CautSubdivO->KeyValue==1)
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->Open();
			}
			else if (CautDirO->KeyValue==1)
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND ";
				FreeQuery += "DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
				DM->QOrdonator->Open();
			}
			else
			{
				FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
				FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
				FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
				FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
				FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
				FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND ";
				FreeQuery += "DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID AND OD.DIRECTIE_ID= :DIRECTIE_ID ";
				DM->QOrdonator->Close();
				DM->QOrdonator->SQL->Clear();
				DM->QOrdonator->SQL->Add(FreeQuery);
				DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
				DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
				DM->QOrdonator->Open();
			}
		}
	}

	OrdonatorID = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::EditBClick(TObject *Sender)
{
	CautSubdivO->KeyValue = 1;
	CautNumeO->Clear();
	CautPrenumeO->Clear();

	CautareO->TabVisible = false;
	InregO->TabVisible = false;
	EditareO->TabVisible = false;
	CautareO->TabVisible = true;

	InregDos->TabVisible = false;
	Ordonator->TabVisible = true;

	DM->QOrdonator->Close();
	DM->QOrdonator->Open();

	Cell_Click = false;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::SelectOClick(TObject *Sender)
{
	NumeO->Text = DM->QOrdonator->FieldByName("NUME")->AsString;
	PrenumeO->Text = DM->QOrdonator->FieldByName("PRENUME")->AsString;
	SubdivO->Text = DM->QOrdonator->FieldByName("PRESCURTARE_SUBDIV")->AsString;
	DirO->Text = DM->QOrdonator->FieldByName("PRESCURTARE_DIR")->AsString;

	InregDos->TabVisible = true;
	Ordonator->TabVisible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::CautSubdivOCloseUp(TObject *Sender)
{
	DM->QDirectieCombo->Close();

	try
	{
		DM->QDirectieCombo->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
	}
	catch (...)	{   }

	DM->QDirectieCombo->Open();
	CautDirO->KeyValue = 1;

	AnsiString FreeQuery = NULL;

	if (CautSubdivO->KeyValue != 1 )
	{
		if (CautNumeO->Text!="" && CautPrenumeO->Text=="")
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->Open();
		}
		else if (CautNumeO->Text=="" && CautPrenumeO->Text!="")
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->Open();
		}
		else if (CautNumeO->Text!="" && CautPrenumeO->Text!="")
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND ";
			FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->Open();
		}
		else
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->Open();
		}
	}
	else
	{
		if (CautNumeO->Text!="" && CautPrenumeO->Text=="")
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->Open();
		}
		else if (CautNumeO->Text=="" && CautPrenumeO->Text!="")
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->Open();
		}
		else if (CautNumeO->Text!="" && CautPrenumeO->Text!="")
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND ";
			FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->Open();
		}
		else
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE OD.ORDONATOR_ID!=1 ORDER BY SU.PRESCURTARE ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->Open();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::CautDirOCloseUp(TObject *Sender)
{
	AnsiString FreeQuery = NULL;

	if (CautDirO->KeyValue!=1)
	{
		if (CautNumeO->Text!="" && CautPrenumeO->Text=="")
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
			FreeQuery += "AND OD.DIRECTIE_ID= :DIRECTIE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
			DM->QOrdonator->Open();
		}
		else if (CautNumeO->Text=="" && CautPrenumeO->Text!="")
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
			FreeQuery += "AND OD.DIRECTIE_ID= :DIRECTIE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
			DM->QOrdonator->Open();
		}
		else if (CautNumeO->Text!="" && CautPrenumeO->Text!="")
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "NPO.NUME LIKE '" + CautNumeO->Text.UpperCase() + "%' AND ";
			FreeQuery += "NPO.PRENUME LIKE '" + CautPrenumeO->Text.UpperCase() + "%' AND DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID ";
			FreeQuery += "AND OD.DIRECTIE_ID= :DIRECTIE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
			DM->QOrdonator->Open();
		}
		else
		{
			FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
			FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
			FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
			FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
			FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
			FreeQuery += "DI.SUBDIVIZIUNE_ID= :SUBDIVIZIUNE_ID AND OD.DIRECTIE_ID= :DIRECTIE_ID ";
			DM->QOrdonator->Close();
			DM->QOrdonator->SQL->Clear();
			DM->QOrdonator->SQL->Add(FreeQuery);
			DM->QOrdonator->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = CautSubdivO->KeyValue;
			DM->QOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = CautDirO->KeyValue;
			DM->QOrdonator->Open();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::DBGrid2CellClick(TColumn *Column)
{
	Cell_Click = true;
	OrdonatorID = DM->QOrdonator->FieldByName("ORDONATOR_ID")->AsInteger;

	if (EditareO->TabVisible==true)
	{
		EditNumeO->Text = DM->QOrdonator->FieldByName("NUME")->AsString;
		EditPrenumeO->Text = DM->QOrdonator->FieldByName("PRENUME")->AsString;
		EditSubdivO->KeyValue = DM->QOrdonator->FieldByName("SUBDIVIZIUNE_ID")->AsInteger;

		DM->QDirectieCombo->Close();
		DM->QDirectieCombo->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = EditSubdivO->KeyValue;
		DM->QDirectieCombo->Open();
		EditDirO->KeyValue = DM->QOrdonator->FieldByName("DIRECTIE_ID")->AsInteger;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::ExitClick(TObject *Sender)
{
	InregDos->TabVisible = true;
	Ordonator->TabVisible = false;

	CautNumeO->Clear();
	CautPrenumeO->Clear();
	CautSubdivO->KeyValue = 1;
	CautDirO->KeyValue = 1;

	DM->QOrdonator->Close();

	Cell_Click = false;
	OrdonatorID = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::NewOClick(TObject *Sender)
{
	AnsiString FreeQuery = NULL;

	InregO->TabVisible = true;
	CautareO->TabVisible = false;
	EditareO->TabVisible = false;

	InregSubdivO->KeyValue = 1;

	InregNumeO->Clear();
	InregPrenumeO->Clear();
	InregSubdivO->KeyValue = 1;
	InregDirO->KeyValue = 1;

	FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
	FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
	FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
	FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
	FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE OD.ORDONATOR_ID!=1 ";
	FreeQuery += "ORDER BY SU.PRESCURTARE ";
	DM->QOrdonator->Close();
	DM->QOrdonator->SQL->Clear();
	DM->QOrdonator->SQL->Add(FreeQuery);
	DM->QOrdonator->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::InregBClick(TObject *Sender)
{
	int NPOrdonatorID = NULL;
	AnsiString FreeQuery = NULL;

	try
	{
		if ( InregNumeO->Text!="" && InregPrenumeO->Text!="" && InregSubdivO->KeyValue!=1 && InregDirO->KeyValue!=1 )
		{
		/////////VERIFICARE + INSERT NP_ORDONATOR
			DM->QDateOrdonator->Close();
			DM->QDateOrdonator->SQL->Clear();
			DM->QDateOrdonator->SQL->Add(" SELECT * FROM NPP_ORDONATOR WHERE NUME=:NUME AND PRENUME=:PRENUME ");
			DM->QDateOrdonator->ParamByName("NUME")->AsString = InregNumeO->Text.UpperCase();
			DM->QDateOrdonator->ParamByName("PRENUME")->AsString = InregPrenumeO->Text.UpperCase();
			DM->QDateOrdonator->Open();

			if ( DM->QDateOrdonator->IsEmpty() ) //DACA NU ESTE NP
			{
				DM->ProcNPOrdonator->Close();
				DM->ProcNPOrdonator->Params->Items[1]->AsString = InregNumeO->Text.UpperCase();
				DM->ProcNPOrdonator->Params->Items[2]->AsString = InregPrenumeO->Text.UpperCase();
				DM->ProcNPOrdonator->ExecProc();
				NPOrdonatorID = DM->ProcNPOrdonator->Params->Items[0]->AsInteger;
			}
			else    //DACA ESTE NP
			{
				NPOrdonatorID = DM->QDateOrdonator->FieldByName("NPP_ORDONATOR_ID")->AsInteger;
			}

		/////////VERIFICARE + INSERT ORDONATOR
			DM->QDateOrdonator->Close();
			DM->QDateOrdonator->SQL->Clear();
			DM->QDateOrdonator->SQL->Add(" SELECT * FROM ORDONATOR WHERE DIRECTIE_ID=:DIRECTIE_ID AND NPP_ORDONATOR_ID=:NPP_ORDONATOR_ID ");
			DM->QDateOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = InregDirO->KeyValue;
			DM->QDateOrdonator->ParamByName("NPP_ORDONATOR_ID")->AsInteger = NPOrdonatorID;
			DM->QDateOrdonator->Open();

			if ( DM->QDateOrdonator->IsEmpty() )
			{
				DM->ProcOrdonator_ID->Close();
				DM->ProcOrdonator_ID->Params->Items[1]->AsInteger = InregDirO->KeyValue;
				DM->ProcOrdonator_ID->Params->Items[2]->AsInteger = NPOrdonatorID;
				DM->ProcOrdonator_ID->ExecProc();
				OrdonatorID = DM->ProcOrdonator_ID->Params->Items[0]->AsInteger;
			}
			else
			{
                ShowMessage("Un astfel de ordonator deja este inregistrat!");
				OrdonatorID = DM->QDateOrdonator->FieldByName("ORDONATOR_ID")->AsInteger;
				//ShowMessage(DM->QDateOrdonator->FieldByName("ORDONATOR_ID")->AsInteger);
				//ShowMessage(DM->QDateOrdonator->FieldByName("DIRECTIE_ID")->AsInteger);
				//ShowMessage(DM->QDateOrdonator->FieldByName("NPP_ORDONATOR_ID")->AsInteger);
			}
			DM->ProcOrdonator_ID->Close();
		}
		else
		{
			if ( InregSubdivO->KeyValue!=1 && InregDirO->KeyValue!=1 && InregNumeO->Text=="" && InregPrenumeO->Text!="" ) { throw 1; }
			if ( InregSubdivO->KeyValue!=1 && InregDirO->KeyValue!=1 && InregNumeO->Text!="" && InregPrenumeO->Text=="" ) { throw 2; }
			if ( InregSubdivO->KeyValue!=1 && InregDirO->KeyValue==1 && InregNumeO->Text!="" && InregPrenumeO->Text!="" ) { throw 3; }
			if ( InregSubdivO->KeyValue==1 && InregNumeO->Text!="" && InregPrenumeO->Text!="" ) { throw 4;}
			if ( InregSubdivO->KeyValue!=1 && InregDirO->KeyValue!=1 && InregNumeO->Text=="" && InregPrenumeO->Text=="" ) { throw 5; }

			if ( InregSubdivO->KeyValue==1 && InregNumeO->Text!="" && InregPrenumeO->Text=="" ) { throw 6; }
			//else if ( InregSubdivO->KeyValue==1 && InregNumeO->Text=="" && InregPrenumeO->Text!="" ) { throw 6; }
			//else if ( InregSubdivO->KeyValue!=1 && InregNumeO->Text=="" && InregPrenumeO->Text=="" ) { throw 6; }
			else { throw 6; }
		}
	}
	catch (int X)
	{
		switch (X)
		{
			case 1: ShowMessage("Nu ati introdus Numele!"); return;
			case 2: ShowMessage("Nu ati introdus Prenumele!"); return;
			case 3: ShowMessage("Nu ati selectat Directia"); return;
			case 4: ShowMessage("Nu ati selectat Subdiviziunea si Directia!"); return;
			case 5: ShowMessage("Nu ati selectat Numele si Prenumele!"); return;
			case 6: ShowMessage("Nu ati introdus toate datele!"); return;
		}
	}

	FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
	FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
	FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
	FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
	FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
	FreeQuery += "OD.ORDONATOR_ID!=1 ORDER BY SU.PRESCURTARE ";

	DM->QOrdonator->Close();
	DM->QOrdonator->SQL->Clear();
	DM->QOrdonator->SQL->Add(FreeQuery);
	DM->QOrdonator->Open();

	InregNumeO->Clear();
	InregPrenumeO->Clear();
	InregSubdivO->KeyValue = 1;
	InregDirO->KeyValue = 1;
}
//---------------------------------------------------------------------------


void __fastcall TFAdd::InregSubdivOCloseUp(TObject *Sender)
{
	DM->QDirectieCombo->Close();

	try
	{
		DM->QDirectieCombo->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = InregSubdivO->KeyValue;
	}
	catch (...)	{   }

	DM->QDirectieCombo->Open();
	InregDirO->KeyValue = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::InregExitBClick(TObject *Sender)
{
	InregDos->TabVisible = true;
	Ordonator->TabVisible = false;

	CautNumeO->Clear();
	CautPrenumeO->Clear();
	CautSubdivO->KeyValue = 1;
	CautDirO->KeyValue = 1;

	InregNumeO->Clear();
	InregPrenumeO->Clear();
	InregSubdivO->KeyValue = 1;
	InregDirO->KeyValue = 1;

	EditNumeO->Clear();
	EditPrenumeO->Clear();
	EditSubdivO->KeyValue = 1;
	EditDirO->KeyValue = 1;

	DM->QOrdonator->Close();

	Cell_Click = false;
	OrdonatorID = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::EditareBClick(TObject *Sender)
{
	InregO->TabVisible = false;
	CautareO->TabVisible = false;
	EditareO->TabVisible = true;

	EditNumeO->Clear();
	EditPrenumeO->Clear();
	EditSubdivO->KeyValue = 1;
	EditDirO->KeyValue = 1;
}
//---------------------------------------------------------------------------


void __fastcall TFAdd::EditExitBClick(TObject *Sender)
{
	InregDos->TabVisible = true;
	Ordonator->TabVisible = false;

	CautNumeO->Clear();
	CautPrenumeO->Clear();
	CautSubdivO->KeyValue = 1;
	CautDirO->KeyValue = 1;

	InregNumeO->Clear();
	InregPrenumeO->Clear();
	InregSubdivO->KeyValue = 1;
	InregDirO->KeyValue = 1;

	EditNumeO->Clear();
	EditPrenumeO->Clear();
	EditSubdivO->KeyValue = 1;
	EditDirO->KeyValue = 1;

	DM->QOrdonator->Close();

	Cell_Click = false;
	OrdonatorID = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::InregBackBClick(TObject *Sender)
{
	CautareO->TabVisible = true;
	InregO->TabVisible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::EditBackBClick(TObject *Sender)
{
	InregO->TabVisible = true;
	EditareO->TabVisible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::EditSaveBClick(TObject *Sender)
{
	AnsiString FreeQuery = NULL;
	int NpOrdonatorID = NULL;

	try
	{
		DM->QDateOrdonator->Close();
		DM->QDateOrdonator->SQL->Clear();
		DM->QDateOrdonator->SQL->Add(" SELECT * FROM NPP_ORDONATOR WHERE NUME= :NUME AND PRENUME= :PRENUME ");
		DM->QDateOrdonator->ParamByName("NUME")->AsString = EditNumeO->Text.UpperCase();
		DM->QDateOrdonator->ParamByName("PRENUME")->AsString = EditPrenumeO->Text.UpperCase();
		DM->QDateOrdonator->Open();

		if ( DM->QDateOrdonator->IsEmpty() )
		{

             ShowMessage("aici");



			NpOrdonatorID = DM->QOrdonator->FieldByName("NPP_ORDONATOR_ID")->AsInteger;
			DM->QLiber->Close();
			DM->QLiber->SQL->Clear();
			DM->QLiber->SQL->Add("UPDATE NPP_ORDONATOR SET NUME = :NUME, PRENUME = :PRENUME WHERE NPP_ORDONATOR_ID = :NPP_ORDONATOR_ID");
			DM->QLiber->ParamByName("NUME")->AsString = EditNumeO->Text.UpperCase();
			DM->QLiber->ParamByName("PRENUME")->AsString = EditPrenumeO->Text.UpperCase();
			DM->QLiber->ParamByName("NPP_ORDONATOR_ID")->AsInteger = NpOrdonatorID;
			DM->QLiber->ExecSQL();
		}
		else
		{
			 NpOrdonatorID = DM->QDateOrdonator->FieldByName("NPP_ORDONATOR_ID")->AsInteger;
		}

////////////////VERIFICARE + UPDATE ORDONATOR
		DM->QDateOrdonator->Close();
		DM->QDateOrdonator->SQL->Clear();
		DM->QDateOrdonator->SQL->Add(" SELECT * FROM ORDONATOR WHERE DIRECTIE_ID= :DIRECTIE_ID AND NPP_ORDONATOR_ID= :NPP_ORDONATOR_ID ");
		DM->QDateOrdonator->ParamByName("DIRECTIE_ID")->AsInteger = EditDirO->KeyValue;
		DM->QDateOrdonator->ParamByName("NPP_ORDONATOR_ID")->AsInteger = NpOrdonatorID;
		DM->QDateOrdonator->Open();

		if ( DM->QDateOrdonator->IsEmpty() )
		{
			DM->QLiber->Close();
			DM->QLiber->SQL->Clear();
			DM->QLiber->SQL->Add("UPDATE ORDONATOR SET NPP_ORDONATOR_ID= :NPP_ORDONATOR_ID, DIRECTIE_ID= :DIRECTIE_ID WHERE ORDONATOR_ID= :ORDONATOR_ID");
			DM->QLiber->ParamByName("NPP_ORDONATOR_ID")->AsInteger = NpOrdonatorID;
			DM->QLiber->ParamByName("DIRECTIE_ID")->AsInteger = EditDirO->KeyValue;
			DM->QLiber->ParamByName("ORDONATOR_ID")->AsInteger = DM->QOrdonator->FieldByName("ORDONATOR_ID")->AsInteger;
			DM->QLiber->ExecSQL();
		}
		else
		{
			if ( DM->QDateOrdonator->FieldByName("ORDONATOR_ID") == DM->QOrdonator->FieldByName("ORDONATOR_ID") )
			{
				ShowMessage("Ordonator editat cu succes!");
			}
			else
			{
				ShowMessage("Ordonatorul dat deja este inregistrat!");
			}
		}
	}
	catch (...)
	{
		return;
	}

	EditNumeO->Clear();
	EditPrenumeO->Clear();
	EditSubdivO->KeyValue = 1;
	EditDirO->KeyValue = 1;

    FreeQuery = NULL;

	FreeQuery = "SELECT OD.*, NPO.NUME+'  '+PRENUME AS NP_ORDONATOR, NPO.NUME, NPO.PRENUME, DI.DIRECTIE, ";
	FreeQuery += "DI.PRESCURTARE AS PRESCURTARE_DIR,DI.SUBDIVIZIUNE_ID, SU.SUBDIVIZIUNE, SU.PRESCURTARE AS PRESCURTARE_SUBDIV ";
	FreeQuery += "FROM NPP_ORDONATOR NPO INNER JOIN ORDONATOR OD ON NPO.NPP_ORDONATOR_ID=OD.NPP_ORDONATOR_ID ";
	FreeQuery += "INNER JOIN DIRECTIE DI ON OD.DIRECTIE_ID=DI.DIRECTIE_ID ";
	FreeQuery += "INNER JOIN SUBDIVIZIUNE SU ON SU.SUBDIVIZIUNE_ID=DI.SUBDIVIZIUNE_ID WHERE ";
	FreeQuery += "OD.ORDONATOR_ID!=1 ORDER BY SU.PRESCURTARE ";

	DM->QOrdonator->Close();
	DM->QOrdonator->SQL->Clear();
	DM->QOrdonator->SQL->Add(FreeQuery);
	DM->QOrdonator->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::EditSubdivOCloseUp(TObject *Sender)
{
	DM->QDirectieCombo->Close();

	try
	{
		DM->QDirectieCombo->ParamByName("SUBDIVIZIUNE_ID")->AsInteger = EditSubdivO->KeyValue;
	}
	catch (...)	{   }

	DM->QDirectieCombo->Open();
	EditDirO->KeyValue = 1;
}
//---------------------------------------------------------------------------

