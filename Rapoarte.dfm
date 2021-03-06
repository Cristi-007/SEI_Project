object FRaport: TFRaport
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'DATE RAPORT'
  ClientHeight = 728
  ClientWidth = 598
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 598
    Height = 728
    Align = alClient
    BevelInner = bvLowered
    Color = clMoneyGreen
    ParentBackground = False
    TabOrder = 0
    OnMouseDown = Panel1MouseDown
    object Label12: TLabel
      Left = 256
      Top = 50
      Width = 95
      Height = 25
      Caption = 'RAPORT'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Century'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Finish: TSpeedButton
      Left = 43
      Top = 648
      Width = 193
      Height = 47
      Caption = 'FINALIZARE'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'SF Pro Display'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = FinishClick
    end
    object Cancel: TSpeedButton
      Left = 360
      Top = 648
      Width = 193
      Height = 47
      Caption = 'ANULARE'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'SF Pro Display'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = CancelClick
    end
    object Obiecte: TGroupBox
      Left = 43
      Top = 359
      Width = 510
      Height = 250
      Caption = 'OBIECTE'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'SF Compact Text'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      object Label7: TLabel
        Left = 64
        Top = 42
        Width = 78
        Height = 16
        Caption = 'TIP OBIECT'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Century'
        Font.Style = []
        ParentFont = False
      end
      object InregOb: TSpeedButton
        Left = 155
        Top = 198
        Width = 193
        Height = 33
        Caption = 'INREGISTREAZA'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'SF Pro Display'
        Font.Style = [fsBold]
        ParentFont = False
        OnClick = InregObClick
      end
      object Label1: TLabel
        Left = 296
        Top = 42
        Width = 48
        Height = 16
        Caption = 'MARCA'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Century'
        Font.Style = []
        ParentFont = False
      end
      object Model: TLabeledEdit
        Left = 296
        Top = 128
        Width = 142
        Height = 26
        EditLabel.Width = 50
        EditLabel.Height = 16
        EditLabel.Caption = 'MODEL'
        EditLabel.Color = clBlue
        EditLabel.Font.Charset = ANSI_CHARSET
        EditLabel.Font.Color = clBlack
        EditLabel.Font.Height = -13
        EditLabel.Font.Name = 'Century'
        EditLabel.Font.Style = []
        EditLabel.ParentColor = False
        EditLabel.ParentFont = False
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'SF Pro Text'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        TextHint = 'Tehnic'
      end
      object Capacit: TLabeledEdit
        Left = 64
        Top = 128
        Width = 137
        Height = 26
        EditLabel.Width = 122
        EditLabel.Height = 16
        EditLabel.Caption = 'CAPACITATEA(GB)'
        EditLabel.Color = clBlue
        EditLabel.Font.Charset = ANSI_CHARSET
        EditLabel.Font.Color = clBlack
        EditLabel.Font.Height = -13
        EditLabel.Font.Name = 'Century'
        EditLabel.Font.Style = []
        EditLabel.ParentColor = False
        EditLabel.ParentFont = False
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'SF Pro Text'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 1
        TextHint = '0'
      end
      object TipObiect: TDBLookupComboBox
        Left = 64
        Top = 61
        Width = 137
        Height = 26
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'SF Pro Text'
        Font.Style = []
        KeyField = 'TIP_OBIECT_ID'
        ListField = 'PRESCURTARE'
        ListSource = DM.DSQTipObiectCombo
        ParentFont = False
        TabOrder = 0
      end
      object Marca: TDBLookupComboBox
        Left = 296
        Top = 61
        Width = 142
        Height = 26
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'SF Pro Text'
        Font.Style = []
        KeyField = 'MARCA_ID'
        ListField = 'MARCA'
        ListSource = DM.DSQMarcaTelCombo
        ParentFont = False
        TabOrder = 3
      end
    end
    object Raport: TGroupBox
      Left = 43
      Top = 101
      Width = 510
      Height = 252
      Caption = 'RAPORT'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'SF Compact Text'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      object Label5: TLabel
        Left = 187
        Top = 39
        Width = 100
        Height = 16
        Caption = 'DATA RAPORT '
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Century'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 187
        Top = 110
        Width = 121
        Height = 16
        Caption = 'EXPERT STAGIAR '
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Century'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 29
        Top = 110
        Width = 58
        Height = 16
        Caption = 'EXPERT '
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Century'
        Font.Style = []
        ParentFont = False
      end
      object InregRap: TSpeedButton
        Left = 155
        Top = 200
        Width = 193
        Height = 33
        Caption = 'INREGISTREAZA'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'SF Pro Display'
        Font.Style = [fsBold]
        ParentFont = False
        OnClick = InregRapClick
      end
      object NumarR: TLabeledEdit
        Left = 29
        Top = 58
        Width = 121
        Height = 26
        EditLabel.Width = 111
        EditLabel.Height = 16
        EditLabel.Caption = 'NUMAR RAPORT'
        EditLabel.Color = clBlue
        EditLabel.Font.Charset = ANSI_CHARSET
        EditLabel.Font.Color = clBlack
        EditLabel.Font.Height = -13
        EditLabel.Font.Name = 'Century'
        EditLabel.Font.Style = []
        EditLabel.ParentColor = False
        EditLabel.ParentFont = False
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'SF Pro Text'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 0
        TextHint = 'Nr.'
      end
      object DataR: TDateTimePicker
        Left = 187
        Top = 58
        Width = 121
        Height = 26
        Date = 44420.874391875000000000
        Time = 44420.874391875000000000
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Century'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object Pret: TLabeledEdit
        Left = 342
        Top = 58
        Width = 121
        Height = 26
        EditLabel.Width = 122
        EditLabel.Height = 16
        EditLabel.Caption = 'PRET EXAMINARE'
        EditLabel.Color = clBlue
        EditLabel.Font.Charset = ANSI_CHARSET
        EditLabel.Font.Color = clBlack
        EditLabel.Font.Height = -13
        EditLabel.Font.Name = 'Century'
        EditLabel.Font.Style = []
        EditLabel.ParentColor = False
        EditLabel.ParentFont = False
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'SF Pro Text'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 2
        TextHint = '0'
      end
      object DosDiv: TLabeledEdit
        Left = 342
        Top = 129
        Width = 121
        Height = 26
        EditLabel.Width = 142
        EditLabel.Height = 16
        EditLabel.Caption = 'NR DOSAR DIVIZARE '
        EditLabel.Color = clBlue
        EditLabel.Font.Charset = ANSI_CHARSET
        EditLabel.Font.Color = clBlack
        EditLabel.Font.Height = -13
        EditLabel.Font.Name = 'Century'
        EditLabel.Font.Style = []
        EditLabel.ParentColor = False
        EditLabel.ParentFont = False
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'SF Pro Text'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 5
        TextHint = 'Nr.'
      end
      object ExpertR: TDBLookupComboBox
        Left = 29
        Top = 129
        Width = 121
        Height = 26
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'SF Pro Text'
        Font.Style = []
        KeyField = 'EXPERT_ID'
        ListField = 'NPP'
        ListSource = DM.DSQExpertCombo
        ParentFont = False
        TabOrder = 3
      end
      object StagiarR: TDBLookupComboBox
        Left = 187
        Top = 129
        Width = 121
        Height = 26
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'SF Pro Text'
        Font.Style = []
        KeyField = 'EXPERT_ID'
        ListField = 'NPP'
        ListSource = DM.DSQStagiarCombo
        ParentFont = False
        TabOrder = 4
      end
    end
  end
end
