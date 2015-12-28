//---------------------------------------------------------------------------
#ifndef PrepH
#define PrepH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Qrctrls.hpp>
#include <quickrpt.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFPrep : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRBand *QRBand1;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRLabel *duplicado;
    TQRLabel *QRLabel24;
    TQRLabel *QRLabel25;
    TQRLabel *QRLabel26;
    TQRBand *QRBand2;
    TQRLabel *QRLabel8;
    TQRLabel *QRLabel9;
    TQRLabel *QRLabel6;
    TQRLabel *QRLabel1;
    TQRBand *QRBand3;
    TQRDBText *QRDBText2;
    TQRDBText *QRDBText3;
    TQRDBText *QRDBText4;
    TQRDBText *QRDBText1;
    TQRBand *QRBand4;
    TQRLabel *QRLabel18;
    TQRLabel *QRLabel19;
    TQRLabel *QRLabel20;
    TQRLabel *QRLabel21;
    TQRLabel *piezas;
    TQRLabel *mano;
    TQRLabel *iva;
    TQRLabel *total;
    TQuery *Query;
    TQRLabel *Matricula;
    TQRLabel *QRLabel4;
    void __fastcall prepararPresupuesto();
private:	// User declarations
public:		// User declarations
    __fastcall TFPrep(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPrep *FPrep;
//---------------------------------------------------------------------------
#endif
