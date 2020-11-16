#pragma once
#include"JuegoForm.h"
namespace JuegoTF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblNombre;
	protected:
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::NumericUpDown^ numvidas;
	private: System::Windows::Forms::NumericUpDown^ numcorruptos;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblCorruptos;


	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->numvidas = (gcnew System::Windows::Forms::NumericUpDown());
			this->numcorruptos = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblCorruptos = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numvidas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numcorruptos))->BeginInit();
			this->SuspendLayout();
			// 
			// lblNombre
			// 
			this->lblNombre->AutoSize = true;
			this->lblNombre->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNombre->Location = System::Drawing::Point(53, 43);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(856, 99);
			this->lblNombre->TabIndex = 0;
			this->lblNombre->Text = L"Laberinto del engaño";
			// 
			// btnStart
			// 
			this->btnStart->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnStart.BackgroundImage")));
			this->btnStart->FlatAppearance->BorderSize = 0;
			this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStart->Location = System::Drawing::Point(270, 434);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(377, 125);
			this->btnStart->TabIndex = 1;
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MenuForm::btnStart_Click);
			// 
			// numvidas
			// 
			this->numvidas->BackColor = System::Drawing::Color::CadetBlue;
			this->numvidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numvidas->ForeColor = System::Drawing::Color::White;
			this->numvidas->Location = System::Drawing::Point(270, 278);
			this->numvidas->Name = L"numvidas";
			this->numvidas->ReadOnly = true;
			this->numvidas->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->numvidas->Size = System::Drawing::Size(120, 61);
			this->numvidas->TabIndex = 2;
			this->numvidas->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// numcorruptos
			// 
			this->numcorruptos->BackColor = System::Drawing::Color::CadetBlue;
			this->numcorruptos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numcorruptos->ForeColor = System::Drawing::Color::White;
			this->numcorruptos->Location = System::Drawing::Point(527, 278);
			this->numcorruptos->Name = L"numcorruptos";
			this->numcorruptos->ReadOnly = true;
			this->numcorruptos->Size = System::Drawing::Size(120, 61);
			this->numcorruptos->TabIndex = 3;
			this->numcorruptos->TabStop = false;
			this->numcorruptos->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->lblVidas->Location = System::Drawing::Point(103, 204);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(327, 48);
			this->lblVidas->TabIndex = 4;
			this->lblVidas->Text = L"Número de vidas";
			// 
			// lblCorruptos
			// 
			this->lblCorruptos->AutoSize = true;
			this->lblCorruptos->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCorruptos->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->lblCorruptos->Location = System::Drawing::Point(474, 204);
			this->lblCorruptos->Name = L"lblCorruptos";
			this->lblCorruptos->Size = System::Drawing::Size(400, 48);
			this->lblCorruptos->TabIndex = 5;
			this->lblCorruptos->Text = L"Número de corruptos";
			// 
			// MenuForm
			// 
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(990, 622);
			this->Controls->Add(this->lblCorruptos);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->numcorruptos);
			this->Controls->Add(this->numvidas);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->lblNombre);
			this->MaximizeBox = false;
			this->Name = L"MenuForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numvidas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numcorruptos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
	
	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Visible = false;
		JuegoForm^ frm = gcnew JuegoForm();
		frm->ShowDialog();
		this->Visible = true;
	}
	};
}
