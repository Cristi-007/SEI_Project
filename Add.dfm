object FAdd: TFAdd
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'INREGISTRARE'
  ClientHeight = 701
  ClientWidth = 1334
  Color = clBtnFace
  Constraints.MaxHeight = 740
  Constraints.MaxWidth = 1350
  Constraints.MinHeight = 740
  Constraints.MinWidth = 1350
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1334
    Height = 675
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitWidth = 1335
    ExplicitHeight = 674
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 1334
      Height = 675
      ActivePage = Ordonator
      Align = alClient
      BiDiMode = bdLeftToRight
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'Century'
      Font.Style = [fsBold]
      ParentBiDiMode = False
      ParentFont = False
      TabHeight = 25
      TabOrder = 0
      TabWidth = 1335
      ExplicitWidth = 1335
      ExplicitHeight = 674
      object InregDos: TTabSheet
        Caption = 'INREGISTRARE DOSAR'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clGreen
        Font.Height = -15
        Font.Name = 'Century'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitWidth = 1327
        ExplicitHeight = 639
        object Panel2: TPanel
          Left = 0
          Top = 0
          Width = 1326
          Height = 265
          Align = alTop
          BevelOuter = bvLowered
          Color = clActiveCaption
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGreen
          Font.Height = -15
          Font.Name = 'Century'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
          ExplicitWidth = 1327
          object Label4: TLabel
            Left = 360
            Top = 30
            Width = 94
            Height = 16
            Caption = 'TIP ACTIUNE '
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object Label5: TLabel
            Left = 832
            Top = 96
            Width = 79
            Height = 16
            Caption = 'EXECUTOR '
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object Label6: TLabel
            Left = 832
            Top = 30
            Width = 76
            Height = 16
            Caption = 'PRIMIT DE '
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object Label8: TLabel
            Left = 999
            Top = 30
            Width = 95
            Height = 16
            Caption = 'ETAPA DOSAR'
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object Label9: TLabel
            Left = 999
            Top = 96
            Width = 123
            Height = 16
            Caption = 'STARE MATERIAL '
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object Label10: TLabel
            Left = 680
            Top = 96
            Width = 63
            Height = 16
            Caption = 'TERMEN '
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object Label3: TLabel
            Left = 37
            Top = 96
            Width = 91
            Height = 16
            Caption = 'DATA DOSAR '
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object Label13: TLabel
            Left = 197
            Top = 96
            Width = 72
            Height = 16
            Caption = 'DATA ACT '
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object Label7: TLabel
            Left = 1158
            Top = 30
            Width = 90
            Height = 16
            Caption = 'CLASIFICARE'
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object Label1: TLabel
            Left = 1158
            Top = 96
            Width = 82
            Height = 16
            Caption = 'TIP RAPORT'
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
          end
          object NumarD: TLabeledEdit
            Left = 37
            Top = 49
            Width = 121
            Height = 26
            EditLabel.Width = 102
            EditLabel.Height = 16
            EditLabel.Caption = 'NUMAR DOSAR'
            EditLabel.Color = clBlue
            EditLabel.Font.Charset = ANSI_CHARSET
            EditLabel.Font.Color = clBlack
            EditLabel.Font.Height = -13
            EditLabel.Font.Name = 'Century'
            EditLabel.Font.Style = []
            EditLabel.ParentColor = False
            EditLabel.ParentFont = False
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            NumbersOnly = True
            ParentFont = False
            TabOrder = 0
            TextHint = '34/12/1-C-'
          end
          object NrActiune: TLabeledEdit
            Left = 360
            Top = 115
            Width = 121
            Height = 26
            EditLabel.Width = 119
            EditLabel.Height = 16
            EditLabel.Caption = 'NUMAR ACTIUNE'
            EditLabel.Font.Charset = ANSI_CHARSET
            EditLabel.Font.Color = clWindowText
            EditLabel.Font.Height = -13
            EditLabel.Font.Name = 'Century'
            EditLabel.Font.Style = []
            EditLabel.ParentFont = False
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            NumbersOnly = True
            ParentFont = False
            TabOrder = 4
            TextHint = 'Nr.'
          end
          object NrPachete: TLabeledEdit
            Left = 520
            Top = 49
            Width = 121
            Height = 26
            EditLabel.Width = 121
            EditLabel.Height = 16
            EditLabel.Caption = 'NUMAR PACHETE'
            EditLabel.Font.Charset = ANSI_CHARSET
            EditLabel.Font.Color = clWindowText
            EditLabel.Font.Height = -13
            EditLabel.Font.Name = 'Century'
            EditLabel.Font.Style = []
            EditLabel.ParentFont = False
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            NumbersOnly = True
            ParentFont = False
            TabOrder = 5
            TextHint = '0'
          end
          object NrObiecte: TLabeledEdit
            Left = 520
            Top = 115
            Width = 121
            Height = 26
            EditLabel.Width = 116
            EditLabel.Height = 16
            EditLabel.Caption = 'NUMAR OBIECTE'
            EditLabel.Font.Charset = ANSI_CHARSET
            EditLabel.Font.Color = clWindowText
            EditLabel.Font.Height = -13
            EditLabel.Font.Name = 'Century'
            EditLabel.Font.Style = []
            EditLabel.ParentFont = False
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            NumbersOnly = True
            ParentFont = False
            TabOrder = 6
            TextHint = '0'
          end
          object Locatia: TLabeledEdit
            Left = 680
            Top = 49
            Width = 121
            Height = 26
            EditLabel.Width = 92
            EditLabel.Height = 16
            EditLabel.Caption = 'LOCATIA CPD'
            EditLabel.Font.Charset = ANSI_CHARSET
            EditLabel.Font.Color = clWindowText
            EditLabel.Font.Height = -13
            EditLabel.Font.Name = 'Century'
            EditLabel.Font.Style = []
            EditLabel.ParentFont = False
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            ParentFont = False
            TabOrder = 7
            TextHint = 'A,B,C,D,F'
          end
          object NrAct: TLabeledEdit
            Left = 197
            Top = 49
            Width = 121
            Height = 26
            EditLabel.Width = 140
            EditLabel.Height = 16
            EditLabel.Caption = 'NR. ACT DISPUNERE'
            EditLabel.Font.Charset = ANSI_CHARSET
            EditLabel.Font.Color = clWindowText
            EditLabel.Font.Height = -13
            EditLabel.Font.Name = 'Century'
            EditLabel.Font.Style = []
            EditLabel.ParentFont = False
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            NumbersOnly = True
            ParentFont = False
            TabOrder = 2
            TextHint = 'Nr.'
          end
          object EtapaDos: TComboBox
            Left = 999
            Top = 49
            Width = 121
            Height = 26
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 13
            Text = 'C (CPD)'
            Items.Strings = (
              'C (CPD)'
              'E (Desigilat)')
          end
          object StMaterial: TComboBox
            Left = 999
            Top = 115
            Width = 121
            Height = 26
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 12
            Text = 'IN EXECUTARE'
            Items.Strings = (
              'IN EXECUTARE'
              'EXECUTAT'
              'FARA EXECUTARE')
          end
          object Termen: TComboBox
            Left = 680
            Top = 115
            Width = 121
            Height = 26
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            ParentFont = False
            TabOrder = 8
            Text = 'IN TERMEN'
            Items.Strings = (
              'IN TERMEN'
              'URGENT')
          end
          object DataD: TDateTimePicker
            Left = 37
            Top = 115
            Width = 121
            Height = 26
            Date = 44420.874391875000000000
            Time = 44420.874391875000000000
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
          object DataAct: TDateTimePicker
            Left = 197
            Top = 115
            Width = 121
            Height = 26
            Date = 44420.874391875000000000
            Time = 44420.874391875000000000
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Century'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
          end
          object Executor: TDBLookupComboBox
            Left = 832
            Top = 115
            Width = 125
            Height = 26
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            KeyField = 'EXPERT_ID'
            ListField = 'NPP'
            ListSource = DM.DSQExecutorCombo
            ParentFont = False
            TabOrder = 9
          end
          object Primit: TDBLookupComboBox
            Left = 832
            Top = 49
            Width = 125
            Height = 26
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            KeyField = 'EXPERT_ID'
            ListField = 'NPP'
            ListSource = DM.DSQPrimitDe
            ParentFont = False
            TabOrder = 10
          end
          object Clasificare: TDBLookupComboBox
            Left = 1158
            Top = 49
            Width = 125
            Height = 26
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            KeyField = 'CLASIFICARE_ID'
            ListField = 'CLASIFICARE'
            ListSource = DM.DSQClasificareCombo
            ParentFont = False
            TabOrder = 11
          end
          object TipRaport: TDBLookupComboBox
            Left = 1158
            Top = 115
            Width = 125
            Height = 26
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            KeyField = 'TIP_RAPORT_ID'
            ListField = 'PRESCURTARE'
            ListSource = DM.DSQTipRaportCombo
            ParentFont = False
            TabOrder = 14
          end
          object DateOrdonator: TGroupBox
            Left = 37
            Top = 155
            Width = 1246
            Height = 97
            BiDiMode = bdLeftToRight
            Caption = 'DATE  ORDONATOR'
            DoubleBuffered = False
            Font.Charset = ANSI_CHARSET
            Font.Color = clBlack
            Font.Height = -15
            Font.Name = 'SF Compact Text'
            Font.Style = [fsBold]
            ParentBiDiMode = False
            ParentDoubleBuffered = False
            ParentFont = False
            TabOrder = 15
            object EditB: TSpeedButton
              Left = 920
              Top = 37
              Width = 249
              Height = 35
              Caption = 'SELECTARE'
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'SF Pro Display'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = EditBClick
            end
            object NumeO: TLabeledEdit
              Left = 50
              Top = 47
              Width = 121
              Height = 26
              EditLabel.Width = 43
              EditLabel.Height = 16
              EditLabel.Caption = 'NUME'
              EditLabel.Font.Charset = ANSI_CHARSET
              EditLabel.Font.Color = clWindowText
              EditLabel.Font.Height = -13
              EditLabel.Font.Name = 'Century'
              EditLabel.Font.Style = []
              EditLabel.ParentFont = False
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              ParentFont = False
              ParentShowHint = False
              ReadOnly = True
              ShowHint = True
              TabOrder = 0
            end
            object PrenumeO: TLabeledEdit
              Left = 251
              Top = 47
              Width = 121
              Height = 26
              EditLabel.Width = 70
              EditLabel.Height = 16
              EditLabel.Caption = 'PRENUME'
              EditLabel.Font.Charset = ANSI_CHARSET
              EditLabel.Font.Color = clWindowText
              EditLabel.Font.Height = -13
              EditLabel.Font.Name = 'Century'
              EditLabel.Font.Style = []
              EditLabel.ParentFont = False
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              ParentFont = False
              ReadOnly = True
              TabOrder = 1
            end
            object SubdivO: TLabeledEdit
              Left = 450
              Top = 47
              Width = 121
              Height = 26
              EditLabel.Width = 101
              EditLabel.Height = 16
              EditLabel.Caption = 'SUBDIVIZIUNE'
              EditLabel.Font.Charset = ANSI_CHARSET
              EditLabel.Font.Color = clWindowText
              EditLabel.Font.Height = -13
              EditLabel.Font.Name = 'Century'
              EditLabel.Font.Style = []
              EditLabel.ParentFont = False
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              ParentFont = False
              ParentShowHint = False
              ReadOnly = True
              ShowHint = True
              TabOrder = 2
            end
            object DirO: TLabeledEdit
              Left = 643
              Top = 47
              Width = 121
              Height = 26
              EditLabel.Width = 65
              EditLabel.Height = 16
              EditLabel.Caption = 'DIRECTIE'
              EditLabel.Font.Charset = ANSI_CHARSET
              EditLabel.Font.Color = clWindowText
              EditLabel.Font.Height = -13
              EditLabel.Font.Name = 'Century'
              EditLabel.Font.Style = []
              EditLabel.ParentFont = False
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              ParentFont = False
              ParentShowHint = False
              ReadOnly = True
              ShowHint = True
              TabOrder = 3
            end
          end
          object TipActiune: TDBLookupComboBox
            Left = 360
            Top = 49
            Width = 121
            Height = 26
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'SF Pro Text'
            Font.Style = []
            KeyField = 'TIP_ACTIUNE_ID'
            ListField = 'PRESCURTARE'
            ListSource = DM.DSQTipActiuneCombo
            ParentFont = False
            TabOrder = 16
          end
        end
        object Panel4: TPanel
          Left = 0
          Top = 265
          Width = 1326
          Height = 307
          Align = alClient
          Color = clActiveCaption
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGreen
          Font.Height = -15
          Font.Name = 'Century'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          ExplicitWidth = 1327
          ExplicitHeight = 306
          inline FNotite: TFNotite
            Left = 911
            Top = 1
            Width = 414
            Height = 305
            Align = alRight
            TabOrder = 0
            Visible = False
            ExplicitLeft = 912
            ExplicitTop = 1
            ExplicitWidth = 414
            ExplicitHeight = 304
            inherited Panel2: TPanel
              Top = 274
              Width = 414
              ExplicitTop = 273
              ExplicitWidth = 414
              inherited SpeedButton2: TSpeedButton
                Width = 412
                Hint = 'Selectati dosarul la care doriti sa adaugati notite'
                ParentShowHint = False
                ShowHint = True
                OnClick = FNotiteSpeedButton2Click
                ExplicitWidth = 437
              end
            end
            inherited Panel3: TPanel
              Width = 414
              Height = 241
              ExplicitWidth = 414
              ExplicitHeight = 240
              inherited Notite: TMemo
                Width = 412
                Height = 239
                Font.Charset = RUSSIAN_CHARSET
                ExplicitLeft = 1
                ExplicitWidth = 412
                ExplicitHeight = 238
              end
            end
            inherited Panel1: TPanel
              Width = 414
              ExplicitWidth = 414
              inherited SpeedButton1: TSpeedButton
                Left = 385
                Top = 6
                OnClick = FNotiteSpeedButton1Click
                ExplicitLeft = 385
                ExplicitTop = 6
              end
              inherited Label1: TLabel
                Left = 176
                ExplicitLeft = 176
              end
            end
          end
          object DBGrid1: TDBGrid
            Left = 1
            Top = 1
            Width = 910
            Height = 305
            Align = alClient
            Color = clActiveCaption
            DataSource = DM.DSQInregistrare
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clGreen
            Font.Height = -15
            Font.Name = 'Century'
            Font.Style = [fsBold]
            Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
            ParentFont = False
            TabOrder = 1
            TitleFont.Charset = RUSSIAN_CHARSET
            TitleFont.Color = clGreen
            TitleFont.Height = -15
            TitleFont.Name = 'Century'
            TitleFont.Style = [fsBold]
            OnCellClick = DBGrid1CellClick
            Columns = <
              item
                Alignment = taCenter
                Expanded = False
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Nr.'
                Title.Color = clRed
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 43
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'COD_SUBDIVIZIUNE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Cod Subdiviziune'
                Title.Color = clRed
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 138
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'NR_DOSAR'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Nr. Dosar'
                Title.Color = clRed
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 108
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'DATA_DOSAR'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Data Dosar'
                Title.Color = clRed
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 145
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'NR_ACT_DISPUNERE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Nr. Act Disp.'
                Title.Color = clRed
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 114
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'DATA_ACT_DISPUNERE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Data Act Disp.'
                Title.Color = clRed
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 121
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'TIP_ACTIUNE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Tip Actiune'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 92
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'NR_ACTIUNE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Nr. Actiune'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 93
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'SUBDIVIZIUNE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Subdiviziune'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 107
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'DIRECTIA'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Directie'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 70
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'NPP_ORDONATOR'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'N.P Ordonator'
                Title.Color = clRed
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 168
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'NR_PACHETE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Nr. Pachete'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 105
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'NR_OBIECTE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Nr. Obiecte'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 97
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'LOCATIA_CPD'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Locatia CPD'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 116
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'TERMEN_CHAR'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Termen'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 106
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'EXECUTOR'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Executor'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 187
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'PRIMIT_DE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Primit de..'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 182
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'CLASIFICARE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Clasificare'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 142
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'STARE_MATERIAL_CHAR'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Stare Material'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 124
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'ETAPE_INTERMEDIARE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Etape Intermediare'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 151
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'TIP_RAPORT'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Tip Raport'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 96
                Visible = True
              end
              item
                Alignment = taCenter
                Expanded = False
                FieldName = 'NOTE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                Title.Alignment = taCenter
                Title.Caption = 'Note'
                Title.Font.Charset = RUSSIAN_CHARSET
                Title.Font.Color = clWindowText
                Title.Font.Height = -15
                Title.Font.Name = 'SF Pro Rounded'
                Title.Font.Style = [fsBold]
                Width = 82
                Visible = True
              end>
          end
        end
        object Panel5: TPanel
          Left = 0
          Top = 572
          Width = 1326
          Height = 68
          Align = alBottom
          Color = clActiveCaption
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGreen
          Font.Height = -15
          Font.Name = 'Century'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          ExplicitTop = 571
          ExplicitWidth = 1327
          object InregistrareB: TSpeedButton
            Left = 422
            Top = 10
            Width = 491
            Height = 47
            Caption = 'INREGISTRARE DOSAR'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'SF Pro Display'
            Font.Style = [fsBold]
            ParentFont = False
            OnClick = InregistrareBClick
          end
          object NoteB: TSpeedButton
            Left = 1089
            Top = 12
            Width = 220
            Height = 47
            Caption = 'NOTITE LA DOSAR'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'SF Pro Display'
            Font.Style = [fsBold]
            ParentFont = False
            OnClick = NoteBClick
          end
          object AnulareB: TSpeedButton
            Left = 20
            Top = 9
            Width = 220
            Height = 47
            Caption = 'ANULARE'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'SF Pro Display'
            Font.Style = [fsBold]
            ParentFont = False
            OnClick = AnulareBClick
          end
        end
      end
      object Ordonator: TTabSheet
        Caption = 'ORDONATOR'
        ImageIndex = 2
        ExplicitWidth = 1327
        ExplicitHeight = 639
        object PageControl2: TPageControl
          Left = 0
          Top = 0
          Width = 393
          Height = 640
          ActivePage = CautareO
          Align = alLeft
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Century'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabWidth = 393
          ExplicitHeight = 639
          object CautareO: TTabSheet
            Caption = 'CAUTARE RAPIDA'
            ImageIndex = 2
            ExplicitHeight = 606
            object Panel6: TPanel
              Left = 0
              Top = 0
              Width = 377
              Height = 607
              Align = alLeft
              Color = clActiveCaption
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clBlack
              Font.Height = -16
              Font.Name = 'Century'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 0
              ExplicitHeight = 606
              object NewO: TSpeedButton
                Left = 70
                Top = 500
                Width = 235
                Height = 51
                Caption = 'ORDONATOR NOU'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = NewOClick
              end
              object SelectO: TSpeedButton
                Left = 200
                Top = 373
                Width = 161
                Height = 52
                Caption = 'SELECTEAZA'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = SelectOClick
              end
              object Exit: TSpeedButton
                Left = 16
                Top = 373
                Width = 161
                Height = 52
                Caption = 'ANULARE'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = ExitClick
              end
              object Label2: TLabel
                Left = 70
                Top = 275
                Width = 78
                Height = 18
                Caption = 'DIRECTIE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                ParentFont = False
              end
              object Label11: TLabel
                Left = 70
                Top = 195
                Width = 117
                Height = 18
                Caption = 'SUBDIVIZIUNE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                ParentFont = False
              end
              object CautDirO: TDBLookupComboBox
                Left = 70
                Top = 297
                Width = 235
                Height = 26
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                KeyField = 'DIRECTIE_ID'
                ListField = 'PRESCURTARE'
                ListSource = DM.DSQDirectieCombo
                ParentFont = False
                TabOrder = 0
                OnCloseUp = CautDirOCloseUp
              end
              object CautSubdivO: TDBLookupComboBox
                Left = 70
                Top = 219
                Width = 235
                Height = 26
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                KeyField = 'SUBDIVIZIUNE_ID'
                ListField = 'PRESCURTARE'
                ListSource = DM.DSQSubdiviziuneCombo
                ParentFont = False
                TabOrder = 1
                OnCloseUp = CautSubdivOCloseUp
              end
              object CautPrenumeO: TLabeledEdit
                Left = 70
                Top = 137
                Width = 235
                Height = 26
                EditLabel.Width = 81
                EditLabel.Height = 18
                EditLabel.Caption = 'PRENUME'
                EditLabel.Color = clBlue
                EditLabel.Font.Charset = ANSI_CHARSET
                EditLabel.Font.Color = clBlack
                EditLabel.Font.Height = -15
                EditLabel.Font.Name = 'Century'
                EditLabel.Font.Style = []
                EditLabel.ParentColor = False
                EditLabel.ParentFont = False
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = CautPrenumeOChange
              end
              object CautNumeO: TLabeledEdit
                Left = 70
                Top = 57
                Width = 235
                Height = 26
                EditLabel.Width = 49
                EditLabel.Height = 18
                EditLabel.Caption = 'NUME'
                EditLabel.Color = clBlue
                EditLabel.Font.Charset = ANSI_CHARSET
                EditLabel.Font.Color = clBlack
                EditLabel.Font.Height = -15
                EditLabel.Font.Name = 'Century'
                EditLabel.Font.Style = []
                EditLabel.ParentColor = False
                EditLabel.ParentFont = False
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
                OnChange = CautNumeOChange
              end
            end
          end
          object InregO: TTabSheet
            Caption = 'INTREGISTRARE'
            ExplicitHeight = 606
            object Panel3: TPanel
              Left = 0
              Top = 0
              Width = 377
              Height = 607
              Align = alLeft
              Color = clActiveCaption
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clBlack
              Font.Height = -16
              Font.Name = 'Century'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 0
              ExplicitHeight = 606
              object EditareB: TSpeedButton
                Left = 70
                Top = 457
                Width = 235
                Height = 51
                Caption = 'EDITARE ORDONATOR'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = EditareBClick
              end
              object InregB: TSpeedButton
                Left = 200
                Top = 378
                Width = 161
                Height = 52
                Caption = 'INREGISTREAZA'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = InregBClick
              end
              object InregExitB: TSpeedButton
                Left = 200
                Top = 530
                Width = 161
                Height = 52
                Caption = 'ANULARE'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = InregExitBClick
              end
              object Label12: TLabel
                Left = 70
                Top = 275
                Width = 78
                Height = 18
                Caption = 'DIRECTIE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                ParentFont = False
              end
              object Label14: TLabel
                Left = 70
                Top = 195
                Width = 117
                Height = 18
                Caption = 'SUBDIVIZIUNE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                ParentFont = False
              end
              object InregSelectB: TSpeedButton
                Left = 15
                Top = 378
                Width = 161
                Height = 52
                Caption = 'SELECTEAZA'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = SelectOClick
              end
              object InregBackB: TSpeedButton
                Left = 15
                Top = 530
                Width = 161
                Height = 52
                Caption = 'BACK'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = InregBackBClick
              end
              object InregDirO: TDBLookupComboBox
                Left = 70
                Top = 297
                Width = 235
                Height = 26
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                KeyField = 'DIRECTIE_ID'
                ListField = 'PRESCURTARE'
                ListSource = DM.DSQDirectieCombo
                ParentFont = False
                TabOrder = 0
              end
              object InregSubdivO: TDBLookupComboBox
                Left = 70
                Top = 219
                Width = 235
                Height = 26
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                KeyField = 'SUBDIVIZIUNE_ID'
                ListField = 'PRESCURTARE'
                ListSource = DM.DSQSubdiviziuneCombo
                ParentFont = False
                TabOrder = 1
                OnCloseUp = InregSubdivOCloseUp
              end
              object InregPrenumeO: TLabeledEdit
                Left = 70
                Top = 137
                Width = 235
                Height = 26
                EditLabel.Width = 81
                EditLabel.Height = 18
                EditLabel.Caption = 'PRENUME'
                EditLabel.Color = clBlue
                EditLabel.Font.Charset = ANSI_CHARSET
                EditLabel.Font.Color = clBlack
                EditLabel.Font.Height = -15
                EditLabel.Font.Name = 'Century'
                EditLabel.Font.Style = []
                EditLabel.ParentColor = False
                EditLabel.ParentFont = False
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
              end
              object InregNumeO: TLabeledEdit
                Left = 70
                Top = 57
                Width = 235
                Height = 26
                EditLabel.Width = 49
                EditLabel.Height = 18
                EditLabel.Caption = 'NUME'
                EditLabel.Color = clBlue
                EditLabel.Font.Charset = ANSI_CHARSET
                EditLabel.Font.Color = clBlack
                EditLabel.Font.Height = -15
                EditLabel.Font.Name = 'Century'
                EditLabel.Font.Style = []
                EditLabel.ParentColor = False
                EditLabel.ParentFont = False
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
              end
            end
          end
          object EditareO: TTabSheet
            Caption = 'EDITARE'
            ImageIndex = 1
            ExplicitHeight = 606
            object Panel7: TPanel
              Left = 0
              Top = 0
              Width = 377
              Height = 607
              Align = alLeft
              Color = clActiveCaption
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clBlack
              Font.Height = -16
              Font.Name = 'Century'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 0
              ExplicitHeight = 606
              object EditSaveB: TSpeedButton
                Left = 70
                Top = 371
                Width = 235
                Height = 52
                Caption = 'SALVEAZA'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = EditSaveBClick
              end
              object EditExitB: TSpeedButton
                Left = 202
                Top = 525
                Width = 161
                Height = 52
                Caption = 'ANULARE'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = EditExitBClick
              end
              object Label15: TLabel
                Left = 70
                Top = 275
                Width = 78
                Height = 18
                Caption = 'DIRECTIE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                ParentFont = False
              end
              object Label16: TLabel
                Left = 70
                Top = 195
                Width = 117
                Height = 18
                Caption = 'SUBDIVIZIUNE'
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                ParentFont = False
              end
              object EditSelectB: TSpeedButton
                Left = 70
                Top = 450
                Width = 235
                Height = 52
                Caption = 'SELECTEAZA'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = SelectOClick
              end
              object EditBackB: TSpeedButton
                Left = 18
                Top = 525
                Width = 161
                Height = 52
                Caption = 'BACK'
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'SF Pro Display'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = EditBackBClick
              end
              object EditDirO: TDBLookupComboBox
                Left = 70
                Top = 297
                Width = 235
                Height = 26
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                KeyField = 'DIRECTIE_ID'
                ListField = 'PRESCURTARE'
                ListSource = DM.DSQDirectieCombo
                ParentFont = False
                TabOrder = 0
              end
              object EditSubdivO: TDBLookupComboBox
                Left = 70
                Top = 219
                Width = 235
                Height = 26
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Century'
                Font.Style = []
                KeyField = 'SUBDIVIZIUNE_ID'
                ListField = 'PRESCURTARE'
                ListSource = DM.DSQSubdiviziuneCombo
                ParentFont = False
                TabOrder = 1
                OnCloseUp = EditSubdivOCloseUp
              end
              object EditPrenumeO: TLabeledEdit
                Left = 70
                Top = 137
                Width = 235
                Height = 26
                EditLabel.Width = 81
                EditLabel.Height = 18
                EditLabel.Caption = 'PRENUME'
                EditLabel.Color = clBlue
                EditLabel.Font.Charset = ANSI_CHARSET
                EditLabel.Font.Color = clBlack
                EditLabel.Font.Height = -15
                EditLabel.Font.Name = 'Century'
                EditLabel.Font.Style = []
                EditLabel.ParentColor = False
                EditLabel.ParentFont = False
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
              end
              object EditNumeO: TLabeledEdit
                Left = 70
                Top = 57
                Width = 235
                Height = 26
                EditLabel.Width = 49
                EditLabel.Height = 18
                EditLabel.Caption = 'NUME'
                EditLabel.Color = clBlue
                EditLabel.Font.Charset = ANSI_CHARSET
                EditLabel.Font.Color = clBlack
                EditLabel.Font.Height = -15
                EditLabel.Font.Name = 'Century'
                EditLabel.Font.Style = []
                EditLabel.ParentColor = False
                EditLabel.ParentFont = False
                Font.Charset = ANSI_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'SF Pro Text'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
              end
            end
          end
        end
        object DBGrid2: TDBGrid
          Left = 393
          Top = 0
          Width = 933
          Height = 640
          Align = alClient
          DataSource = DM.DSQOrdonator
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
          TabOrder = 1
          TitleFont.Charset = RUSSIAN_CHARSET
          TitleFont.Color = clBlack
          TitleFont.Height = -16
          TitleFont.Name = 'Century'
          TitleFont.Style = [fsBold]
          OnCellClick = DBGrid2CellClick
          Columns = <
            item
              Expanded = False
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clBlack
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              Title.Alignment = taCenter
              Title.Caption = 'Nr.'
              Title.Font.Charset = RUSSIAN_CHARSET
              Title.Font.Color = clBlack
              Title.Font.Height = -16
              Title.Font.Name = 'SF Pro Rounded'
              Title.Font.Style = [fsBold]
              Width = 52
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'NP_ORDONATOR'
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clBlack
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              Title.Alignment = taCenter
              Title.Caption = 'N. P. Ordonator'
              Title.Font.Charset = RUSSIAN_CHARSET
              Title.Font.Color = clBlack
              Title.Font.Height = -16
              Title.Font.Name = 'SF Pro Rounded'
              Title.Font.Style = [fsBold]
              Width = 201
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'SUBDIVIZIUNE'
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clBlack
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              Title.Alignment = taCenter
              Title.Caption = 'Subdiviziunea'
              Title.Font.Charset = RUSSIAN_CHARSET
              Title.Font.Color = clBlack
              Title.Font.Height = -16
              Title.Font.Name = 'SF Pro Rounded'
              Title.Font.Style = [fsBold]
              Width = 295
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'PRESCURTARE_SUBDIV'
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clBlack
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              Title.Alignment = taCenter
              Title.Caption = 'Initiale'
              Title.Font.Charset = RUSSIAN_CHARSET
              Title.Font.Color = clBlack
              Title.Font.Height = -16
              Title.Font.Name = 'SF Pro Rounded'
              Title.Font.Style = [fsBold]
              Width = 69
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'DIRECTIE'
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clBlack
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              Title.Alignment = taCenter
              Title.Caption = 'Directia'
              Title.Font.Charset = RUSSIAN_CHARSET
              Title.Font.Color = clBlack
              Title.Font.Height = -16
              Title.Font.Name = 'SF Pro Rounded'
              Title.Font.Style = [fsBold]
              Width = 217
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'PRESCURTARE_DIR'
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clBlack
              Font.Height = -15
              Font.Name = 'SF Pro Text'
              Font.Style = []
              Title.Alignment = taCenter
              Title.Caption = 'Initiale'
              Title.Font.Charset = RUSSIAN_CHARSET
              Title.Font.Color = clBlack
              Title.Font.Height = -16
              Title.Font.Name = 'SF Pro Rounded'
              Title.Font.Style = [fsBold]
              Width = 77
              Visible = True
            end>
        end
      end
    end
  end
  object FAddStatusBar: TStatusBar
    Left = 0
    Top = 675
    Width = 1334
    Height = 26
    Panels = <
      item
        Text = 'Utilizator: Nume Prenume'
        Width = 200
      end
      item
        Text = 'Functia: expert criminal principal'
        Width = 250
      end
      item
        Alignment = taRightJustify
        Text = 'Data '
        Width = 400
      end
      item
        Alignment = taRightJustify
        Text = 'Ora '
        Width = 50
      end
      item
        Alignment = taRightJustify
        Text = 'Status BD:      '
        Width = 50
      end>
    ExplicitTop = 674
    ExplicitWidth = 1335
  end
end
