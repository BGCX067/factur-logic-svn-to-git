//---------------------------------------------------------------------------
#ifndef BuscarH
#define BuscarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFBuscar : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *clave;
    TButton *BBuscar;
    TDBGrid *DBGrid1;
    TQuery *SuperQuery;
    TDataSource *DataSource1;
    TQuery *Query1;
    TLabel *Label3;
    TGroupBox *GroupBox1;
    TRadioButton *numFact;
    TRadioButton *matricula;
    TButton *BDetallar;
    TEdit *factura;
    TLabel *Label2;
    TStaticText *StaticText1;
    TLabel *Label4;
    void __fastcall BBuscarClick(TObject *Sender);
    void __fastcall claveChange(TObject *Sender);
    void __fastcall numFactClick(TObject *Sender);
    void __fastcall matriculaClick(TObject *Sender);
    
    void __fastcall facturaChange(TObject *Sender);
    void __fastcall BDetallarClick(TObject *Sender);
    void __fastcall BSalirClick(TObject *Sender);
    
    
    void __fastcall FormShow(TObject *Sender);
    void __fastcall claveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFBuscar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFBuscar *FBuscar;
//---------------------------------------------------------------------------
#endif
