�
 TFRPREP 0�  TPF0TFRPrepFRPrepLeft� Top� Width�Height�BorderIconsbiSystemMenu CaptionRealizar PresupuestoFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style WindowStatewsMaximizedOnShowFormShowPixelsPerInch`
TextHeight TLabelLabel2Left� TopLWidth<HeightCaption
Componente  TLabelLabel3Left� Top~Width*HeightCaptionCantidad  TLabelLabel4Left� Top�WidthHeightCaptionPrecio  TLabelLabel5Left� Top�Width5HeightCaption	Mano Obra  TLabelLabel1Left� Top Width� HeightCaption%Introduzca la Matricula del vehiculo Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFont  TLabelLabel11Left0Top@Width4HeightCaption
Formatos->  TLabelLabel12LeftpTop@Width8HeightCaption
BI-2345-BM  TLabelLabel13LeftpTopPWidth0HeightCaption2345-BDF  TDBGridDBGrid1LeftTop4Width�Height� 
DataSource
DataSourceTabOrder TitleFont.CharsetDEFAULT_CHARSETTitleFont.ColorclWindowTextTitleFont.Height�TitleFont.NameMS Sans SerifTitleFont.Style Visible  TPanelPanel1LeftToptWidth�Height� TabOrder TButton	BInsertarLeft-Top.Width� Height;CaptionInsertarTabOrder OnClickBInsertarClick  TButton	BImprimirLeftTop(Width� Height9CaptionImprimirEnabledTabOrderOnClickBImprimirClick   TEdit
componenteLeftTopLWidth!HeightTabOrder  TEditcantidadLeftToptWidthyHeightTabOrder  TEditprecioLeftTop�WidthyHeightTabOrder  TEditmanoLeftTop�WidthyHeightTabOrder  TEdit	matriculaLefthTop WidthAHeightTabOrder  TQueryQueryDatabaseName.\TablasSQL.Strings#select * from linea where id_fact=0 Left(Top  TDataSource
DataSourceDataSetQueryLeftPTop  TQueryQueryBorrarDatabaseName.\TablasSQL.Strings!delete from linea where id_fact=0 Left� Top   