//---------------------------------------------------------------------------
#ifndef BuscarFactH
#define BuscarFactH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFBuscarFact : public TForm
{
__published:	// IDE-managed Components
    TEdit *NumFact;
    TLabel *Label1;
    TButton *BAceptar;
    TQuery *Query1;
    TDataSource *DataSource1;
    TLabel *Label2;
    TQuery *Query2;
    TLabel *identificativo;
    TGroupBox *GroupBox2;
    TLabel *Label12;
    TLabel *Label15;
    TLabel *Label6;
    TLabel *Label7;
    TEdit *mano;
    TEdit *fechEntrada;
    TEdit *fechSalida;
    TButton *BModLineas;
    TGroupBox *GroupBox1;
    TLabel *Label4;
    TLabel *Label3;
    TLabel *Label5;
    TLabel *Label8;
    TLabel *Label11;
    TLabel *Label9;
    TLabel *Label10;
    TEdit *Vehiculo;
    TEdit *Marca;
    TEdit *matricula;
    TEdit *nombre;
    TEdit *dni;
    TEdit *dir;
    TEdit *tlf;
    TButton *BModVehiculo;
    TButton *BCambiarVehiculo;
    TQuery *QVehiculo;
    TButton *BModificar;
    void __fastcall BCancelarClick(TObject *Sender);
    void __fastcall BAceptarClick(TObject *Sender);
    
    
    
    void __fastcall BModificarClick(TObject *Sender);
    
    
    
    
    
    
    
    void __fastcall BModLineasClick(TObject *Sender);
    
    
    void __fastcall BModVehiculoClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall NumFactClick(TObject *Sender);
    void __fastcall NumFactChange(TObject *Sender);
    void __fastcall BCambiarVehiculoClick(TObject *Sender);

    
private:	// User declarations
public:		// User declarations
    __fastcall TFBuscarFact(TComponent* Owner);
    void __fastcall BuscarVehiculo(String mat);
};
//---------------------------------------------------------------------------
extern PACKAGE TFBuscarFact *FBuscarFact;
//---------------------------------------------------------------------------
#endif
