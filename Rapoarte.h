//---------------------------------------------------------------------------

#ifndef RapoarteH
#define RapoarteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.DBCtrls.hpp>
//---------------------------------------------------------------------------
class TFRaport : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label5;
	TLabel *Label12;
	TLabeledEdit *NumarR;
	TDateTimePicker *DataR;
	TLabeledEdit *Pret;
	TLabel *Label3;
	TLabeledEdit *DosDiv;
	TGroupBox *Obiecte;
	TLabel *Label7;
	TLabeledEdit *Model;
	TLabeledEdit *Capacit;
	TSpeedButton *Finish;
	TSpeedButton *Cancel;
	TLabel *Label2;
	TGroupBox *Raport;
	TDBLookupComboBox *ExpertR;
	TDBLookupComboBox *StagiarR;
	TDBLookupComboBox *TipObiect;
	TSpeedButton *InregOb;
	TSpeedButton *InregRap;
	TDBLookupComboBox *Marca;
	TLabel *Label1;
	void __fastcall Panel1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CancelClick(TObject *Sender);
	void __fastcall InregRapClick(TObject *Sender);
	void __fastcall InregObClick(TObject *Sender);
	void __fastcall FinishClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFRaport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRaport *FRaport;
//---------------------------------------------------------------------------
#endif
