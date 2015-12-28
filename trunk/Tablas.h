//---------------------------------------------------------------------------
#ifndef TablasH
#define TablasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TMTablas : public TDataModule
{
__published:	// IDE-managed Components
    TTable *TLinea;
    TDataSource *LineaDS;
    TTable *TFactura;
    TDataSource *FacturaDS;
    TTable *TCoche;
    TDataSource *CocheDS;
private:	// User declarations
public:		// User declarations
    __fastcall TMTablas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMTablas *MTablas;
//---------------------------------------------------------------------------
#endif
