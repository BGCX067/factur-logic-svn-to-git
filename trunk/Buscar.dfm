�
 TFBUSCAR 0�	  TPF0TFBuscarFBuscarLeft%Top� BorderIconsbiSystemMenu BorderStylebsSingleCaptionBuscar la FacturaClientHeight�ClientWidth Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style PositionpoScreenCenterWindowStatewsMaximizedOnShowFormShowPixelsPerInch`
TextHeight TLabelLabel1Left�Top`Width� HeightCaption Introduce el t�rmino de b�squeda  TLabelLabel3Left Top� WidthZHeightCaptionDatos de la facturaVisible  TLabelLabel2Left�Top@WidthFHeightCaption;Para ver en detalle la factura que le interese introduzca, Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFontVisible  TLabelLabel4Left�TopPWidth;HeightCaption7el n�mero de la misma y pulse sobre el bot�n "Detallar"Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFontVisible  TEditclaveLeftTopxWidthYHeightReadOnly	TabOrder OnChangeclaveChangeOnClick
claveClick  TButtonBBuscarLeftxTopxWidthAHeightCaptionBuscarEnabledTabOrderOnClickBBuscarClick  TDBGridDBGrid1LeftTop� Width�HeightI
DataSourceDataSource1TabOrderTitleFont.CharsetDEFAULT_CHARSETTitleFont.ColorclWindowTextTitleFont.Height�TitleFont.NameMS Sans SerifTitleFont.Style Visible  	TGroupBox	GroupBox1Left8TopHWidth� HeightYCaptionCriterio de B�squedaTabOrder TRadioButtonnumFactLeft0TopWidthqHeightCaptionN�mero FacturaTabOrder OnClicknumFactClick  TRadioButton	matriculaLeft0Top0WidthYHeightCaption	MatriculaTabOrderOnClickmatriculaClick   TButton	BDetallarLeft@TophWidthKHeightCaptionDetallarEnabledTabOrderVisibleOnClickBDetallarClick  TEditfacturaLeft�TophWidthYHeightTabOrderVisibleOnChangefacturaChange  TStaticTextStaticText1LeftPTop�WidthHeightTabOrder  TQuery
SuperQueryDatabaseName.\TablasSQL.Strings5select * from factura where Matricula=:identificativo Params.Data
     identificativo  0   Left�Top  TDataSourceDataSource1DataSet
SuperQueryLeft�Top  TQueryQuery1DatabaseName.\TablasSQL.Strings3select * from factura where id_fact=:identificativo Params.Data
     identificativo        Left�Top@   