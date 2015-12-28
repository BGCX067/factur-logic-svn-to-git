//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("FacturLogic.res");
USEFORM("Clientes.cpp", FClientes);
USEFORM("Factura.cpp", FFactura);
USEFORM("Tablas.cpp", MTablas); /* TDataModule: DesignClass */
USEFORM("Listado.cpp", FListado);
USEFORM("Buscar.cpp", FBuscar);
USEFORM("prueba.cpp", FPrueba);
USEFORM("BuscarFact.cpp", FBuscarFact);
USEFORM("ModLineas.cpp", FModLineas);
USEFORM("Prep.cpp", FPrep);
USEFORM("Principal.cpp", FPrincipal);
USEFORM("RPrep.cpp", FRPrep);
USEFORM("ModVehiculo.cpp", FModVehiculo);
USEFORM("Matricula.cpp", FMatricula);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TFPrincipal), &FPrincipal);
        Application->CreateForm(__classid(TFClientes), &FClientes);
        Application->CreateForm(__classid(TFFactura), &FFactura);
        Application->CreateForm(__classid(TMTablas), &MTablas);
        Application->CreateForm(__classid(TFListado), &FListado);
        Application->CreateForm(__classid(TFBuscar), &FBuscar);
        Application->CreateForm(__classid(TFPrueba), &FPrueba);
        Application->CreateForm(__classid(TFBuscarFact), &FBuscarFact);
        Application->CreateForm(__classid(TFModLineas), &FModLineas);
        Application->CreateForm(__classid(TFPrep), &FPrep);
        Application->CreateForm(__classid(TFRPrep), &FRPrep);
        Application->CreateForm(__classid(TFModVehiculo), &FModVehiculo);
        Application->CreateForm(__classid(TFMatricula), &FMatricula);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
