//---------------------------------------------------------------------------
#ifndef RPrepH
#define RPrepH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFRPrep : public TForm
{
__published:	// IDE-managed Components
    TQuery *Query;
    TDataSource *DataSource;
    TQuery *QueryBorrar;
    TDBGrid *DBGrid1;
    TPanel *Panel1;
    TButton *BInsertar;
    TButton *BImprimir;
    TEdit *componente;
    TEdit *cantidad;
    TEdit *precio;
    TEdit *mano;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TEdit *matricula;
    TLabel *Label1;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    void __fastcall BInsertarClick(TObject *Sender);
    void __fastcall BImprimirClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    
    
    
private:	// User declarations
public:		// User declarations
    int idFact;
    int numLineas;
    double total, iva;
    __fastcall TFRPrep(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRPrep *FRPrep;
//---------------------------------------------------------------------------
#endif
