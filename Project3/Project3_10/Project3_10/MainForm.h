#pragma once

#include "VesselObject.h"
#include "Team.h"
#include "Command.h"
#include "Shell.h"
#include "Torpedo.h"
#include "GeographicSystem.h"
#include "HydrometeorologicSystem.h"
using namespace CommandAnalyze;

namespace Project310 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm 的摘要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnStart;
	protected:
	private: System::Windows::Forms::Button^  btnPause;
	private: System::Windows::Forms::Timer^  timerMain;
	private: System::Windows::Forms::GroupBox^  grpboxCommands;
	private: System::Windows::Forms::TextBox^  txtCommand_A;
	private: System::Windows::Forms::TextBox^  txtCommand_B;






	private: System::Windows::Forms::Label^  lblNowTime;
	private: System::Windows::Forms::GroupBox^  grpboxBattleLog;
	private: System::Windows::Forms::TextBox^  txtBattleLog;
	private: System::Windows::Forms::Panel^  pnlGamePage;
	private: System::Windows::Forms::PictureBox^  picBoard;
	private: System::Windows::Forms::Label^  lblCoordinateHint;
	private: System::Windows::Forms::Panel^  pnlMenuPage;
	private: System::Windows::Forms::Button^  btnStartGame;
	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::Button^  btnTyphoon;
	private: System::Windows::Forms::Button^  btnLightning;
	private: System::Windows::Forms::Button^  btnNewGeo;




	private: System::Windows::Forms::Button^  btnFog;

	private: System::Windows::Forms::GroupBox^  grpNewGeo;
	private: System::Windows::Forms::Button^  btnNewGeoConfirm;
	private: System::Windows::Forms::TrackBar^  tckGeoX;
	private: System::Windows::Forms::TrackBar^  tckGeoY;
	private: System::Windows::Forms::TrackBar^  tckGeoWidth;
	private: System::Windows::Forms::Label^  lblGeoHeight;
	private: System::Windows::Forms::Label^  lblGeoWidth;
	private: System::Windows::Forms::Label^  lblGeoY;
	private: System::Windows::Forms::TrackBar^  tckGeoHeight;
	private: System::Windows::Forms::Label^  lblGeoX;
	private: System::Windows::Forms::ComboBox^  cbbGeoType;
	private: System::Windows::Forms::Button^  btnNewGeoCancel;
	private: System::Windows::Forms::Label^  lblMsg4AddingNewGeo;
	private: System::Windows::Forms::Panel^  pnlSettingPage;
	private: System::Windows::Forms::Button^  btnBackInSetting;
	private: System::Windows::Forms::Button^  btnStartInSetting;
	private: System::Windows::Forms::GroupBox^  grpNewGeoInSetting;
	private: System::Windows::Forms::Button^  btnNewGeoCancelInSetting;

	private: System::Windows::Forms::ComboBox^  cbbNewGeoTypeInSetting;
	private: System::Windows::Forms::Button^  btnNewGeoConfirmInSetting;
	private: System::Windows::Forms::TrackBar^  tckGeoXInSetting;
	private: System::Windows::Forms::TrackBar^  tckGeoYInSetting;
	private: System::Windows::Forms::TrackBar^  tckGeoWidthInSetting;





	private: System::Windows::Forms::Label^  lblGeoHeightInSetting;

	private: System::Windows::Forms::Label^  lblGeoWidthInSetting;

	private: System::Windows::Forms::Label^  lblGeoYInSetting;
	private: System::Windows::Forms::TrackBar^  tckGeoHeightInSetting;


	private: System::Windows::Forms::Label^  lblGeoXInSetting;

	private: System::Windows::Forms::PictureBox^  picBoardInSetting;
	private: System::Windows::Forms::Label^  lblSettingPageTitle;
	private: System::Windows::Forms::GroupBox^  grpHydroSetting;
	private: System::Windows::Forms::CheckBox^  chckIsUseTyphoon;
	private: System::Windows::Forms::CheckBox^  chckIsUseFog;
	private: System::Windows::Forms::CheckBox^  chckIsUseLightning;
	private: System::Windows::Forms::CheckBox^  chckIsLogFog;
	private: System::Windows::Forms::CheckBox^  chckIsLogLightning;
	private: System::Windows::Forms::CheckBox^  chckIsLogTyphoon;
	private: System::Windows::Forms::Label^  lblMsg4AddingNewGeoInSetting;
private: System::Windows::Forms::Button^  btnBackToMenu;
private: System::Windows::Forms::Label^  lblBoardHint;
private: System::Windows::Forms::Button^  btnDanmakuModeStartGame;
private: System::Windows::Forms::Label^  lblShowDanmakuHitNum;
private: System::Windows::Forms::Button^  btnNextSecond;






















	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


	#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnPause = (gcnew System::Windows::Forms::Button());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->grpboxCommands = (gcnew System::Windows::Forms::GroupBox());
			this->txtCommand_B = (gcnew System::Windows::Forms::TextBox());
			this->txtCommand_A = (gcnew System::Windows::Forms::TextBox());
			this->lblNowTime = (gcnew System::Windows::Forms::Label());
			this->grpboxBattleLog = (gcnew System::Windows::Forms::GroupBox());
			this->txtBattleLog = (gcnew System::Windows::Forms::TextBox());
			this->lblMsg4AddingNewGeo = (gcnew System::Windows::Forms::Label());
			this->pnlGamePage = (gcnew System::Windows::Forms::Panel());
			this->btnNextSecond = (gcnew System::Windows::Forms::Button());
			this->lblShowDanmakuHitNum = (gcnew System::Windows::Forms::Label());
			this->lblBoardHint = (gcnew System::Windows::Forms::Label());
			this->btnBackToMenu = (gcnew System::Windows::Forms::Button());
			this->grpNewGeo = (gcnew System::Windows::Forms::GroupBox());
			this->btnNewGeoCancel = (gcnew System::Windows::Forms::Button());
			this->cbbGeoType = (gcnew System::Windows::Forms::ComboBox());
			this->btnNewGeoConfirm = (gcnew System::Windows::Forms::Button());
			this->tckGeoX = (gcnew System::Windows::Forms::TrackBar());
			this->tckGeoY = (gcnew System::Windows::Forms::TrackBar());
			this->tckGeoWidth = (gcnew System::Windows::Forms::TrackBar());
			this->lblGeoHeight = (gcnew System::Windows::Forms::Label());
			this->lblGeoWidth = (gcnew System::Windows::Forms::Label());
			this->lblGeoY = (gcnew System::Windows::Forms::Label());
			this->tckGeoHeight = (gcnew System::Windows::Forms::TrackBar());
			this->lblGeoX = (gcnew System::Windows::Forms::Label());
			this->btnNewGeo = (gcnew System::Windows::Forms::Button());
			this->btnFog = (gcnew System::Windows::Forms::Button());
			this->btnLightning = (gcnew System::Windows::Forms::Button());
			this->btnTyphoon = (gcnew System::Windows::Forms::Button());
			this->lblCoordinateHint = (gcnew System::Windows::Forms::Label());
			this->picBoard = (gcnew System::Windows::Forms::PictureBox());
			this->pnlMenuPage = (gcnew System::Windows::Forms::Panel());
			this->btnDanmakuModeStartGame = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnStartGame = (gcnew System::Windows::Forms::Button());
			this->pnlSettingPage = (gcnew System::Windows::Forms::Panel());
			this->lblMsg4AddingNewGeoInSetting = (gcnew System::Windows::Forms::Label());
			this->grpHydroSetting = (gcnew System::Windows::Forms::GroupBox());
			this->chckIsLogFog = (gcnew System::Windows::Forms::CheckBox());
			this->chckIsLogLightning = (gcnew System::Windows::Forms::CheckBox());
			this->chckIsLogTyphoon = (gcnew System::Windows::Forms::CheckBox());
			this->chckIsUseFog = (gcnew System::Windows::Forms::CheckBox());
			this->chckIsUseLightning = (gcnew System::Windows::Forms::CheckBox());
			this->chckIsUseTyphoon = (gcnew System::Windows::Forms::CheckBox());
			this->lblSettingPageTitle = (gcnew System::Windows::Forms::Label());
			this->grpNewGeoInSetting = (gcnew System::Windows::Forms::GroupBox());
			this->btnNewGeoCancelInSetting = (gcnew System::Windows::Forms::Button());
			this->cbbNewGeoTypeInSetting = (gcnew System::Windows::Forms::ComboBox());
			this->btnNewGeoConfirmInSetting = (gcnew System::Windows::Forms::Button());
			this->tckGeoXInSetting = (gcnew System::Windows::Forms::TrackBar());
			this->tckGeoYInSetting = (gcnew System::Windows::Forms::TrackBar());
			this->tckGeoWidthInSetting = (gcnew System::Windows::Forms::TrackBar());
			this->lblGeoHeightInSetting = (gcnew System::Windows::Forms::Label());
			this->lblGeoWidthInSetting = (gcnew System::Windows::Forms::Label());
			this->lblGeoYInSetting = (gcnew System::Windows::Forms::Label());
			this->tckGeoHeightInSetting = (gcnew System::Windows::Forms::TrackBar());
			this->lblGeoXInSetting = (gcnew System::Windows::Forms::Label());
			this->picBoardInSetting = (gcnew System::Windows::Forms::PictureBox());
			this->btnBackInSetting = (gcnew System::Windows::Forms::Button());
			this->btnStartInSetting = (gcnew System::Windows::Forms::Button());
			this->grpboxCommands->SuspendLayout();
			this->grpboxBattleLog->SuspendLayout();
			this->pnlGamePage->SuspendLayout();
			this->grpNewGeo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoHeight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoard))->BeginInit();
			this->pnlMenuPage->SuspendLayout();
			this->pnlSettingPage->SuspendLayout();
			this->grpHydroSetting->SuspendLayout();
			this->grpNewGeoInSetting->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoXInSetting))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoYInSetting))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoWidthInSetting))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoHeightInSetting))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoardInSetting))->BeginInit();
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStart->Location = System::Drawing::Point(563, 12);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(628, 55);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::btnStart_Click);
			// 
			// btnPause
			// 
			this->btnPause->Enabled = false;
			this->btnPause->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPause->Location = System::Drawing::Point(563, 80);
			this->btnPause->Name = L"btnPause";
			this->btnPause->Size = System::Drawing::Size(628, 55);
			this->btnPause->TabIndex = 1;
			this->btnPause->Text = L"Pause";
			this->btnPause->UseVisualStyleBackColor = true;
			this->btnPause->Click += gcnew System::EventHandler(this, &MainForm::btnPause_Click);
			// 
			// timerMain
			// 
			this->timerMain->Interval = 66;
			this->timerMain->Tick += gcnew System::EventHandler(this, &MainForm::timerMain_Tick);
			// 
			// grpboxCommands
			// 
			this->grpboxCommands->Controls->Add(this->txtCommand_B);
			this->grpboxCommands->Controls->Add(this->txtCommand_A);
			this->grpboxCommands->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpboxCommands->Location = System::Drawing::Point(563, 142);
			this->grpboxCommands->Name = L"grpboxCommands";
			this->grpboxCommands->Size = System::Drawing::Size(817, 425);
			this->grpboxCommands->TabIndex = 2;
			this->grpboxCommands->TabStop = false;
			this->grpboxCommands->Text = L"Commands";
			// 
			// txtCommand_B
			// 
			this->txtCommand_B->ForeColor = System::Drawing::Color::Blue;
			this->txtCommand_B->Location = System::Drawing::Point(415, 24);
			this->txtCommand_B->Multiline = true;
			this->txtCommand_B->Name = L"txtCommand_B";
			this->txtCommand_B->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtCommand_B->Size = System::Drawing::Size(385, 384);
			this->txtCommand_B->TabIndex = 1;
			// 
			// txtCommand_A
			// 
			this->txtCommand_A->ForeColor = System::Drawing::Color::Red;
			this->txtCommand_A->Location = System::Drawing::Point(15, 24);
			this->txtCommand_A->Multiline = true;
			this->txtCommand_A->Name = L"txtCommand_A";
			this->txtCommand_A->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtCommand_A->Size = System::Drawing::Size(385, 384);
			this->txtCommand_A->TabIndex = 0;
			// 
			// lblNowTime
			// 
			this->lblNowTime->AutoSize = true;
			this->lblNowTime->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNowTime->Location = System::Drawing::Point(5, 524);
			this->lblNowTime->Name = L"lblNowTime";
			this->lblNowTime->Size = System::Drawing::Size(107, 38);
			this->lblNowTime->TabIndex = 3;
			this->lblNowTime->Text = L"MM:SS";
			// 
			// grpboxBattleLog
			// 
			this->grpboxBattleLog->Controls->Add(this->txtBattleLog);
			this->grpboxBattleLog->Controls->Add(this->lblMsg4AddingNewGeo);
			this->grpboxBattleLog->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpboxBattleLog->Location = System::Drawing::Point(12, 573);
			this->grpboxBattleLog->Name = L"grpboxBattleLog";
			this->grpboxBattleLog->Size = System::Drawing::Size(1368, 257);
			this->grpboxBattleLog->TabIndex = 4;
			this->grpboxBattleLog->TabStop = false;
			this->grpboxBattleLog->Text = L"Battle Log";
			// 
			// txtBattleLog
			// 
			this->txtBattleLog->Location = System::Drawing::Point(15, 24);
			this->txtBattleLog->Multiline = true;
			this->txtBattleLog->Name = L"txtBattleLog";
			this->txtBattleLog->ReadOnly = true;
			this->txtBattleLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtBattleLog->Size = System::Drawing::Size(1336, 187);
			this->txtBattleLog->TabIndex = 0;
			// 
			// lblMsg4AddingNewGeo
			// 
			this->lblMsg4AddingNewGeo->AutoSize = true;
			this->lblMsg4AddingNewGeo->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblMsg4AddingNewGeo->Location = System::Drawing::Point(11, 217);
			this->lblMsg4AddingNewGeo->Name = L"lblMsg4AddingNewGeo";
			this->lblMsg4AddingNewGeo->Size = System::Drawing::Size(0, 23);
			this->lblMsg4AddingNewGeo->TabIndex = 19;
			// 
			// pnlGamePage
			// 
			this->pnlGamePage->Controls->Add(this->btnNextSecond);
			this->pnlGamePage->Controls->Add(this->lblShowDanmakuHitNum);
			this->pnlGamePage->Controls->Add(this->lblBoardHint);
			this->pnlGamePage->Controls->Add(this->btnBackToMenu);
			this->pnlGamePage->Controls->Add(this->grpNewGeo);
			this->pnlGamePage->Controls->Add(this->btnNewGeo);
			this->pnlGamePage->Controls->Add(this->btnFog);
			this->pnlGamePage->Controls->Add(this->btnLightning);
			this->pnlGamePage->Controls->Add(this->btnTyphoon);
			this->pnlGamePage->Controls->Add(this->lblCoordinateHint);
			this->pnlGamePage->Controls->Add(this->lblNowTime);
			this->pnlGamePage->Controls->Add(this->grpboxBattleLog);
			this->pnlGamePage->Controls->Add(this->btnPause);
			this->pnlGamePage->Controls->Add(this->btnStart);
			this->pnlGamePage->Controls->Add(this->grpboxCommands);
			this->pnlGamePage->Controls->Add(this->picBoard);
			this->pnlGamePage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlGamePage->Location = System::Drawing::Point(0, 0);
			this->pnlGamePage->Name = L"pnlGamePage";
			this->pnlGamePage->Size = System::Drawing::Size(1641, 879);
			this->pnlGamePage->TabIndex = 5;
			this->pnlGamePage->Visible = false;
			// 
			// btnNextSecond
			// 
			this->btnNextSecond->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNextSecond->Location = System::Drawing::Point(1203, 12);
			this->btnNextSecond->Name = L"btnNextSecond";
			this->btnNextSecond->Size = System::Drawing::Size(177, 123);
			this->btnNextSecond->TabIndex = 22;
			this->btnNextSecond->Text = L"Next Second";
			this->btnNextSecond->UseVisualStyleBackColor = true;
			this->btnNextSecond->Click += gcnew System::EventHandler(this, &MainForm::btnNextSecond_Click);
			// 
			// lblShowDanmakuHitNum
			// 
			this->lblShowDanmakuHitNum->AutoSize = true;
			this->lblShowDanmakuHitNum->Font = (gcnew System::Drawing::Font(L"Consolas", 24));
			this->lblShowDanmakuHitNum->Location = System::Drawing::Point(267, 194);
			this->lblShowDanmakuHitNum->Name = L"lblShowDanmakuHitNum";
			this->lblShowDanmakuHitNum->Size = System::Drawing::Size(284, 47);
			this->lblShowDanmakuHitNum->TabIndex = 21;
			this->lblShowDanmakuHitNum->Text = L"Hit num: 000";
			// 
			// lblBoardHint
			// 
			this->lblBoardHint->AutoSize = true;
			this->lblBoardHint->BackColor = System::Drawing::Color::Transparent;
			this->lblBoardHint->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBoardHint->Location = System::Drawing::Point(145, 524);
			this->lblBoardHint->Name = L"lblBoardHint";
			this->lblBoardHint->Size = System::Drawing::Size(0, 38);
			this->lblBoardHint->TabIndex = 20;
			this->lblBoardHint->Visible = false;
			// 
			// btnBackToMenu
			// 
			this->btnBackToMenu->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBackToMenu->Location = System::Drawing::Point(1393, 775);
			this->btnBackToMenu->Name = L"btnBackToMenu";
			this->btnBackToMenu->Size = System::Drawing::Size(236, 55);
			this->btnBackToMenu->TabIndex = 19;
			this->btnBackToMenu->Text = L"Exit";
			this->btnBackToMenu->UseVisualStyleBackColor = true;
			this->btnBackToMenu->Click += gcnew System::EventHandler(this, &MainForm::btnBackToMenu_Click);
			// 
			// grpNewGeo
			// 
			this->grpNewGeo->Controls->Add(this->btnNewGeoCancel);
			this->grpNewGeo->Controls->Add(this->cbbGeoType);
			this->grpNewGeo->Controls->Add(this->btnNewGeoConfirm);
			this->grpNewGeo->Controls->Add(this->tckGeoX);
			this->grpNewGeo->Controls->Add(this->tckGeoY);
			this->grpNewGeo->Controls->Add(this->tckGeoWidth);
			this->grpNewGeo->Controls->Add(this->lblGeoHeight);
			this->grpNewGeo->Controls->Add(this->lblGeoWidth);
			this->grpNewGeo->Controls->Add(this->lblGeoY);
			this->grpNewGeo->Controls->Add(this->tckGeoHeight);
			this->grpNewGeo->Controls->Add(this->lblGeoX);
			this->grpNewGeo->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpNewGeo->Location = System::Drawing::Point(1387, 276);
			this->grpNewGeo->Name = L"grpNewGeo";
			this->grpNewGeo->Size = System::Drawing::Size(248, 486);
			this->grpNewGeo->TabIndex = 15;
			this->grpNewGeo->TabStop = false;
			this->grpNewGeo->Visible = false;
			// 
			// btnNewGeoCancel
			// 
			this->btnNewGeoCancel->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNewGeoCancel->Location = System::Drawing::Point(6, 418);
			this->btnNewGeoCancel->Name = L"btnNewGeoCancel";
			this->btnNewGeoCancel->Size = System::Drawing::Size(236, 55);
			this->btnNewGeoCancel->TabIndex = 18;
			this->btnNewGeoCancel->Text = L"Cancel";
			this->btnNewGeoCancel->UseVisualStyleBackColor = true;
			this->btnNewGeoCancel->Click += gcnew System::EventHandler(this, &MainForm::btnNewGeoCancel_Click);
			// 
			// cbbGeoType
			// 
			this->cbbGeoType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbbGeoType->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbbGeoType->FormattingEnabled = true;
			this->cbbGeoType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Reef", L"Flatland", L"Mountain" });
			this->cbbGeoType->Location = System::Drawing::Point(6, 24);
			this->cbbGeoType->Name = L"cbbGeoType";
			this->cbbGeoType->Size = System::Drawing::Size(234, 31);
			this->cbbGeoType->TabIndex = 16;
			this->cbbGeoType->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cbbGeoType_SelectedIndexChanged);
			// 
			// btnNewGeoConfirm
			// 
			this->btnNewGeoConfirm->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNewGeoConfirm->Location = System::Drawing::Point(6, 351);
			this->btnNewGeoConfirm->Name = L"btnNewGeoConfirm";
			this->btnNewGeoConfirm->Size = System::Drawing::Size(236, 55);
			this->btnNewGeoConfirm->TabIndex = 15;
			this->btnNewGeoConfirm->Text = L"Confirm";
			this->btnNewGeoConfirm->UseVisualStyleBackColor = true;
			this->btnNewGeoConfirm->Click += gcnew System::EventHandler(this, &MainForm::btnNewGeoConfirm_Click);
			// 
			// tckGeoX
			// 
			this->tckGeoX->Location = System::Drawing::Point(84, 90);
			this->tckGeoX->Maximum = 100;
			this->tckGeoX->Name = L"tckGeoX";
			this->tckGeoX->Size = System::Drawing::Size(164, 56);
			this->tckGeoX->TabIndex = 9;
			this->tckGeoX->ValueChanged += gcnew System::EventHandler(this, &MainForm::tckGeoX_ValueChanged);
			// 
			// tckGeoY
			// 
			this->tckGeoY->Location = System::Drawing::Point(84, 157);
			this->tckGeoY->Maximum = 100;
			this->tckGeoY->Name = L"tckGeoY";
			this->tckGeoY->Size = System::Drawing::Size(164, 56);
			this->tckGeoY->TabIndex = 8;
			this->tckGeoY->ValueChanged += gcnew System::EventHandler(this, &MainForm::tckGeoY_ValueChanged);
			// 
			// tckGeoWidth
			// 
			this->tckGeoWidth->Location = System::Drawing::Point(84, 224);
			this->tckGeoWidth->Maximum = 100;
			this->tckGeoWidth->Name = L"tckGeoWidth";
			this->tckGeoWidth->Size = System::Drawing::Size(164, 56);
			this->tckGeoWidth->TabIndex = 7;
			this->tckGeoWidth->ValueChanged += gcnew System::EventHandler(this, &MainForm::tckGeoWidth_ValueChanged);
			// 
			// lblGeoHeight
			// 
			this->lblGeoHeight->AutoSize = true;
			this->lblGeoHeight->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblGeoHeight->Location = System::Drawing::Point(6, 288);
			this->lblGeoHeight->Name = L"lblGeoHeight";
			this->lblGeoHeight->Size = System::Drawing::Size(76, 23);
			this->lblGeoHeight->TabIndex = 6;
			this->lblGeoHeight->Text = L"Height";
			// 
			// lblGeoWidth
			// 
			this->lblGeoWidth->AutoSize = true;
			this->lblGeoWidth->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblGeoWidth->Location = System::Drawing::Point(6, 224);
			this->lblGeoWidth->Name = L"lblGeoWidth";
			this->lblGeoWidth->Size = System::Drawing::Size(65, 23);
			this->lblGeoWidth->TabIndex = 4;
			this->lblGeoWidth->Text = L"Width";
			// 
			// lblGeoY
			// 
			this->lblGeoY->AutoSize = true;
			this->lblGeoY->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblGeoY->Location = System::Drawing::Point(6, 157);
			this->lblGeoY->Name = L"lblGeoY";
			this->lblGeoY->Size = System::Drawing::Size(21, 23);
			this->lblGeoY->TabIndex = 2;
			this->lblGeoY->Text = L"Y";
			// 
			// tckGeoHeight
			// 
			this->tckGeoHeight->Location = System::Drawing::Point(84, 286);
			this->tckGeoHeight->Maximum = 100;
			this->tckGeoHeight->Name = L"tckGeoHeight";
			this->tckGeoHeight->Size = System::Drawing::Size(164, 56);
			this->tckGeoHeight->TabIndex = 1;
			this->tckGeoHeight->ValueChanged += gcnew System::EventHandler(this, &MainForm::tckGeoHeight_ValueChanged);
			// 
			// lblGeoX
			// 
			this->lblGeoX->AutoSize = true;
			this->lblGeoX->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblGeoX->Location = System::Drawing::Point(6, 90);
			this->lblGeoX->Name = L"lblGeoX";
			this->lblGeoX->Size = System::Drawing::Size(21, 23);
			this->lblGeoX->TabIndex = 0;
			this->lblGeoX->Text = L"X";
			// 
			// btnNewGeo
			// 
			this->btnNewGeo->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNewGeo->Location = System::Drawing::Point(1393, 215);
			this->btnNewGeo->Name = L"btnNewGeo";
			this->btnNewGeo->Size = System::Drawing::Size(236, 55);
			this->btnNewGeo->TabIndex = 11;
			this->btnNewGeo->Text = L"Geography";
			this->btnNewGeo->UseVisualStyleBackColor = true;
			this->btnNewGeo->Click += gcnew System::EventHandler(this, &MainForm::btnNewGeo_Click);
			// 
			// btnFog
			// 
			this->btnFog->Enabled = false;
			this->btnFog->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFog->Location = System::Drawing::Point(1393, 148);
			this->btnFog->Name = L"btnFog";
			this->btnFog->Size = System::Drawing::Size(236, 55);
			this->btnFog->TabIndex = 9;
			this->btnFog->Text = L"Fog";
			this->btnFog->UseVisualStyleBackColor = true;
			this->btnFog->Click += gcnew System::EventHandler(this, &MainForm::btnFog_Click);
			// 
			// btnLightning
			// 
			this->btnLightning->Enabled = false;
			this->btnLightning->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLightning->Location = System::Drawing::Point(1393, 80);
			this->btnLightning->Name = L"btnLightning";
			this->btnLightning->Size = System::Drawing::Size(236, 55);
			this->btnLightning->TabIndex = 7;
			this->btnLightning->Text = L"Lightning";
			this->btnLightning->UseVisualStyleBackColor = true;
			this->btnLightning->Click += gcnew System::EventHandler(this, &MainForm::btnLightning_Click);
			// 
			// btnTyphoon
			// 
			this->btnTyphoon->Enabled = false;
			this->btnTyphoon->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTyphoon->Location = System::Drawing::Point(1393, 12);
			this->btnTyphoon->Name = L"btnTyphoon";
			this->btnTyphoon->Size = System::Drawing::Size(236, 55);
			this->btnTyphoon->TabIndex = 4;
			this->btnTyphoon->Text = L"Typhoon";
			this->btnTyphoon->UseVisualStyleBackColor = true;
			this->btnTyphoon->Click += gcnew System::EventHandler(this, &MainForm::btnTyphoon_Click);
			// 
			// lblCoordinateHint
			// 
			this->lblCoordinateHint->AutoSize = true;
			this->lblCoordinateHint->BackColor = System::Drawing::Color::Transparent;
			this->lblCoordinateHint->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCoordinateHint->Location = System::Drawing::Point(417, 524);
			this->lblCoordinateHint->Name = L"lblCoordinateHint";
			this->lblCoordinateHint->Size = System::Drawing::Size(125, 38);
			this->lblCoordinateHint->TabIndex = 6;
			this->lblCoordinateHint->Text = L"XX, YY";
			this->lblCoordinateHint->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lblCoordinateHint->Visible = false;
			// 
			// picBoard
			// 
			this->picBoard->Location = System::Drawing::Point(0, 0);
			this->picBoard->Name = L"picBoard";
			this->picBoard->Size = System::Drawing::Size(563, 527);
			this->picBoard->TabIndex = 0;
			this->picBoard->TabStop = false;
			this->picBoard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::picBoard_Paint);
			this->picBoard->MouseEnter += gcnew System::EventHandler(this, &MainForm::picBoard_MouseEnter);
			this->picBoard->MouseLeave += gcnew System::EventHandler(this, &MainForm::picBoard_MouseLeave);
			this->picBoard->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::picBoard_MouseMove);
			// 
			// pnlMenuPage
			// 
			this->pnlMenuPage->Controls->Add(this->btnDanmakuModeStartGame);
			this->pnlMenuPage->Controls->Add(this->btnExit);
			this->pnlMenuPage->Controls->Add(this->btnStartGame);
			this->pnlMenuPage->Location = System::Drawing::Point(0, 0);
			this->pnlMenuPage->Name = L"pnlMenuPage";
			this->pnlMenuPage->Size = System::Drawing::Size(1641, 787);
			this->pnlMenuPage->TabIndex = 7;
			// 
			// btnDanmakuModeStartGame
			// 
			this->btnDanmakuModeStartGame->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDanmakuModeStartGame->Location = System::Drawing::Point(12, 257);
			this->btnDanmakuModeStartGame->Name = L"btnDanmakuModeStartGame";
			this->btnDanmakuModeStartGame->Size = System::Drawing::Size(1617, 55);
			this->btnDanmakuModeStartGame->TabIndex = 5;
			this->btnDanmakuModeStartGame->Text = L"Danmaku Mode";
			this->btnDanmakuModeStartGame->UseVisualStyleBackColor = true;
			this->btnDanmakuModeStartGame->Click += gcnew System::EventHandler(this, &MainForm::btnDanmakuModeStartGame_Click);
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->Location = System::Drawing::Point(12, 328);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(1617, 55);
			this->btnExit->TabIndex = 3;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_Click);
			// 
			// btnStartGame
			// 
			this->btnStartGame->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStartGame->Location = System::Drawing::Point(12, 186);
			this->btnStartGame->Name = L"btnStartGame";
			this->btnStartGame->Size = System::Drawing::Size(1617, 55);
			this->btnStartGame->TabIndex = 2;
			this->btnStartGame->Text = L"Tradition Mode";
			this->btnStartGame->UseVisualStyleBackColor = true;
			this->btnStartGame->Click += gcnew System::EventHandler(this, &MainForm::btnStartGame_Click);
			// 
			// pnlSettingPage
			// 
			this->pnlSettingPage->Controls->Add(this->lblMsg4AddingNewGeoInSetting);
			this->pnlSettingPage->Controls->Add(this->grpHydroSetting);
			this->pnlSettingPage->Controls->Add(this->lblSettingPageTitle);
			this->pnlSettingPage->Controls->Add(this->grpNewGeoInSetting);
			this->pnlSettingPage->Controls->Add(this->picBoardInSetting);
			this->pnlSettingPage->Controls->Add(this->btnBackInSetting);
			this->pnlSettingPage->Controls->Add(this->btnStartInSetting);
			this->pnlSettingPage->Location = System::Drawing::Point(0, 0);
			this->pnlSettingPage->Name = L"pnlSettingPage";
			this->pnlSettingPage->Size = System::Drawing::Size(1641, 879);
			this->pnlSettingPage->TabIndex = 8;
			// 
			// lblMsg4AddingNewGeoInSetting
			// 
			this->lblMsg4AddingNewGeoInSetting->AutoSize = true;
			this->lblMsg4AddingNewGeoInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblMsg4AddingNewGeoInSetting->Location = System::Drawing::Point(12, 625);
			this->lblMsg4AddingNewGeoInSetting->Name = L"lblMsg4AddingNewGeoInSetting";
			this->lblMsg4AddingNewGeoInSetting->Size = System::Drawing::Size(0, 23);
			this->lblMsg4AddingNewGeoInSetting->TabIndex = 20;
			// 
			// grpHydroSetting
			// 
			this->grpHydroSetting->Controls->Add(this->chckIsLogFog);
			this->grpHydroSetting->Controls->Add(this->chckIsLogLightning);
			this->grpHydroSetting->Controls->Add(this->chckIsLogTyphoon);
			this->grpHydroSetting->Controls->Add(this->chckIsUseFog);
			this->grpHydroSetting->Controls->Add(this->chckIsUseLightning);
			this->grpHydroSetting->Controls->Add(this->chckIsUseTyphoon);
			this->grpHydroSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpHydroSetting->Location = System::Drawing::Point(12, 659);
			this->grpHydroSetting->Name = L"grpHydroSetting";
			this->grpHydroSetting->Size = System::Drawing::Size(1615, 138);
			this->grpHydroSetting->TabIndex = 18;
			this->grpHydroSetting->TabStop = false;
			this->grpHydroSetting->Text = L"Hydrometeorology System";
			// 
			// chckIsLogFog
			// 
			this->chckIsLogFog->AutoSize = true;
			this->chckIsLogFog->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->chckIsLogFog->Location = System::Drawing::Point(321, 105);
			this->chckIsLogFog->Name = L"chckIsLogFog";
			this->chckIsLogFog->Size = System::Drawing::Size(406, 27);
			this->chckIsLogFog->TabIndex = 5;
			this->chckIsLogFog->Text = L"Write a Log when a new fog genesis";
			this->chckIsLogFog->UseVisualStyleBackColor = true;
			this->chckIsLogFog->Visible = false;
			// 
			// chckIsLogLightning
			// 
			this->chckIsLogLightning->AutoSize = true;
			this->chckIsLogLightning->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->chckIsLogLightning->Location = System::Drawing::Point(321, 63);
			this->chckIsLogLightning->Name = L"chckIsLogLightning";
			this->chckIsLogLightning->Size = System::Drawing::Size(472, 27);
			this->chckIsLogLightning->TabIndex = 4;
			this->chckIsLogLightning->Text = L"Write a Log when a new lightning genesis";
			this->chckIsLogLightning->UseVisualStyleBackColor = true;
			this->chckIsLogLightning->Visible = false;
			// 
			// chckIsLogTyphoon
			// 
			this->chckIsLogTyphoon->AutoSize = true;
			this->chckIsLogTyphoon->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->chckIsLogTyphoon->Location = System::Drawing::Point(321, 24);
			this->chckIsLogTyphoon->Name = L"chckIsLogTyphoon";
			this->chckIsLogTyphoon->Size = System::Drawing::Size(450, 27);
			this->chckIsLogTyphoon->TabIndex = 3;
			this->chckIsLogTyphoon->Text = L"Write a Log when a new typhoon genesis";
			this->chckIsLogTyphoon->UseVisualStyleBackColor = true;
			this->chckIsLogTyphoon->Visible = false;
			// 
			// chckIsUseFog
			// 
			this->chckIsUseFog->AutoSize = true;
			this->chckIsUseFog->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->chckIsUseFog->Location = System::Drawing::Point(15, 105);
			this->chckIsUseFog->Name = L"chckIsUseFog";
			this->chckIsUseFog->Size = System::Drawing::Size(186, 27);
			this->chckIsUseFog->TabIndex = 2;
			this->chckIsUseFog->Text = L"Use Fog System";
			this->chckIsUseFog->UseVisualStyleBackColor = true;
			this->chckIsUseFog->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chckIsUseFog_CheckedChanged);
			// 
			// chckIsUseLightning
			// 
			this->chckIsUseLightning->AutoSize = true;
			this->chckIsUseLightning->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->chckIsUseLightning->Location = System::Drawing::Point(15, 63);
			this->chckIsUseLightning->Name = L"chckIsUseLightning";
			this->chckIsUseLightning->Size = System::Drawing::Size(252, 27);
			this->chckIsUseLightning->TabIndex = 1;
			this->chckIsUseLightning->Text = L"Use Lightning System";
			this->chckIsUseLightning->UseVisualStyleBackColor = true;
			this->chckIsUseLightning->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chckIsUseLightning_CheckedChanged);
			// 
			// chckIsUseTyphoon
			// 
			this->chckIsUseTyphoon->AutoSize = true;
			this->chckIsUseTyphoon->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->chckIsUseTyphoon->Location = System::Drawing::Point(15, 24);
			this->chckIsUseTyphoon->Name = L"chckIsUseTyphoon";
			this->chckIsUseTyphoon->Size = System::Drawing::Size(230, 27);
			this->chckIsUseTyphoon->TabIndex = 0;
			this->chckIsUseTyphoon->Text = L"Use Typhoon System";
			this->chckIsUseTyphoon->UseVisualStyleBackColor = true;
			this->chckIsUseTyphoon->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chckIsUseTyphoon_CheckedChanged);
			// 
			// lblSettingPageTitle
			// 
			this->lblSettingPageTitle->AutoSize = true;
			this->lblSettingPageTitle->Font = (gcnew System::Drawing::Font(L"Consolas", 25));
			this->lblSettingPageTitle->Location = System::Drawing::Point(18, 17);
			this->lblSettingPageTitle->Name = L"lblSettingPageTitle";
			this->lblSettingPageTitle->Size = System::Drawing::Size(1218, 50);
			this->lblSettingPageTitle->TabIndex = 17;
			this->lblSettingPageTitle->Text = L"Geography System and Hydrometeorology System Setting";
			// 
			// grpNewGeoInSetting
			// 
			this->grpNewGeoInSetting->Controls->Add(this->btnNewGeoCancelInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->cbbNewGeoTypeInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->btnNewGeoConfirmInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->tckGeoXInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->tckGeoYInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->tckGeoWidthInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->lblGeoHeightInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->lblGeoWidthInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->lblGeoYInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->tckGeoHeightInSetting);
			this->grpNewGeoInSetting->Controls->Add(this->lblGeoXInSetting);
			this->grpNewGeoInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpNewGeoInSetting->Location = System::Drawing::Point(590, 103);
			this->grpNewGeoInSetting->Name = L"grpNewGeoInSetting";
			this->grpNewGeoInSetting->Size = System::Drawing::Size(1039, 515);
			this->grpNewGeoInSetting->TabIndex = 16;
			this->grpNewGeoInSetting->TabStop = false;
			this->grpNewGeoInSetting->Text = L"Geography System";
			// 
			// btnNewGeoCancelInSetting
			// 
			this->btnNewGeoCancelInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNewGeoCancelInSetting->Location = System::Drawing::Point(6, 427);
			this->btnNewGeoCancelInSetting->Name = L"btnNewGeoCancelInSetting";
			this->btnNewGeoCancelInSetting->Size = System::Drawing::Size(1013, 55);
			this->btnNewGeoCancelInSetting->TabIndex = 18;
			this->btnNewGeoCancelInSetting->Text = L"Reset";
			this->btnNewGeoCancelInSetting->UseVisualStyleBackColor = true;
			this->btnNewGeoCancelInSetting->Click += gcnew System::EventHandler(this, &MainForm::btnNewGeoCancelInSetting_Click);
			// 
			// cbbNewGeoTypeInSetting
			// 
			this->cbbNewGeoTypeInSetting->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbbNewGeoTypeInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbbNewGeoTypeInSetting->FormattingEnabled = true;
			this->cbbNewGeoTypeInSetting->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Reef", L"Flatland", L"Mountain" });
			this->cbbNewGeoTypeInSetting->Location = System::Drawing::Point(6, 24);
			this->cbbNewGeoTypeInSetting->Name = L"cbbNewGeoTypeInSetting";
			this->cbbNewGeoTypeInSetting->Size = System::Drawing::Size(1013, 31);
			this->cbbNewGeoTypeInSetting->TabIndex = 16;
			this->cbbNewGeoTypeInSetting->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cbbNewGeoTypeInSetting_SelectedIndexChanged);
			// 
			// btnNewGeoConfirmInSetting
			// 
			this->btnNewGeoConfirmInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNewGeoConfirmInSetting->Location = System::Drawing::Point(6, 360);
			this->btnNewGeoConfirmInSetting->Name = L"btnNewGeoConfirmInSetting";
			this->btnNewGeoConfirmInSetting->Size = System::Drawing::Size(1013, 55);
			this->btnNewGeoConfirmInSetting->TabIndex = 15;
			this->btnNewGeoConfirmInSetting->Text = L"Confirm";
			this->btnNewGeoConfirmInSetting->UseVisualStyleBackColor = true;
			this->btnNewGeoConfirmInSetting->Click += gcnew System::EventHandler(this, &MainForm::btnNewGeoConfirmInSetting_Click);
			// 
			// tckGeoXInSetting
			// 
			this->tckGeoXInSetting->Location = System::Drawing::Point(84, 90);
			this->tckGeoXInSetting->Maximum = 100;
			this->tckGeoXInSetting->Name = L"tckGeoXInSetting";
			this->tckGeoXInSetting->Size = System::Drawing::Size(949, 56);
			this->tckGeoXInSetting->TabIndex = 9;
			this->tckGeoXInSetting->ValueChanged += gcnew System::EventHandler(this, &MainForm::tckGeoXInSetting_ValueChanged);
			// 
			// tckGeoYInSetting
			// 
			this->tckGeoYInSetting->Location = System::Drawing::Point(84, 157);
			this->tckGeoYInSetting->Maximum = 100;
			this->tckGeoYInSetting->Name = L"tckGeoYInSetting";
			this->tckGeoYInSetting->Size = System::Drawing::Size(949, 56);
			this->tckGeoYInSetting->TabIndex = 8;
			this->tckGeoYInSetting->ValueChanged += gcnew System::EventHandler(this, &MainForm::tckGeoYInSetting_ValueChanged);
			// 
			// tckGeoWidthInSetting
			// 
			this->tckGeoWidthInSetting->Location = System::Drawing::Point(84, 224);
			this->tckGeoWidthInSetting->Maximum = 100;
			this->tckGeoWidthInSetting->Name = L"tckGeoWidthInSetting";
			this->tckGeoWidthInSetting->Size = System::Drawing::Size(949, 56);
			this->tckGeoWidthInSetting->TabIndex = 7;
			this->tckGeoWidthInSetting->ValueChanged += gcnew System::EventHandler(this, &MainForm::tckGeoWidthInSetting_ValueChanged);
			// 
			// lblGeoHeightInSetting
			// 
			this->lblGeoHeightInSetting->AutoSize = true;
			this->lblGeoHeightInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblGeoHeightInSetting->Location = System::Drawing::Point(6, 288);
			this->lblGeoHeightInSetting->Name = L"lblGeoHeightInSetting";
			this->lblGeoHeightInSetting->Size = System::Drawing::Size(76, 23);
			this->lblGeoHeightInSetting->TabIndex = 6;
			this->lblGeoHeightInSetting->Text = L"Height";
			// 
			// lblGeoWidthInSetting
			// 
			this->lblGeoWidthInSetting->AutoSize = true;
			this->lblGeoWidthInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblGeoWidthInSetting->Location = System::Drawing::Point(6, 224);
			this->lblGeoWidthInSetting->Name = L"lblGeoWidthInSetting";
			this->lblGeoWidthInSetting->Size = System::Drawing::Size(65, 23);
			this->lblGeoWidthInSetting->TabIndex = 4;
			this->lblGeoWidthInSetting->Text = L"Width";
			// 
			// lblGeoYInSetting
			// 
			this->lblGeoYInSetting->AutoSize = true;
			this->lblGeoYInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblGeoYInSetting->Location = System::Drawing::Point(6, 157);
			this->lblGeoYInSetting->Name = L"lblGeoYInSetting";
			this->lblGeoYInSetting->Size = System::Drawing::Size(21, 23);
			this->lblGeoYInSetting->TabIndex = 2;
			this->lblGeoYInSetting->Text = L"Y";
			// 
			// tckGeoHeightInSetting
			// 
			this->tckGeoHeightInSetting->Location = System::Drawing::Point(84, 286);
			this->tckGeoHeightInSetting->Maximum = 100;
			this->tckGeoHeightInSetting->Name = L"tckGeoHeightInSetting";
			this->tckGeoHeightInSetting->Size = System::Drawing::Size(949, 56);
			this->tckGeoHeightInSetting->TabIndex = 1;
			this->tckGeoHeightInSetting->ValueChanged += gcnew System::EventHandler(this, &MainForm::tckGeoHeightInSetting_ValueChanged);
			// 
			// lblGeoXInSetting
			// 
			this->lblGeoXInSetting->AutoSize = true;
			this->lblGeoXInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->lblGeoXInSetting->Location = System::Drawing::Point(6, 90);
			this->lblGeoXInSetting->Name = L"lblGeoXInSetting";
			this->lblGeoXInSetting->Size = System::Drawing::Size(21, 23);
			this->lblGeoXInSetting->TabIndex = 0;
			this->lblGeoXInSetting->Text = L"X";
			// 
			// picBoardInSetting
			// 
			this->picBoardInSetting->Location = System::Drawing::Point(12, 103);
			this->picBoardInSetting->Name = L"picBoardInSetting";
			this->picBoardInSetting->Size = System::Drawing::Size(563, 527);
			this->picBoardInSetting->TabIndex = 4;
			this->picBoardInSetting->TabStop = false;
			this->picBoardInSetting->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::picBoardInSetting_Paint);
			// 
			// btnBackInSetting
			// 
			this->btnBackInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBackInSetting->Location = System::Drawing::Point(12, 812);
			this->btnBackInSetting->Name = L"btnBackInSetting";
			this->btnBackInSetting->Size = System::Drawing::Size(802, 55);
			this->btnBackInSetting->TabIndex = 3;
			this->btnBackInSetting->Text = L"Back";
			this->btnBackInSetting->UseVisualStyleBackColor = true;
			this->btnBackInSetting->Click += gcnew System::EventHandler(this, &MainForm::btnBackInSetting_Click);
			// 
			// btnStartInSetting
			// 
			this->btnStartInSetting->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStartInSetting->Location = System::Drawing::Point(825, 812);
			this->btnStartInSetting->Name = L"btnStartInSetting";
			this->btnStartInSetting->Size = System::Drawing::Size(802, 55);
			this->btnStartInSetting->TabIndex = 2;
			this->btnStartInSetting->Text = L"Start";
			this->btnStartInSetting->UseVisualStyleBackColor = true;
			this->btnStartInSetting->Click += gcnew System::EventHandler(this, &MainForm::btnStartInSetting_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1641, 879);
			this->Controls->Add(this->pnlSettingPage);
			this->Controls->Add(this->pnlMenuPage);
			this->Controls->Add(this->pnlGamePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"Za Warudo";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->grpboxCommands->ResumeLayout(false);
			this->grpboxCommands->PerformLayout();
			this->grpboxBattleLog->ResumeLayout(false);
			this->grpboxBattleLog->PerformLayout();
			this->pnlGamePage->ResumeLayout(false);
			this->pnlGamePage->PerformLayout();
			this->grpNewGeo->ResumeLayout(false);
			this->grpNewGeo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoHeight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoard))->EndInit();
			this->pnlMenuPage->ResumeLayout(false);
			this->pnlSettingPage->ResumeLayout(false);
			this->pnlSettingPage->PerformLayout();
			this->grpHydroSetting->ResumeLayout(false);
			this->grpHydroSetting->PerformLayout();
			this->grpNewGeoInSetting->ResumeLayout(false);
			this->grpNewGeoInSetting->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoXInSetting))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoYInSetting))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoWidthInSetting))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tckGeoHeightInSetting))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoardInSetting))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		#pragma region Global variables
		Random^ r4danmaku = gcnew Random(DateTime::Now.Millisecond);
		int minute, second;
		Team^ team_A = gcnew Team(A);
		Team^ team_B = gcnew Team(B);
		RectangleF^ recNewGeoGraph = gcnew RectangleF();
		bool typhoonLog, lightningLog, fogLog;
		int playMode;
		int danmakuHitNum;
		int danmakuLevel;
		int counter = 0;
		bool leftForward;
		#pragma endregion

		#pragma region Helper functions
		// 畫板子
		void printBoard(Graphics^ g) {
			Brush^ bruBoard = gcnew SolidBrush(Color::AntiqueWhite);
			const int OFFSET_X = 8, OFFSET_Y = 8;

			g->FillRectangle(bruBoard, Rectangle(BIAS_X - OFFSET_X, BIAS_Y - OFFSET_Y, BOARD_LENGTH + (OFFSET_X << 1), BOARD_LENGTH + (OFFSET_Y << 1)));
		}

		// 畫網格線
		void printBlockLines(Graphics^ g) {
			Pen^ penBoard = gcnew Pen(Color::Black, 1);
			const int OFFSET_X = 8, OFFSET_Y = 8;

			#pragma region render the border of board
			g->DrawLine(penBoard, PointF(BIAS_X - OFFSET_X, BIAS_Y - OFFSET_Y), PointF(BIAS_X - OFFSET_X, BIAS_Y + OFFSET_Y + BOARD_LENGTH));
			g->DrawLine(penBoard, PointF(BIAS_X - OFFSET_X, BIAS_Y + OFFSET_Y + BOARD_LENGTH), PointF(BIAS_X + OFFSET_X + BOARD_LENGTH, BIAS_Y + OFFSET_Y + BOARD_LENGTH));
			g->DrawLine(penBoard, PointF(BIAS_X + OFFSET_X + BOARD_LENGTH, BIAS_Y + OFFSET_Y + BOARD_LENGTH), PointF(BIAS_X + OFFSET_X + BOARD_LENGTH, BIAS_Y - OFFSET_Y));
			g->DrawLine(penBoard, PointF(BIAS_X + OFFSET_X + BOARD_LENGTH, BIAS_Y - OFFSET_Y), PointF(BIAS_X - OFFSET_X, BIAS_Y - OFFSET_Y));
			#pragma endregion

			for (int i = 0; i <= BOARD_SIZE; i++)
				g->DrawLine(penBoard, Point((0 + BIAS_X) + (i * BLOCK_LENGTH), 0 + BIAS_Y), Point((0 + BIAS_X) + (i * BLOCK_LENGTH), BOARD_LENGTH + BIAS_Y));

			for (int i = 0; i <= BOARD_SIZE; i++)
				g->DrawLine(penBoard, Point(0 + BIAS_X, (0 + BIAS_Y) + (i * BLOCK_LENGTH)), Point(BOARD_LENGTH + BIAS_X, (0 + BIAS_Y) + (i * BLOCK_LENGTH)));
		}

		// 一般砲彈傷害
		bool shellExplode(Shell^ shell) {

			double bombX = shell->getGoalCoord().X;
			double bombY = shell->getGoalCoord().Y;
			bool hasHitVessel = false;
			String^ newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] " + shell->getName() + " arrived (" + bombX + ", " + bombY + ") -> ";
			//Dictionary<String^, VesselObject^> destroyedVesselList;

			#pragma region search the vessel which is in the range, and give them damage
			for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {

				// the vessel is in the damage range
				if (((vessel_A.Value->getCoord().X - bombX) * (vessel_A.Value->getCoord().X - bombX)) + (((vessel_A.Value->getCoord().Y - bombY) * (vessel_A.Value->getCoord().Y - bombY))) <= EXPLOSION_RADIUS * EXPLOSION_RADIUS) {
					vessel_A.Value->setRemainHp(vessel_A.Value->getRemainHp() - shell->getDamage());

					if (hasHitVessel == false)
						newLog += "hit {TeamA " + vessel_A.Key;
					else
						newLog += ", TeamA " + vessel_A.Key;

					hasHitVessel = true;

					// the hitpoint of the vessel is under 0, destroyed
					/*if (vessel_A.Value->getHp() <= 0.0) {
						destroyedVesselList.Add(vessel_A.Value->getName(), vessel_A.Value);
					}*/
				}
			}
			for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {

				// the vessel is in the damage range
				if (((vessel_B.Value->getCoord().X - bombX) * (vessel_B.Value->getCoord().X - bombX)) + (((vessel_B.Value->getCoord().Y - bombY) * (vessel_B.Value->getCoord().Y - bombY))) <= EXPLOSION_RADIUS * EXPLOSION_RADIUS) {
					vessel_B.Value->setRemainHp(vessel_B.Value->getRemainHp() - shell->getDamage());

					if (hasHitVessel == false)
						newLog += "hit {TeamB " + vessel_B.Key;
					else
						newLog += ", TeamB " + vessel_B.Key;

					hasHitVessel = true;

					// the hitpoint of the vessel is under 0, destroyed
					/*if (vessel_B.Value->getHp() <= 0.0) {
						destroyedVesselList.Add(vessel_B.Value->getName(), vessel_B.Value);
					}*/
				}
			}

			if (hasHitVessel)
				newLog += "}\r\n";
			else
				newLog += "miss\r\n";

			txtBattleLog->Text += newLog;
			#pragma endregion

			/* ===================================================================================================== */

			#pragma region the vessel which hitpoints is under 0 should be destroyed
			/*for each (KeyValuePair<String^, VesselObject^> destroyedVessel in destroyedVesselList) {
				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team";

				if (destroyedVessel.Value->getTeam() == A && team_A->vesselList.ContainsKey(destroyedVessel.Key)) {
					team_A->vesselList.Remove(destroyedVessel.Key);

					newLog += "A " + destroyedVessel.Key + " destroyed\r\n";
					txtBattleLog->Text += newLog;
				}

				if (destroyedVessel.Value->getTeam() == B && team_B->vesselList.ContainsKey(destroyedVessel.Key)) {
					team_B->vesselList.Remove(destroyedVessel.Key);

					newLog += "B " + destroyedVessel.Key + " destroyed\r\n";
					txtBattleLog->Text += newLog;
				}
			}*/
			#pragma endregion

			return hasHitVessel;
		}

		bool isCollapsed(VesselObject ^vessel) {

			// dis2 means the square of distance -> dis * dis
			double dis2_before = 0.0, dis2_after = 0.0;
			VesselObject ^thisVessel = vessel;

			Dictionary<String^, VesselObject^> collapsedVesselList_A;
			Dictionary<String^, VesselObject^> collapsedVesselList_B;
			bool isCollapse = false;
			String^ newLog = "";

			collapsedVesselList_A.Clear();
			collapsedVesselList_B.Clear();

			for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
				if (vessel_A.Value != nullptr) {

					// 是自己，跳過
					if (vessel_A.Value->getTeam() == thisVessel->getTeam() && vessel_A.Value->getName() == thisVessel->getName())
						continue;

					dis2_before = ((vessel_A.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_A.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y));




					//thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove();

					/*darling*/
					double temXofMove = thisVessel->getCoord().X;
					double temYofMove = thisVessel->getCoord().Y;
					double temSpeed = thisVessel->getNowSpeed();
					double temAngle = thisVessel->getNowAngle();
					double moveX = 0.0;
					double moveY = 0.0;
					double movedis = 0.0;
					for (int temi = 0; temi < 5; temi++) {
						if (temSpeed == 0) { break; }
						else if (temSpeed < 0) {

							temSpeed = temSpeed * (-1);
							temAngle += 180;
						}
						else {
							if (temXofMove >= 0 && temYofMove >= 0 && temXofMove <= 20 && temYofMove <= 20) {
								moveX = Math::Cos(ANGLE_TO_RADIUS(temAngle));
								moveY = -(Math::Sin(ANGLE_TO_RADIUS(temAngle)));
								movedis = Math::Sqrt((moveX * moveX) + (moveY * moveY));

								temXofMove += moveX * temSpeed;
								temYofMove + -moveY * temSpeed;
							}
							else {
								temSpeed = 0.0;
								temAngle = 0.0;

								if (moveX < 0.0)
									moveX = 0.0;
								if (moveY < 0.0)
									moveY = 0.0;

								if (moveX > 20.0)
									moveX = 20.0;
								if (moveY > 20.0)
									moveY = 20.0;


							}
						}
					}
					//dis2_after = ((vessel_A.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_A.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y));
					dis2_after = ((vessel_A.Value->getCoord().X - temXofMove) * (vessel_A.Value->getCoord().X - temXofMove)) + ((vessel_A.Value->getCoord().Y - temYofMove) * (vessel_A.Value->getCoord().Y - temYofMove));
					// the distance between 2 vessels is too close that collapsion happened
					if (dis2_after <= COLLAPSE_DISTANCE * COLLAPSE_DISTANCE && dis2_after < dis2_before) {
						if (!collapsedVesselList_A.ContainsKey(vessel_A.Value->getName())) {
							collapsedVesselList_A.Add(vessel_A.Value->getName(), vessel_A.Value);
							isCollapse = true;
						}
					}


				}
				for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
					if (vessel_B.Value != nullptr) {

						if (vessel_B.Value->getTeam() == thisVessel->getTeam() && vessel_B.Value->getName() == thisVessel->getName())
							continue;

						dis2_before = ((vessel_B.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_B.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y));


						//thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove();

						//dis2_after = ((vessel_B.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_B.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y));
						/*darling*/
						double temXofMove = thisVessel->getCoord().X;
						double temYofMove = thisVessel->getCoord().Y;
						double temSpeed = thisVessel->getNowSpeed();
						double temAngle = thisVessel->getNowAngle();
						double moveX = 0.0;
						double moveY = 0.0;
						double movedis = 0.0;
						for (int temi = 0; temi < 5; temi++) {
							if (temSpeed == 0) { break; }
							else if (temSpeed < 0) {

								temSpeed = temSpeed * (-1);
								temAngle += 180;
							}
							else {
								if (temXofMove >= 0 && temYofMove >= 0 && temXofMove <= 20 && temYofMove <= 20) {
									moveX = Math::Cos(ANGLE_TO_RADIUS(temAngle));
									moveY = -(Math::Sin(ANGLE_TO_RADIUS(temAngle)));
									movedis = Math::Sqrt((moveX * moveX) + (moveY * moveY));

									temXofMove += moveX * temSpeed;
									temYofMove + -moveY * temSpeed;
								}
								else {
									temSpeed = 0.0;
									temAngle = 0.0;

									if (moveX < 0.0)
										moveX = 0.0;
									if (moveY < 0.0)
										moveY = 0.0;

									if (moveX > 20.0)
										moveX = 20.0;
									if (moveY > 20.0)
										moveY = 20.0;


								}
							}
						}
						dis2_after = ((vessel_B.Value->getCoord().X - temXofMove) * (vessel_B.Value->getCoord().X - temXofMove)) + ((vessel_B.Value->getCoord().Y - temYofMove) * (vessel_B.Value->getCoord().Y - temYofMove));
						// the distance between 2 vessels is too close that collapsion happened
						if (dis2_after <= COLLAPSE_DISTANCE * COLLAPSE_DISTANCE && dis2_after < dis2_before) {
							if (!collapsedVesselList_B.ContainsKey(vessel_B.Value->getName())) {
								collapsedVesselList_B.Add(vessel_B.Value->getName(), vessel_B.Value);
								isCollapse = true;
							}
						}
					}
				}


			}


			#pragma region Collapsion damage
			if (isCollapse && thisVessel->getNowSpeed() != 0.0) {

				for each (KeyValuePair<String^, VesselObject^> vessel in collapsedVesselList_A) {
					if (team_A->vesselList.ContainsKey(vessel.Key) && vessel.Value->getTeam() == A) {

						team_A->vesselList[vessel.Key]->setRemainHp(team_A->vesselList[vessel.Key]->getRemainHp() - COLLAPSION_DAMAGE);
						team_A->vesselList[vessel.Key]->setNowSpeed(0.0);
						team_A->vesselList[vessel.Key]->setNowAngle(0.0);


						newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] {Team" + (thisVessel->getTeam() == A ? "A " : "B ") + thisVessel->getName() + "} and {TeamA " + vessel.Value->getName() + "} has COLLAPSED\r\n";
						txtBattleLog->Text += newLog;
					}
				}
				for each (KeyValuePair<String^, VesselObject^> vessel in collapsedVesselList_B) {
					if (team_B->vesselList.ContainsKey(vessel.Key) && vessel.Value->getTeam() == B) {

						team_B->vesselList[vessel.Key]->setRemainHp(team_B->vesselList[vessel.Key]->getRemainHp() - COLLAPSION_DAMAGE);
						team_B->vesselList[vessel.Key]->setNowSpeed(0.0);
						team_B->vesselList[vessel.Key]->setNowAngle(0.0);

						newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] {Team" + (thisVessel->getTeam() == A ? "A " : "B ") + thisVessel->getName() + "} and {TeamB " + vessel.Value->getName() + "} has COLLAPSED\r\n";
						txtBattleLog->Text += newLog;
					}
				}

				if (vessel->getTeam() == A)
					team_A->vesselList[vessel->getName()]->setRemainHp(team_A->vesselList[vessel->getName()]->getRemainHp() - COLLAPSION_DAMAGE);
				else
					team_B->vesselList[vessel->getName()]->setRemainHp(team_B->vesselList[vessel->getName()]->getRemainHp() - COLLAPSION_DAMAGE);
			}
			#pragma endregion

			return isCollapse;
		}

		#pragma region wrong isCollapsed
		//bool isCollapsed(VesselObject ^vessel) {

		//	// dis2 means the square of distance -> dis * dis
		//	double dis2_before = 0.0, dis2_after = 0.0;
		//	VesselObject ^thisVessel = vessel;

		//	Dictionary<String^, VesselObject^> collapsedVesselList_A;
		//	Dictionary<String^, VesselObject^> collapsedVesselList_B;
		//	bool isCollapse = false;
		//	String^ newLog = "";

		//	collapsedVesselList_A.Clear();
		//	collapsedVesselList_B.Clear();

		//	for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
		//		if (vessel_A.Value != nullptr) {

		//			// 是自己，跳過
		//			if (vessel_A.Value->getTeam() == thisVessel->getTeam() && vessel_A.Value->getName() == thisVessel->getName())
		//				continue;

		//			dis2_before = ((vessel_A.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_A.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y));




		//			//thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove();

		//			/*darling*/
		//			double temXofMove = thisVessel->getCoord().X;
		//			double temYofMove = thisVessel->getCoord().Y;
		//			double temSpeed = thisVessel->getNowSpeed();
		//			double temAngle = thisVessel->getNowAngle();
		//			double moveX = 0.0;
		//			double moveY = 0.0;
		//			double movedis = 0.0;
		//			for (int temi = 0; temi < 5; temi++) {
		//				if (temSpeed == 0) { break; }
		//				else if (temSpeed < 0) {

		//					temSpeed = temSpeed * (-1);
		//					temAngle += 180;
		//				}
		//				else {
		//					if (temXofMove >= 0 && temYofMove >= 0 && temXofMove <= 20 && temYofMove <= 20) {
		//						moveX = Math::Cos(ANGLE_TO_RADIUS(temAngle));
		//						moveY = -(Math::Sin(ANGLE_TO_RADIUS(temAngle)));
		//						movedis = Math::Sqrt((moveX * moveX) + (moveY * moveY));

		//						temXofMove += moveX * temSpeed;
		//						temYofMove + -moveY * temSpeed;
		//					}
		//					else {
		//						temSpeed = 0.0;
		//						temAngle = 0.0;

		//						if (moveX < 0.0)
		//							moveX = 0.0;
		//						if (moveY < 0.0)
		//							moveY = 0.0;

		//						if (moveX > 20.0)
		//							moveX = 20.0;
		//						if (moveY > 20.0)
		//							moveY = 20.0;


		//					}
		//				}
		//			}
		//			//dis2_after = ((vessel_A.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_A.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y));
		//			dis2_after = ((vessel_A.Value->getCoord().X - temXofMove) * (vessel_A.Value->getCoord().X - temXofMove)) + ((vessel_A.Value->getCoord().Y - temYofMove) * (vessel_A.Value->getCoord().Y - temYofMove));
		//			// the distance between 2 vessels is too close that collapsion happened
		//			if (dis2_after <= COLLAPSE_DISTANCE * COLLAPSE_DISTANCE && dis2_after < dis2_before) {
		//				if (!collapsedVesselList_A.ContainsKey(vessel_A.Value->getName())) {
		//					collapsedVesselList_A.Add(vessel_A.Value->getName(), vessel_A.Value);
		//					isCollapse = true;
		//				}
		//			}


		//		}
		//		for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
		//			if (vessel_B.Value != nullptr) {

		//				if (vessel_B.Value->getTeam() == thisVessel->getTeam() && vessel_B.Value->getName() == thisVessel->getName())
		//					continue;

		//				dis2_before = ((vessel_B.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_B.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y));


		//				//thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove();

		//				//dis2_after = ((vessel_B.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_B.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y));
		//				/*darling*/
		//				double temXofMove = thisVessel->getCoord().X;
		//				double temYofMove = thisVessel->getCoord().Y;
		//				double temSpeed = thisVessel->getNowSpeed();
		//				double temAngle = thisVessel->getNowAngle();
		//				double moveX = 0.0;
		//				double moveY = 0.0;
		//				double movedis = 0.0;
		//				for (int temi = 0; temi < 5; temi++) {
		//					if (temSpeed == 0) { break; }
		//					else if (temSpeed < 0) {

		//						temSpeed = temSpeed * (-1);
		//						temAngle += 180;
		//					}
		//					else {
		//						if (temXofMove >= 0 && temYofMove >= 0 && temXofMove <= 20 && temYofMove <= 20) {
		//							moveX = Math::Cos(ANGLE_TO_RADIUS(temAngle));
		//							moveY = -(Math::Sin(ANGLE_TO_RADIUS(temAngle)));
		//							movedis = Math::Sqrt((moveX * moveX) + (moveY * moveY));

		//							temXofMove += moveX * temSpeed;
		//							temYofMove + -moveY * temSpeed;
		//						}
		//						else {
		//							temSpeed = 0.0;
		//							temAngle = 0.0;

		//							if (moveX < 0.0)
		//								moveX = 0.0;
		//							if (moveY < 0.0)
		//								moveY = 0.0;

		//							if (moveX > 20.0)
		//								moveX = 20.0;
		//							if (moveY > 20.0)
		//								moveY = 20.0;


		//						}
		//					}
		//				}
		//				dis2_after = ((vessel_B.Value->getCoord().X - temXofMove) * (vessel_B.Value->getCoord().X - temXofMove)) + ((vessel_B.Value->getCoord().Y - temYofMove) * (vessel_B.Value->getCoord().Y - temYofMove));
		//				// the distance between 2 vessels is too close that collapsion happened
		//				if (dis2_after <= COLLAPSE_DISTANCE * COLLAPSE_DISTANCE && dis2_after < dis2_before) {
		//					if (!collapsedVesselList_B.ContainsKey(vessel_B.Value->getName())) {
		//						collapsedVesselList_B.Add(vessel_B.Value->getName(), vessel_B.Value);
		//						isCollapse = true;
		//					}
		//				}
		//			}
		//		}


		//	}


		//	#pragma region Collapsion damage
		//	if (isCollapse && thisVessel->getNowSpeed() != 0.0) {

		//		for each (KeyValuePair<String^, VesselObject^> vessel in collapsedVesselList_A) {
		//			if (team_A->vesselList.ContainsKey(vessel.Key) && vessel.Value->getTeam() == A) {

		//				team_A->vesselList[vessel.Key]->setRemainHp(team_A->vesselList[vessel.Key]->getRemainHp() - COLLAPSION_DAMAGE);
		//				team_A->vesselList[vessel.Key]->setNowSpeed(0.0);
		//				team_A->vesselList[vessel.Key]->setNowAngle(0.0);


		//				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] {Team" + (thisVessel->getTeam() == A ? "A " : "B ") + thisVessel->getName() + "} and {TeamA " + vessel.Value->getName() + "} has COLLAPSED\r\n";
		//				txtBattleLog->Text += newLog;
		//			}
		//		}
		//		for each (KeyValuePair<String^, VesselObject^> vessel in collapsedVesselList_B) {
		//			if (team_B->vesselList.ContainsKey(vessel.Key) && vessel.Value->getTeam() == B) {

		//				team_B->vesselList[vessel.Key]->setRemainHp(team_B->vesselList[vessel.Key]->getRemainHp() - COLLAPSION_DAMAGE);
		//				team_B->vesselList[vessel.Key]->setNowSpeed(0.0);
		//				team_B->vesselList[vessel.Key]->setNowAngle(0.0);

		//				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] {Team" + (thisVessel->getTeam() == A ? "A " : "B ") + thisVessel->getName() + "} and {TeamB " + vessel.Value->getName() + "} has COLLAPSED\r\n";
		//				txtBattleLog->Text += newLog;
		//			}
		//		}

		//		if (vessel->getTeam() == A)
		//			team_A->vesselList[vessel->getName()]->setRemainHp(team_A->vesselList[vessel->getName()]->getRemainHp() - COLLAPSION_DAMAGE);
		//		else
		//			team_B->vesselList[vessel->getName()]->setRemainHp(team_B->vesselList[vessel->getName()]->getRemainHp() - COLLAPSION_DAMAGE);
		//	}
		//	#pragma endregion

		//	return isCollapse;
		//}
		#pragma endregion

		#pragma region wrong isCollapsed

		// 多船互撞
		//bool isCollapsed(VesselObject^ vessel) {

		//	// dis2 means the square of distance -> dis * dis
		//	double dis2_before = 0.0, dis2_after = 0.0;
		//	VesselObject^ thisVessel = vessel;
		//	Dictionary<String^, VesselObject^> collapsedVesselList_A;
		//	Dictionary<String^, VesselObject^> collapsedVesselList_B;
		//	bool isCollapse = false;
		//	String^ newLog = "";

		//	collapsedVesselList_A.Clear();
		//	collapsedVesselList_B.Clear();

		//	for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
		//		if (vessel_A.Value != nullptr) {

		//			// 是自己，跳過
		//			if (vessel_A.Value->getTeam() == thisVessel->getTeam() && vessel_A.Value->getName() == thisVessel->getName())
		//				continue;

		//			dis2_before = ((vessel_A.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_A.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y));

		//			thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove();
		//			dis2_after = ((vessel_A.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_A.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_A.Value->getCoord().Y - thisVessel->getCoord().Y));

		//			// the distance between 2 vessels is too close that collapsion happened
		//			if (dis2_after <= COLLAPSE_DISTANCE * COLLAPSE_DISTANCE && dis2_after < dis2_before) {
		//				collapsedVesselList_A.Add(vessel_A.Value->getName(), vessel_A.Value);
		//				isCollapse = true;
		//			}
		//		}
		//	}
		//	for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
		//		if (vessel_B.Value != nullptr) {

		//			if (vessel_B.Value->getTeam() == thisVessel->getTeam() && vessel_B.Value->getName() == thisVessel->getName())
		//				continue;

		//			dis2_before = ((vessel_B.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_B.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y));

		//			thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove();
		//			dis2_after = ((vessel_B.Value->getCoord().X - thisVessel->getCoord().X) * (vessel_B.Value->getCoord().X - thisVessel->getCoord().X)) + ((vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y) * (vessel_B.Value->getCoord().Y - thisVessel->getCoord().Y));

		//			// the distance between 2 vessels is too close that collapsion happened
		//			if (dis2_after <= COLLAPSE_DISTANCE * COLLAPSE_DISTANCE && dis2_after < dis2_before) {
		//				collapsedVesselList_B.Add(vessel_B.Value->getName(), vessel_B.Value);
		//				isCollapse = true;
		//			}
		//		}
		//	}

		//	#pragma region Collapsion damage
		//	if (isCollapse && thisVessel->getNowSpeed() != 0.0) {

		//		for each (KeyValuePair<String^, VesselObject^> vessel in collapsedVesselList_A) {
		//			if (team_A->vesselList.ContainsKey(vessel.Key) && vessel.Value->getTeam() == A) {

		//				team_A->vesselList[vessel.Key]->setRemainHp(team_A->vesselList[vessel.Key]->getRemainHp() - COLLAPSION_DAMAGE);
		//				team_A->vesselList[vessel.Key]->setNowSpeed(0.0);
		//				team_A->vesselList[vessel.Key]->setNowAngle(0.0);


		//				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] {Team" + (thisVessel->getTeam() == A ? "A " : "B ") + thisVessel->getName() + "} and {TeamA " + vessel.Value->getName() + "} has COLLAPSED\r\n";
		//				txtBattleLog->Text += newLog;
		//			}
		//		}
		//		for each (KeyValuePair<String^, VesselObject^> vessel in collapsedVesselList_B) {
		//			if (team_B->vesselList.ContainsKey(vessel.Key) && vessel.Value->getTeam() == B) {

		//				team_B->vesselList[vessel.Key]->setRemainHp(team_B->vesselList[vessel.Key]->getRemainHp() - COLLAPSION_DAMAGE);
		//				team_B->vesselList[vessel.Key]->setNowSpeed(0.0);
		//				team_B->vesselList[vessel.Key]->setNowAngle(0.0);

		//				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] {Team" + (thisVessel->getTeam() == A ? "A " : "B ") + thisVessel->getName() + "} and {TeamB " + vessel.Value->getName() + "} has COLLAPSED\r\n";
		//				txtBattleLog->Text += newLog;
		//			}
		//		}

		//		if (vessel->getTeam() == A)
		//			team_A->vesselList[vessel->getName()]->setRemainHp(team_A->vesselList[vessel->getName()]->getRemainHp() - COLLAPSION_DAMAGE);
		//		else
		//			team_B->vesselList[vessel->getName()]->setRemainHp(team_B->vesselList[vessel->getName()]->getRemainHp() - COLLAPSION_DAMAGE);
		//	}
		//	#pragma endregion

		//	return isCollapse;
		//}
		#pragma endregion

		// 雷射傷害
		bool laserAttack(VesselObject^ laserVessel) {

			PointF nowLoc, endLoc;
			double theta = 0.0, a = 0.0, b = 0.0, c = 0.0, dis = 0.0;
			const double R = 1000.0;
			//String^ newLog;
			bool hitSomething;

			theta = laserVessel->GetLaserAngle();
			nowLoc = laserVessel->getCoord();
			endLoc = PointF((R * Math::Cos(ANGLE_TO_RADIUS(theta))) + nowLoc.X, ((-1) * R * Math::Sin(ANGLE_TO_RADIUS(theta))) + nowLoc.Y);

			//newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (laserVessel->getTeam() == A ? "A" : "B") + " " + laserVessel->getName() + " use LASER ";
			hitSomething = laserVessel->getIsLaserHitSomething();


			for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
				// 是自己，跳過
				if (vessel_A.Value->getTeam() == A && vessel_A.Value->getName() == laserVessel->getName())
					continue;

				dis = getDistanceBetweenPointAndSegment(vessel_A.Value->getCoord(), nowLoc, endLoc);
				//Debug::WriteLine("Dis: " + dis);

				if (dis <= LASER_ATTACK_RADIUS) {
					vessel_A.Value->setRemainHp(vessel_A.Value->getRemainHp() - laserVessel->getDamage());

					if (hitSomething == false) {
						laserVessel->strcatLaserLog("-> hit {TeamA " + vessel_A.Value->getName());
						//newLog += "-> hit {TeamA " + vessel_A.Value->getName();
						hitSomething = true;
					}
					else {
						laserVessel->strcatLaserLog(", TeamA " + vessel_A.Value->getName());
						//newLog += ", TeamA " + vessel_A.Value->getName();
					}
				}
			}
			for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
				// 是自己，跳過
				if (vessel_B.Value->getTeam() == B && vessel_B.Value->getName() == laserVessel->getName())
					continue;

				dis = getDistanceBetweenPointAndSegment(vessel_B.Value->getCoord(), nowLoc, endLoc);

				if (dis <= LASER_ATTACK_RADIUS) {
					vessel_B.Value->setRemainHp(vessel_B.Value->getRemainHp() - laserVessel->getDamage());

					if (hitSomething == false) {
						laserVessel->strcatLaserLog("-> hit {TeamB " + vessel_B.Value->getName());
						//newLog += "-> hit {TeamB " + vessel_B.Value->getName();
						hitSomething = true;
					}
					else {
						laserVessel->strcatLaserLog(", TeamB " + vessel_B.Value->getName());
						//newLog += ", TeamB " + vessel_B.Value->getName();
					}
				}
			}

			/*if (hitSomething == false)
				newLog += "-> miss\r\n";
			else
				newLog += "}\r\n";

			txtBattleLog->Text += newLog;*/
			return hitSomething;
		}

		// 點到線段（注意：不是直線，是線段）距離
		double getDistanceBetweenPointAndSegment(PointF point, PointF nowLoc, PointF endLoc) {
			/*double x = point.X, y = point.Y;
			double x1 = nowLoc.X, y1 = nowLoc.Y;
			double x2 = endLoc.X, y2 = endLoc.Y;

			double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);

			if (cross <= 0)
				return Math::Sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));



			double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

			if (cross >= d2)
				return Math::Sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));



			double r = cross / d2;
			double px = x1 + (x2 - x1) * r;
			double py = y1 + (y2 - y1) * r;

			return Math::Sqrt((x - px) * (x - px) + (py - y) * (py - y));*/

			double a, b, c;

			a = getPointDistance(nowLoc, point);
			if (a <= 0.00001)
				return 0.0;

			b = getPointDistance(endLoc, point);
			if (b <= 0.00001)
				return 0.0;

			c = getPointDistance(endLoc, nowLoc);
			if (c <= 0.00001)
				return a;

			if (a * a >= (b * b) + (c * c))
				return b;
			if (b * b >= (a * a) + (c * c))
				return a;

			double l = (a + b + c) / (double)2.0;
			double s = Math::Sqrt(Math::Abs(l * (l - a) * (l - b) * (l - c)));

			return ((double)2.0 * s) / c;
		}

		// 點到點的距離
		double getPointDistance(PointF p1, PointF p2) {
			return Math::Sqrt((p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y));
		}

		// 把 HP 低於 0 的船艦從 List 中移除，相當於破壞掉
		void destroyVessels() {
			Dictionary<String^, VesselObject^> destroyedVesselList_A;
			Dictionary<String^, VesselObject^> destroyedVesselList_B;
			String^ newLog = "";

			destroyedVesselList_A.Clear();
			destroyedVesselList_B.Clear();

			for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
				// the hitpoints of the vessel is under 0, destroyed
				if (vessel_A.Value->getRemainHp() <= 0.0)
					destroyedVesselList_A.Add(vessel_A.Value->getName(), vessel_A.Value);
			}
			for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
				// the hitpoints of the vessel is under 0, destroyed
				if (vessel_B.Value->getRemainHp() <= 0.0)
					destroyedVesselList_B.Add(vessel_B.Value->getName(), vessel_B.Value);
			}


			for each (KeyValuePair<String^, VesselObject^> destroyedVessel in destroyedVesselList_A) {
				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team";

				if (destroyedVessel.Value->getTeam() == A && team_A->vesselList.ContainsKey(destroyedVessel.Key)) {
					team_A->vesselList.Remove(destroyedVessel.Key);

					newLog += "A " + destroyedVessel.Key + " destroyed\r\n";
					txtBattleLog->Text += newLog;
				}
			}
			for each (KeyValuePair<String^, VesselObject^> destroyedVessel in destroyedVesselList_B) {
				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team";

				if (destroyedVessel.Value->getTeam() == B && team_B->vesselList.ContainsKey(destroyedVessel.Key)) {
					team_B->vesselList.Remove(destroyedVessel.Key);

					newLog += "B " + destroyedVessel.Key + " destroyed\r\n";
					txtBattleLog->Text += newLog;
				}
			}
		}

		// 颱風偵測
		bool typhoonDetect(HydrometeorologicSystem^ hydro) {
			if (hydro->getHydroType() != TYPHOON)
				return true;

			String^ newLog = "";

			for each (KeyValuePair<String^, VesselObject^>^ vessel_A in team_A->vesselList) {
				double dis2 = ((vessel_A->Value->getCoord().X - hydro->getNowCoord().X) * (vessel_A->Value->getCoord().X - hydro->getNowCoord().X)) + ((vessel_A->Value->getCoord().Y - hydro->getNowCoord().Y) * (vessel_A->Value->getCoord().Y - hydro->getNowCoord().Y));
				double dis = Math::Sqrt(dis2);

				if (dis2 <= hydro->getAttackRange() * hydro->getAttackRange()) {
					vessel_A->Value->setRemainHp(vessel_A->Value->getRemainHp() - hydro->getDamage());
					newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] TeamA " + vessel_A->Value->getName() + " attacked by typhoon\r\n";
					txtBattleLog->Text += newLog;
				}
			}
			for each (KeyValuePair<String^, VesselObject^>^ vessel_B in team_B->vesselList) {
				double dis2 = ((vessel_B->Value->getCoord().X - hydro->getNowCoord().X) * (vessel_B->Value->getCoord().X - hydro->getNowCoord().X)) + ((vessel_B->Value->getCoord().Y - hydro->getNowCoord().Y) * (vessel_B->Value->getCoord().Y - hydro->getNowCoord().Y));
				double dis = Math::Sqrt(dis2);

				if (dis2 <= hydro->getAttackRange() * hydro->getAttackRange()) {
					vessel_B->Value->setRemainHp(vessel_B->Value->getRemainHp() - hydro->getDamage());
					newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] TeamB " + vessel_B->Value->getName() + " attacked by typhoon\r\n";
					txtBattleLog->Text += newLog;
				}
			}

			for each (GeographicSystem^ geo in GeographicSystem::geoList) {
				if (geo->getGeoType() != MOUNTAIN)
					continue;

				double x1 = geo->getCoord().X, x2 = geo->getCoord().X + geo->getSize().Width;
				double y1 = geo->getCoord().Y, y2 = geo->getCoord().Y + geo->getSize().Height;

				if (hydro->getNowCoord().X >= x1 && hydro->getNowCoord().X <= x2 && hydro->getNowCoord().Y >= y1 && hydro->getNowCoord().Y <= y2) {
					newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] a typhoon hit a mountain and was destroyed\r\n";
					txtBattleLog->Text += newLog;

					return false;
				}
			}

			return true;
		}

		// 霧的影響，船隻不能移動
		bool fogEffect(HydrometeorologicSystem^ hydro) {
			if (hydro->getHydroType() != FOG)
				return true;

			for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
				if (hydro->getGp()->IsVisible(vessel_A.Value->getCoord4Draw()))
					vessel_A.Value->setCanMove(false);
				else
					vessel_A.Value->setCanMove(true);

			}
			for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
				if (hydro->getGp()->IsVisible(vessel_B.Value->getCoord4Draw()))
					vessel_B.Value->setCanMove(false);
				else
					vessel_B.Value->setCanMove(true);

			}

			return true;
		}

		// 判斷新增的地形是否合法
		bool isNewGeoLegal() {
			Label^ newLbl;

			if (pnlGamePage->Visible)
				newLbl = lblMsg4AddingNewGeo;
			else
				newLbl = lblMsg4AddingNewGeoInSetting;

			// illegal: geography type not selected
			if (pnlGamePage->Visible == true && cbbGeoType->SelectedIndex < 0) {
				newLbl->ForeColor = Color::Red;
				newLbl->Text = "Please select a type";
				return false;
			}
			if (pnlSettingPage->Visible == true && cbbNewGeoTypeInSetting->SelectedIndex < 0) {
				newLbl->ForeColor = Color::Red;
				newLbl->Text = "Please select a type";
				return false;
			}

			// illegal: area is 0
			if (recNewGeoGraph->Width == 0.0 || recNewGeoGraph->Height == 0.0) {
				newLbl->ForeColor = Color::Red;
				newLbl->Text = "Width or height is 0";
				return false;
			}

			// illegal: rectangle exceeds the board length
			if (recNewGeoGraph->X + recNewGeoGraph->Width > BOARD_LENGTH + BIAS_X || recNewGeoGraph->Y + recNewGeoGraph->Height > BOARD_LENGTH + BIAS_Y) {
				newLbl->ForeColor = Color::Red;
				newLbl->Text = "The area is out of board size";
				return false;
			}

			GraphicsPath^ gp = gcnew GraphicsPath();
			gp->AddRectangle(Rectangle(recNewGeoGraph->X, recNewGeoGraph->Y, recNewGeoGraph->Width, recNewGeoGraph->Height));

			// illegal: No vessel in the range of new geography allowed
			for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
				if (gp->IsVisible(vessel_A.Value->getCoord4Draw())) {

					newLbl->ForeColor = Color::Red;
					newLbl->Text = "No vessel in the range allowed";
					return false;
				}
			}
			for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
				if (gp->IsVisible(vessel_B.Value->getCoord4Draw())) {

					newLbl->ForeColor = Color::Red;
					newLbl->Text = "No vessel in the range allowed";
					return false;
				}
			}

			// illegal: No torpedo in the range of new geography allowed
			for each (Torpedo^ torpedo_A in team_A->torpedoList) {
				if (gp->IsVisible(torpedo_A->getNowCoord4Draw())) {

					newLbl->ForeColor = Color::Red;
					newLbl->Text = "No torpedo in the range allowed";
					return false;
				}
			}
			for each (Torpedo^ torpedo_B in team_B->torpedoList) {
				if (gp->IsVisible(torpedo_B->getNowCoord4Draw())) {

					newLbl->ForeColor = Color::Red;
					newLbl->Text = "No torpedo in the range allowed";
					return false;
				}
			}

			// illegal: If the new area is MOUNTAIN type, no shell in the range of new geography allowed
			if (pnlGamePage->Visible == true && cbbGeoType->SelectedIndex == 2) {
				for each (Shell^ shell_A in team_A->shellList) {
					if (gp->IsVisible(shell_A->getNowCoord4Draw())) {

						newLbl->ForeColor = Color::Red;
						newLbl->Text = "No shell in the MOUNTAIN range allowed";
						return false;
					}
				}
				for each (Shell^ shell_B in team_B->shellList) {
					if (gp->IsVisible(shell_B->getNowCoord4Draw())) {

						newLbl->ForeColor = Color::Red;
						newLbl->Text = "No shell in the MOUNTAIN range allowed";
						return false;
					}
				}
			}

			// illegal: No areas overlapping allowed
			for each (GeographicSystem^ geo in GeographicSystem::geoList) {
				RectangleF recGeo1 = RectangleF(geo->getCoord4Draw().X, geo->getCoord4Draw().Y, geo->getSize4Draw().Width, geo->getSize4Draw().Height);
				RectangleF recGeo2 = RectangleF(recNewGeoGraph->X, recNewGeoGraph->Y, recNewGeoGraph->Width, recNewGeoGraph->Height);

				if (RectangleF::Intersect(recGeo1, recGeo2) != RectangleF()) {

					newLbl->ForeColor = Color::Red;
					newLbl->Text = "No areas overlapping allowed";
					return false;
				}
			}


			lblMsg4AddingNewGeo->Text = "";
			lblMsg4AddingNewGeoInSetting->Text = "";
			return true;
		}

		// 彈幕模式：Boss 射擊彈幕
		bool shootDanmaku(int level, int lastLevel) {
			//level = 18;

			if (level != lastLevel && level == 19) {
				team_B->torpedoList.Clear();
			}

			const double R = 50.0;
			static double torpedoLocTheta1 = 0.0;
			static double torpedoLocTheta2 = 0.0;
			double x1, y1, x2, y2, x3, y3, x4, y4;
			double angle1, angle2;

			if (level == 1) {
				if (second % 2 == 0) {
					x1 = R * Math::Cos(torpedoLocTheta1);
					y1 = R * Math::Sin(torpedoLocTheta1);
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);

					torpedoLocTheta1 += 0.5;
					if (torpedoLocTheta1 > 360.0) torpedoLocTheta1 -= 360.0;
				}
			}

			else if (level == 2) {
				if (second % 1 == 0) {
					x1 = R * Math::Cos(torpedoLocTheta1);
					y1 = R * Math::Sin(torpedoLocTheta1);
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);

					torpedoLocTheta1 -= 0.3;
					//if (torpedoLocTheta1 < 0.0) torpedoLocTheta1 += 360.0;
				}
			}

			else if (level == 3) {
				if (second % 1 == 0) {
					x1 = R * Math::Cos(torpedoLocTheta1);
					y1 = R * Math::Sin(torpedoLocTheta1);
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);

					torpedoLocTheta1 += 0.3;
					//if (torpedoLocTheta1 < 0.0) torpedoLocTheta1 += 360.0;

					x2 = R * Math::Cos(torpedoLocTheta2);
					y2 = R * Math::Sin(torpedoLocTheta2);
					angle2 = (180.0 / Math::PI) * Math::Atan2(2.0 - y2, 10.0 - x2);

					Torpedo^ newTorpedo2 = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle2, PointF(10.0, 2.0), PointF(x2, y2));
					team_B->torpedoList.Add(newTorpedo2);

					torpedoLocTheta2 -= 0.4;
					//if (torpedoLocTheta1 < 0.0) torpedoLocTheta1 += 360.0;
				}
			}

			else if (level == 4) {
				for (int i = 0; i < 4; i++) {
					torpedoLocTheta1 = r4danmaku->NextDouble() * 180.0;

					x1 = R * Math::Cos(torpedoLocTheta1);
					y1 = R * Math::Sin(torpedoLocTheta1);
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);
				}
			}

			else if (level == 5) {
				if (((minute * 60) + second) % 8 == 0) {
					int startLoc = r4danmaku->Next(360);

					for (int i = startLoc; i < 360 + startLoc; i += 10) {
						torpedoLocTheta1 = i;

						x1 = R * Math::Cos(torpedoLocTheta1);
						y1 = R * Math::Sin(torpedoLocTheta1);
						angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
						team_B->torpedoList.Add(newTorpedo);
					}
				}
			}

			else if (level == 6) {
				if (second % 1 == 0) {
					x1 = R * Math::Cos(torpedoLocTheta1);
					y1 = R * Math::Sin(torpedoLocTheta1);
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);

					x1 = R * Math::Cos(torpedoLocTheta1 + ANGLE_TO_RADIUS(120.0));
					y1 = R * Math::Sin(torpedoLocTheta1 + ANGLE_TO_RADIUS(120.0));
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);

					x1 = R * Math::Cos(torpedoLocTheta1 - ANGLE_TO_RADIUS(120.0));
					y1 = R * Math::Sin(torpedoLocTheta1 - ANGLE_TO_RADIUS(120.0));
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);


					torpedoLocTheta1 += 0.2;
					if (torpedoLocTheta1 > 360.0) torpedoLocTheta1 -= 360.0;
				}
			}

			else if (level == 7) {
				if (second % 1 == 0) {
					x1 = R * Math::Cos(torpedoLocTheta1);
					y1 = R * Math::Sin(torpedoLocTheta1);
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);

					x1 = R * Math::Cos(torpedoLocTheta1 + ANGLE_TO_RADIUS(120.0));
					y1 = R * Math::Sin(torpedoLocTheta1 + ANGLE_TO_RADIUS(120.0));
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);

					x1 = R * Math::Cos(torpedoLocTheta1 - ANGLE_TO_RADIUS(120.0));
					y1 = R * Math::Sin(torpedoLocTheta1 - ANGLE_TO_RADIUS(120.0));
					angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

					newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
					team_B->torpedoList.Add(newTorpedo);

					torpedoLocTheta1 += 0.2;
					if (torpedoLocTheta1 > 360.0) torpedoLocTheta1 -= 360.0;

					/* ================================================================== */

					x2 = R * Math::Cos(torpedoLocTheta2);
					y2 = R * Math::Sin(torpedoLocTheta2);
					angle2 = (180.0 / Math::PI) * Math::Atan2(2.0 - y2, 10.0 - x2);

					newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle2, PointF(10.0, 2.0), PointF(x2, y2));
					team_B->torpedoList.Add(newTorpedo);

					x2 = R * Math::Cos(torpedoLocTheta2 + ANGLE_TO_RADIUS(120.0));
					y2 = R * Math::Sin(torpedoLocTheta2 + ANGLE_TO_RADIUS(120.0));
					angle2 = (180.0 / Math::PI) * Math::Atan2(2.0 - y2, 10.0 - x2);

					newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle2, PointF(10.0, 2.0), PointF(x2, y2));
					team_B->torpedoList.Add(newTorpedo);

					x2 = R * Math::Cos(torpedoLocTheta2 - ANGLE_TO_RADIUS(120.0));
					y2 = R * Math::Sin(torpedoLocTheta2 - ANGLE_TO_RADIUS(120.0));
					angle2 = (180.0 / Math::PI) * Math::Atan2(2.0 - y2, 10.0 - x2);

					newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle2, PointF(10.0, 2.0), PointF(x2, y2));
					team_B->torpedoList.Add(newTorpedo);


					torpedoLocTheta2 -= 0.2;
					if (torpedoLocTheta2 > 360.0) torpedoLocTheta2 -= 360.0;
				}
			}
			
			else if (level == 8) {
				if (second % 3 == 0) {

					torpedoLocTheta1 = r4danmaku->NextDouble() * 120.0 + 30.0;
					torpedoLocTheta2 = torpedoLocTheta1 - 10.0;

					for (int i = 0; i < 21; i++) {
						x1 = R * Math::Cos(ANGLE_TO_RADIUS(torpedoLocTheta2));
						y1 = R * Math::Sin(ANGLE_TO_RADIUS(torpedoLocTheta2));
						angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
						team_B->torpedoList.Add(newTorpedo);

						torpedoLocTheta2 += 1.0;
					}
				}
			}

			else if (level == 9) {
				if (second % 5 == 0) {
					for (int i = 0; i < 7; i++) {

						x1 = r4danmaku->NextDouble() * (double)BOARD_SIZE;
						x2 = x1;
						y1 = -5.0;
						y2 = 31.0;
						angle1 = (180.0 / Math::PI) * Math::Atan2(y2 - y1, x2 - x1);

						double dis = Math::Sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
						newTorpedo->setSpeed(r4danmaku->NextDouble() * 1.5 + 0.1);
						newTorpedo->setTotalFlyingTime(dis / newTorpedo->getSpeed() + 4.5);
						team_B->torpedoList.Add(newTorpedo);
					}
				}

				torpedoLocTheta1 = 270;
				torpedoLocTheta2 = 240;
			}

			else if (level == 10) {
				for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
					for (int i = -2; i <= 2; i++) {
						x1 = vessel_A.Value->getCoord().X + (double)i * 3.0;
						y1 = vessel_A.Value->getCoord().Y;

						angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
						team_B->torpedoList.Add(newTorpedo);
					}
				}

				torpedoLocTheta1 = 30.0;
				torpedoLocTheta2 = 150.0;
			}

			else if (level == 11) {
				for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
					for (int i = -2; i <= 2; i++) {
						x1 = vessel_A.Value->getCoord().X + (double)i * (Math::Abs(i) == 2 ? 5.0 : 1.0);
						y1 = vessel_A.Value->getCoord().Y;

						angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
						team_B->torpedoList.Add(newTorpedo);
					}

					for (int i = -2; i <= 2; i++) {
						x1 = (double)BOARD_SIZE - vessel_A.Value->getCoord().X + (double)i * (Math::Abs(i) == 2 ? 6.0 : 1.0);
						y1 = -vessel_A.Value->getCoord().Y;

						angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
						team_B->torpedoList.Add(newTorpedo);
					}
				}
			}

			else if (level == 12) {
				static bool forward1 = true;
				static bool forward2 = false;

				x1 = -2; y1 = -2;

				x2 = R * Math::Cos(ANGLE_TO_RADIUS(torpedoLocTheta1));
				y2 = R * Math::Sin(ANGLE_TO_RADIUS(torpedoLocTheta1));

				angle1 = (180.0 / Math::PI) * Math::Atan2(y2 - y1, x2 - x1);

				Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
				team_B->torpedoList.Add(newTorpedo);

				if (torpedoLocTheta1 >= 90)
					forward1 = false;
				if (torpedoLocTheta1 <= 0)
					forward1 = true;

				if (forward1)
					torpedoLocTheta1 += 4.0;
				else
					torpedoLocTheta1 -= 4.0;


				x3 = 22; y3 = -2;

				x4 = R * Math::Cos(ANGLE_TO_RADIUS(torpedoLocTheta2));
				y4 = R * Math::Sin(ANGLE_TO_RADIUS(torpedoLocTheta2));

				angle2 = (180.0 / Math::PI) * Math::Atan2(y4 - y3, x4 - x3);

				Torpedo^ newTorpedo2 = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle2, PointF(x3, y3), PointF(x4, y4));
				team_B->torpedoList.Add(newTorpedo2);

				if (torpedoLocTheta2 >= 180)
					forward2 = false;
				if (torpedoLocTheta2 <= 90)
					forward2 = true;

				if (forward2)
					torpedoLocTheta2 += 4.0;
				else
					torpedoLocTheta2 -= 4.0;
			}

			else if (level == 13) {

				if (second % 5 == 0) {
					PointF loc = PointF(r4danmaku->NextDouble() * (double)BOARD_SIZE, r4danmaku->NextDouble() * ((double)BOARD_SIZE / 2.0));
					int startLoc = r4danmaku->Next(360);
					double speed;
					speed = r4danmaku->NextDouble() * 0.5 + 0.5;

					for (int i = startLoc; i < 360 + startLoc; i += 10) {
						torpedoLocTheta1 = i;

						x1 = R * Math::Cos(ANGLE_TO_RADIUS(torpedoLocTheta1));
						y1 = R * Math::Sin(ANGLE_TO_RADIUS(torpedoLocTheta1));
						angle1 = (180.0 / Math::PI) * Math::Atan2(loc.Y - y1, loc.X - x1);

						double dis = Math::Sqrt(((x1 - loc.X) * (x1 - loc.X)) + ((y1 - loc.Y) * (y1 - loc.Y)));

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(loc.X, loc.Y), PointF(x1, y1));
						newTorpedo->setSpeed(speed);
						newTorpedo->setTotalFlyingTime(dis / newTorpedo->getSpeed() + 4.5);
						team_B->torpedoList.Add(newTorpedo);
					}
				}
			}

			else if (level == 14) {

				if (second % 8 == 0) {
					for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {

						PointF loc = PointF(r4danmaku->NextDouble() * (double)BOARD_SIZE, r4danmaku->NextDouble() * ((double)BOARD_SIZE / 2.0));
						int startLoc = r4danmaku->Next(360);
						double speed;
						double banJing = 5.0;
						speed = r4danmaku->NextDouble() * 0.5 + 0.5;

						for (int i = startLoc; i < 360 + startLoc; i += 20) {
							torpedoLocTheta1 = i;

							x1 = banJing * Math::Cos(ANGLE_TO_RADIUS(torpedoLocTheta1)) + loc.X;
							y1 = banJing * Math::Sin(ANGLE_TO_RADIUS(torpedoLocTheta1)) + loc.Y;
							x2 = vessel_A.Value->getCoord().X + (vessel_A.Value->getCoord().X - x1);
							y2 = vessel_A.Value->getCoord().Y + (vessel_A.Value->getCoord().Y - y1);

							angle1 = (180.0 / Math::PI) * Math::Atan2(y1 - y2, x1 - x2);

							double dis = Math::Sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

							Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
							newTorpedo->setSpeed(speed);
							newTorpedo->setTotalFlyingTime(dis / newTorpedo->getSpeed() + 4.5);
							team_B->torpedoList.Add(newTorpedo);
						}
					}
				}
			}

			else if (level == 15) {
				if (second % 1 == 0) {

					x1 = r4danmaku->NextDouble() * BOARD_SIZE; y1 = 23.0;
					x2 = x1; y2 = -3.0;
					angle1 = (180.0 / Math::PI) * Math::Atan2(y1 - y2, x1 - x2);

					double speed = r4danmaku->NextDouble() * 0.5 + 0.4;
					double dis = Math::Sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

					Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
					newTorpedo->setSpeed(speed);
					newTorpedo->setTotalFlyingTime((dis / speed) + 4.5123);
					team_B->torpedoList.Add(newTorpedo);
				}
			}

			else if (level == 16) {
				if (second % 1 == 0) {

					x1 = r4danmaku->NextDouble() * BOARD_SIZE; y1 = 23.0;
					x2 = x1; y2 = -3.0;
					angle1 = (180.0 / Math::PI) * Math::Atan2(y1 - y2, x1 - x2);

					double speed = r4danmaku->NextDouble() * 0.5 + 0.4;
					double dis = Math::Sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

					Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
					newTorpedo->setSpeed(speed);
					newTorpedo->setTotalFlyingTime((dis / speed) + 4.5123);
					team_B->torpedoList.Add(newTorpedo);

					/* ============================================================ */

					for (int i = 0; i < 2; i++) {
						x1 = r4danmaku->NextDouble() * BOARD_SIZE; y1 = -3.0;
						x2 = x1; y2 = 23.0;
						angle1 = (180.0 / Math::PI) * Math::Atan2(y1 - y2, x1 - x2);

						speed = r4danmaku->NextDouble() * 0.5 + 0.8;
						dis = Math::Sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

						newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
						newTorpedo->setSpeed(speed);
						newTorpedo->setTotalFlyingTime((dis / speed) + 4.5123);
						team_B->torpedoList.Add(newTorpedo);
					}
				}
			}

			else if (level == 17) {
				if (second % 1 == 0) {
					static int cnt = 0;
					cnt++;

					int startLoc = 0;
					int jianGe = 40;

					for (int i = startLoc; i <= 380 + startLoc; i += jianGe) {
						x1 = R * Math::Cos(torpedoLocTheta1 + ANGLE_TO_RADIUS(((double)360.0 / (double)jianGe)) * ((double)i / (double)jianGe));
						y1 = R * Math::Sin(torpedoLocTheta1 + ANGLE_TO_RADIUS(((double)360.0 / (double)jianGe)) * ((double)i / (double)jianGe));
						angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
						team_B->torpedoList.Add(newTorpedo);
					}

					if(cnt >= 30)
						torpedoLocTheta1 += 0.2;
					else if (cnt >= 20)
						torpedoLocTheta1 -= 0.3;
					else
						torpedoLocTheta1 += 0.5;
					if (torpedoLocTheta1 > 360) torpedoLocTheta1 -= 360;
				}
			}

			else if (level == 18) {
				if (second % 4 == 0) {
					int startLoc = r4danmaku->Next(360);

					for (int i = startLoc; i < 360 + startLoc; i += (second % 8 == 0) ? 5 : 10) {
						torpedoLocTheta1 = i;

						x1 = R * Math::Cos(ANGLE_TO_RADIUS(torpedoLocTheta1));
						y1 = R * Math::Sin(ANGLE_TO_RADIUS(torpedoLocTheta1));
						y2 = 2.0; x2 = 10.0;
						angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

						double speed = (second % 8 == 0) ? 0.5 : 1.0;
						double dis = Math::Sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
						newTorpedo->setSpeed(speed);
						newTorpedo->setTotalFlyingTime(dis / newTorpedo->getSpeed() + 4.5);

						team_B->torpedoList.Add(newTorpedo);
					}
				}
			}

			else if (level == 19) {

				if (second % 2 == 0) {
					if (leftForward)
						counter++;
					else
						counter--;

					for (int i = 0; i < 2; i++) {

						x1 = 0.5 + counter;
						if (x1 > BOARD_SIZE)
							leftForward = false;
						if (x1 < 0.0)
							leftForward = true;

						y1 = 3.0;
						x2 = R * Math::Cos(ANGLE_TO_RADIUS((double)i * 180.0) + ANGLE_TO_RADIUS(90.0)) + x1;
						y2 = R * Math::Sin(ANGLE_TO_RADIUS((double)i * 180.0) + ANGLE_TO_RADIUS(90.0)) + y1;

						angle1 = (180.0 / Math::PI) * Math::Atan2(y1 - y2, x1 - x2);

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
						team_B->torpedoList.Add(newTorpedo);
					}
					
					for (int i = 0; i < 2; i++) {

						x1 = 20.5 - counter;
						y1 = 3.0;
						x2 = R * Math::Cos(ANGLE_TO_RADIUS((double)i * 180.0) + ANGLE_TO_RADIUS(90.0)) + x1;
						y2 = R * Math::Sin(ANGLE_TO_RADIUS((double)i * 180.0) + ANGLE_TO_RADIUS(90.0)) + y1;

						angle1 = (180.0 / Math::PI) * Math::Atan2(y1 - y2, x1 - x2);

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(x1, y1), PointF(x2, y2));
						team_B->torpedoList.Add(newTorpedo);
					}
				}
			}

			else if (level == 20) {
				if (second % 1 == 0) {

					int startLoc = 0;
					int jianGe = 20;

					for (int i = startLoc; i <= 380 + startLoc; i += jianGe) {
						x1 = R * Math::Cos(torpedoLocTheta1 + ANGLE_TO_RADIUS(((double)360.0 / (double)jianGe)) * ((double)i / (double)jianGe));
						y1 = R * Math::Sin(torpedoLocTheta1 + ANGLE_TO_RADIUS(((double)360.0 / (double)jianGe)) * ((double)i / (double)jianGe));
						angle1 = (180.0 / Math::PI) * Math::Atan2(2.0 - y1, 10.0 - x1);

						Torpedo^ newTorpedo = gcnew Torpedo("", "Boss", B, 1.0, 1000.0, angle1, PointF(10.0, 2.0), PointF(x1, y1));
						team_B->torpedoList.Add(newTorpedo);
					}

					torpedoLocTheta1 += 0.2;
					if (torpedoLocTheta1 > 360) torpedoLocTheta1 -= 360;
				}
			}

			// End
			else if (level == 21) {
				timerMain->Enabled = false;
				pnlGamePage->Visible = false;
				MessageBox::Show("You hit " + danmakuHitNum.ToString("000") + " times!", "loser");
				return false;
			}

			return true;
		}
		#pragma endregion

		#pragma region mouse on picBoard
		// picBoard : mouseMove
		System::Void picBoard_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			PointF conceptCoord = DRAWING_COORD_TO_COORD(e->X, e->Y);

			if (conceptCoord.X < 0.0) conceptCoord.X = 0.0;
			if (conceptCoord.X > 20.0) conceptCoord.X = 20.0;

			if (conceptCoord.Y < 0.0) conceptCoord.Y = 0.0;
			if (conceptCoord.Y > 20.0) conceptCoord.Y = 20.0;

			lblCoordinateHint->ForeColor = Color::Black;
			lblCoordinateHint->Text = conceptCoord.X.ToString("00") + ", " + conceptCoord.Y.ToString("00");

			// Tradition Mode
			if (playMode == 0) {
				for each (GeographicSystem^ geo in GeographicSystem::geoList) {
					if (geo->getGp()->IsVisible(e->Location)) {
						geo->mouseIn = true;

						lblCoordinateHint->ForeColor = Color::Black;
						lblCoordinateHint->Text = geo->getName();
					}
					else {
						geo->mouseIn = false;
					}
				}

				for each (HydrometeorologicSystem^ hydro in HydrometeorologicSystem::hydroList) {

					if (hydro->getGp()->IsVisible(e->Location)) {
						hydro->setMouseIn(true);

						lblCoordinateHint->ForeColor = Color::Black;

						if (hydro->getHydroType() == FOG) {
							lblCoordinateHint->Text = "Fog";
							//txtBattleLog->Text += "fuck you\r\n";
							//MessageBox::Show("fuck");
						}
						else if (hydro->getHydroType() == TYPHOON)
							lblCoordinateHint->Text = "Typhoon";
						else if (hydro->getHydroType() == LIGHTNING)
							lblCoordinateHint->Text = "Lightning";
					}
					else {
						hydro->setMouseIn(false);
						lblBoardHint->Text = "";
					}
				}

				for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
					if (vessel_A.Value->getGp()->IsVisible(e->Location)) {
						lblCoordinateHint->ForeColor = Color::Red;
						lblCoordinateHint->Text = vessel_A.Value->getName() + " (" + VesselObject::typeStringList[vessel_A.Value->getVesselType()] + ")";
						vessel_A.Value->mouseIn = true;
					}
					else
						vessel_A.Value->mouseIn = false;
				}
				for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
					if (vessel_B.Value->getGp()->IsVisible(e->Location)) {
						lblCoordinateHint->ForeColor = Color::Blue;
						lblCoordinateHint->Text = vessel_B.Value->getName() + " (" + VesselObject::typeStringList[vessel_B.Value->getVesselType()] + ")";
						vessel_B.Value->mouseIn = true;
					}
					else
						vessel_B.Value->mouseIn = false;
				}
			}
			
			// Danmaku Mode
			else if (playMode == 1) {

				if (timerMain->Enabled == true) {
					for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
						vessel_A.Value->setCoord(PointF(conceptCoord.X, vessel_A.Value->getCoord().Y));
						vessel_A.Value->setCoord4Draw(COORD_TO_DRAWING_COORD(vessel_A.Value->getCoord().X, vessel_A.Value->getCoord().Y));
					}
				}
			}


			if (timerMain->Enabled == true)
				return;

			this->Refresh();
		}

		// picBoard : mouseEnter
		System::Void picBoard_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			lblCoordinateHint->Visible = true;
		}

		// picBoard : mouseLeave
		System::Void picBoard_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			lblCoordinateHint->Visible = false;
		}
		#pragma endregion

		/* =========================================================================================================== */
		// MainForm : load
		System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			lblShowDanmakuHitNum->Location = Point(620, 250);

			pnlMenuPage->Visible = true;
			pnlSettingPage->Visible = false;
			pnlGamePage->Visible = false;

			txtBattleLog->Text = "";
			btnTyphoon->Enabled = false;
			minute = second = 0;
			lblNowTime->Text = "00:00";

			playMode = 0;

			this->DoubleBuffered = true;
		}
		/* =========================================================================================================== */
		#pragma region in MenuPage
		// btnStartGame : click
		System::Void btnStartGame_Click(System::Object^  sender, System::EventArgs^  e) {
			playMode = 0;

			pnlMenuPage->Visible = false;
			pnlSettingPage->Visible = true;
			pnlGamePage->Visible = false;

			btnNewGeoCancelInSetting->Enabled = true;
			btnNewGeoConfirmInSetting->Enabled = false;

			chckIsUseTyphoon->Checked = false;
			chckIsUseLightning->Checked = false;
			chckIsUseFog->Checked = false;

			chckIsLogTyphoon->Checked = false;
			chckIsLogLightning->Checked = false;
			chckIsLogFog->Checked = false;

			chckIsLogTyphoon->Visible = false;
			chckIsLogLightning->Visible = false;
			chckIsLogFog->Visible = false;

			recNewGeoGraph->Location = PointF(BIAS_X, BIAS_Y);
			recNewGeoGraph->Size = SizeF();

			lblMsg4AddingNewGeoInSetting->ForeColor = Color::Red;
			lblMsg4AddingNewGeoInSetting->Text = "Please select a type";

			cbbNewGeoTypeInSetting->SelectedIndex = -1;
			tckGeoXInSetting->Value = 0;
			tckGeoYInSetting->Value = 0;
			tckGeoWidthInSetting->Value = 0;
			tckGeoHeightInSetting->Value = 0;

			txtBattleLog->Text = "";
			txtCommand_A->Text = ""; txtCommand_B->Text = "";
			minute = 0; second = 0;

			GeographicSystem::geoList.Clear();
			HydrometeorologicSystem::hydroList.Clear();
			team_A->vesselList.Clear();
			team_A->shellList.Clear();
			team_A->torpedoList.Clear();
			team_B->vesselList.Clear();
			team_B->shellList.Clear();
			team_B->torpedoList.Clear();

			txtCommand_A->Enabled = true; txtCommand_B->Enabled = true;

			this->Refresh();
		}

		// btnDanmakuModeStartGame : click
		System::Void btnDanmakuModeStartGame_Click(System::Object^  sender, System::EventArgs^  e) {
			playMode = 1;
			danmakuHitNum = 0;
			counter = 0;
			leftForward = true;

			lblShowDanmakuHitNum->Text = "  Level 00\r\nHit num: 000";
			lblShowDanmakuHitNum->Visible = true;

			pnlMenuPage->Visible = false;
			pnlSettingPage->Visible = false;
			pnlGamePage->Visible = true;

			btnNewGeo->Visible = false;
			grpboxCommands->Visible = false;

			btnTyphoon->Visible = chckIsUseTyphoon->Checked;
			btnLightning->Visible = chckIsUseLightning->Checked;
			btnFog->Visible = chckIsUseFog->Checked;

			typhoonLog = chckIsLogTyphoon->Checked;
			lightningLog = chckIsLogLightning->Checked;
			fogLog = chckIsLogFog->Checked;

			lblMsg4AddingNewGeo->Text = "";
			lblMsg4AddingNewGeoInSetting->Text = "";

			VesselLV^ you = gcnew VesselLV("You", team_A->getSymbol(), PointF(10.0F, 18.0F));
			team_A->vesselList.Add("You", you);

			VesselCG^ boss = gcnew VesselCG("Boss", team_B->getSymbol(), PointF(10.0F, 2.0F));
			boss->setAttackCD(0.0);
			boss->setLaunchCD(0.0);
			boss->setMaxAttackDistance(200.0);
			boss->setMaxHp(10000000.0);
			boss->setRemainHp(boss->getMaxHp());
			boss->setDamage(10000.0);
			boss->setTorpedoDamage(10000.0);
			boss->setTorpedoSpeed(1.0);

			team_B->vesselList.Add("Boss", boss);

			this->Refresh();
		}

		// btnExit : click
		System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}
		#pragma endregion
		/* =========================================================================================================== */
		#pragma region in SettingPage
		// btnBackInSetting : click
		System::Void btnBackInSetting_Click(System::Object^  sender, System::EventArgs^  e) {
			pnlMenuPage->Visible = true;
			pnlSettingPage->Visible = false;
			pnlGamePage->Visible = false;
		}

		// btnStartInSetting : click
		System::Void btnStartInSetting_Click(System::Object^  sender, System::EventArgs^  e) {
			lblShowDanmakuHitNum->Visible = false;

			pnlMenuPage->Visible = false;
			pnlSettingPage->Visible = false;
			pnlGamePage->Visible = true;

			btnNewGeo->Visible = true;
			grpboxCommands->Visible = true;

			btnTyphoon->Visible = chckIsUseTyphoon->Checked;
			btnLightning->Visible = chckIsUseLightning->Checked;
			btnFog->Visible = chckIsUseFog->Checked;

			typhoonLog = chckIsLogTyphoon->Checked;
			lightningLog = chckIsLogLightning->Checked;
			fogLog = chckIsLogFog->Checked;

			btnNextSecond->Enabled = true;

			lblMsg4AddingNewGeo->Text = "";
			lblMsg4AddingNewGeoInSetting->Text = "";

			this->Refresh();
		}

		// btnNewGeoConfirmInSetting : click
		System::Void btnNewGeoConfirmInSetting_Click(System::Object^  sender, System::EventArgs^  e) {
			Reef^ newReef;
			Flatland^ newFlatland;
			Mountain^ newMountain;

			switch (cbbNewGeoTypeInSetting->SelectedIndex) {
				case 0:
					newReef = gcnew Reef(DRAWING_COORD_TO_COORD(recNewGeoGraph->X, recNewGeoGraph->Y), SizeF(recNewGeoGraph->Width / BLOCK_LENGTH, recNewGeoGraph->Height / BLOCK_LENGTH));
					GeographicSystem::geoList.Add(newReef);
					break;
				case 1:
					newFlatland = gcnew Flatland(DRAWING_COORD_TO_COORD(recNewGeoGraph->X, recNewGeoGraph->Y), SizeF(recNewGeoGraph->Width / BLOCK_LENGTH, recNewGeoGraph->Height / BLOCK_LENGTH));
					GeographicSystem::geoList.Add(newFlatland);
					break;
				case 2:
					newMountain = gcnew Mountain(DRAWING_COORD_TO_COORD(recNewGeoGraph->X, recNewGeoGraph->Y), SizeF(recNewGeoGraph->Width / BLOCK_LENGTH, recNewGeoGraph->Height / BLOCK_LENGTH));
					GeographicSystem::geoList.Add(newMountain);
					break;
			}

			recNewGeoGraph->Location = PointF(BIAS_X, BIAS_Y);
			recNewGeoGraph->Size = SizeF();
			tckGeoXInSetting->Value = 0;
			tckGeoYInSetting->Value = 0;
			tckGeoWidthInSetting->Value = 0;
			tckGeoHeightInSetting->Value = 0;

			cbbNewGeoTypeInSetting->SelectedIndex = -1;

			this->Refresh();
		}

		// btnNewGeoCancelInSetting : click (Reset)
		System::Void btnNewGeoCancelInSetting_Click(System::Object^  sender, System::EventArgs^  e) {

			try {
				if (MessageBox::Show("Are you sure you want to reset all of the geography areas?", "Please make sure before resetting", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Forms::DialogResult::Yes) {
					tckGeoXInSetting->Value = 0;
					tckGeoYInSetting->Value = 0;
					tckGeoWidthInSetting->Value = 0;
					tckGeoHeightInSetting->Value = 0;

					cbbNewGeoTypeInSetting->SelectedIndex = -1;

					List<GeographicSystem^> destroyedList;
					destroyedList.Clear();

					for (int u = 0; u < GeographicSystem::geoList.Count; u++)
						destroyedList.Add(GeographicSystem::geoList[u]);
					for each (GeographicSystem^ geo in destroyedList)
						GeographicSystem::geoList.Remove(geo);

					this->Refresh();
				}
			}
			catch (...) {}
		}

		// cbbNewGeoTypeInSetting : selectedIndexChanged
		System::Void cbbNewGeoTypeInSetting_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			btnNewGeoConfirmInSetting->Enabled = isNewGeoLegal();
			this->Refresh();
		}

		System::Void tckGeoXInSetting_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			double x4Draw = COORD_TO_DRAWING_COORD(((double)tckGeoXInSetting->Value * 0.2), 0.0).X;
			recNewGeoGraph->X = x4Draw;

			btnNewGeoConfirmInSetting->Enabled = isNewGeoLegal();
			this->Refresh();
		}

		System::Void tckGeoYInSetting_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			double y4Draw = COORD_TO_DRAWING_COORD(0.0, ((double)tckGeoYInSetting->Value * 0.2)).Y;
			recNewGeoGraph->Y = y4Draw;

			btnNewGeoConfirmInSetting->Enabled = isNewGeoLegal();
			this->Refresh();
		}

		System::Void tckGeoWidthInSetting_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			double width4Draw = ((double)tckGeoWidthInSetting->Value * 0.2) * BLOCK_LENGTH;
			recNewGeoGraph->Width = width4Draw;

			btnNewGeoConfirmInSetting->Enabled = isNewGeoLegal();
			this->Refresh();
		}

		System::Void tckGeoHeightInSetting_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			double height4Draw = ((double)tckGeoHeightInSetting->Value * 0.2) * BLOCK_LENGTH;
			recNewGeoGraph->Height = height4Draw;

			btnNewGeoConfirmInSetting->Enabled = isNewGeoLegal();
			this->Refresh();
		}

		System::Void chckIsUseTyphoon_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			chckIsLogTyphoon->Visible = chckIsUseTyphoon->Checked;
			chckIsLogTyphoon->Checked = false;
		}

		System::Void chckIsUseLightning_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			chckIsLogLightning->Visible = chckIsUseLightning->Checked;
			chckIsLogLightning->Checked = false;
		}

		System::Void chckIsUseFog_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			chckIsLogFog->Visible = chckIsUseFog->Checked;
			chckIsLogFog->Checked = false;
		}

		// picBoardInSetting : paint
		System::Void picBoardInSetting_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			Graphics^ g = e->Graphics;

			printBoard(g);

			#pragma region geography render
			for each (GeographicSystem^ geo in GeographicSystem::geoList) {
				//Debug::WriteLine("coord: " + geo->getCoord4Draw() + " | size: " + geo->getSize4Draw());
				geo->render(g);
			}

			#pragma region Draw virutal(undefined) geograpgy rectangle
			if (grpNewGeoInSetting->Visible == true && cbbNewGeoTypeInSetting->SelectedIndex >= 0) {

				Color newClr;
				switch (cbbNewGeoTypeInSetting->SelectedIndex) {
					case 0: newClr = Color::FromArgb(VIRTUAL_GEO_ALPHA, 100, 100, 100); break;
					case 1: newClr = Color::FromArgb(VIRTUAL_GEO_ALPHA, 23, 100, 14); break;
					case 2: newClr = Color::FromArgb(VIRTUAL_GEO_ALPHA, 45, 45, 245); break;
				}

				g->FillRectangle(gcnew SolidBrush(newClr), RectangleF(recNewGeoGraph->X, recNewGeoGraph->Y, recNewGeoGraph->Width, recNewGeoGraph->Height));
			}
			#pragma endregion
			#pragma endregion

			printBlockLines(g);
		}
		#pragma endregion
		/* =========================================================================================================== */
		#pragma region in GamePage
		// timerMain : tick
		System::Void timerMain_Tick(System::Object^  sender, System::EventArgs^  e) {

			second++;
			if (second == 60)
				minute++, second = 0;

			try {
				if (playMode == 0) {

					#pragma region Hydrometeorology
					try {
						List<HydrometeorologicSystem^> destroyedHydroList;
						destroyedHydroList.Clear();

						for each (HydrometeorologicSystem^ hydro in HydrometeorologicSystem::hydroList) {
							hydro->hydroMove();

							if (typhoonDetect(hydro) == false)
								destroyedHydroList.Add(hydro);

							hydro->setExistTime(hydro->getExistTime() + 1);

							fogEffect(hydro);

							if (hydro->getHydroType() == FOG && hydro->getExistTime() >= TOTAL_FOG_TIME)
								destroyedHydroList.Add(hydro);
						}
						for each (HydrometeorologicSystem^ hydro in destroyedHydroList) {
							if (hydro->getHydroType() == FOG) {
								hydro->getGp()->Reset();
								fogEffect(hydro);
							}

							HydrometeorologicSystem::hydroList.Remove(hydro);
						}

						for (int i = 0; i < HydrometeorologicSystem::hydroList.Count; i++) {
							if (HydrometeorologicSystem::hydroList[i]->getHydroType() == TYPHOON && HydrometeorologicSystem::hydroList[i]->getSpeed() == 0.0)
								HydrometeorologicSystem::hydroList.RemoveAt(i);

							if (HydrometeorologicSystem::hydroList[i]->getHydroType() == LIGHTNING && HydrometeorologicSystem::hydroList[i]->getExistTime() >= 5) {
								HydrometeorologicSystem::hydroList.RemoveAt(i);
							}
						}
					} catch (...) {}
					#pragma endregion

					#pragma region attack/launch/defense/laser/enrich CD consuming
					for each(KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
						vessel_A.Value->minus1RemainAttackCD();
						vessel_A.Value->minus1RemainLaunchCD();
						vessel_A.Value->minus1RemainDefenseCD();
						vessel_A.Value->minus1RemainLaserCD();
						vessel_A.Value->minus1remain_Enrich_CD();

						#pragma region laser vanish
						if (vessel_A.Value->getIsLaserShooting() && vessel_A.Value->getLaserCD() - vessel_A.Value->getRemainLaserCD() >= LASER_ATTACK_TIME) {

							if (vessel_A.Value->getIsLaserHitSomething() == false)
								vessel_A.Value->strcatLaserLog("-> miss\r\n");
							else
								vessel_A.Value->strcatLaserLog("}\r\n");

							txtBattleLog->Text += vessel_A.Value->getLaserLog();

							vessel_A.Value->setIsLaserShooting(false);
							vessel_A.Value->setIsLaserHitSomething(false);
							vessel_A.Value->setLaserLog("");
						}
						#pragma endregion
					}
					for each(KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
						vessel_B.Value->minus1RemainAttackCD();
						vessel_B.Value->minus1RemainLaunchCD();
						vessel_B.Value->minus1RemainDefenseCD();
						vessel_B.Value->minus1RemainLaserCD();
						vessel_B.Value->minus1remain_Enrich_CD();

						#pragma region laser vanish
						if (vessel_B.Value->getIsLaserShooting() && vessel_B.Value->getLaserCD() - vessel_B.Value->getRemainLaserCD() >= LASER_ATTACK_TIME) {

							if (vessel_B.Value->getIsLaserHitSomething() == false)
								vessel_B.Value->strcatLaserLog("-> miss\r\n");
							else
								vessel_B.Value->strcatLaserLog("}\r\n");

							txtBattleLog->Text += vessel_B.Value->getLaserLog();

							vessel_B.Value->setIsLaserShooting(false);
							vessel_B.Value->setIsLaserHitSomething(false);
							vessel_B.Value->setLaserLog("");
						}
						#pragma endregion
					}
					#pragma endregion

					#pragma region geography detect
					int colorAlpha_A = 0;
					int colorAlpha_B = 0;

					for each (GeographicSystem^ geo in GeographicSystem::geoList) {
						txtBattleLog->Text += geo->detectAll(team_A, minute, second, colorAlpha_A);
						txtBattleLog->Text += geo->detectAll(team_B, minute, second, colorAlpha_B);

						geo->setColorAlpha(colorAlpha_A > colorAlpha_B ? colorAlpha_A : colorAlpha_B);
					}
					#pragma endregion

					#pragma region shells move
					for each(Shell^ shell_A in team_A->shellList) {
						shell_A->ShellMove();
						/*double dx = (shell_A->getGoalCoord().X - shell_A->getNowCoord().X);
						double dy = (shell_A->getGoalCoord().Y - shell_A->getNowCoord().Y);
						double dis = sqrt((dx * dx) + (dy * dy));

						shell_A->setNowCoord(PointF(shell_A->getNowCoord().X + shell_A->getSpeed() * (dx / dis), shell_A->getNowCoord().Y + shell_A->getSpeed() * (dy / dis)));
						shell_A->setNowCoord4Draw(COORD_TO_DRAWING_COORD(shell_A->getNowCoord().X, shell_A->getNowCoord().Y));*/
					}
					for each(Shell^ shell_B in team_B->shellList) {
						shell_B->ShellMove();
					}
					#pragma endregion
					#pragma region shells explode
					for (int j = 0; j < team_A->shellList.Count; j++) {
						if (team_A->shellList[j]->getNowFlyingTime() >= (int)Math::Round(team_A->shellList[j]->getTotalFlyingTime())) {

							shellExplode(team_A->shellList[j]);
							team_A->shellList.RemoveAt(j);
						}

						/*if (Math::Abs(team_A->shellList[j]->getNowCoord().X - team_A->shellList[j]->getGoalCoord().X) <= EPS && Math::Abs(team_A->shellList[j]->getNowCoord().Y - team_A->shellList[j]->getGoalCoord().Y) <= EPS) {

						shellExplode(team_A->shellList[j]);
						team_A->shellList.RemoveAt(j);
						}*/
					}
					for (int j = 0; j < team_B->shellList.Count; j++) {
						if (team_B->shellList[j]->getNowFlyingTime() >= (int)Math::Round(team_B->shellList[j]->getTotalFlyingTime())) {

							shellExplode(team_B->shellList[j]);
							team_B->shellList.RemoveAt(j);
						}

						/*if (Math::Abs(team_B->shellList[j]->getNowCoord().X - team_B->shellList[j]->getGoalCoord().X) <= EPS && Math::Abs(team_B->shellList[j]->getNowCoord().Y - team_B->shellList[j]->getGoalCoord().Y) <= EPS) {

						shellExplode(team_B->shellList[j]);
						team_B->shellList.RemoveAt(j);
						}*/
					}
					#pragma endregion
					#pragma region vessels destroy
					// remove the vessel whose hitpoint is under 0
					destroyVessels();
					#pragma endregion

					#pragma region torpedoes move and detect vessel
					List<Torpedo^> explodedTorpedo;

					explodedTorpedo.Clear();
					for each(Torpedo^ torpedo_A in team_A->torpedoList) {
						torpedo_A->TorpedoMove();

						VesselObject^ bombedVessel = gcnew VesselObject();
						double minDis = 100.0;

						for each (KeyValuePair<String^, VesselObject^>^ vessel_A in team_A->vesselList) {
							double dis2 = ((vessel_A->Value->getCoord().X - torpedo_A->getNowCoord().X) * (vessel_A->Value->getCoord().X - torpedo_A->getNowCoord().X)) + ((vessel_A->Value->getCoord().Y - torpedo_A->getNowCoord().Y) * (vessel_A->Value->getCoord().Y - torpedo_A->getNowCoord().Y));
							double dis = Math::Sqrt(dis2);

							if (dis2 <= TORPEDO_DAMAGE_RADIUS * TORPEDO_DAMAGE_RADIUS && vessel_A->Value->getName() != torpedo_A->getVesselName()) {
								if (dis < minDis) {
									minDis = dis;

									bombedVessel->setName(vessel_A->Value->getName());
									bombedVessel->setTeam(A);
								}
							}
						}
						for each (KeyValuePair<String^, VesselObject^>^ vessel_B in team_B->vesselList) {
							double dis2 = ((vessel_B->Value->getCoord().X - torpedo_A->getNowCoord().X) * (vessel_B->Value->getCoord().X - torpedo_A->getNowCoord().X)) + ((vessel_B->Value->getCoord().Y - torpedo_A->getNowCoord().Y) * (vessel_B->Value->getCoord().Y - torpedo_A->getNowCoord().Y));
							double dis = Math::Sqrt(dis2);

							if (dis2 <= TORPEDO_DAMAGE_RADIUS * TORPEDO_DAMAGE_RADIUS) {
								if (dis < minDis) {
									minDis = dis;

									bombedVessel->setName(vessel_B->Value->getName());
									bombedVessel->setTeam(B);
								}
							}
						}

						// a vessel is in the damage radius of torpedo
						if (bombedVessel->getTeam() == A || bombedVessel->getTeam() == B) {
							if (bombedVessel->getTeam() == A)
								team_A->vesselList[bombedVessel->getName()]->setRemainHp(team_A->vesselList[bombedVessel->getName()]->getRemainHp() - torpedo_A->getDamage());
							else
								team_B->vesselList[bombedVessel->getName()]->setRemainHp(team_B->vesselList[bombedVessel->getName()]->getRemainHp() - torpedo_A->getDamage());

							txtBattleLog->Text += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] TeamA " + torpedo_A->getName() + " exploded -> hit Team" + (bombedVessel->getTeam() == A ? "A " : "B ") + bombedVessel->getName() + "\r\n";
							explodedTorpedo.Add(torpedo_A);
						}
					}
					for each (Torpedo^ torpedo in explodedTorpedo)
						team_A->torpedoList.Remove(torpedo);

					explodedTorpedo.Clear();
					for each(Torpedo^ torpedo_B in team_B->torpedoList) {
						torpedo_B->TorpedoMove();

						VesselObject^ bombedVessel = gcnew VesselObject();
						double minDis = 100.0;

						for each (KeyValuePair<String^, VesselObject^>^ vessel_A in team_A->vesselList) {
							double dis2 = ((vessel_A->Value->getCoord().X - torpedo_B->getNowCoord().X) * (vessel_A->Value->getCoord().X - torpedo_B->getNowCoord().X)) + ((vessel_A->Value->getCoord().Y - torpedo_B->getNowCoord().Y) * (vessel_A->Value->getCoord().Y - torpedo_B->getNowCoord().Y));
							double dis = Math::Sqrt(dis2);

							if (dis2 <= TORPEDO_DAMAGE_RADIUS * TORPEDO_DAMAGE_RADIUS) {
								if (dis < minDis) {
									minDis = dis;

									bombedVessel->setName(vessel_A->Value->getName());
									bombedVessel->setTeam(A);
								}
							}
						}
						for each (KeyValuePair<String^, VesselObject^>^ vessel_B in team_B->vesselList) {
							double dis2 = ((vessel_B->Value->getCoord().X - torpedo_B->getNowCoord().X) * (vessel_B->Value->getCoord().X - torpedo_B->getNowCoord().X)) + ((vessel_B->Value->getCoord().Y - torpedo_B->getNowCoord().Y) * (vessel_B->Value->getCoord().Y - torpedo_B->getNowCoord().Y));
							double dis = Math::Sqrt(dis2);

							if (dis2 <= TORPEDO_DAMAGE_RADIUS * TORPEDO_DAMAGE_RADIUS && vessel_B->Value->getName() != torpedo_B->getVesselName()) {
								if (dis < minDis) {
									minDis = dis;

									bombedVessel->setName(vessel_B->Value->getName());
									bombedVessel->setTeam(B);
								}
							}
						}

						// a vessel is in the damage radius of torpedo
						if (bombedVessel->getTeam() == A || bombedVessel->getTeam() == B) {
							if (bombedVessel->getTeam() == A)
								team_A->vesselList[bombedVessel->getName()]->setRemainHp(team_A->vesselList[bombedVessel->getName()]->getRemainHp() - torpedo_B->getDamage());
							else
								team_B->vesselList[bombedVessel->getName()]->setRemainHp(team_B->vesselList[bombedVessel->getName()]->getRemainHp() - torpedo_B->getDamage());

							txtBattleLog->Text += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] TeamB " + torpedo_B->getName() + " exploded -> hit Team" + (bombedVessel->getTeam() == A ? "A " : "B ") + bombedVessel->getName() + "\r\n";
							explodedTorpedo.Add(torpedo_B);
						}
					}
					for each (Torpedo^ torpedo in explodedTorpedo)
						team_B->torpedoList.Remove(torpedo);

					#pragma endregion
					#pragma region torpedoes destroy
					for (int j = 0; j < team_A->torpedoList.Count; j++) {
						if (Math::Abs(team_A->torpedoList[j]->getNowCoord().X - team_A->torpedoList[j]->getGoalCoord().X) <= TORPEDO_EXPLODE_RANGE && Math::Abs(team_A->torpedoList[j]->getNowCoord().Y - team_A->torpedoList[j]->getGoalCoord().Y) <= TORPEDO_EXPLODE_RANGE) {
							txtBattleLog->Text += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] TeamA " + team_A->torpedoList[j]->getName() + " exploded -> miss\r\n";
							team_A->torpedoList.RemoveAt(j);
						}
					}
					for (int j = 0; j < team_B->torpedoList.Count; j++) {
						if (Math::Abs(team_B->torpedoList[j]->getNowCoord().X - team_B->torpedoList[j]->getGoalCoord().X) <= TORPEDO_EXPLODE_RANGE && Math::Abs(team_B->torpedoList[j]->getNowCoord().Y - team_B->torpedoList[j]->getGoalCoord().Y) <= TORPEDO_EXPLODE_RANGE) {
							txtBattleLog->Text += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] TeamB " + team_B->torpedoList[j]->getName() + " exploded -> miss\r\n";
							team_B->torpedoList.RemoveAt(j);
						}
					}
					#pragma endregion
					#pragma region vessels destroy
					// remove the vessel whose hitpoint is under 0
					destroyVessels();
					#pragma endregion

					#pragma region laser damage

					for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {

						if (vessel_A.Value->getIsLaserShooting()) {
							if (vessel_A.Value->getLaserLog() == "")
								vessel_A.Value->setLaserLog("[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (vessel_A.Value->getTeam() == A ? "A" : "B") + " " + vessel_A.Value->getName() + " use LASER ");

							if (laserAttack(vessel_A.Value))
								vessel_A.Value->setIsLaserHitSomething(true);
						}
					}
					for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {

						if (vessel_B.Value->getIsLaserShooting()) {
							if (vessel_B.Value->getLaserLog() == "")
								vessel_B.Value->setLaserLog("[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (vessel_B.Value->getTeam() == A ? "A" : "B") + " " + vessel_B.Value->getName() + " use LASER ");

							if (laserAttack(vessel_B.Value))
								vessel_B.Value->setIsLaserHitSomething(true);
						}
					}
					#pragma endregion
					#pragma region vessels destroy
					// remove the vessel whose hitpoint is under 0
					destroyVessels();
					#pragma endregion

					#pragma region vessels move
					for each (KeyValuePair<String^, VesselObject^>^ vessel_A in team_A->vesselList) {
						if (vessel_A->Value != nullptr && vessel_A->Value->getNowSpeed() != 0.0 && vessel_A->Value->getRemainHp() > 0.0) {

							for each (HydrometeorologicSystem^ hydro in HydrometeorologicSystem::hydroList) {
								fogEffect(hydro);
							}

							if (isCollapsed(vessel_A->Value) || vessel_A->Value->getCanMove() == false) {
								vessel_A->Value->setNowSpeed(0.0);
								vessel_A->Value->setNowAngle(0.0);
							}

							vessel_A->Value->VesselMove();
						}
					}
					for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
						if (vessel_B.Value != nullptr && vessel_B.Value->getNowSpeed() != 0.0 && vessel_B.Value->getRemainHp() > 0.0) {

							for each (HydrometeorologicSystem^ hydro in HydrometeorologicSystem::hydroList) {
								fogEffect(hydro);
							}

							if (isCollapsed(vessel_B.Value) || vessel_B.Value->getCanMove() == false) {
								vessel_B.Value->setNowSpeed(0.0);
								vessel_B.Value->setNowAngle(0.0);
							}

							//Debug::WriteLine("canMove: " + vessel_B.Value->getCanMove());

							vessel_B.Value->VesselMove();
						}
					}
					#pragma endregion
					#pragma region vessels destroy
					// remove the vessel whose hitpoint is under 0
					destroyVessels();
					#pragma endregion
				}

				else if (playMode == 1) {

					if (shootDanmaku(danmakuLevel, minute + 1) == false) {
						danmakuLevel = 1;
						initialize();
					}

					if (danmakuLevel == minute) {
						danmakuLevel++;
						txtBattleLog->Text += "Level " + danmakuLevel.ToString("00") + "\r\n";
					}
					
					lblShowDanmakuHitNum->Text = "  Level " + danmakuLevel.ToString("00") + "\r\nHit num: " + danmakuHitNum.ToString("000");

					#pragma region torpedoes move and detect vessel
					List<Torpedo^> explodedTorpedo;

					explodedTorpedo.Clear();
					for each(Torpedo^ torpedo_B in team_B->torpedoList) {
						torpedo_B->TorpedoMove();
						torpedo_B->setNowFlyingTime(torpedo_B->getNowFlyingTime() + 1);

						VesselObject^ bombedVessel = gcnew VesselObject();
						double minDis = 100.0;

						for each (KeyValuePair<String^, VesselObject^>^ vessel_A in team_A->vesselList) {
							double dis2 = ((vessel_A->Value->getCoord().X - torpedo_B->getNowCoord().X) * (vessel_A->Value->getCoord().X - torpedo_B->getNowCoord().X)) + ((vessel_A->Value->getCoord().Y - torpedo_B->getNowCoord().Y) * (vessel_A->Value->getCoord().Y - torpedo_B->getNowCoord().Y));
							double dis = Math::Sqrt(dis2);

							if (dis2 <= 0.6 * 0.6) {
								if (dis < minDis) {
									minDis = dis;

									bombedVessel->setName(vessel_A->Value->getName());
									bombedVessel->setTeam(A);
								}
							}
						}

						// a vessel is in the damage radius of torpedo
						if (bombedVessel->getTeam() == A || bombedVessel->getTeam() == B) {
							if (bombedVessel->getTeam() == A)
								team_A->vesselList[bombedVessel->getName()]->setRemainHp(team_A->vesselList[bombedVessel->getName()]->getRemainHp() - torpedo_B->getDamage());
							else
								team_B->vesselList[bombedVessel->getName()]->setRemainHp(team_B->vesselList[bombedVessel->getName()]->getRemainHp() - torpedo_B->getDamage());

							danmakuHitNum++;

							txtBattleLog->Text += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] TeamB " + torpedo_B->getName() + " exploded -> hit Team" + (bombedVessel->getTeam() == A ? "A " : "B ") + bombedVessel->getName() + "\r\n";
							explodedTorpedo.Add(torpedo_B);
						}
					}
					for each (Torpedo^ torpedo in explodedTorpedo)
						team_B->torpedoList.Remove(torpedo);

					#pragma endregion
					#pragma region torpedoes destroy
					for (int j = 0; j < team_B->torpedoList.Count; j++) {
						if (team_B->torpedoList[j]->getNowFlyingTime() >= (int)Math::Round(team_B->torpedoList[j]->getTotalFlyingTime())) {
							team_B->torpedoList.RemoveAt(j);
						}
					}
					#pragma endregion
					#pragma region vessels destroy
					// remove the vessel whose hitpoint is under 0
					//destroyVessels();
					#pragma endregion
				}
			}
			catch (...) {}


			lblNowTime->Text = minute.ToString("00") + ":" + second.ToString("00");

			this->Refresh();
		}
		
		// btnStart : click
		System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {

			try {
				txtCommand_A->Enabled = false; txtCommand_B->Enabled = false;
				btnStart->Enabled = false; btnPause->Enabled = true; btnNextSecond->Enabled = false;
				btnTyphoon->Enabled = true; btnLightning->Enabled = true; btnFog->Enabled = true;
				btnNewGeo->Enabled = false;

				array<String^>^ cmdList;

				// analyze commands of team A
				cmdList = txtCommand_A->Text->Split('\n');
				for each (String^ cmdString in cmdList) {
					if (cmdString == "")
						continue;

					txtBattleLog->Text += processCommand(minute, second, cmdString, team_A, team_B);
				}

				// analyze commands of team B
				cmdList = txtCommand_B->Text->Split('\n');
				for each (String^ cmdString in cmdList) {
					if (cmdString == "")
						continue;

					txtBattleLog->Text += processCommand(minute, second, cmdString, team_B, team_A);
				}

				txtCommand_A->Text = ""; txtCommand_B->Text = "";
				timerMain->Enabled = true;
			}
			catch (...) {}
		}

		// btnPause : click
		System::Void btnPause_Click(System::Object^  sender, System::EventArgs^  e) {

			try {
				txtCommand_A->Enabled = true; txtCommand_B->Enabled = true; btnNextSecond->Enabled = true;
				btnStart->Enabled = true; btnPause->Enabled = false;
				timerMain->Enabled = false;
				btnTyphoon->Enabled = false; btnLightning->Enabled = false; btnFog->Enabled = false;
				btnNewGeo->Enabled = true;
			}
			catch (...) {}
		}

		// btnNextSecond : click
		System::Void btnNextSecond_Click(System::Object^  sender, System::EventArgs^  e) {
			array<String^>^ cmdList;

			// analyze commands of team A
			cmdList = txtCommand_A->Text->Split('\n');
			for each (String^ cmdString in cmdList) {
				if (cmdString == "")
					continue;

				txtBattleLog->Text += processCommand(minute, second, cmdString, team_A, team_B);
			}

			// analyze commands of team B
			cmdList = txtCommand_B->Text->Split('\n');
			for each (String^ cmdString in cmdList) {
				if (cmdString == "")
					continue;

				txtBattleLog->Text += processCommand(minute, second, cmdString, team_B, team_A);
			}

			txtCommand_A->Text = ""; txtCommand_B->Text = "";

			timerMain_Tick(gcnew Object(), gcnew EventArgs());
		}

		#pragma region New Hydrometeorology
		// btnTyphoon : click
		System::Void btnTyphoon_Click(System::Object^  sender, System::EventArgs^  e) {
			Random^ r = gcnew Random(DateTime::Now.Millisecond);

			double angle = r->NextDouble() * 180.0;
			int enterSide = r->Next(4);
			double onePoint = r->NextDouble() * BOARD_SIZE;
			double start0 = -1.0;
			double start20 = 20.0;
			PointF loc;

			String^ newLog = "";

			// left side
			if (enterSide == 0) {
				loc = PointF(start0, onePoint);
				angle -= 90.0;
			}

			// up side
			else if (enterSide == 1) {
				loc = PointF(onePoint, start0);
				angle += 180.0;
			}

			// right side
			else if (enterSide == 2) {
				loc = PointF(start20, onePoint);
				angle += 90.0;
			}

			// down side
			else {
				loc = PointF(onePoint, start20);
			}

			Typhoon^ newTyphoon = gcnew Typhoon(angle, loc);
			HydrometeorologicSystem::hydroList.Add(newTyphoon);

			if (typhoonLog) {
				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] a typhoon genesis D:\r\n";
				txtBattleLog->Text += newLog;
			}
		}

		// btnLightning : click
		System::Void btnLightning_Click(System::Object^  sender, System::EventArgs^  e) {
			Random^ r = gcnew Random(DateTime::Now.Millisecond);
			PointF loc = PointF(r->NextDouble() * BOARD_SIZE, r->NextDouble() * BOARD_SIZE);
			Lightning^ newLightning = gcnew Lightning(loc);
			String^ newLog = "";

			HydrometeorologicSystem::hydroList.Add(newLightning);

			#pragma region lightning attack
			for each (KeyValuePair<String^, VesselObject^>^ vessel_A in team_A->vesselList) {
				double dis2 = ((vessel_A->Value->getCoord().X - newLightning->getNowCoord().X) * (vessel_A->Value->getCoord().X - newLightning->getNowCoord().X)) + ((vessel_A->Value->getCoord().Y - newLightning->getNowCoord().Y) * (vessel_A->Value->getCoord().Y - newLightning->getNowCoord().Y));
				double dis = Math::Sqrt(dis2);

				if (dis2 <= newLightning->getAttackRange() * newLightning->getAttackRange()) {
					vessel_A->Value->setRemainHp(vessel_A->Value->getRemainHp() - newLightning->getDamage());
					newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] TeamA " + vessel_A->Value->getName() + " attacked by lighting\r\n";
					txtBattleLog->Text += newLog;
				}
			}
			for each (KeyValuePair<String^, VesselObject^>^ vessel_B in team_B->vesselList) {
				double dis2 = ((vessel_B->Value->getCoord().X - newLightning->getNowCoord().X) * (vessel_B->Value->getCoord().X - newLightning->getNowCoord().X)) + ((vessel_B->Value->getCoord().Y - newLightning->getNowCoord().Y) * (vessel_B->Value->getCoord().Y - newLightning->getNowCoord().Y));
				double dis = Math::Sqrt(dis2);

				if (dis2 <= newLightning->getAttackRange() * newLightning->getAttackRange()) {
					vessel_B->Value->setRemainHp(vessel_B->Value->getRemainHp() - newLightning->getDamage());
					newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] TeamB " + vessel_B->Value->getName() + " attacked by lighting\r\n";
					txtBattleLog->Text += newLog;
				}
			}
			#pragma endregion

			if (lightningLog) {
				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] a lightning appears D:\r\n";
				txtBattleLog->Text += newLog;
			}
		}

		// btnFog : click
		System::Void btnFog_Click(System::Object^  sender, System::EventArgs^  e) {
			Random^ r = gcnew Random(DateTime::Now.Millisecond);
			Fog^ newFog = gcnew Fog();
			String^ newLog = "";

			HydrometeorologicSystem::hydroList.Add(newFog);

			if (fogLog) {
				newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] an area is in the mist D:\r\n";
				txtBattleLog->Text += newLog;
			}
		}
		#pragma endregion

		#pragma region New Geography
		// btnNewGeo : click
		System::Void btnNewGeo_Click(System::Object^  sender, System::EventArgs^  e) {
			tckGeoX->Value = 0; tckGeoY->Value = 0; tckGeoWidth->Value = 0; tckGeoHeight->Value = 0;
			cbbGeoType->SelectedIndex = -1;
			grpNewGeo->Visible = true; btnNewGeo->Enabled = false; btnStart->Enabled = false; btnPause->Enabled = false;
			btnNewGeoConfirm->Enabled = false; btnNewGeoCancel->Enabled = true;

			recNewGeoGraph->Location = PointF(BIAS_X, BIAS_Y);
			recNewGeoGraph->Size = SizeF();

			btnNewGeoConfirm->Enabled = isNewGeoLegal();
		}

		// btnNewGeoConfirm : click
		System::Void btnNewGeoConfirm_Click(System::Object^  sender, System::EventArgs^  e) {
			grpNewGeo->Visible = false; btnNewGeo->Enabled = true; btnStart->Enabled = true; btnPause->Enabled = false;
			lblMsg4AddingNewGeo->Text = "";

			Reef^ newReef;
			Flatland^ newFlatland;
			Mountain^ newMountain;

			switch (cbbGeoType->SelectedIndex) {
				case 0:
					newReef = gcnew Reef(DRAWING_COORD_TO_COORD(recNewGeoGraph->X, recNewGeoGraph->Y), SizeF(recNewGeoGraph->Width / BLOCK_LENGTH, recNewGeoGraph->Height / BLOCK_LENGTH));
					GeographicSystem::geoList.Add(newReef);
					break;
				case 1:
					newFlatland = gcnew Flatland(DRAWING_COORD_TO_COORD(recNewGeoGraph->X, recNewGeoGraph->Y), SizeF(recNewGeoGraph->Width / BLOCK_LENGTH, recNewGeoGraph->Height / BLOCK_LENGTH));
					GeographicSystem::geoList.Add(newFlatland);
					break;
				case 2:
					newMountain = gcnew Mountain(DRAWING_COORD_TO_COORD(recNewGeoGraph->X, recNewGeoGraph->Y), SizeF(recNewGeoGraph->Width / BLOCK_LENGTH, recNewGeoGraph->Height / BLOCK_LENGTH));
					GeographicSystem::geoList.Add(newMountain);
					break;
			}

			recNewGeoGraph->Size = SizeF(); this->Refresh();

			String^ newLog = "[" + minute.ToString("00") + ":" + second.ToString("00") + "] a new geographic area added :D\r\n";
			txtBattleLog->Text += newLog;
		}

		// btnNewGeoCancel : click
		System::Void btnNewGeoCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			grpNewGeo->Visible = false; btnNewGeo->Enabled = true; btnStart->Enabled = true; btnPause->Enabled = false;
			lblMsg4AddingNewGeo->Text = "";

			recNewGeoGraph->Size = SizeF(); this->Refresh();
		}

		// cbbGeoType : SelectedIndexChanged
		System::Void cbbGeoType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			btnNewGeoConfirm->Enabled = isNewGeoLegal();
			this->Refresh();
		}

		// tckGeoX : ValueChanged
		System::Void tckGeoX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			double x4Draw = COORD_TO_DRAWING_COORD(((double)tckGeoX->Value * 0.2), 0.0).X;
			recNewGeoGraph->X = x4Draw;

			btnNewGeoConfirm->Enabled = isNewGeoLegal();
			this->Refresh();
		}

		// tckGeoY : ValueChanged
		System::Void tckGeoY_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			double y4Draw = COORD_TO_DRAWING_COORD(0.0, ((double)tckGeoY->Value * 0.2)).Y;
			recNewGeoGraph->Y = y4Draw;

			btnNewGeoConfirm->Enabled = isNewGeoLegal();
			this->Refresh();
		}

		// tckGeoWidth : ValueChanged
		System::Void tckGeoWidth_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			double width4Draw = ((double)tckGeoWidth->Value * 0.2) * BLOCK_LENGTH;
			recNewGeoGraph->Width = width4Draw;

			btnNewGeoConfirm->Enabled = isNewGeoLegal();
			this->Refresh();
		}

		// tckGeoHeight : ValueChanged
		System::Void tckGeoHeight_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			double height4Draw = ((double)tckGeoHeight->Value * 0.2) * BLOCK_LENGTH;
			recNewGeoGraph->Height = height4Draw;

			btnNewGeoConfirm->Enabled = isNewGeoLegal();
			this->Refresh();
		}
		#pragma endregion

		// btnBackToMenu : click (End of game, return to menu)
		System::Void btnBackToMenu_Click(System::Object^  sender, System::EventArgs^  e) {
			if (MessageBox::Show("Are you sure you want to end the game?", "Bye bye", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Forms::DialogResult::Yes) {
				initialize();
			}
		}

		void initialize() {

			lblShowDanmakuHitNum->Text = "";
			lblShowDanmakuHitNum->Visible = false;
			danmakuLevel = 1;
			danmakuHitNum = 0;

			pnlMenuPage->Visible = true;
			pnlSettingPage->Visible = false;
			pnlGamePage->Visible = false;

			grpNewGeo->Visible = false; btnNewGeo->Enabled = true; btnStart->Enabled = true; btnPause->Enabled = false;
			lblMsg4AddingNewGeo->Text = "";

			recNewGeoGraph->Size = SizeF();

			btnNewGeoCancelInSetting->Enabled = true;
			btnNewGeoConfirmInSetting->Enabled = false;

			chckIsUseTyphoon->Checked = false;
			chckIsUseLightning->Checked = false;
			chckIsUseFog->Checked = false;

			chckIsLogTyphoon->Checked = false;
			chckIsLogLightning->Checked = false;
			chckIsLogFog->Checked = false;

			chckIsLogTyphoon->Visible = false;
			chckIsLogLightning->Visible = false;
			chckIsLogFog->Visible = false;

			recNewGeoGraph->Location = PointF(BIAS_X, BIAS_Y);
			recNewGeoGraph->Size = SizeF();

			lblMsg4AddingNewGeoInSetting->ForeColor = Color::Red;
			lblMsg4AddingNewGeoInSetting->Text = "Please select a type";

			cbbNewGeoTypeInSetting->SelectedIndex = -1;
			tckGeoXInSetting->Value = 0;
			tckGeoYInSetting->Value = 0;
			tckGeoWidthInSetting->Value = 0;
			tckGeoHeightInSetting->Value = 0;

			txtBattleLog->Text = "";
			txtCommand_A->Text = ""; txtCommand_B->Text = "";
			txtCommand_A->Enabled = true; txtCommand_B->Enabled = true;
			minute = 0; second = 0;

			GeographicSystem::geoList.Clear();
			HydrometeorologicSystem::hydroList.Clear();
			team_A->vesselList.Clear();
			team_A->shellList.Clear();
			team_A->torpedoList.Clear();
			team_B->vesselList.Clear();
			team_B->shellList.Clear();
			team_B->torpedoList.Clear();

			team_A->setLauchedShellNum(0);
			team_B->setLauchedShellNum(0);
			team_A->setLaunchedTorpedoNum(0);
			team_B->setLaunchedTorpedoNum(0);

			minute = second = 0;
			lblNowTime->Text = "00:00";
			timerMain->Enabled = false;
		}

		// picboard : paint
		System::Void picBoard_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

			try {
				Graphics^ g = e->Graphics;

				// The start point is (10, 10), the length of board is 400
				// That is, the end point is (410, 410)

				printBoard(g);

				#pragma region geography render
				for each (GeographicSystem^ geo in GeographicSystem::geoList) {
					//Debug::WriteLine("coord: " + geo->getCoord4Draw() + " | size: " + geo->getSize4Draw());
					geo->render(g);
				}

				#pragma region Draw virutal(undefined) geograpgy rectangle
				if (grpNewGeo->Visible == true && cbbGeoType->SelectedIndex >= 0) {

					Color newClr;
					switch (cbbGeoType->SelectedIndex) {
						case 0: newClr = Color::FromArgb(VIRTUAL_GEO_ALPHA, 100, 100, 100); break;
						case 1: newClr = Color::FromArgb(VIRTUAL_GEO_ALPHA, 23, 100, 14); break;
						case 2: newClr = Color::FromArgb(VIRTUAL_GEO_ALPHA, 45, 45, 245); break;
					}

					g->FillRectangle(gcnew SolidBrush(newClr), RectangleF(recNewGeoGraph->X, recNewGeoGraph->Y, recNewGeoGraph->Width, recNewGeoGraph->Height));
				}
				#pragma endregion
				#pragma endregion

				printBlockLines(g);

				#pragma region laser render
				for each (KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList) {
					if (vessel_A.Value->getIsLaserShooting()) {
						vessel_A.Value->DrawLaser(g);
					}
				}
				for each (KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList) {
					if (vessel_B.Value->getIsLaserShooting()) {
						vessel_B.Value->DrawLaser(g);
					}
				}
				#pragma endregion

				#pragma region vessel render
				for each(KeyValuePair<String^, VesselObject^> vessel_A in team_A->vesselList)
					vessel_A.Value->render(g);
				for each(KeyValuePair<String^, VesselObject^> vessel_B in team_B->vesselList)
					vessel_B.Value->render(g);
				#pragma endregion

				#pragma region shell render
				for each(Shell^ shell_A in team_A->shellList)
					shell_A->render(g);
				for each(Shell^ shell_B in team_B->shellList)
					shell_B->render(g);
				#pragma endregion

				#pragma region torpedo render
				for each (Torpedo^ torpedo_A in team_A->torpedoList)
					torpedo_A->render(g);
				for each (Torpedo^ torpedo_B in team_B->torpedoList)
					torpedo_B->render(g);
				#pragma endregion

				#pragma region hydrometeorology render
				for each (HydrometeorologicSystem^ hydro in HydrometeorologicSystem::hydroList) {
					hydro->render(g);
				}
				#pragma endregion

			}
			catch (...) {}
		}
		#pragma endregion
		/* =========================================================================================================== */
};
}