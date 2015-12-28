//---------------------------------------------------------------------------
#ifndef PresupuestoH
#define PresupuestoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFPresupuesto : public TForm
{
__published:	// IDE-managed Components
    TDBGrid *DBGrid1;
    TLabel *Label1;
    TQuery *Query;
    TDataSource *DataSource;
    TLabel *Label2;
    TEdit *componente;
    TLabel *Label3;
    TEdit *cantidad;
    TLabel *Label4;
    TEdit *precio;
    TEdit *mano;
    TLabel *Label5;
    TPanel *Panel1;
    TButton *BInsertar;
    TButton *BImprimir;
    TQuery *QueryBorrar;
    void __fastcall BInsertarClick(TObject *Sender);
    
    void __fastcall FormShow(TObject *Sender);
    void __fastcall BImprimirClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    int idFact, numLineas; 
    __fastcall TFPresupuesto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPresupuesto *FPresupuesto;
//---------------------------------------------------------------------------
#endif
