#pragma once

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormCrane
	/// </summary>
	public ref class FormCrane : public System::Windows::Forms::Form
	{
	public:
		FormCrane(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormCrane()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBoxArea;
	private: System::Windows::Forms::Button^ buttonGo;
	protected:


	private: System::Windows::Forms::Timer^ timer;
	private: System::ComponentModel::IContainer^ components;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormCrane::typeid));
			this->pictureBoxArea = (gcnew System::Windows::Forms::PictureBox());
			this->buttonGo = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxArea))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxArea
			// 
			this->pictureBoxArea->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxArea->Location = System::Drawing::Point(300, 109);
			this->pictureBoxArea->Name = L"pictureBoxArea";
			this->pictureBoxArea->Size = System::Drawing::Size(330, 480);
			this->pictureBoxArea->TabIndex = 0;
			this->pictureBoxArea->TabStop = false;
			// 
			// buttonGo
			// 
			this->buttonGo->Location = System::Drawing::Point(565, 10);
			this->buttonGo->Name = L"buttonGo";
			this->buttonGo->Size = System::Drawing::Size(57, 20);
			this->buttonGo->TabIndex = 1;
			this->buttonGo->Text = L"Go!";
			this->buttonGo->UseVisualStyleBackColor = true;
			this->buttonGo->Click += gcnew System::EventHandler(this, &FormCrane::buttonBlock_Click);
			// 
			// timer
			// 
			this->timer->Interval = 350;
			this->timer->Tick += gcnew System::EventHandler(this, &FormCrane::FormCrane_Update);
			// 
			// FormCrane
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(640, 591);
			this->Controls->Add(this->buttonGo);
			this->Controls->Add(this->pictureBoxArea);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"FormCrane";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Projekt 4 - Wizualizacja Systemów Automatyki";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxArea))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: array<PictureBox^, 1>^ blocks;		// Tworzenie tablicy blokow
	private: PictureBox^ block1;				// Zmienne blokow typu pictureBox
	private: PictureBox^ block2;
	private: PictureBox^ block3;
	private: PictureBox^ hook;					// Zmienne haka typu pictureBox
	private: int step = 30;						// Krok
	private: int stage;							// Etap
	private: bool work;							// Dzialanie programu (true - kontynuj, false - zakoncz)
	private: float updateInterval = 350;		// Interwal odswierzania (wyrazony w milisekundach)

	private: void NewSimulation();
	private: void GenerateBlockPositions();
	private: void MovementHook();
	private: void MovementDirection();
	private: void MovementBlocks();

	private: System::Void buttonBlock_Click(System::Object^ sender, System::EventArgs^ e);

	private: void FormCrane_Update(Object^ object, EventArgs^ e);
	};
}
