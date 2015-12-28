//---------------------------------------------------------------------------
#ifndef ModLineasH
#define ModLineasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFModLineas : public TForm
{
__published:	// IDE-managed Components
    TDBGrid *DBGrid1;
    TPanel *Panel1;
    TEdit *componente;
    TEdit *cantidad;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *precio;
    TLabel *Label3;
    TQuery *Query;
    TDataSource *DataSource1;
    TLabel *Label6;
    TEdit *numLinea;
    TButton *BSituar;
    TLabel *Label4;
    TPanel *Panel2;
    TButton *BFinalizar;
    TButton *BInsertar;
    TButton *BBorrar;
    TQuery *QueryLinea;
    TLabel *totalL;
    TQuery *QueryUpdate;
    TLabel *Label5;
    TLabel *Label7;
    void __fastcall FormShow(TObject *Sender);
    
    
    void __fastcall BSituarClick(TObject *Sender);
    
    void __fastcall BInsertarClick(TObject *Sender);
    void __fastcall BFinalizarClick(TObject *Sender);
    
    void __fastcall numLineaChange(TObject *Sender);
    void __fastcall numLineaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    int idFact;
    int idLinea;
    int estado;
    __fastcall TFModLineas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFModLineas *FModLineas;
//---------------------------------------------------------------------------
#endif
