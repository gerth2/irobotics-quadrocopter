#pragma once
#include "Header.h"
namespace Quadrocopter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  TabControl;
	protected: 
	private: System::Windows::Forms::TabPage^  TiltPID;
	private: System::Windows::Forms::TabPage^  YawPID;
	private: System::Windows::Forms::TabPage^  AltitudePID;
	private: System::Windows::Forms::TabPage^  Monitoring;
	private: System::Windows::Forms::Label^  TiltLabel;

	private: System::Windows::Forms::TextBox^  TiltTextBox;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TabPage^  Settings;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Panel^  panel3;









	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::TextBox^  textBox25;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::TextBox^  textBox26;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::TextBox^  textBox27;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::TextBox^  textBox28;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::TextBox^  textBox29;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::TextBox^  textBox30;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::TextBox^  textBox31;
	private: System::Windows::Forms::Label^  label48;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::TextBox^  textBox40;
	private: System::Windows::Forms::TextBox^  textBox32;
	private: System::Windows::Forms::TextBox^  textBox33;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::TextBox^  textBox34;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::TextBox^  textBox35;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::TextBox^  textBox36;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::TextBox^  textBox37;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::TextBox^  textBox38;
	private: System::Windows::Forms::Label^  label46;
	private: System::Windows::Forms::TextBox^  textBox39;
	private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::TabPage^  tabPage1;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Panel^  panel10;
private: System::Windows::Forms::Button^  button10;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::Panel^  panel9;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::StatusStrip^  statusStrip1;
private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  newPIDToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  loadPIDToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  savePIDToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  quitToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  controlToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  runPIDToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  runManualToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kILLToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  tellAJokeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
private: System::Windows::Forms::Button^  button12;
private: System::Windows::Forms::ToolStripMenuItem^  clearTerminalToolStripMenuItem;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::Button^  button13;
private: System::Windows::Forms::Button^  button14;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
private: System::Windows::Forms::Button^  codetestbutton;
private: System::Windows::Forms::ToolStripMenuItem^  setupComportsToolStripMenuItem;



private: 



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->TabControl = (gcnew System::Windows::Forms::TabControl());
			this->Settings = (gcnew System::Windows::Forms::TabPage());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->TiltPID = (gcnew System::Windows::Forms::TabPage());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->YawPID = (gcnew System::Windows::Forms::TabPage());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->AltitudePID = (gcnew System::Windows::Forms::TabPage());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->textBox40 = (gcnew System::Windows::Forms::TextBox());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->textBox34 = (gcnew System::Windows::Forms::TextBox());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->textBox35 = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->textBox36 = (gcnew System::Windows::Forms::TextBox());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->textBox38 = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->textBox39 = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->Monitoring = (gcnew System::Windows::Forms::TabPage());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TiltTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TiltLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->codetestbutton = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newPIDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadPIDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->savePIDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->controlToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runPIDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runManualToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearTerminalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kILLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tellAJokeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->setupComportsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TabControl->SuspendLayout();
			this->Settings->SuspendLayout();
			this->TiltPID->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->YawPID->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->AltitudePID->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->Monitoring->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel9->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// TabControl
			// 
			this->TabControl->Controls->Add(this->Settings);
			this->TabControl->Controls->Add(this->TiltPID);
			this->TabControl->Controls->Add(this->YawPID);
			this->TabControl->Controls->Add(this->AltitudePID);
			this->TabControl->Controls->Add(this->Monitoring);
			this->TabControl->Controls->Add(this->tabPage1);
			this->TabControl->Location = System::Drawing::Point(12, 35);
			this->TabControl->Name = L"TabControl";
			this->TabControl->SelectedIndex = 0;
			this->TabControl->Size = System::Drawing::Size(494, 418);
			this->TabControl->TabIndex = 0;
			// 
			// Settings
			// 
			this->Settings->Controls->Add(this->button13);
			this->Settings->Controls->Add(this->button3);
			this->Settings->Controls->Add(this->button2);
			this->Settings->Controls->Add(this->button1);
			this->Settings->Location = System::Drawing::Point(4, 22);
			this->Settings->Name = L"Settings";
			this->Settings->Padding = System::Windows::Forms::Padding(3);
			this->Settings->Size = System::Drawing::Size(486, 392);
			this->Settings->TabIndex = 4;
			this->Settings->Text = L"Settings";
			this->Settings->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button13->Location = System::Drawing::Point(243, 363);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(75, 23);
			this->button13->TabIndex = 3;
			this->button13->Text = L"Cancel";
			this->button13->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Red;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button3->Font = (gcnew System::Drawing::Font(L"Dutch801 XBd BT", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Yellow;
			this->button3->Location = System::Drawing::Point(6, 263);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(98, 123);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Yellow;
			this->button2->Location = System::Drawing::Point(324, 363);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Run Manual";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(405, 363);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Run PID Control";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// TiltPID
			// 
			this->TiltPID->Controls->Add(this->label25);
			this->TiltPID->Controls->Add(this->label14);
			this->TiltPID->Controls->Add(this->panel4);
			this->TiltPID->Controls->Add(this->panel3);
			this->TiltPID->Location = System::Drawing::Point(4, 22);
			this->TiltPID->Name = L"TiltPID";
			this->TiltPID->Padding = System::Windows::Forms::Padding(3);
			this->TiltPID->Size = System::Drawing::Size(486, 392);
			this->TiltPID->TabIndex = 0;
			this->TiltPID->Text = L"Tilt PID";
			this->TiltPID->UseVisualStyleBackColor = true;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(6, 3);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(67, 13);
			this->label25->TabIndex = 22;
			this->label25->Text = L"PID weights:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(191, 3);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(57, 13);
			this->label14->TabIndex = 10;
			this->label14->Text = L"Reactivity:";
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->textBox22);
			this->panel4->Controls->Add(this->label29);
			this->panel4->Controls->Add(this->label26);
			this->panel4->Controls->Add(this->textBox25);
			this->panel4->Controls->Add(this->textBox23);
			this->panel4->Controls->Add(this->label28);
			this->panel4->Controls->Add(this->label27);
			this->panel4->Controls->Add(this->textBox24);
			this->panel4->Location = System::Drawing::Point(9, 19);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(179, 136);
			this->panel4->TabIndex = 21;
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(76, 81);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(98, 20);
			this->textBox22->TabIndex = 30;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(3, 6);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(67, 13);
			this->label29->TabIndex = 23;
			this->label29->Text = L"Maximum tilt:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(3, 84);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(52, 13);
			this->label26->TabIndex = 29;
			this->label26->Text = L"D weight:";
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(76, 3);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(98, 20);
			this->textBox25->TabIndex = 24;
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(76, 55);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(98, 20);
			this->textBox23->TabIndex = 28;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(3, 32);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(51, 13);
			this->label28->TabIndex = 25;
			this->label28->Text = L"P weight:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(3, 58);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(47, 13);
			this->label27->TabIndex = 27;
			this->label27->Text = L"I weight:";
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(76, 29);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(98, 20);
			this->textBox24->TabIndex = 26;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->textBox21);
			this->panel3->Controls->Add(this->label24);
			this->panel3->Controls->Add(this->textBox20);
			this->panel3->Controls->Add(this->label23);
			this->panel3->Controls->Add(this->textBox19);
			this->panel3->Controls->Add(this->label22);
			this->panel3->Controls->Add(this->textBox18);
			this->panel3->Controls->Add(this->label21);
			this->panel3->Controls->Add(this->textBox13);
			this->panel3->Controls->Add(this->label20);
			this->panel3->Location = System::Drawing::Point(194, 19);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(179, 136);
			this->panel3->TabIndex = 9;
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(57, 107);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(112, 20);
			this->textBox21->TabIndex = 20;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(2, 110);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(37, 13);
			this->label24->TabIndex = 19;
			this->label24->Text = L"Cubic:";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(57, 81);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(112, 20);
			this->textBox20->TabIndex = 18;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(2, 84);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(56, 13);
			this->label23->TabIndex = 17;
			this->label23->Text = L"Quadratic:";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(57, 55);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(112, 20);
			this->textBox19->TabIndex = 16;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(2, 58);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(39, 13);
			this->label22->TabIndex = 15;
			this->label22->Text = L"Linear:";
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(57, 29);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(112, 20);
			this->textBox18->TabIndex = 14;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(2, 32);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(52, 13);
			this->label21->TabIndex = 13;
			this->label21->Text = L"Constant:";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(57, 3);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(112, 20);
			this->textBox13->TabIndex = 12;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(2, 6);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(45, 13);
			this->label20->TabIndex = 11;
			this->label20->Text = L"Degree:";
			// 
			// YawPID
			// 
			this->YawPID->Controls->Add(this->label10);
			this->YawPID->Controls->Add(this->label11);
			this->YawPID->Controls->Add(this->panel5);
			this->YawPID->Controls->Add(this->panel6);
			this->YawPID->Location = System::Drawing::Point(4, 22);
			this->YawPID->Name = L"YawPID";
			this->YawPID->Padding = System::Windows::Forms::Padding(3);
			this->YawPID->Size = System::Drawing::Size(486, 392);
			this->YawPID->TabIndex = 1;
			this->YawPID->Text = L"Yaw PID";
			this->YawPID->UseVisualStyleBackColor = true;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 6);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(67, 13);
			this->label10->TabIndex = 30;
			this->label10->Text = L"PID weights:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(191, 6);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 13);
			this->label11->TabIndex = 28;
			this->label11->Text = L"Reactivity:";
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->textBox9);
			this->panel5->Controls->Add(this->label12);
			this->panel5->Controls->Add(this->label13);
			this->panel5->Controls->Add(this->textBox10);
			this->panel5->Controls->Add(this->textBox11);
			this->panel5->Controls->Add(this->label30);
			this->panel5->Controls->Add(this->label31);
			this->panel5->Controls->Add(this->textBox12);
			this->panel5->Location = System::Drawing::Point(9, 22);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(179, 136);
			this->panel5->TabIndex = 29;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(76, 81);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(98, 20);
			this->textBox9->TabIndex = 30;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(3, 6);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(52, 13);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Max yaw:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 84);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(52, 13);
			this->label13->TabIndex = 29;
			this->label13->Text = L"D weight:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(76, 3);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(98, 20);
			this->textBox10->TabIndex = 24;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(76, 55);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(98, 20);
			this->textBox11->TabIndex = 28;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(3, 32);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(51, 13);
			this->label30->TabIndex = 25;
			this->label30->Text = L"P weight:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(3, 58);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(47, 13);
			this->label31->TabIndex = 27;
			this->label31->Text = L"I weight:";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(76, 29);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(98, 20);
			this->textBox12->TabIndex = 26;
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->textBox26);
			this->panel6->Controls->Add(this->label32);
			this->panel6->Controls->Add(this->textBox27);
			this->panel6->Controls->Add(this->label33);
			this->panel6->Controls->Add(this->textBox28);
			this->panel6->Controls->Add(this->label34);
			this->panel6->Controls->Add(this->textBox29);
			this->panel6->Controls->Add(this->label35);
			this->panel6->Controls->Add(this->textBox30);
			this->panel6->Controls->Add(this->label36);
			this->panel6->Location = System::Drawing::Point(194, 22);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(179, 136);
			this->panel6->TabIndex = 27;
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(57, 107);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(112, 20);
			this->textBox26->TabIndex = 20;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(2, 110);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(37, 13);
			this->label32->TabIndex = 19;
			this->label32->Text = L"Cubic:";
			// 
			// textBox27
			// 
			this->textBox27->Location = System::Drawing::Point(57, 81);
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(112, 20);
			this->textBox27->TabIndex = 18;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(2, 84);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(56, 13);
			this->label33->TabIndex = 17;
			this->label33->Text = L"Quadratic:";
			// 
			// textBox28
			// 
			this->textBox28->Location = System::Drawing::Point(57, 55);
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(112, 20);
			this->textBox28->TabIndex = 16;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(2, 58);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(39, 13);
			this->label34->TabIndex = 15;
			this->label34->Text = L"Linear:";
			// 
			// textBox29
			// 
			this->textBox29->Location = System::Drawing::Point(57, 29);
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(112, 20);
			this->textBox29->TabIndex = 14;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(2, 32);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(52, 13);
			this->label35->TabIndex = 13;
			this->label35->Text = L"Constant:";
			// 
			// textBox30
			// 
			this->textBox30->Location = System::Drawing::Point(57, 3);
			this->textBox30->Name = L"textBox30";
			this->textBox30->Size = System::Drawing::Size(112, 20);
			this->textBox30->TabIndex = 12;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(2, 6);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(45, 13);
			this->label36->TabIndex = 11;
			this->label36->Text = L"Degree:";
			// 
			// AltitudePID
			// 
			this->AltitudePID->Controls->Add(this->label37);
			this->AltitudePID->Controls->Add(this->label38);
			this->AltitudePID->Controls->Add(this->panel7);
			this->AltitudePID->Controls->Add(this->panel8);
			this->AltitudePID->Location = System::Drawing::Point(4, 22);
			this->AltitudePID->Name = L"AltitudePID";
			this->AltitudePID->Padding = System::Windows::Forms::Padding(3);
			this->AltitudePID->Size = System::Drawing::Size(486, 392);
			this->AltitudePID->TabIndex = 2;
			this->AltitudePID->Text = L"Altitude PID";
			this->AltitudePID->UseVisualStyleBackColor = true;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(6, 3);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(67, 13);
			this->label37->TabIndex = 30;
			this->label37->Text = L"PID weights:";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(191, 3);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(57, 13);
			this->label38->TabIndex = 28;
			this->label38->Text = L"Reactivity:";
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->textBox31);
			this->panel7->Controls->Add(this->label48);
			this->panel7->Controls->Add(this->label39);
			this->panel7->Controls->Add(this->label40);
			this->panel7->Controls->Add(this->textBox40);
			this->panel7->Controls->Add(this->textBox32);
			this->panel7->Controls->Add(this->textBox33);
			this->panel7->Controls->Add(this->label41);
			this->panel7->Controls->Add(this->label42);
			this->panel7->Controls->Add(this->textBox34);
			this->panel7->Location = System::Drawing::Point(9, 19);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(179, 136);
			this->panel7->TabIndex = 29;
			// 
			// textBox31
			// 
			this->textBox31->Location = System::Drawing::Point(76, 107);
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(98, 20);
			this->textBox31->TabIndex = 30;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(3, 32);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(66, 13);
			this->label48->TabIndex = 23;
			this->label48->Text = L"Base height:";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(3, 6);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(42, 13);
			this->label39->TabIndex = 23;
			this->label39->Text = L"Range:";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(3, 110);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(52, 13);
			this->label40->TabIndex = 29;
			this->label40->Text = L"D weight:";
			// 
			// textBox40
			// 
			this->textBox40->Location = System::Drawing::Point(76, 29);
			this->textBox40->Name = L"textBox40";
			this->textBox40->Size = System::Drawing::Size(98, 20);
			this->textBox40->TabIndex = 24;
			// 
			// textBox32
			// 
			this->textBox32->Location = System::Drawing::Point(76, 3);
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(98, 20);
			this->textBox32->TabIndex = 24;
			// 
			// textBox33
			// 
			this->textBox33->Location = System::Drawing::Point(76, 81);
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(98, 20);
			this->textBox33->TabIndex = 28;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(3, 58);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(51, 13);
			this->label41->TabIndex = 25;
			this->label41->Text = L"P weight:";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(3, 84);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(47, 13);
			this->label42->TabIndex = 27;
			this->label42->Text = L"I weight:";
			// 
			// textBox34
			// 
			this->textBox34->Location = System::Drawing::Point(76, 55);
			this->textBox34->Name = L"textBox34";
			this->textBox34->Size = System::Drawing::Size(98, 20);
			this->textBox34->TabIndex = 26;
			// 
			// panel8
			// 
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Controls->Add(this->textBox35);
			this->panel8->Controls->Add(this->label43);
			this->panel8->Controls->Add(this->textBox36);
			this->panel8->Controls->Add(this->label44);
			this->panel8->Controls->Add(this->textBox37);
			this->panel8->Controls->Add(this->label45);
			this->panel8->Controls->Add(this->textBox38);
			this->panel8->Controls->Add(this->label46);
			this->panel8->Controls->Add(this->textBox39);
			this->panel8->Controls->Add(this->label47);
			this->panel8->Location = System::Drawing::Point(194, 19);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(179, 136);
			this->panel8->TabIndex = 27;
			// 
			// textBox35
			// 
			this->textBox35->Location = System::Drawing::Point(57, 107);
			this->textBox35->Name = L"textBox35";
			this->textBox35->Size = System::Drawing::Size(112, 20);
			this->textBox35->TabIndex = 20;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(2, 110);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(37, 13);
			this->label43->TabIndex = 19;
			this->label43->Text = L"Cubic:";
			// 
			// textBox36
			// 
			this->textBox36->Location = System::Drawing::Point(57, 81);
			this->textBox36->Name = L"textBox36";
			this->textBox36->Size = System::Drawing::Size(112, 20);
			this->textBox36->TabIndex = 18;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(2, 84);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(56, 13);
			this->label44->TabIndex = 17;
			this->label44->Text = L"Quadratic:";
			// 
			// textBox37
			// 
			this->textBox37->Location = System::Drawing::Point(57, 55);
			this->textBox37->Name = L"textBox37";
			this->textBox37->Size = System::Drawing::Size(112, 20);
			this->textBox37->TabIndex = 16;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(2, 58);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(39, 13);
			this->label45->TabIndex = 15;
			this->label45->Text = L"Linear:";
			// 
			// textBox38
			// 
			this->textBox38->Location = System::Drawing::Point(57, 29);
			this->textBox38->Name = L"textBox38";
			this->textBox38->Size = System::Drawing::Size(112, 20);
			this->textBox38->TabIndex = 14;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(2, 32);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(52, 13);
			this->label46->TabIndex = 13;
			this->label46->Text = L"Constant:";
			// 
			// textBox39
			// 
			this->textBox39->Location = System::Drawing::Point(57, 3);
			this->textBox39->Name = L"textBox39";
			this->textBox39->Size = System::Drawing::Size(112, 20);
			this->textBox39->TabIndex = 12;
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(2, 6);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(45, 13);
			this->label47->TabIndex = 11;
			this->label47->Text = L"Degree:";
			// 
			// Monitoring
			// 
			this->Monitoring->Controls->Add(this->label19);
			this->Monitoring->Controls->Add(this->panel2);
			this->Monitoring->Controls->Add(this->label1);
			this->Monitoring->Controls->Add(this->panel1);
			this->Monitoring->Location = System::Drawing::Point(4, 22);
			this->Monitoring->Name = L"Monitoring";
			this->Monitoring->Padding = System::Windows::Forms::Padding(3);
			this->Monitoring->Size = System::Drawing::Size(486, 392);
			this->Monitoring->TabIndex = 3;
			this->Monitoring->Text = L"Monitoring and Control";
			this->Monitoring->UseVisualStyleBackColor = true;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(3, 263);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(67, 13);
			this->label19->TabIndex = 19;
			this->label19->Text = L"Motor Panel:";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->textBox14);
			this->panel2->Controls->Add(this->label15);
			this->panel2->Controls->Add(this->textBox15);
			this->panel2->Controls->Add(this->label16);
			this->panel2->Controls->Add(this->textBox16);
			this->panel2->Controls->Add(this->label17);
			this->panel2->Controls->Add(this->textBox17);
			this->panel2->Controls->Add(this->label18);
			this->panel2->Location = System::Drawing::Point(6, 277);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(209, 109);
			this->panel2->TabIndex = 18;
			// 
			// textBox14
			// 
			this->textBox14->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox14->Enabled = false;
			this->textBox14->Location = System::Drawing::Point(101, 81);
			this->textBox14->Name = L"textBox14";
			this->textBox14->ReadOnly = true;
			this->textBox14->Size = System::Drawing::Size(100, 20);
			this->textBox14->TabIndex = 7;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(3, 84);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(49, 13);
			this->label15->TabIndex = 6;
			this->label15->Text = L"-X motor:";
			// 
			// textBox15
			// 
			this->textBox15->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox15->Enabled = false;
			this->textBox15->Location = System::Drawing::Point(101, 55);
			this->textBox15->Name = L"textBox15";
			this->textBox15->ReadOnly = true;
			this->textBox15->Size = System::Drawing::Size(100, 20);
			this->textBox15->TabIndex = 5;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(3, 58);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(49, 13);
			this->label16->TabIndex = 4;
			this->label16->Text = L"-Y motor:";
			// 
			// textBox16
			// 
			this->textBox16->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox16->Enabled = false;
			this->textBox16->Location = System::Drawing::Point(101, 29);
			this->textBox16->Name = L"textBox16";
			this->textBox16->ReadOnly = true;
			this->textBox16->Size = System::Drawing::Size(100, 20);
			this->textBox16->TabIndex = 0;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(3, 32);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(52, 13);
			this->label17->TabIndex = 3;
			this->label17->Text = L"+X motor:";
			// 
			// textBox17
			// 
			this->textBox17->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox17->Enabled = false;
			this->textBox17->Location = System::Drawing::Point(101, 3);
			this->textBox17->Name = L"textBox17";
			this->textBox17->ReadOnly = true;
			this->textBox17->Size = System::Drawing::Size(100, 20);
			this->textBox17->TabIndex = 1;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(3, 6);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(52, 13);
			this->label18->TabIndex = 2;
			this->label18->Text = L"+Y motor:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Sensor Panel:";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->textBox8);
			this->panel1->Controls->Add(this->textBox7);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->textBox6);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->TiltTextBox);
			this->panel1->Controls->Add(this->TiltLabel);
			this->panel1->Location = System::Drawing::Point(6, 20);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(209, 241);
			this->panel1->TabIndex = 4;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 214);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(85, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Current heading:";
			// 
			// textBox8
			// 
			this->textBox8->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox8->Enabled = false;
			this->textBox8->Location = System::Drawing::Point(101, 211);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 16;
			// 
			// textBox7
			// 
			this->textBox7->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox7->Enabled = false;
			this->textBox7->Location = System::Drawing::Point(101, 185);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 15;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 188);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(76, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Current height:";
			// 
			// textBox6
			// 
			this->textBox6->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(101, 159);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 162);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(93, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Current z ang. vel:";
			// 
			// textBox5
			// 
			this->textBox5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(101, 133);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 136);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Current y ang. vel:";
			// 
			// textBox4
			// 
			this->textBox4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(101, 107);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 110);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Current x ang. vel:";
			// 
			// textBox3
			// 
			this->textBox3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(101, 81);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 84);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Current z acc:";
			// 
			// textBox2
			// 
			this->textBox2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(101, 55);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Current y acc:";
			// 
			// textBox1
			// 
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(101, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Current x acc:";
			// 
			// TiltTextBox
			// 
			this->TiltTextBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->TiltTextBox->Enabled = false;
			this->TiltTextBox->Location = System::Drawing::Point(101, 3);
			this->TiltTextBox->Name = L"TiltTextBox";
			this->TiltTextBox->ReadOnly = true;
			this->TiltTextBox->Size = System::Drawing::Size(100, 20);
			this->TiltTextBox->TabIndex = 1;
			this->TiltTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// TiltLabel
			// 
			this->TiltLabel->AutoSize = true;
			this->TiltLabel->Location = System::Drawing::Point(3, 6);
			this->TiltLabel->Name = L"TiltLabel";
			this->TiltLabel->Size = System::Drawing::Size(57, 13);
			this->TiltLabel->TabIndex = 2;
			this->TiltLabel->Text = L"Current tilt:";
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->codetestbutton);
			this->tabPage1->Controls->Add(this->button14);
			this->tabPage1->Controls->Add(this->button12);
			this->tabPage1->Controls->Add(this->label50);
			this->tabPage1->Controls->Add(this->panel10);
			this->tabPage1->Controls->Add(this->label49);
			this->tabPage1->Controls->Add(this->panel9);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(486, 392);
			this->tabPage1->TabIndex = 5;
			this->tabPage1->Text = L"Debugging Tests";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// codetestbutton
			// 
			this->codetestbutton->Location = System::Drawing::Point(368, 91);
			this->codetestbutton->Name = L"codetestbutton";
			this->codetestbutton->Size = System::Drawing::Size(105, 23);
			this->codetestbutton->TabIndex = 11;
			this->codetestbutton->Text = L"Code Test Button";
			this->codetestbutton->UseVisualStyleBackColor = true;
			this->codetestbutton->Click += gcnew System::EventHandler(this, &Form1::codetestbutton_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button14->Location = System::Drawing::Point(306, 363);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(75, 23);
			this->button14->TabIndex = 10;
			this->button14->Text = L"Cancel";
			this->button14->UseVisualStyleBackColor = false;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(387, 363);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(93, 23);
			this->button12->TabIndex = 9;
			this->button12->Text = L"Clear Terminal";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(290, 11);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(35, 13);
			this->label50->TabIndex = 8;
			this->label50->Text = L"Setup";
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->button10);
			this->panel10->Controls->Add(this->button9);
			this->panel10->Location = System::Drawing::Point(286, 27);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(190, 34);
			this->panel10->TabIndex = 7;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(82, 3);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(105, 23);
			this->button10->TabIndex = 1;
			this->button10->Text = L"Teardown HW";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(3, 3);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(73, 23);
			this->button9->TabIndex = 0;
			this->button9->Text = L"Init. HW";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(6, 14);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(56, 13);
			this->label49->TabIndex = 6;
			this->label49->Text = L"Run Tests";
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->button11);
			this->panel9->Controls->Add(this->button8);
			this->panel9->Controls->Add(this->button7);
			this->panel9->Controls->Add(this->button6);
			this->panel9->Controls->Add(this->button5);
			this->panel9->Location = System::Drawing::Point(6, 30);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(158, 100);
			this->panel9->TabIndex = 5;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(4, 61);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(151, 23);
			this->button11->TabIndex = 8;
			this->button11->Text = L"ESC Program";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(80, 31);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Joystick";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(1, 31);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Sensor";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(82, 2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 5;
			this->button6->Text = L"PWM Write";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(0, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"PWM Time";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Red;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button4->Font = (gcnew System::Drawing::Font(L"Dutch801 XBd BT", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Yellow;
			this->button4->Location = System::Drawing::Point(6, 284);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(128, 102);
			this->button4->TabIndex = 3;
			this->button4->Text = L"KILL!";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 455);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(70, 17);
			this->checkBox1->TabIndex = 10;
			this->checkBox1->Text = L"Log Data";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripProgressBar1});
			this->statusStrip1->Location = System::Drawing::Point(0, 475);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(518, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(100, 16);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->controlToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(518, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->newPIDToolStripMenuItem, 
				this->loadPIDToolStripMenuItem, this->savePIDToolStripMenuItem, this->setupComportsToolStripMenuItem, this->quitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newPIDToolStripMenuItem
			// 
			this->newPIDToolStripMenuItem->Name = L"newPIDToolStripMenuItem";
			this->newPIDToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->newPIDToolStripMenuItem->Text = L"New PID";
			// 
			// loadPIDToolStripMenuItem
			// 
			this->loadPIDToolStripMenuItem->Name = L"loadPIDToolStripMenuItem";
			this->loadPIDToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->loadPIDToolStripMenuItem->Text = L"Load PID";
			// 
			// savePIDToolStripMenuItem
			// 
			this->savePIDToolStripMenuItem->Name = L"savePIDToolStripMenuItem";
			this->savePIDToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->savePIDToolStripMenuItem->Text = L"Save PID";
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::quitToolStripMenuItem_Click);
			// 
			// controlToolStripMenuItem
			// 
			this->controlToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->runPIDToolStripMenuItem, 
				this->runManualToolStripMenuItem, this->clearTerminalToolStripMenuItem, this->kILLToolStripMenuItem, this->tellAJokeToolStripMenuItem});
			this->controlToolStripMenuItem->Name = L"controlToolStripMenuItem";
			this->controlToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->controlToolStripMenuItem->Text = L"Control";
			// 
			// runPIDToolStripMenuItem
			// 
			this->runPIDToolStripMenuItem->Name = L"runPIDToolStripMenuItem";
			this->runPIDToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->runPIDToolStripMenuItem->Text = L"Run PID";
			// 
			// runManualToolStripMenuItem
			// 
			this->runManualToolStripMenuItem->Name = L"runManualToolStripMenuItem";
			this->runManualToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->runManualToolStripMenuItem->Text = L"Run Manual";
			this->runManualToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::runManualToolStripMenuItem_Click);
			// 
			// clearTerminalToolStripMenuItem
			// 
			this->clearTerminalToolStripMenuItem->Name = L"clearTerminalToolStripMenuItem";
			this->clearTerminalToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->clearTerminalToolStripMenuItem->Text = L"Clear Terminal";
			// 
			// kILLToolStripMenuItem
			// 
			this->kILLToolStripMenuItem->Name = L"kILLToolStripMenuItem";
			this->kILLToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->kILLToolStripMenuItem->Text = L"KILL";
			this->kILLToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kILLToolStripMenuItem_Click);
			// 
			// tellAJokeToolStripMenuItem
			// 
			this->tellAJokeToolStripMenuItem->Name = L"tellAJokeToolStripMenuItem";
			this->tellAJokeToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->tellAJokeToolStripMenuItem->Text = L"Tell A Joke";
			this->tellAJokeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::tellAJokeToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			// 
			// setupComportsToolStripMenuItem
			// 
			this->setupComportsToolStripMenuItem->Name = L"setupComportsToolStripMenuItem";
			this->setupComportsToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->setupComportsToolStripMenuItem->Text = L"Setup Comports";
			this->setupComportsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::setupComportsToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(518, 497);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->TabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Quadrocopter Control Panel";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->TabControl->ResumeLayout(false);
			this->Settings->ResumeLayout(false);
			this->TiltPID->ResumeLayout(false);
			this->TiltPID->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->YawPID->ResumeLayout(false);
			this->YawPID->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->AltitudePID->ResumeLayout(false);
			this->AltitudePID->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->Monitoring->ResumeLayout(false);
			this->Monitoring->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
/*code for Settings page controls*/
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			//add code to execute the PID-corrected control loop here.
			 int counter=0;
			 while (counter<1)
			 {

			 }
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 int m = Kill(); //code for red kill button
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 	AllocConsole(); //opens a terminal window when the form is executed
				freopen("CONOUT$", "wb", stdout); //redirects all printf statements to that window
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 int m = Initalize_Hardware(); //manual flight execution
			 datalog log;
			 datalog * logptr;
			 if(logdata)
			 {
				 StartDataLogging(&log);
				 logptr = &log;
			 }
			 else
				 logptr = NULL;
			 m = ManFlight(logptr); /*main control loop*/
			 if(logdata)
				 EndDataLogging(logptr);
			 m = Teardown_Hardware();
		 }
/*code for Debug page buttons*/
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 int m = Initalize_Hardware(); //initalize hardware button
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 int m = Teardown_Hardware(); //teardown hardware button
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 datalog log;//pwm time test button 
			 datalog * logptr;
			 if(logdata)
			 {
				 StartDataLogging(&log);
				 logptr = &log;
			 }
			 else
				 logptr = NULL;
			 int m = PWM_Time_Test(&log);
			 if(logdata)
				 EndDataLogging(logptr);
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 int m = ESC_Program(); //esc program button
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 datalog log; //PWM write test button
			 datalog * logptr;
			 if(logdata)
			 {
				 StartDataLogging(&log);
				 logptr = &log;
			 }
			 else
				 logptr = NULL;
			 int m = PWM_Write_Test(logptr);
			 if(logdata)
				 EndDataLogging(logptr);

		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 datalog log; //Sensor Read Test button
			 datalog * logptr;
			 if(logdata)
			 {
				 StartDataLogging(&log);
				 logptr = &log;
			 }
			 else
				 logptr = NULL;
			 int m = Sensor_Read_Test(logptr);
			 if(logdata)
				 EndDataLogging(logptr);
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 datalog log; //Joystick Read test button
			 datalog * logptr;
			 if(logdata)
			 {
				 StartDataLogging(&log);
				 logptr = &log;
			 }
			 else
				 logptr = NULL;
			 int m = Joystick_Read_Test(logptr);
			 if(logdata)
				 EndDataLogging(logptr);
		 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 int m = Teardown_Hardware(); //code to be executed as program is closed
			 printf("NO NO!!!! DON'T KILL ME!!!! NOOOOO!!!!\n\n\n ....I'm dying.... gaaak... :(\n\n");
		 }
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //"about" selection under help menu
			 MessageBox::Show("iRobotics Quadcopter Computer Interface V.1.00\nInterface Design and Programming by Chris Gerth and Michael Vilim\nThank you to all our sponsors who will eventually be mentioned here.");
		 }
private: System::Void tellAJokeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //"Tell a Joke" selection under control menu
			 MessageBox::Show("So a Pirate walks into a bar (the drinking establishment type), and he's got this steering wheel down the front of his pants. The bartender says, 'Sir, that looks really uncomfortable!' and the pirate replies 'Yar! and it's driving me nuts!");
		 }
private: System::Void quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //"exit selection" under file menu
			 Close();
		 }
private: System::Void runManualToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //"Run Manual" under control menu
			 int m = Initalize_Hardware();
			 datalog log;
			 datalog * logptr;
			 if(logdata)
			 {
				 StartDataLogging(&log);
				 logptr = &log;
			 }
			 else
				 logptr = NULL;
			 m = ManFlight(logptr);
			 m = Teardown_Hardware();
			 if(logdata)
				 EndDataLogging(logptr);
			 m = Teardown_Hardware();
		 }
private: System::Void kILLToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //"kill" under control menu
			 int m = Kill();
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			 //"clear console" button
			 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 //log data checkbox checked action
			 logdata = !logdata;
			 //printf("logdata = %d\n", logdata);
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Kill button on debug page
			 int m = Kill();
		 }

private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 
			 printf("executing background code...\n");
		 }
private: System::Void codetestbutton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
		 }
private: System::Void setupComportsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 /*local vars*/
			 int input;
			 
			 /*code to execute when "setup comports" is selected under the file menu*/
			 printf("\n-----------------------------\n");
			 printf("Current Comports:\n");
			 printf("	to joystick interface - %d\n", joystickcomport);
			 printf("	to Xbee wireless      - %d\n", wirelesscomport);
			 printf("	to FTDI interface     - %d\n", wiredcomport);
			 /*get new values for comports*/
			 printf("\nEnter new comport for Joystick interface: ");
			 scanf("%d", &input);
			 if(input < 0) //perform error check
			 {
				 printf("\ninvalid entry\n");
				 return;
			 }
			 joystickcomport = input;
			 printf("\nEnter new comport for Xbee wireless interface: ");
			 scanf("%d", &input);
			 if(input < 0) //perform error check
			 {
				 printf("\ninvalid entry\n");
				 return;
			 }
			 wirelesscomport = input;
			 printf("\nEnter new comport for FTDI wired interface: ");
			 scanf("%d", &input);
			 if(input < 0) //perform error check
			 {
				 printf("\ninvalid entry\n");
				 return;
			 }
			 wiredcomport = input;
			 printf("\nNew comports:\n");
			 printf("	joystick - %d\n", joystickcomport);
			 printf("	Xbee     - %d\n", wirelesscomport);
			 printf("	FTDI     - %d\n", wiredcomport);
			 printf("\n-----------------------------\n");
			 return;
		 }
};
}

